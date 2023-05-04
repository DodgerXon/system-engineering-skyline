#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4IMU imu;

#include "TurnSensor.h"

void setup()
{
  turnSensorSetup();
  delay(500);
  turnSensorReset();
}

void loop()
{
  turnSensorUpdate();
  if(buttonA.isPressed()) {
    Serial.println((((int32_t)turnAngle >> 16) * 360) >> 16);  
  }
}
