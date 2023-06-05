
#include <Zumo32U4.h>
#include <Wire.h>
#include "IMU.h"
Zumo32U4IMU sensor;
Zumo32U4Motors motors;
using namespace std;


    IMU::IMU() {
  

    }
    void IMU::klaarmaken(){
        Wire.begin();
        //Anders werkt de IMU niet
  
        if (!sensor.init())
        {
        // Failed to detect the compass.
            ledRed(1);
            while(1)
            {
                Serial.println(F("Failed to initialize IMU sensors."));
                delay(100);
            }
        }
        //Dit is geeft aan wanneer de imu kapot is of dat de pin nummers niet goed zijn.
  

        sensor.configureForBalancing();

        // Dit doet letterlijk wat het zegt lol


    }
    void IMU::lezen(){
          sensor.read();
        // Leest de IMU waarde uit

    }
    void IMU::printen(){
      Serial.println(sensor.a.x);
      if (sensor.a.x < 100 && sensor.a.x > -100 ) {
        Serial.println("Pitch 0°");


      
      }
        // print de waarde uit van de accelerometer

    }
    void IMU::balans(){
      if (sensor.a.x < 100 && sensor.a.x > -100 ) {
          motors.setLeftSpeed(0);
          motors.setRightSpeed(0);
        }
      if (sensor.a.x > 100) {
          motors.setLeftSpeed(100);
          motors.setRightSpeed(100);
        }
      if (sensor.a.x < 100) {
          motors.setLeftSpeed(-100);
          motors.setRightSpeed(-100);
        }
    }
    IMU::~IMU(){

    }