#include "Lijnsensoren.h"
#include "Lijnsensoren.cpp"

#include <QTRSensors.h>

#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;


void setup() {
  // put your setup code here, to run once:
    lineSensors.initFiveSensors;
}

void loop() {
  // put your main code here, to run repeatedly:
  lineSensors.readCalibrated();
}