#include <Wire.h>
#include "Arduino.h"
#include <Zumo32U4.h>
#include "IMU.h"
IMU imusensor;


void setup(){

imusensor.klaarmaken();


}

void loop(){
imusensor.lezen();
imusensor.printen();




}