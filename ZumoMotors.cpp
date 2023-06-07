#include ZumoMotors.h
#include <Zumo32u4.h>
#include <Whire.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

void ZumoRijden::voorwaarts(int Speed){

  motors.setSpeeds(Speed, Speed);
  delay(500);

}

void ZumoRijden::achterwaarts(int SpeedBackwards, int SpeedBackwards){
  
  motors.setSpeeds(SpeedBackwards, SpeedBackwarts);
  delay(500);

}

void ZumoRijden::bochtLinksom(int HalveSpeedBackwards, int RightmotorTurn);{

  motor.setSpeeds(HalveSpeedBackwards, RightmotorTurn);
  delay(100);

}

void ZumoRijden::bochtRechtsom(int LeftmotorTurn, int HalveSpeedBackwards){

  motor.setSpeeds(LeftmotorTurn, HalveSpeedBackwards);
  delay(100);
}

void ZumoRijden::Stop(int Stop, int Stop){

  motor.setSpeeds(Stop, Stop);
  delay (1000)
}
