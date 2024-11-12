#ifndef AGREGARNUEVOLIBRO_H
#define AGREGARNUEVOLIBRO_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class agregarnuevolibro;
}

class agregarnuevolibro : public QDialog
{
    Q_OBJECT

public:
    explicit agregarnuevolibro(QWidget *parent = nullptr);
    ~agregarnuevolibro();

    QString getTitulo() const;
    QString getAutor() const;
    QString getEditorial() const;
    int getAño() const;
    int getStock() const;


    void cargarDatos(const QString &titulo, const QString &autor, const QString &editorial, int año, int stock);

private slots:
    void on_botonAceptar_clicked();
    void on_botonCancelar_clicked();


private:
    Ui::agregarnuevolibro *ui;
};

#endif // AGREGARNUEVOLIBRO_H
