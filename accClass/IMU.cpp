#include   <iostream>
//#include <Zumo32U4.h>
//#include <Wire.h>
#include "IMU.h"
using namespace std;


    IMU::IMU(string s) : sensor(s) {
        Zumo32U4IMU sensor;

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
        // print de waarde uit van de accelerometer

    }
    IMU::~IMU(){

    }