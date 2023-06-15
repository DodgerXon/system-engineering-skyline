#include "Linesensording.h"

Line linesensor;
Line motors;

Proximity prox;
Zumo32U4Motors motors;

int speedL = 200;
int speedR = -200;
char input = Serial1.read();

int waardes[5];
int zwart[2];
int groen[2];
int bruin[2];
int wit[2];
int switchm = 0;

void setup() {
  linesensor.setup(groen[0], groen[1], zwart[0], zwart[1], bruin[0], bruin[1], wit[0], wit[1]); // calibreert de verschillende kleuren, en returned de waarden die hiern
}

void loop() {
  linesensor.lezen(waardes[0], waardes[1], waardes[2], waardes[3], waardes[4]);
 
  for (int i = 0; i < 5; i++) {
    if (waardes[i] <= zwart[1] && waardes[i] >= wit[0])  {
      switchm = 3;
    }
    else if(waardes[i] <= groen[0] && waardes[i] >= wit[1])   {
      switchm = 1;
    } 
    else if (waardes[i] <= bruin[0] && waardes[i] >= bruin[1])  {
      switchm = 2;
    } else if (input = 'p') {
        input = Serial1.read();
        prox.setup();
        switchm = 4;
        break;
    }
  }

  switch(switchm) {
    case 1:
      linesensor.LineRijdenGroen();
      break;
    case 2:
      linesensor.LineRijdenBruin();
      break;
    case 3:
      linesensor.LineRijdenzwart();
      break;
      case 4:

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
  // for (int i = 0; i < 5; i++) {
  //   Serial1.println(waardes[i]);
  // }
}