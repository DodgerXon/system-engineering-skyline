#include "Linesensording.h"

Line linesensor;

void setup() {
  Serial.begin(9600);
  linesensor.setup();
}

void loop() {
  linesensor.read(geefWaardes(sensorWaardes));

for (int i = 0; i < 5; i++) {
  Serial.print(sensorWaardes[i]);
  Serial.print(" ");
}
Serial.println("");
delay(250);


}