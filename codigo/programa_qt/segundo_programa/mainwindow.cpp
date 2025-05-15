#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cargarPuertos();
    connect(ui->comboBox_ports, &QComboBox::currentIndexChanged,
            this, &MainWindow::puerto_seleccionado);
    connect(ui->pushButton_iniciar, &QPushButton::clicked,
            this, &MainWindow::iniciar);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::puerto_seleccionado(int index)
{
   MainWindow::puertoSeleccionado = ui->comboBox_ports->itemText(index);
}
void MainWindow::cargarPuertos() {
    ui->comboBox_ports->clear();
    const auto puertos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : puertos) {
        ui->comboBox_ports->addItem(info.portName());
    }
}
void MainWindow::iniciar(){
    iniciar_monitor_serie(&serial, puertoSeleccionado);
    lectura(&serial, temp, hum, lat, lon, alt, vel);
    mostrar_hum(hum);
    mostrar_temp(temp);
}
void MainWindow:: iniciar_monitor_serie(QSerialPort *serial, QString puerto){//iniciar el monitor serie
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
                                 float &lon, float &alt, float &vel){// leer los datos y escribirlos en las variables globales
    QByteArray rawData = serial->readAll();
    //formato de los datos que llegan.
    //"TEMP:25.80,HUM:33.00,LAT:-38.92,LON:-69.20,ALT:611.40,VEL:0.30";

    std::stringstream ss(rawData.toStdString());
    std::string segmento;

    while (std::getline(ss, segmento, ',')) {    //separa la linea que llega y divide cada segmento por "," hasta que no encuentre otra linea
        if (segmento.find("TEMP:") == 0) {       //identifica la etiqueta y sustrae todo los valores comenzando desde la posicion 4 o 5
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
void MainWindow::mostrar_temp(float temp){//muestra el valor de temperatura en el display
    ui->lcd_temperatura->display(temp);
}

void MainWindow::mostrar_hum(float hum){  // muestra el valor de la humedad en la barra
    ui->bar_humedad->setValue(hum);
}

void MainWindow::view_humidity_graph(float hum, float time_hum){ //muestra el grafico la humedad respecto el tiempo que definamos

}

void MainWindow::view_temp_graph(float hum, float time_temp){ // muestra el grafico la temperatura respecto el tiempo que definamos

}
