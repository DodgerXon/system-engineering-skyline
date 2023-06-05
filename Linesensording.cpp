#include "LineSensording.h"

LineSensording::LineSensording() {

}

void LineSensording::lezen() {
  lineSensors.read(sensorWaardes);
}

void LineSensording::setup() {
  lineSensors.initFiveSensors();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes);
}

void LineSensording::vindHoogsteLaagste(int sensorWaardes[]) {



  for(int i = 0; i <= 5; i++) {
    if (sensorWaardes[i] > max && sensorWaardes[i] <= 2000) {
      max = sensorWaardes[i];
    }
    if (sensorWaardes[i] < min && sensorWaardes[i] > 0) {
      min = sensorWaardes[i];
    }
  }
  Serial.print("Hoogste waarde is: ");
  Serial.println(max);
  Serial.print("Kleinste waarde is: ");
  Serial.println(min);
}

int LineSensording::geefWaardeTerug() {
  return min;
}