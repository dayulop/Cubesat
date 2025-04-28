#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    puertoSeleccionado ="COM7";
    iniciar_monitor_serie(&serial, puertoSeleccionado);
    lectura(&serial, temp, hum, lat, lon, alt, vel);
    mostrar_hum(hum);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: iniciar_monitor_serie(QSerialPort *serial, QString puerto){
    serial->setPortName(puerto);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->isOpen()){
        qDebug() << "Serial Port Is Connected";
        qDebug() << serial->error();
    }else{
        qDebug() << "Serial Port Is Not Connected";
        qDebug() << serial->error();
    }
}

void MainWindow::lectura(QSerialPort*serial,float &temp,
                                 float &hum, float &lat,
                                 float &lon, float &alt, float &vel){
    QByteArray rawData = serial->readAll();
    //formato de los datos que llegan.
    //"TEMP:25.80,HUM:33.00,LAT:-38.92,LON:-69.20,ALT:611.40,VEL:0.30";

    std::stringstream ss(rawData.toStdString());
    std::string segmento;

    while (std::getline(ss, segmento, ',')) {
        if (segmento.find("TEMP:") == 0) {
            temp = std::stof(segmento.substr(5));
        } else if (segmento.find("HUM:") == 0) {
            hum = std::stof(segmento.substr(4));
        } else if (segmento.find("LAT:") == 0) {
            lat = std::stof(segmento.substr(4));
        } else if (segmento.find("LON:") == 0) {
            lon = std::stof(segmento.substr(4));
        } else if (segmento.find("ALT:") == 0) {
            alt = std::stof(segmento.substr(4));
        } else if (segmento.find("VEL:") == 0) {
            vel = std::stof(segmento.substr(4));
        }
    }
}
void MainWindow::mostrar_temp(float temp){

}

void MainWindow::mostrar_hum(float hum){
    ui->bar_humedad->setValue(hum);
}
