#include "heltec.h"

void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, true /*Serial Enable*/);

}

void loop() {
  Heltec.display->clear();
  Heltec.display->drawString(0, 0, "Update Complete!");
  Heltec.display->display();

}