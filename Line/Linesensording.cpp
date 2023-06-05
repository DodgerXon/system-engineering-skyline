#include "LineSensording.h"

Line::Line() {

}

void Line::setup() {
  lineSensors.initFiveSensors();

  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  findHighestLowest(sensorWaardes, zwart[0], zwart[1]);

  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  findHighestLowest(sensorWaardes, grijs[0], grijs[1]);

  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  findHighestLowest(sensorWaardes, groen[0], groen[1]);

  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  findHighestLowest(sensorWaardes, rood[0], rood[1]);

  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  findHighestLowest(sensorWaardes, bruin[0], bruin[1]);
}

void Line::vindHoogsteLaagste(int sensorWaardes[], int& max, int& min) {
 
  for(int i = 0; i <= 5; i++) {
    if (sensorWaardes[i] > max && sensorWaardes[i] <= 2000) {
      max = sensorWaardes[i];
    }
    if (sensorWaardes[i] < min && sensorWaardes[i] >= 0) {
      min = sensorWaardes[i];
    }
  }
  Serial.print("Hoogste waarde is: ");
  Serial.println(max);
  Serial.print("Kleinste waarde is: ");
  Serial.println(min);
}