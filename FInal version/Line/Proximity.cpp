#include "HardwareSerial.h"
#include "Proximity.h"

Proximity::Proximity():message("") {
}

void Proximity::detect() {

}

void Proximity::setup() {
  Serial1.begin(9600);
  Wire.begin();
  proximit.initThreeSensors();
  message = "Setup success";
  Serial1.print(message);
}

void Proximity::print() {
  message = "Returning the print function";
  Serial1.println(message);
}

void Proximity::printReadingsToSerial()
{
  proximit.read();
  static char buffer[80];
  sprintf(buffer, "%d %d \n",
    proximit.countsFrontWithLeftLeds(),
    proximit.countsFrontWithRightLeds()
  );
  Serial1.print(buffer);
}

int Proximity::giveReadingFrontLeft() {
  int frontleft = proximit.countsFrontWithLeftLeds();
  return frontleft;
}

int Proximity::giveReadingFrontRight() {
  int frontright = proximit.countsFrontWithRightLeds();
  return frontright;
}

void Proximity::uitvoeren() {
  
  motors.setLeftSpeed(speedL);
  motors.setRightSpeed(speedR);   
  
  if(proximit.giveReadingFrontLeft() > 2 || proximit.giveReadingFrontRight() > 2) {
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
  if(proximit.giveReadingFrontLeft() == 0 || proximit.giveReadingFrontRight() == 0){
  speedL = 200;
  speedR = -200;
  motors.setLeftSpeed(speedL);
  motors.setRightSpeed(speedR);
  }
}