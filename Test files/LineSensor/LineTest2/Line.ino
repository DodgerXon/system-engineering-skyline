#include "Linesensording.h"

LineSensording linesensor;

void setup() {
  Serial.begin(9600);
  linesensor.setup();
}

void loop() {
  linesensor.lezen();
  for (int i = 0; i < 5; i++) {
    int waardes[linesensor.geefWaardeTerug()];
    Serial.print(waardes[i]);
    Serial.print(" ");
  }
  Serial.println("");
  delay(250);
}