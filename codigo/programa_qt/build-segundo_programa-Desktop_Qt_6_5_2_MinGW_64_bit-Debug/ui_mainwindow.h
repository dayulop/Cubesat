/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox_ports;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_recibido;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_lectura_de_serial;
    QHBoxLayout *graficas;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_humedad;
    QProgressBar *bar_humedad;
    QCustomPlot *widget_humedad;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_temperatura;
    QLCDNumber *lcd_temperatura;
    QCustomPlot *widget_temperatura;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_iniciar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBox_ports = new QComboBox(centralwidget);
        comboBox_ports->addItem(QString());
        comboBox_ports->setObjectName("comboBox_ports");
        comboBox_ports->setGeometry(QRect(0, 0, 509, 24));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 30, 511, 415));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_recibido = new QLabel(widget);
        label_recibido->setObjectName("label_recibido");

        horizontalLayout_3->addWidget(label_recibido);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_4);

        label_lectura_de_serial = new QLabel(widget);
        label_lectura_de_serial->setObjectName("label_lectura_de_serial");

        verticalLayout_7->addWidget(label_lectura_de_serial);


        verticalLayout_8->addLayout(verticalLayout_7);

        graficas = new QHBoxLayout();
        graficas->setObjectName("graficas");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_humedad = new QLabel(widget);
        label_humedad->setObjectName("label_humedad");

        verticalLayout_2->addWidget(label_humedad);

        bar_humedad = new QProgressBar(widget);
        bar_humedad->setObjectName("bar_humedad");
        bar_humedad->setMaximumSize(QSize(16777215, 16777215));
        bar_humedad->setValue(0);

        verticalLayout_2->addWidget(bar_humedad);


        verticalLayout_4->addLayout(verticalLayout_2);

        widget_humedad = new QCustomPlot(widget);
        widget_humedad->setObjectName("widget_humedad");
        verticalLayout_5 = new QVBoxLayout(widget_humedad);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer = new QSpacerItem(20, 228, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalSpacer = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer);


        verticalLayout_4->addWidget(widget_humedad);


        graficas->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_temperatura = new QLabel(widget);
        label_temperatura->setObjectName("label_temperatura");
        label_temperatura->setMinimumSize(QSize(71, 0));
        label_temperatura->setMaximumSize(QSize(71, 16777215));

        verticalLayout->addWidget(label_temperatura);

        lcd_temperatura = new QLCDNumber(widget);
        lcd_temperatura->setObjectName("lcd_temperatura");
        lcd_temperatura->setMinimumSize(QSize(64, 0));
        lcd_temperatura->setMaximumSize(QSize(64, 16777215));
        lcd_temperatura->setStyleSheet(QString::fromUtf8("hola rgb(255, 255, 255)"));
        lcd_temperatura->setInputMethodHints(Qt::ImhNone);
        lcd_temperatura->setSmallDecimalPoint(false);

        verticalLayout->addWidget(lcd_temperatura);

        widget_temperatura = new QCustomPlot(widget);
        widget_temperatura->setObjectName("widget_temperatura");
        verticalLayout_6 = new QVBoxLayout(widget_temperatura);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalSpacer_2 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        horizontalSpacer_2 = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_temperatura);


        graficas->addLayout(verticalLayout);


        verticalLayout_8->addLayout(graficas);

        pushButton_iniciar = new QPushButton(widget);
        pushButton_iniciar->setObjectName("pushButton_iniciar");

        verticalLayout_8->addWidget(pushButton_iniciar);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        comboBox_ports->setItemText(0, QCoreApplication::translate("MainWindow", "Ports", nullptr));

        comboBox_ports->setCurrentText(QCoreApplication::translate("MainWindow", "Ports", nullptr));
        label_recibido->setText(QCoreApplication::translate("MainWindow", "Recibido", nullptr));
        label_lectura_de_serial->setText(QString());
        label_humedad->setText(QCoreApplication::translate("MainWindow", "Humedad", nullptr));
        label_temperatura->setText(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        pushButton_iniciar->setText(QCoreApplication::translate("MainWindow", "iniciar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
