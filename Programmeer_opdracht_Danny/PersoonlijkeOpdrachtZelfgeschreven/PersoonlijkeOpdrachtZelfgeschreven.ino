#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;

#define zwartmin 1100
#define zwartmax 1300

#define bruinmin 380
#define bruinmax 500

#define roodmin 88
#define roodmax 180

#define groenmin 192
#define groenmax 340

#define grijsmin 300
#define grijsmax 500

#define witmin 80
#define witmax 190

int sensorWaardes[5];
int grijsOfBruin = 0;

void setup() {
  Serial.begin(9600);
  lineSensors.initFiveSensors();
}

void loop() {
  lineSensors.read(sensorWaardes);

for (int i = 0; i < 5; i++) {
  Serial.print(sensorWaardes[i]);
  Serial.print(" ");
}
Serial.println("");

if (sensorWaardes[2] >= zwartmin && sensorWaardes[2] <= zwartmax && sensorWaardes[3] >= witmin && sensorWaardes[3] <= witmax && sensorWaardes[4] >= witmin && sensorWaardes[4] <= witmax && sensorWaardes[1] >= witmin && sensorWaardes[1] <= witmax && sensorWaardes[0] >= witmin && sensorWaardes[0] <= witmax  && grijsOfBruin == 0) {
  
  //zwarte lijn in het midden volgen
}

if (sensorWaardes[2] >= witmin && sensorWaardes[2] <= witmax && sensorWaardes[3] >= witmin && sensorWaardes[3] <= witmax && sensorWaardes[4] >= witmin && sensorWaardes[4] <= witmax && sensorWaardes[1] >= zwartmin && sensorWaardes[1] <= zwartmax && sensorWaardes[0] >= witmin && sensorWaardes[0] <= witmax  && grijsOfBruin == 0) {
  
  //sturen naar links
}

if (sensorWaardes[2] >= zwartmin && sensorWaardes[2] <= zwartmax && sensorWaardes[3] >= grijsmin && sensorWaardes[3] <= grijsmax && sensorWaardes[4] >= grijsmin && sensorWaardes[4] <= grijsmax && grijsOfBruin == 0) {
  
  // volgende kruispunt rechts
} 

if (sensorWaardes[2] >= zwartmin && sensorWaardes[2] <= zwartmax && sensorWaardes[1] >= grijsmin && sensorWaardes[1] <= grijsmax && sensorWaardes[0] >= grijsmin && sensorWaardes[0] <= grijsmax && grijsOfBruin == 0) {
  
  // volgende kruispunt links
} 

if (sensorWaardes[2] >= zwartmin && sensorWaardes[2] <= zwartmax && sensorWaardes[3] >= grijsmin && sensorWaardes[3] <= grijsmax && sensorWaardes[4] >= grijsmin && sensorWaardes[4] <= grijsmax && sensorWaardes[1] >= grijsmin && sensorWaardes[1] <= grijsmax && sensorWaardes[0] >= grijsmin && sensorWaardes[0] <= grijsmax  && grijsOfBruin == 0) {
  
  //Stilstaan voor WipWap en wachten op IMU = 0 (of whatever de waarde ervoor is)
} 

if (sensorWaardes[2] >= zwartmin && sensorWaardes[2] <= zwartmax && sensorWaardes[3] >= bruinmin && sensorWaardes[3] <= bruinmax && sensorWaardes[4] >= bruinmin && sensorWaardes[4] <= bruinmax && sensorWaardes[1] >= bruinmin && sensorWaardes[1] <= bruinmax && sensorWaardes[0] >= bruinmin && sensorWaardes[0] <= bruinmax  && grijsOfBruin == 1) {

  //20 cm vooruitrijden
  //fase 2
}

if (sensorWaardes[2] >= bruinmin && sensorWaardes[2] <= bruinmax && grijsOfBruin == 1) {
  
}
if (sensorWaardes[2] >= roodmin && sensorWaardes[2] <= roodmax) {
  //niet volgen
}

if (sensorWaardes[2] >= groenmin && sensorWaardes[2] <= groenmax) {
  //snelheid = 50%
  grijsOfBruin = 1;
} 
if (sensorWaardes[2] >= grijsmin && sensorWaardes[2] <= grijsmax && grijsOfBruin == 0) {
  
}

}