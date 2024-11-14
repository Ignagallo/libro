#include "mainwindow.h"
#include "qdatetime.h"
#include "ui_mainwindow.h"
#include <libro.h>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "agregarnuevolibro.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->agregarLibro, &QPushButton::clicked, this, &MainWindow::onAgregarLibro);
    connect(ui->modificarLibro, &QPushButton::clicked, this, &MainWindow::onModificarLibro);
    connect(ui->eliminarLibro, &QPushButton::clicked, this, &MainWindow::onEliminarLibro);

    // conexion botones de busqeuda y filtrado
    connect(ui->botonBuscar, &QPushButton::clicked, this, &MainWindow::filtrarLibros);
    connect(ui->mostrarTodos, &QPushButton::clicked, this, &MainWindow::mostrarTodosLosLibros);

    // Guardar en archivo
    connect(ui->botonGuardarLista, &QPushButton::clicked, this, &MainWindow::guardarEnCSV);

    // Cargar libros desde CSV
    connect(ui->botonCargarLista, &QPushButton::clicked, this, &MainWindow::cargarDesdeCSV);
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
        QString genero = dialogo.getGenero();
        QString editorial = dialogo.getEditorial();
        int año = dialogo.getAño();
        QString isbn = dialogo.getIsbn();
        int stock = dialogo.getStock();

        // Crea un nuevo libro y lo añade a la lista
        libro nuevoLibro(titulo, autor, genero, editorial, año, isbn, stock);
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
    ui->tabla->setItem(fila, 2, new QTableWidgetItem(libro.getGenero()));
    ui->tabla->setItem(fila, 3, new QTableWidgetItem(libro.getEditorial()));
    ui->tabla->setItem(fila, 4, new QTableWidgetItem(QString::number(libro.getAño())));
    ui->tabla->setItem(fila, 5, new QTableWidgetItem(libro.getIsbn()));
    ui->tabla->setItem(fila, 6, new QTableWidgetItem(QString::number(libro.getStock())));

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
        dialogo.cargarDatos(libroSeleccionado.getTitulo(),
                            libroSeleccionado.getAutor(),
                            libroSeleccionado.getGenero(),
                            libroSeleccionado.getEditorial(),
                            QDate(libroSeleccionado.getAño(), 1, 1),
                            libroSeleccionado.getIsbn(),
                            libroSeleccionado.getStock());

        // Mostrar el diálogo y capturar los cambios
        if (dialogo.exec() == QDialog::Accepted) {
            // Actualizar los datos del libro con los valores del diálogo
            libroSeleccionado.setTitulo(dialogo.getTitulo());
            libroSeleccionado.setAutor(dialogo.getAutor());
            libroSeleccionado.setGenero(dialogo.getGenero());
            libroSeleccionado.setEditorial(dialogo.getEditorial());
            libroSeleccionado.setAño(dialogo.getAño());
            libroSeleccionado.setIsbn(dialogo.getIsbn());
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
            libroActual.getGenero(),
            libroActual.getEditorial(),
            QString::number(libroActual.getAño()),
            libroActual.getIsbn(),
            QString::number(libroActual.getStock())
        };

        // Asignamos cada valor a la columna correspondiente
        for (int j = 0; j < datosLibro.size(); ++j) {
            ui->tabla->setItem(i, j, new QTableWidgetItem(datosLibro[j]));
        }
    }
}

//  FILTROS DE BUSQUEDA

