#include <Wire.h>
#include <Zumo32U4.h>


Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4Buzzer buzzer;
Zumo32U4IMU imu;

#include "TurnSensor.h"

char input;

int snelheidLinks = 0;
int snelheidRechts = 0;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);

  turnSensorSetup();
  delay(500);
  turnSensorReset();

  lineSensors.initFiveSensors();
}

void loop() {
  // put your main code here, to run repeatedly:
  basicControls();

  turnSensorUpdate();
  if(buttonA.isPressed()) {
    Serial.println((((int32_t)turnAngle >> 16) * 360) >> 16);  
  }
  
  lineSensors.read(lineSensorValues);
  printen();
}

void printen(){
  uint16_t sensorEen = lineSensorValues[0];
  uint16_t sensorTwee = lineSensorValues[1];
  uint16_t sensorDrie = lineSensorValues[2];
  uint16_t sensorVier = lineSensorValues[3];
  uint16_t sensorVijf = lineSensorValues[4];
  Serial.print("Links: ");
  Serial.print(" ");
  Serial.print(sensorEen);
  Serial.print(" ");
  Serial.print(sensorTwee);

  Serial.print("  Midden: ");
  Serial.print(" ");
  Serial.print(sensorDrie); 

  Serial.print("  rechts: ");
  Serial.print(" ");
  Serial.print(sensorVier);
  Serial.print(" ");
  Serial.print(sensorVijf);
  Serial.println();
}

void basicControls()
{
  
  if (Serial1.available())
  { 
    input=Serial1.read();
  
  if (input == 'w') //forward = w
  {
    moveForward();
  }
    
  if (input == 'a') // corner to the left = a
  {
      cornerLeft();
  }
  
  if (input == 'd') // corner to the right = d
  {
      cornerRight();
  }    
  
 
  if (input == 's') //backwards = s
  {
      moveBackwards();
  }    

 
  if (input == 'q') // stop = q
  {
      stopMoving();
  }   
   
    if (snelheidLinks > 400) snelheidLinks = 400; // engine safety (forward)
    if (snelheidLinks < -400) snelheidLinks = -400; // engine safety (backwards)
    if (snelheidRechts > 400) snelheidRechts = 400; // engine safety (forward)
    if (snelheidRechts < -400) snelheidRechts = -400; // engine safety (backwards)
    motors.setLeftSpeed(snelheidLinks);
    motors.setRightSpeed(snelheidRechts);
 }
}

  void moveForward() //settings to move forward
  {
    snelheidLinks = 400;
    snelheidRechts = 400; 
    Serial1.println("Vooruit!");
  }
  void cornerLeft() //settings for corner to the left
  {
      snelheidLinks = -180;
      snelheidRechts = 140; // bocht naar links
      Serial1.println("bocht naar links!");
  }
  void cornerRight() //settings for corner to the right
  {
      snelheidLinks = 140;
      snelheidRechts = -180; // bocht naar rechts
      Serial1.println("bocht naar rechts!");
  }
 void moveBackwards() // settings for backwards
 {
      snelheidLinks = -250; 
      snelheidRechts = -250;
      Serial1.println("achteruit!!");
 }
   void stopMoving() // settings for STOP
  {
      snelheidLinks = 0;
      snelheidRechts = 0;
      Serial1.println("stop!!");
  } 
  