/*#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define LORA_SS 8
#define LORA_RST 4
#define LORA_DI0 7

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Configura pines personalizados
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DI0);

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed!");
    while (1);
  }

  Serial.println("LoRa Emisor Listo");
}

void loop() {
  Serial.print("Enviando: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  delay(1000);
}*/
//Misma configuración que el emisor
#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define LORA_SS 8
#define LORA_RST 4
#define LORA_DI0 7

void setup() {
  Serial.begin(9600);
  while (!Serial);

  LoRa.setPins(LORA_SS, LORA_RST, LORA_DI0);

  if (!LoRa.begin(433E6)) {
    Serial.println("Error al iniciar LoRa");
    while (1);
  }

  Serial.println("LoRa Receptor Listo");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.print("Recibido: ");
    while (LoRa.available()) {
      String data = LoRa.readString();
      Serial.print(data);
    }
    Serial.println();
  }
}