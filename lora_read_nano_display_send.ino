#include "heltec.h"
#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

char ss_available[20]; //Initialized variable to store recieved data
char ss_read[20]; //Initialized variable to store recieved data
char ss_encode[20]; //Initialized variable to store recieved data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(115200);
  Heltec.begin(true /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
}

void loop() {
  Heltec.display->clear();
  Serial.readBytes(ss_available,20); //Read the serial data and store in var
  Serial.println(ss_available); //Print data on Serial Monitor
  Heltec.display->drawString(0, 0, ss_available);

  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print(ss_available);
  LoRa.endPacket();
  
  delay(1000);

  Serial.readBytes(ss_read,20); //Read the serial data and store in var
  Serial.println(ss_read); //Print data on Serial Monitor
  Heltec.display->drawString(0, 10, ss_read);

  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print(ss_read);
  LoRa.endPacket();

  delay(1000);

  Serial.readBytes(ss_encode,20); //Read the serial data and store in var
  Serial.println(ss_encode); //Print data on Serial Monitor
  Heltec.display->drawString(0, 20, ss_encode);

  LoRa.beginPacket();
  LoRa.setTxPower(14,RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print(ss_encode);
  LoRa.endPacket();

  Heltec.display->display();
  delay(1000);
}