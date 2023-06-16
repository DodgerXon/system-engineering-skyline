#ifndef PROXIMITY_H
#define PROXIMITY_H

#include <Wire.h>
#include <Arduino.h>
#include <Zumo32U4.h>

#pragma once

class Proximity {
public:
	Proximity();
	void print();
	void setup();
  void detect();
  void uitvoeren();
  void printReadingsToSerial();
  int giveReadingFrontLeft();
  int giveReadingFrontRight();
  

private:
  Zumo32U4ProximitySensors proximit;
  Zumo32U4Motors motors;
  String message;
  int speedL = 200;
  int speedR = -200;


};

#endif