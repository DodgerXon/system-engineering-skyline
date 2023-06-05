#include "Proximity.h"

Proximity prox;
Zumo32U4Motors motors;

int speedL = 200;
int speedR = -200;

void setup() {
  prox.setup();
  delay(1000);
}

void loop() {
  motors.setLeftSpeed(speedL);
  motors.setRightSpeed(speedR);

  prox.printReadingsToSerial();

  if(prox.giveReadingFrontLeft() > 2 || prox.giveReadingFrontRight() > 2) {
    speedL = 0;
    speedR = 0;
    Serial.println("test");
    motors.setRightSpeed(speedR);
    motors.setLeftSpeed(speedL);
    Serial.println("test2");
    delay(3000);
    speedL = 400;
    speedR = 400;
    motors.setRightSpeed(speedR);
    motors.setLeftSpeed(speedL);
    delay(3000);
  }
  speedL = 200;
  speedR = -200;
  motors.setLeftSpeed(speedL);
  motors.setRightSpeed(speedR);
}