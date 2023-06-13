#include "Linesensording.h"

Line linesensor;
Line motors;

int waardes[5];
int zwart[2];
int groen[2];
int bruin[2];
int switchm;

void setup() {
  Serial1.begin(9600);
  linesensor.setup(groen[0], groen[1], zwart[0], zwart[1], bruin[0], bruin[1]);
}

void loop() {
  linesensor.lezen(waardes[0], waardes[1], waardes[2], waardes[3], waardes[4]);
  for (int i = 0; i < 5; i++) {
    if (waardes[i] <= bruin[0] && waardes[i] >= bruin[1]) {
      switchm = 3;
      break;
    } else if (waardes[i] <= groen[0] && waardes[i] >= groen[1]){
      switchm = 2;
      break;
    } else {
      switchm = 1;
      break;
    }
  }

  if (switchm == 1) { 
  linesensor.LineRijdenzwart(waardes);
  }
  if (switchm == 2) {
    linesensor.LineRijdenGroen();
  }
  if (switchm == 3) {
    linesensor.LineRijdenBruin();
  }
  

/*for (int i = 0; i < 5; i++) {
  Serial1.print(waardes[i]);
  Serial1.print(" ");
}
Serial1.println("");*/



}