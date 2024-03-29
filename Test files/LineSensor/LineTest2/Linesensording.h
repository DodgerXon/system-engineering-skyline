#ifndef LINESENSORDING_H
#define LINESENSORDING_H

#include <Zumo32U4.h>
#include "Arduino.h"
#include <Wire.h>

class LineSensording {
public:
  LineSensording();
  void vindHoogsteLaagste(int[]);
  void setup();
  void lezen();
  int geefWaardeTerug();

private:
  int sensorWaardes[5];
  Zumo32U4LineSensors lineSensors;
  int max = 0;
  int min = 2000;
};

#endif