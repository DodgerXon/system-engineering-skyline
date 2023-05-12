#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];


void setup()  {
  Serial.begin(9600);
  lineSensors.initFiveSensors();
  

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

void loop() {
  lineSensors.read(lineSensorValues);
  printen();
  delay(1000);
}
