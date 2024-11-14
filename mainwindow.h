#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "libro.h"
#include <QMainWindow>
#include <QTableWidgetItem>
#include <libro.h>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAgregarLibro();
    void onModificarLibro();
    void onEliminarLibro();
    void actualizarLibro(int fila, const libro &libro);
    void filtrarLibros();
    void mostrarTodosLosLibros();
    void guardarEnCSV();
    void cargarDesdeCSV();

private:
    Ui::MainWindow *ui;
    QList<libro> libros;  // Lista para almacenar los libros
    void actualizarTabla();
};
#endif // MAINWINDOW_H
