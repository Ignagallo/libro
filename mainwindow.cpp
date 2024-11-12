#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <libro.h>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "agregarnuevolibro.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->agregarLibro, &QPushButton::clicked, this, &MainWindow::onAgregarLibro);
    connect(ui->modificarLibro, &QPushButton::clicked, this, &MainWindow::onModificarLibro);
    connect(ui->eliminarLibro, &QPushButton::clicked, this, &MainWindow::onEliminarLibro);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onAgregarLibro()
{
    agregarnuevolibro dialogo(this);
    if (dialogo.exec() == QDialog::Accepted) {
        // Obtén los datos del diálogo
        QString titulo = dialogo.getTitulo();
        QString autor = dialogo.getAutor();
        QString editorial = dialogo.getEditorial();
        int año = dialogo.getAño();
        int stock = dialogo.getStock();

        // Crea un nuevo libro y añádelo a la lista
        libro nuevoLibro(titulo, autor, editorial, año, stock);
        libros.append(nuevoLibro);

        // Actualiza la tabla
        actualizarTabla();
    }
}
void MainWindow::actualizarLibro(int fila, const libro &libro)
{
    // Actualiza el libro en la lista
    libros[fila] = libro;

    // Actualizar solo la fila en la tabla
    ui->tabla->setItem(fila, 0, new QTableWidgetItem(libro.getTitulo()));
    ui->tabla->setItem(fila, 1, new QTableWidgetItem(libro.getAutor()));
    ui->tabla->setItem(fila, 2, new QTableWidgetItem(libro.getEditorial()));
    ui->tabla->setItem(fila, 3, new QTableWidgetItem(QString::number(libro.getAño())));
    ui->tabla->setItem(fila, 4, new QTableWidgetItem(QString::number(libro.getStock())));

}

void MainWindow::onModificarLibro()
{
    // Obtener la fila seleccionada en la tabla
    int filaSeleccionada = ui->tabla->currentRow();
    if (filaSeleccionada >= 0) {
        // Obtener el libro correspondiente de la lista
        libro libroSeleccionado = libros[filaSeleccionada];

        // Crear el diálogo de modificación y cargar los datos actuales
        agregarnuevolibro dialogo(this);
        dialogo.cargarDatos(libroSeleccionado.getTitulo(), libroSeleccionado.getAutor(),
                            libroSeleccionado.getEditorial(), libroSeleccionado.getAño(),
                            libroSeleccionado.getStock());

        // Mostrar el diálogo y capturar los cambios
        if (dialogo.exec() == QDialog::Accepted) {
            // Actualizar los datos del libro con los valores del diálogo
            libroSeleccionado.setTitulo(dialogo.getTitulo());
            libroSeleccionado.setAutor(dialogo.getAutor());
            libroSeleccionado.setEditorial(dialogo.getEditorial());
            libroSeleccionado.setAño(dialogo.getAño());
            libroSeleccionado.setStock(dialogo.getStock());

            // Llamada a actualizarLibro para actualizar el libro en la lista y la tabla
            actualizarLibro(filaSeleccionada, libroSeleccionado);
        }
    } else {
        QMessageBox::warning(this, "Error", "Por favor selecciona un libro para modificar.");
    }
}


void MainWindow::onEliminarLibro()
{
    int filaSeleccionada = ui->tabla->currentRow();
    if (filaSeleccionada >= 0) {
        libros.removeAt(filaSeleccionada);
        actualizarTabla();
    } else {
        QMessageBox::warning(this, "Error", "Por favor selecciona un libro para eliminar.");
    }
}

void MainWindow::actualizarTabla()
{
    ui->tabla->setRowCount(libros.size());

    for (int i = 0; i < libros.size(); ++i) {
        const libro &libroActual = libros[i];

        // Creamos un QVector de QStrings que contiene los valores de cada atributo del libro
        QVector<QString> datosLibro = {
            libroActual.getTitulo(),
            libroActual.getAutor(),
            libroActual.getEditorial(),
            QString::number(libroActual.getAño()),
            QString::number(libroActual.getStock())
        };

        // Asignamos cada valor a la columna correspondiente
        for (int j = 0; j < datosLibro.size(); ++j) {
            ui->tabla->setItem(i, j, new QTableWidgetItem(datosLibro[j]));
        }
    }
}
