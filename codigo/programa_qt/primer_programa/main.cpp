#include "mainwindow.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    QSerialPort serial;
    serial.setPortName("COM8");  // En Linux sería algo como "/dev/ttyUSB0"
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
    }

    return a.exec();
}
