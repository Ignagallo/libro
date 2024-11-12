/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tabla;
    QPushButton *agregarLibro;
    QPushButton *modificarLibro;
    QPushButton *eliminarLibro;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(690, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabla = new QTableWidget(centralwidget);
        if (tabla->columnCount() < 5)
            tabla->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tabla->setObjectName("tabla");
        tabla->setGeometry(QRect(20, 10, 501, 192));
        tabla->setAutoScrollMargin(10);
        tabla->setAlternatingRowColors(true);
        tabla->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        tabla->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tabla->horizontalHeader()->setDefaultSectionSize(100);
        agregarLibro = new QPushButton(centralwidget);
        agregarLibro->setObjectName("agregarLibro");
        agregarLibro->setGeometry(QRect(100, 210, 80, 24));
        modificarLibro = new QPushButton(centralwidget);
        modificarLibro->setObjectName("modificarLibro");
        modificarLibro->setGeometry(QRect(230, 210, 80, 24));
        eliminarLibro = new QPushButton(centralwidget);
        eliminarLibro->setObjectName("eliminarLibro");
        eliminarLibro->setGeometry(QRect(360, 210, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 690, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Titulo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Autor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Editorial", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "A\303\261o", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        agregarLibro->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        modificarLibro->setText(QCoreApplication::translate("MainWindow", "Modificar", nullptr));
        eliminarLibro->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
