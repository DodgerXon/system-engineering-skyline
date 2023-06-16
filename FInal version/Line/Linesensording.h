#ifndef LINE_H
#define LINE_H

#include "Arduino.h" 
#include <Zumo32U4.h>
#include <Wire.h>
#include "HardwareSerial.h"

class Line {
public:
  Line();
  void vindHoogsteLaagste(int[], int&, int&);
  void setup(int&, int&, int&, int&, int&, int&, int&, int&, int&, int&);
  void correctie(int);
  int LineRijdenzwart();
  int LineRijdenGroen();
  int LineRijdenBruin();
  int geefWaardes(int&, int&, int&, int&, int&);
  void lezen(int&, int&, int&, int&, int&);

  private:
  Zumo32U4LineSensors lineSensors;
  Zumo32U4Motors motors;
  Zumo32U4ButtonA ButtonA;
  Zumo32U4ButtonC buttonc;
  Zumo32U4Buzzer buzzer;
  
  bool blijflinks;
  bool blijfrechts;
  bool isGroen = false;
  int sensorWaardes[5];
  int zwart[2];
  int grijs[2];
  int groen[2];
  int rood[2];
  int bruin[2];
  int wit[2];
  int lastError = 0;
  int16_t maxSpeed = 340;
  int16_t groeneSnelheid = 50;
};

#endif