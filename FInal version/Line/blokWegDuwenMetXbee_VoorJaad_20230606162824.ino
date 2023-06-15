#include "Proximity.h"
#include <Zumo32U4.h>

Proximity prox;
Zumo32U4Motors motors;

int speedL = 200;
int speedR = -200;
char input = Serial1.read();

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  while(input != 'p') {
    input = Serial1.read();
  }
  prox.setup();
  delay(500);
}

void loop() {
  prox.printReadingsToSerial();
  motors.setLeftSpeed(speedL);
  motors.setRightSpeed(speedR);   
  
  if(prox.giveReadingFrontLeft() > 2 || prox.giveReadingFrontRight() > 2) {
    speedL = 0;
    speedR = 0;
    motors.setRightSpeed(speedR);
    motors.setLeftSpeed(speedL);
    //delay(1500);
    speedL = 400;
    speedR = 400;
    motors.setRightSpeed(speedR);
    motors.setLeftSpeed(speedL);
    //delay(1500);
  }
  if(prox.giveReadingFrontLeft() == 0 || prox.giveReadingFrontRight() == 0){
  speedL = 200;
  speedR = -200;
  motors.setLeftSpeed(speedL);
  motors.setRightSpeed(speedR);
  }
}