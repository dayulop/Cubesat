#include "mainwindow.h"

#include <QApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*QTextStream out(stdout);

    QSerialPort serial;

    // Cambiá el nombre del puerto según tu sistema
    serial.setPortName("COM7");  // En Linux sería algo como "/dev/ttyUSB0"
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (serial.open(QIODevice::ReadOnly)) {
        out << "Conectado al puerto serie." << Qt::endl;

        QObject::connect(&serial, &QSerialPort::readyRead, [&]() {
            QByteArray datos = serial.readAll();
            out << "Datos recibidos: " << datos << Qt::endl;
        });
    } else {
        out << "Error al abrir el puerto: " << serial.errorString() << Qt::endl;
        return 1;
    }*/
    return a.exec();
}
