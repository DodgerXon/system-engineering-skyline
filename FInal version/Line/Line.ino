#include "Linesensording.h"
#include "Proximity.h"
#include "IMU.h"

Line linesensor; //construeren objecten
Line motors;

Proximity prox;

IMU imusensor;

int speedL = 200;
int speedR = -200;
char input = Serial1.read(); //voor xbee, dat hij dingen in kan lezen

int waardes[5]; //Dit geldt voor alles hieronder, Arraylengte, en om de waardes in de main te krijgen en te gebruiken in methodes.
int zwart[2];
int groen[2];
int bruin[2];
int wit[2];
int grijs[2];
int switchm = 0; //voor switch

void setup() {
  linesensor.setup(groen[0], groen[1], zwart[0], zwart[1], bruin[0], bruin[1], wit[0], wit[1], grijs[0], grijs[1]); // calibreert de verschillende kleuren, en returned de waarden die hierin, die boven worden opgeslagen.
}

void loop() {
  input = Serial1.read(); //voor fase 2, zo blijft hij het inlezen
  linesensor.lezen(waardes[0], waardes[1], waardes[2], waardes[3], waardes[4]); //Deze methode zorgt ervoor dat de sensorwaardes in de main komt.
 
  for (int i = 0; i < 5; i++) { //for loop om te kijken welke switch case actief moet zijn, het eronder vergelijkt waardes, om zo de case te bepalen.
    if (waardes[i] <= zwart[1] && waardes[i] >= wit[0])  {
      switchm = 3;
    }
    else if(waardes[i] <= groen[0] && waardes[i] >= wit[1])   {
      switchm = 1;
    } 
    else if (waardes[i] <= bruin[0] && waardes[i] >= bruin[1])  {
      switchm = 2;
    } 
    else if (input == 'p') {
        prox.setup();
        switchm = 4;
    }
    else if (waardes[i] <= grijs[0] && waardes[i] >=  grijs[1]){
      imusensor.klaarmaken();
      switchm = 5;


    }
  }

  switch(switchm) { //switch voor verschillende cases, om de andere uit te sluiten en maar 1 ding uit te voeren.
    case 1: //Groenelijn
      linesensor.LineRijdenGroen();
      break;
    case 2: //bruinelijn
      linesensor.LineRijdenBruin();
      break;
    case 3: //zwartelijn
      linesensor.LineRijdenzwart();
      break;
    case 4: //fase 2 (proximity gebruiken)
      prox.printReadingsToSerial();
      prox.uitvoeren();
    break;
    case 5://imu gebruiken
      imusensor.lezen();
      imusensor.printen();
      imusensor.balans();
    break;
  }
  Serial1.println(switchm); //printen van de switch voor debugging purposes
}