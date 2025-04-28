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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_temperatura;
    QLCDNumber *lcd_temperatura;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_humedad;
    QProgressBar *bar_humedad;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 130, 73, 47));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_temperatura = new QLabel(widget);
        label_temperatura->setObjectName("label_temperatura");
        label_temperatura->setMinimumSize(QSize(71, 0));
        label_temperatura->setMaximumSize(QSize(71, 16777215));

        verticalLayout->addWidget(label_temperatura);

        lcd_temperatura = new QLCDNumber(widget);
        lcd_temperatura->setObjectName("lcd_temperatura");
        lcd_temperatura->setMinimumSize(QSize(64, 0));
        lcd_temperatura->setMaximumSize(QSize(64, 16777215));

        verticalLayout->addWidget(lcd_temperatura);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(140, 130, 89, 48));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_humedad = new QLabel(widget1);
        label_humedad->setObjectName("label_humedad");

        verticalLayout_2->addWidget(label_humedad);

        bar_humedad = new QProgressBar(widget1);
        bar_humedad->setObjectName("bar_humedad");
        bar_humedad->setValue(0);

        verticalLayout_2->addWidget(bar_humedad);

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
        label_temperatura->setText(QCoreApplication::translate("MainWindow", "temperatura", nullptr));
        label_humedad->setText(QCoreApplication::translate("MainWindow", "humedad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
