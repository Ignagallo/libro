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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *eliminarLibro;
    QPushButton *modificarLibro;
    QPushButton *agregarLibro;
    QTableWidget *tabla;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *campoTituloBusqueda;
    QLineEdit *campoAutorBusqueda;
    QLineEdit *campoEditorialBusqueda;
    QLineEdit *campoGeneroBusqueda;
    QLabel *label;
    QPushButton *botonBuscar;
    QPushButton *mostrarTodos;
    QPushButton *botonGuardarLista;
    QPushButton *botonCargarLista;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(726, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 701, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        eliminarLibro = new QPushButton(gridLayoutWidget);
        eliminarLibro->setObjectName("eliminarLibro");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eliminarLibro->sizePolicy().hasHeightForWidth());
        eliminarLibro->setSizePolicy(sizePolicy);
        eliminarLibro->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(eliminarLibro, 1, 2, 1, 1);

        modificarLibro = new QPushButton(gridLayoutWidget);
        modificarLibro->setObjectName("modificarLibro");
        sizePolicy.setHeightForWidth(modificarLibro->sizePolicy().hasHeightForWidth());
        modificarLibro->setSizePolicy(sizePolicy);
        modificarLibro->setMinimumSize(QSize(0, 35));
        modificarLibro->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(modificarLibro, 1, 1, 1, 1);

        agregarLibro = new QPushButton(gridLayoutWidget);
        agregarLibro->setObjectName("agregarLibro");
        sizePolicy.setHeightForWidth(agregarLibro->sizePolicy().hasHeightForWidth());
        agregarLibro->setSizePolicy(sizePolicy);
        agregarLibro->setMaximumSize(QSize(16777215, 35));

        gridLayout->addWidget(agregarLibro, 1, 0, 1, 1);

        tabla = new QTableWidget(gridLayoutWidget);
        if (tabla->columnCount() < 7)
            tabla->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tabla->setObjectName("tabla");
        tabla->setAutoScrollMargin(10);
        tabla->setAlternatingRowColors(true);
        tabla->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        tabla->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tabla->horizontalHeader()->setDefaultSectionSize(100);

        gridLayout->addWidget(tabla, 0, 0, 1, 3);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(160, 390, 211, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        campoTituloBusqueda = new QLineEdit(formLayoutWidget);
        campoTituloBusqueda->setObjectName("campoTituloBusqueda");

        formLayout->setWidget(2, QFormLayout::FieldRole, campoTituloBusqueda);

        campoAutorBusqueda = new QLineEdit(formLayoutWidget);
        campoAutorBusqueda->setObjectName("campoAutorBusqueda");

        formLayout->setWidget(3, QFormLayout::FieldRole, campoAutorBusqueda);

        campoEditorialBusqueda = new QLineEdit(formLayoutWidget);
        campoEditorialBusqueda->setObjectName("campoEditorialBusqueda");

        formLayout->setWidget(4, QFormLayout::FieldRole, campoEditorialBusqueda);

        campoGeneroBusqueda = new QLineEdit(formLayoutWidget);
        campoGeneroBusqueda->setObjectName("campoGeneroBusqueda");

        formLayout->setWidget(5, QFormLayout::FieldRole, campoGeneroBusqueda);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        botonBuscar = new QPushButton(centralwidget);
        botonBuscar->setObjectName("botonBuscar");
        botonBuscar->setGeometry(QRect(410, 400, 80, 24));
        mostrarTodos = new QPushButton(centralwidget);
        mostrarTodos->setObjectName("mostrarTodos");
        mostrarTodos->setGeometry(QRect(410, 440, 81, 41));
        sizePolicy.setHeightForWidth(mostrarTodos->sizePolicy().hasHeightForWidth());
        mostrarTodos->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setStrikeOut(false);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        font1.setHintingPreference(QFont::PreferDefaultHinting);
        mostrarTodos->setFont(font1);
        mostrarTodos->setMouseTracking(false);
        mostrarTodos->setTabletTracking(false);
        mostrarTodos->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        mostrarTodos->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        mostrarTodos->setAcceptDrops(false);
        mostrarTodos->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);\n"
"color: black;"));
        botonGuardarLista = new QPushButton(centralwidget);
        botonGuardarLista->setObjectName("botonGuardarLista");
        botonGuardarLista->setGeometry(QRect(530, 400, 80, 24));
        botonCargarLista = new QPushButton(centralwidget);
        botonCargarLista->setObjectName("botonCargarLista");
        botonCargarLista->setGeometry(QRect(530, 450, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 726, 21));
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
        eliminarLibro->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        modificarLibro->setText(QCoreApplication::translate("MainWindow", "Modificar", nullptr));
        agregarLibro->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Titulo", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Autor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Genero", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Editorial", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "A\303\261o", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tabla->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "ISBN", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tabla->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Por Titulo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Por Editorial", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Por Autor", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Por Genero", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Filtrar tabla", nullptr));
        botonBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        mostrarTodos->setText(QCoreApplication::translate("MainWindow", "Mostrar todos", nullptr));
        botonGuardarLista->setText(QCoreApplication::translate("MainWindow", "Guardar CSV", nullptr));
        botonCargarLista->setText(QCoreApplication::translate("MainWindow", "Cargar CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