void MainWindow::filtrarLibros()
{
    // Obtiene los textos de los campos de búsqueda
    QString tituloFiltro = ui->campoTituloBusqueda->text();
    QString autorFiltro = ui->campoAutorBusqueda->text();
    QString generoFiltro = ui->campoGeneroBusqueda->text();
    QString editorialFiltro = ui->campoEditorialBusqueda->text();

    // Limpia solo la tabla visualmente; la lista de libros no se afecta
    ui->tabla->clearContents();
    ui->tabla->setRowCount(0);

    // Itera sobre la lista de libros y agrega solo los que coinciden con los filtros
    int fila = 0;
    for (const libro &libroActual : libros) {
        bool coincide = true;

        if (!tituloFiltro.isEmpty() && !libroActual.getTitulo().contains(tituloFiltro, Qt::CaseInsensitive)) {
            coincide = false;
        }
        if (!autorFiltro.isEmpty() && !libroActual.getAutor().contains(autorFiltro, Qt::CaseInsensitive)) {
            coincide = false;
        }
        if (!generoFiltro.isEmpty() && !libroActual.getGenero().contains(generoFiltro, Qt::CaseInsensitive)) {
            coincide = false;
        }
        if (!editorialFiltro.isEmpty() && !libroActual.getEditorial().contains(editorialFiltro, Qt::CaseInsensitive)) {
            coincide = false;
        }

        if (coincide) {
            // Agrega el libro a la tabla si coincide con los filtros
            ui->tabla->insertRow(fila);
            ui->tabla->setItem(fila, 0, new QTableWidgetItem(libroActual.getTitulo()));
            ui->tabla->setItem(fila, 1, new QTableWidgetItem(libroActual.getAutor()));
            ui->tabla->setItem(fila, 2, new QTableWidgetItem(libroActual.getGenero()));
            ui->tabla->setItem(fila, 3, new QTableWidgetItem(libroActual.getEditorial()));
            ui->tabla->setItem(fila, 4, new QTableWidgetItem(QString::number(libroActual.getAño())));
            ui->tabla->setItem(fila, 5, new QTableWidgetItem(libroActual.getIsbn()));
            ui->tabla->setItem(fila, 6, new QTableWidgetItem(QString::number(libroActual.getStock())));
            fila++;
        }
    }
}
void MainWindow::mostrarTodosLosLibros()
{
    // Limpia los campos de búsqueda
    ui->campoTituloBusqueda->clear();
    ui->campoAutorBusqueda->clear();
    ui->campoGeneroBusqueda->clear();
    ui->campoEditorialBusqueda->clear();

    // Llama a filtrarLibros para refrescar la tabla con todos los libros
    filtrarLibros();
}

// Archivos CSV

void MainWindow::guardarEnCSV() {
    QFile archivo("libros.csv");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&archivo);

        // Escribimos los encabezados
        out << "Titulo,Autor,Genero,Editorial,Año,ISBN,Stock\n";

        // Escribimos cada libro en una línea
        for (const libro &lib : libros) {
            out << lib.getTitulo() << ","
                << lib.getAutor() << ","
                << lib.getGenero() << ","
                << lib.getEditorial() << ","
                << lib.getAño() << ","
                << lib.getIsbn() << ","
                << lib.getStock() << "\n";
        }
        archivo.close();
        QMessageBox::information(this, "Éxito", "Archivo guardado correctamente.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo guardar el archivo CSV.");
    }
}
//MainWindow::cargarDesdeCSV("libros.csv");
void MainWindow::cargarDesdeCSV() {
    QFile archivo("libros.csv");

    // Verificamos si el archivo existe
    if (!archivo.exists()) {
        // Si el archivo no existe, crearlo e inicializarlo con los encabezados
        if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "Error", "No se pudo crear el archivo.");
            return;
        }
        QTextStream out(&archivo);
        // Escribir los encabezados y datos de prueba
        out << "Titulo,Autor,Genero,Editorial,Año,ISBN,Stock\n";/*
            out << "Cien años de soledad,Gabriel Garcia Marquez,Ficción,Editorial Sudamericana,1967,1234567890,5\n";
            out << "1984,George Orwell,Ficción,Dystopian Books,1949,2345678901,3\n";
            out << "El principito,Antoine de Saint-Exupéry,Ficción infantil,Editorial Reynal & Hitchcock,1943,3456789012,10\n";
            out << "Orgullo y prejuicio,Jane Austen,Romance,Editorial Whitehall,1813,4567890123,2\n";
            out << "Rayuela,Julio Cortázar,Ficción,Editorial Sudamericana,1963,5678901234,4\n";
            out << "Don Quijote de la Mancha,Miguel de Cervantes,Aventura,Editorial Francisco de Robles,1605,6789012345,6\n";
        */
        archivo.close();
        QMessageBox::information(this, "Información", "El archivo no existía, se ha creado uno nuevo.");
        return;  // Salir de la función, ya que el archivo acaba de ser creado
    }

    // Ahora cargamos el archivo si ya existe
    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&archivo);

        // Limpiar lista actual de libros
        libros.clear();

        // Leer cada línea, ignorando la primera (encabezados)
        in.readLine();
        while (!in.atEnd()) {
            QString linea = in.readLine();
            QStringList datos = linea.split(',');

            if (datos.size() == 7) {
                QString titulo = datos[0];
                QString autor = datos[1];
                QString genero = datos[2];
                QString editorial = datos[3];
                int año = datos[4].toInt();
                QString isbn = datos[5];
                int stock = datos[6].toInt();

                // Crear libro y agregarlo a la lista
                libro nuevoLibro(titulo, autor, genero, editorial, año, isbn, stock);
                libros.append(nuevoLibro);
            }
        }
        archivo.close();
        actualizarTabla();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cargar el archivo CSV.");
    }
}
