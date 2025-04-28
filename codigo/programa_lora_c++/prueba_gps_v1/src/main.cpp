#include <Arduino.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

// Creamos una instancia del GPS y del puerto serial
TinyGPSPlus gps;
HardwareSerial GPS_Serial(1);  // UART1 del ESP32

void setup() {
  Serial.begin(9600);             // Monitor serial
  GPS_Serial.begin(4800, SERIAL_8N1, 16, 17); // Baudrate, configuración, RX, TX

  Serial.println("Esperando datos del GPS...");
}

void loop() {
  // Mientras haya datos disponibles en el puerto serial del GPS
  while (GPS_Serial.available() > 0) {
    char c = GPS_Serial.read();
    gps.encode(c);

    if (gps.location.isUpdated()) {
      Serial.print("Latitud: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitud: ");
      Serial.println(gps.location.lng(), 6);
      Serial.println("---------------------------");
    }
  }
}/*
#include <HardwareSerial.h>

HardwareSerial GPS_Serial(1);

void setup() {
  Serial.begin(9600);
  GPS_Serial.begin(4800, SERIAL_8N1, 16, 17);  // RX = GPIO16, TX = GPIO17 (TX no es obligatorio si solo recibís)
  Serial.println("Esperando datos NMEA del GPS...");
}

void loop() {
  while (GPS_Serial.available()) {
    char c = GPS_Serial.read();
    Serial.print(c);  // Mostrar directamente las cadenas NMEA
  }
}*/

