#ifndef LINE_H
#define LINE_H

#include <Zumo32U4.h>
#include <Wire.h>

class Line {
public:
  Line();
  void vindHoogsteLaagste(int, int, int);
  void setup();
  void LineRijden();
  int geefWaardes();

  private:
  int sensorWaardes[5];
  int zwart[2] = {0, 2000};
  int grijs[2] = {0, 2000};
  int groen[2] = {0, 2000};
  int rood[2] = {0, 2000};
  int bruin[2] = {0, 2000};
  int wit[2] = {0, 2000};
  Zumo32U4LineSensors lineSensors;
  Zumo32U4ButtonA ButtonA;
  Zumo32U4Buzzer buzzer;
};

#endif