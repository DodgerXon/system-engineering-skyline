#include "Linesensording.h"

Line linesensor;
Line motors;

int waardes[5];

void setup() {
  Serial1.begin(9600);
  linesensor.setup();
}

void loop() {
  linesensor.lezen(waardes[0], waardes[1], waardes[2], waardes[3], waardes[4]);

/*for (int i = 0; i < 5; i++) {
  Serial1.print(waardes[i]);
  Serial1.print(" ");
}
Serial1.println("");*/
linesensor.LineRijden(waardes);


}