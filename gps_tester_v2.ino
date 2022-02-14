#include <SoftwareSerial.h>

#include <TinyGPS++.h>

//VCC  GND  RXD  TXD  PPS

TinyGPSPlus gps;
SoftwareSerial ss(4, 3); // (RX, TX)

void setup()
{
  Serial.begin(115200);
  ss.begin(4800);
  
  Serial.print("Simple TinyGPS library v. "); Serial.println(TinyGPSPlus::library_version());
  Serial.println();
}

void loop()
{
  gps.encode(ss.read());
  Serial.println("Satellite Value");
  Serial.println(gps.satellites.value());

  Serial.println("Latitude");
  Serial.println(gps.location.lat());

  Serial.println("Longitude");
  Serial.println(gps.location.lng());

  Serial.println("Altitude");
  Serial.println(gps.altitude.feet());

  Serial.println();
  delay(1000);
  
}