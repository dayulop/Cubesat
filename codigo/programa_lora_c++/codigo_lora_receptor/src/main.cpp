#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>

#define LORA_SS 8
#define LORA_RST 4
#define LORA_DI0 7

void setup() {
  Serial.begin(9600);
  //while (!Serial);

  LoRa.setPins(LORA_SS, LORA_RST, LORA_DI0);

  if (!LoRa.begin(915E6)) {
    //Serial.println("Error al iniciar LoRa");
    while (1);
  }

  //Serial.println("LoRa Receptor Listo");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    //Serial.print("Recibido: ");
    while (LoRa.available()) {
      String data = LoRa.readString();
      Serial.print(data);
    }
    //Serial.println();
  }
}