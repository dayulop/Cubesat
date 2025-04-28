#include <Arduino.h>
#include <DHT.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>
#include "SoftwareSerial.h"
#include <SPI.h>
#include <LoRa.h>
#include <stdint.h>

// Pines de la antena
#define LORA_SS 8
#define LORA_RST 4
#define LORA_DI0 7

// Creamos una instancia del GPS y del puerto serial
TinyGPSPlus gps;
SoftwareSerial ss(14, 16);  // RX, TX (GPS a LoRa32u4)

double lat_microdeg=0;
double lon_microdeg=0;
double alt_m=0;
double vel_kmph=0;

// Definir el pin de datos del DHT y el tipo de sensor de temperatura y humedad
#define DHTPIN 2          // Pin digital conectado al DHT
#define DHTTYPE DHT11     // Tipo de sensor (DHT11 o DHT22)
// Crear objeto DHT
DHT dht(DHTPIN, DHTTYPE);
float tem=0;
float hum=0;

//_________________declaracion de funciones_________________//
void humedad_temperatura();
void localizacion();
void enviar_datos();

void setup() {
  Serial.begin(9600);
  //_________________inicializacion de sensor de temperatura_________________//
  //while (!Serial); // Esperar a que el puerto serial esté listo (importante en placas como LoRa32u4)
  dht.begin();
  Serial.println("Iniciando lectura del sensor DHT11...");

  //_________________inicializacion de gps_________________//
  ss.begin(4800);         // GPS típicamente trabaja a 9600
  Serial.println("Esperando datos NMEA del GPS...");

  //_________________inicializacion de la antena_________________//
  //while (!Serial);

  // Configura pines personalizados
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DI0);

  if (!LoRa.begin(915E6)) {
    Serial.println("LoRa init failed!");
    while (1);
  }

  Serial.println("LoRa Emisor Listo");

}

void loop() {
  //delay(2000); // Esperar 2 segundos entre lecturas
  humedad_temperatura();
  localizacion();
  enviar_datos();
}

//__________________________________funciones__________________________________//
void humedad_temperatura(){
  float h_ant = hum;
  float t_ant = tem;
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  tem = t;
  hum = h;
  // Verificar si la lectura fue válida
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer del sensor DHT!");
    return;
  }
  if((h_ant != h) || (t_ant !=t)){
  // Mostrar valores por serial
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" °C");
  }

}

void localizacion(){
  unsigned long start = millis();
  while (millis() - start < 2000) {  // Leer durante 2 segundos
    while (ss.available() > 0) {
      gps.encode(ss.read());
    }
  }

  if (gps.location.isUpdated()) {
    lat_microdeg = gps.location.lat();
    lon_microdeg = gps.location.lng();
    alt_m = gps.altitude.meters();
    vel_kmph = gps.speed.kmph();

    Serial.print("Latitud: ");
    Serial.println(lat_microdeg, 6);
    Serial.print("Longitud: ");
    Serial.println(lon_microdeg, 6);
    Serial.print("Altitud: ");
    Serial.print(alt_m);
    Serial.println(" m");
    Serial.print("Velocidad: ");
    Serial.print(vel_kmph);
    Serial.println(" km/h");
    Serial.println("---");
  } else {
    Serial.println("No hay actualización de GPS aún.");
  }
}

void enviar_datos(){
  Serial.print("Enviando datos a base...");
  Serial.println();

  LoRa.beginPacket();
  LoRa.print("temp:");
  LoRa.print(tem);
  LoRa.print(",");
  LoRa.print("hum:");
  LoRa.print(hum);
  LoRa.print(",");
  LoRa.print("lat:");
  LoRa.print(lat_microdeg);
  LoRa.print(",");
  LoRa.print("lon:");
  LoRa.print(lon_microdeg);
  LoRa.print(",");
  LoRa.print("alt:");
  LoRa.print(alt_m);
  LoRa.print(",");
  LoRa.print("vel:");
  LoRa.print(vel_kmph);
  LoRa.endPacket();
}