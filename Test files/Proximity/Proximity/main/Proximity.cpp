#include "Proximity.h"

Proximity::Proximity():message("") {
}

void Proximity::setup() {
  Serial.begin(9600);
  Wire.begin();
  proximity.initThreeSensors();
  message = "Setup success";
  Serial.print(message);
}

void Proximity::printReadingsToSerial()
{
  proximity.read();
  static char buffer[80];
  sprintf(buffer, "%d %d \n",
    proximity.countsFrontWithLeftLeds(),
    proximity.countsFrontWithRightLeds()
  );
  Serial.print(buffer);
}

int Proximity::giveReadingFrontLeft() {
  int frontleft = proximity.countsFrontWithLeftLeds();
  return frontleft;
}

int Proximity::giveReadingFrontRight() {
  int frontright = proximity.countsFrontWithRightLeds();
  return frontright;
}
