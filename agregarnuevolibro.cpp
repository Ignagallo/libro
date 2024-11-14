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
QString agregarnuevolibro::getGenero() const { return ui->campoGenero->text(); }
QString agregarnuevolibro::getEditorial() const { return ui->campoEditorial->text(); }
int agregarnuevolibro::getAño() const { return ui->anioLibro->date().year(); }
QString agregarnuevolibro::getIsbn() const { return ui->campoIsbn->text(); }
int agregarnuevolibro::getStock() const { return ui->campoStock->value(); }

void agregarnuevolibro::on_botonAceptar_clicked()
{
    // Obtener los valores de los campos
    QString titulo = ui->campoTitulo->text();
    QString autor = ui->campoAutor->text();
    QString genero = ui->campoGenero->text();
    QString editorial = ui->campoEditorial->text();
    int año = ui->anioLibro->date().year();
    QString isbn = ui->campoIsbn->text();
    int stock = ui->campoStock->value();

    // Validar que todos los campos estén completos
    if (titulo.isEmpty() || autor.isEmpty() || genero.isEmpty() || editorial.isEmpty() || isbn.isEmpty()) {
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
void agregarnuevolibro::cargarDatos(const QString &titulo, const QString &autor, const QString &genero, const QString &editorial, const QDate &año, const QString &isbn, int stock)
{
    ui->campoTitulo->setText(titulo);
    ui->campoAutor->setText(autor);
    ui->campoGenero->setText(genero);
    ui->campoEditorial->setText(editorial);   
    ui->campoIsbn->setText(isbn);
    ui->campoStock->setValue(stock);

    ui->anioLibro->setDisplayFormat("dd/mm/yyyy");
    ui->anioLibro->setDate(QDate(año));
}
