#ifndef LINE_H
#define LINE_H

#include <Zumo32U4.h>
#include <Wire.h>

class Line {
public:
  Line();
  void vindHoogsteLaagste(int[], int&, int&);
  void setup(int&, int&, int&, int&, int&, int&);
  int LineRijdenzwart(int[]);
  int LineRijdenGroen(int[]);
  int LineRijdenBruin(int[]);
  int geefWaardes(int&, int&, int&, int&, int&);
  void lezen(int&, int&, int&, int&, int&);

  private:
  Zumo32U4LineSensors lineSensors;
  Zumo32U4Motors motors;
  Zumo32U4ButtonA ButtonA;
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
  int maxSpeed = 360;
  int groeneSnelheid = 150;
  
};

#endif