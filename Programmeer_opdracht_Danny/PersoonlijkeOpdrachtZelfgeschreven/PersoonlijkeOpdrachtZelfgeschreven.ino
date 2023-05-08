#include <Zumo32U4.h>
#include <Wire.h>

Zumo32U4LineSensors lineSensors;

int sensorWaardes[5];

void setup() {
  Serial.begin(9600);
  lineSensors.initFiveSensors();
}

void loop() {
  lineSensors.read(sensorWaardes);

for (int i = 0; i< 5; i++) {
  Serial.print(sensorWaardes[i]);
  Serial.print(" ");
}
Serial.println("");
delay(250);
}