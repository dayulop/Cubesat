#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <iostream>
#include <sstream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void iniciar_monitor_serie(QSerialPort *serial, QString puerto);
    void lectura(QSerialPort*serial,float &temp,
                                 float &hum, float &lat,
                                 float &lon, float &alt, float &vel);
    void mostrar_temp(float temp);
    void mostrar_hum(float hum);
    float temp = 0, hum = 50, lat = 0, lon = 0, alt = 0, vel = 0;

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QString puertoSeleccionado;

};
#endif // MAINWINDOW_H
