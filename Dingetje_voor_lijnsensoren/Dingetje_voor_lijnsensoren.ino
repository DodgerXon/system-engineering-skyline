#include <Wire.h>
#include <Zumo32U4.h>
#include "Calibrateding.cpp"

const uint16_t maxSpeed = 400;

int16_t lastError = 0;

Zumo32U4Buzzer buzzer;
Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

int calibrationSensors[2];

unsigned int lineSensorValues[5];

int zwart[2];

int bruin[2];

int grijs[2];

int rood[2];

int groen[2];

int wit[2];

//eerste waarde is minimum, 2de is maximum

void setup() {
  // put your setup code here, to run once:
    lineSensors.initFiveSensors();

    buttonA.waitForButton();



    calibrate();


}


void calibrate()
{
  for (int i = 0; i < 2; i++) {
  lineSensors.calibrate(&zwart[0], &zwart[1]);
  delay(2000);
  buzzer.play(">g32>>c32");
  }

  for (int i = 0; i < 2; i++) {
  lineSensors.calibrate(&bruin[0], &bruin[1]);
  delay(2000);
  buzzer.play(">g32>>c32");
  }

for (int i = 0; i < 2; i++) {
  lineSensors.calibrate(&grijs[0], &grijs[1]);
  delay(2000);
  buzzer.play(">g32>>c32");
}

for (int i = 0; i < 2; i++) {
  lineSensors.calibrate(&rood[0], &rood[1]);
  delay(2000);
  buzzer.play(">g32>>c32");
}

for (int i = 0; i < 2; i++) {
  lineSensors.calibrate(&groen[0], &groen[1]);
  delay(2000);
  buzzer.play(">g32>>c32");
}

for (int i = 0; i < 2; i++) {
  lineSensors.calibrate(&wit[0], &wit[1]);
  delay(2000);
  buzzer.play(">g32>>c32");
}

while(!buttonA.getSingleDebouncedPress())
  {
    lineSensors.readCalibrated(lineSensorValues);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    int16_t position = lineSensors.readLine(lineSensorValues);

    int16_t error = position - 2000;

     int16_t speedDifference = error / 4 + 6 * (error - lastError);

  lastError = error;

    if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= wit[0] && sensorWaardes[3] <= wit[1] && sensorWaardes[4] >= wit[0] && sensorWaardes[4] <= wit[1] && sensorWaardes[1] >= wit[0] && sensorWaardes[1] <= wit[1] && sensorWaardes[0] >= wit[0] && sensorWaardes[0] <= wit[1]  && grijsOfBruin == 0) {
  
  //zwarte lijn in het midden volgen

    int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
    int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

    leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
}

if (sensorWaardes[2] >= wit[0] && sensorWaardes[2] <= wit[1] && sensorWaardes[3] >= wit[0] && sensorWaardes[3] <= wit[1] && sensorWaardes[4] >= wit[0] && sensorWaardes[4] <= wit[1] && sensorWaardes[1] >= zwart[0] && sensorWaardes[1] <= zwart[1] && sensorWaardes[0] >= wit[0] && sensorWaardes[0] <= wit[1]  && grijsOfBruin == 0) {
  
  //sturen naar links
}

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= grijs[0] && sensorWaardes[3] <= grijs[1] && sensorWaardes[4] >= grijs[0] && sensorWaardes[4] <= grijs[1] && grijsOfBruin == 0) {
  
  // volgende kruispunt rechts
} 

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[1] >= grijs[0] && sensorWaardes[1] <= grijs[1] && sensorWaardes[0] >= grijs[0] && sensorWaardes[0] <= grijs[1] && grijsOfBruin == 0) {
  
  // volgende kruispunt links
} 

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= grijs[0] && sensorWaardes[3] <= grijs[1] && sensorWaardes[4] >= grijs[0] && sensorWaardes[4] <= grijs[1] && sensorWaardes[1] >= grijs[0] && sensorWaardes[1] <= grijs[1] && sensorWaardes[0] >= grijs[0] && sensorWaardes[0] <= grijs[1]  && grijsOfBruin == 0) {
  
  //Stilstaan voor WipWap en wachten op IMU = 0 (of whatever de waarde ervoor is)
} 

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= bruin[0] && sensorWaardes[3] <= bruin[1] && sensorWaardes[4] >= bruin[0] && sensorWaardes[4] <= bruin[1] && sensorWaardes[1] >= bruin[0] && sensorWaardes[1] <= bruin[1] && sensorWaardes[0] >= bruin[0] && sensorWaardes[0] <= bruin[1]  && grijsOfBruin == 1) {

  //20 cm vooruitrijden
  //fase 2
}

if (sensorWaardes[2] >= bruin[0] && sensorWaardes[2] <= bruin[1] && grijsOfBruin == 1) {
  
}
if (sensorWaardes[2] >= rood[0] && sensorWaardes[2] <= rood[1]) {
  //niet volgen
}

if (sensorWaardes[2] >= groen[0] && sensorWaardes[2] <= groen[1]) {
  //snelheid = 50%
  grijsOfBruin = 1;
} 
if (sensorWaardes[2] >= grijs[0] && sensorWaardes[2] <= grijs[1] && grijsOfBruin == 0) {
  
}
}
