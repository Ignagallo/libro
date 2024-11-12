#include "agregarnuevolibro.h"
#include "qpushbutton.h"
#include "ui_agregarnuevolibro.h"
#include <QMessageBox>

agregarnuevolibro::agregarnuevolibro(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::agregarnuevolibro)
{
    ui->setupUi(this);

    // Conectar los botones a las funciones correspondientes
    connect(ui->confirmarCambio, &QPushButton::clicked, this, &::agregarnuevolibro::on_botonAceptar_clicked);
    connect(ui->cancelarCambio, &QPushButton::clicked, this, &::agregarnuevolibro::on_botonCancelar_clicked);
}

agregarnuevolibro::~agregarnuevolibro()
{
    delete ui;
}

QString agregarnuevolibro::getTitulo() const { return ui->campoTitulo->text(); }
QString agregarnuevolibro::getAutor() const { return ui->campoAutor->text(); }
QString agregarnuevolibro::getEditorial() const { return ui->campoEditorial->text(); }
int agregarnuevolibro::getAño() const { return ui->anioLibro->date().year(); }
int agregarnuevolibro::getStock() const { return ui->campoStock->value(); }

void agregarnuevolibro::on_botonAceptar_clicked()
{
    // Obtener los valores de los campos
    QString titulo = ui->campoTitulo->text();
    QString autor = ui->campoAutor->text();
    QString editorial = ui->campoEditorial->text();
    int año = ui->anioLibro->date().year();
    int stock = ui->campoStock->value();

    // Validar que todos los campos estén completos
    if (titulo.isEmpty() || autor.isEmpty() || editorial.isEmpty()) {
        // Mostrar mensaje de error si algún campo está vacío
        QMessageBox::warning(this, "Error", "Todos los campos son obligatorios.");
        return;  // No continuar, ya que hay un error
    }

    // Validar que el año esté en un rango lógico (por ejemplo, mayor que 1800)
    if (año < 1800 || año > QDate::currentDate().year()) {
        QMessageBox::warning(this, "Error", "El año debe estar entre 1800 y el año actual.");
        return;  // No continuar, ya que hay un error
    }

    // Validar que el stock sea un número positivo
    if (stock < 0) {
        QMessageBox::warning(this, "Error", "El stock no puede ser negativo.");
        return;  // No continuar, ya que hay un error
    }

    // Si todo es válido, aceptamos el diálogo
    accept();
}

void agregarnuevolibro::on_botonCancelar_clicked()
{
    // Cerrar el diálogo sin hacer nada
    reject();
}
void agregarnuevolibro::cargarDatos(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock)
{
    ui->campoTitulo->setText(titulo);
    ui->campoAutor->setText(autor);
    ui->campoEditorial->setText(editorial);
    ui->anioLibro->setDate(QDate(año, 1, 1));
    ui->campoStock->setValue(stock);
}
