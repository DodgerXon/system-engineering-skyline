#include "HardwareSerial.h"
#include "Proximity.h"

Proximity::Proximity():message("") {
}

void Proximity::detect() {

}

void Proximity::setup() {
  Serial1.begin(9600);
  Wire.begin();
  proximity.initThreeSensors();
  message = "Setup success";
  Serial1.print(message);
}

void Proximity::print() {
  message = "Returning the print function";
  Serial1.println(message);
}

void Proximity::printReadingsToSerial()
{
  proximity.read();
  static char buffer[80];
  sprintf(buffer, "%d %d \n",
    proximity.countsFrontWithLeftLeds(),
    proximity.countsFrontWithRightLeds()
  );
  Serial1.print(buffer);
}

int Proximity::giveReadingFrontLeft() {
  int frontleft = proximity.countsFrontWithLeftLeds();
  return frontleft;
}

int Proximity::giveReadingFrontRight() {
  int frontright = proximity.countsFrontWithRightLeds();
  return frontright;
}