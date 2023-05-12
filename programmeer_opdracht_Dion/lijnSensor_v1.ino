#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LineSensors lineSensors;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];
bool  useEmitters = true;

void setup()  {
  Serial.begin(9600);
  lineSensors.initFiveSensors();
  
  

}
void printReadingsToSerial()
{
  char buffer[80];
  sprintf(buffer, "%4d %4d %4d %4d %4d %c\n",
    lineSensorValues[0],
    lineSensorValues[1],
    lineSensorValues[2],
    lineSensorValues[3],
    lineSensorValues[4],
    useEmitters ? 'E' : 'e'
  );
  Serial.print(buffer);
  delay(50);
}

void loop() {
  lineSensors.read(lineSensorValues, useEmitters ? QTR_EMITTERS_ON : QTR_EMITTERS_OFF);
  printReadingsToSerial();
  

  
}
