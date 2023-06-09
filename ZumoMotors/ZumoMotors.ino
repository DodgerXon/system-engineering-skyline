#include "ZumoMotors.h"
#include "ZumoMotors.cpp"
#include <Zumo32u4.h>
#include <Whire.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

void setup(){
  buttonA.waitForButton();
  delay(1000);

}

void loop(){
  voorwaarts();
  bochtLinksom();
  achterwaarts();
  bochtRechtsom();
  Stop();
  
}
