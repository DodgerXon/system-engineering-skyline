#ifndef LINESENSORDING_H
#define LINESENSORDING_H

#include <Zumo32U4.h>
#include <Wire.h>

class LineSensording {
public:
  LineSensording();
  void vindHoogsteLaagste(int);
  void setup();

  private:
  int sensorWaardes[5];
  Zumo32U4LineSensors lineSensors;
}

#endif