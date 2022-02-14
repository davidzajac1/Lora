#include <SoftwareSerial.h>

#include <TinyGPS.h>

//VCC  GND  RXD  TXD  PPS

TinyGPS gps;
SoftwareSerial ss(4, 3); // (RX, TX)

void setup()
{
  Serial.begin(115200);
  ss.begin(4800);
  
  Serial.print("Simple TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
}

void loop()
{
  Serial.println(ss.available());
  Serial.println(ss.read());
  Serial.println(gps.encode(ss.read()));
  Serial.println();
  delay(1000);
  
}
