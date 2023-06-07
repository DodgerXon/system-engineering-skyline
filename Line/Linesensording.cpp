#include "Arduino.h"
#include "HardwareSerial.h"
#include "LineSensording.h"

Line::Line() {

}

/*int Line::geefWaardes(int& pos0, int&pos1, int& pos2, int& pos3, int& pos4) {
    for(int i=0; i <= 5; i++) {
      Serial.print("Test");
      Serial.println(sensorWaardes[i]);
    }
    pos0 = sensorWaardes[0];
    pos1 = sensorWaardes[1];
    pos2 = sensorWaardes[2];
    pos3 = sensorWaardes[3];
    pos4 = sensorWaardes[4];
    return 0;
}*/

void Line::lezen(int& pos0, int& pos1, int& pos2, int& pos3, int& pos4) {
  lineSensors.read(sensorWaardes);

    pos0 = sensorWaardes[0];
    pos1 = sensorWaardes[1];
    pos2 = sensorWaardes[2];
    pos3 = sensorWaardes[3];
    pos4 = sensorWaardes[4];
}

void Line::setup() {
  lineSensors.initFiveSensors();

  Serial1.println("Calibreer zwart!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, zwart[0], zwart[1]);
  buzzer.play(">g32>>c32");

  Serial1.println("Calibreer grijs!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, grijs[0], grijs[1]);
  buzzer.play(">g32>>c32");

  Serial1.println("Calibreer groen!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, groen[0], groen[1]);
  buzzer.play(">g32>>c32");

  Serial1.println("Calibreer rood!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, rood[0], rood[1]);
  buzzer.play(">g32>>c32");

  Serial1.println("Calibreer bruin!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, bruin[0], bruin[1]);
  buzzer.play(">g32>>c32");

  Serial1.println("Calibreer wit!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, wit[0], wit[1]);
  buzzer.play(">g32>>c32");

  Serial1.println("Calibratie voltooid! Druk knop 'A' om verder te gaan!");
  ButtonA.waitForButton();
}

void Line::vindHoogsteLaagste(int sensorWaardes[], int& max, int& min) {
  max = 0;
  min = 2000;

  for(int i = 0; i < 5; i++) {
    if (sensorWaardes[i] > max) {
      max = sensorWaardes[i];
    }
    if (sensorWaardes[i] < min) {
      min = sensorWaardes[i];
    }
  }
  Serial1.print("Hoogste waarde is: ");
  Serial1.println(max);
  Serial1.print("Kleinste waarde is: ");
  Serial1.println(min);
}

int Line::LineRijden(int Waardes1[]) {
  
  int lastError = 0;

  lineSensors.read(sensorWaardes);

  if (Waardes1[0] <= zwart[0] && Waardes1[0] >= zwart[1] || Waardes1[1] <= zwart[0] && Waardes1[1] >= zwart[1] || Waardes1[2] <= zwart[0] && Waardes1[2] >= zwart[1] || Waardes1[3] <= zwart[0] && Waardes1[3] >= zwart[1] || Waardes1[4] <= zwart[0] && Waardes1[4] >= zwart[1]) {
    //Als er minimaal 1 sensor zwart detecteert
    
    int16_t position = lineSensors.readLine(sensorWaardes);

    int16_t error = position - 2000;

     int16_t speedDifference = error / 4 + 6 * (error - lastError);

    lastError = error;

   int16_t leftSpeed = maxSpeed + speedDifference;
    int16_t rightSpeed = maxSpeed - speedDifference;

    leftSpeed = constrain(leftSpeed, 0, maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
    Serial1.println("Rechtdoor!");
    Serial1.println(leftSpeed);
    Serial1.println(rightSpeed);
    if (blijfrechts == 1){
      if (Waardes1[0] <= zwart[0] && Waardes1[0] >= zwart[1] && Waardes1[1] <= zwart[0] && Waardes1[1] >= zwart[1] && Waardes1[2] <= zwart[0] && Waardes1[2] >= zwart[1] && Waardes1[3] <= zwart[0] && Waardes1[3] >= zwart[1] && Waardes1[4] <= zwart[0] && Waardes1[4] >= zwart[1]) {
      motors.setSpeeds(0, 325);
      delay(850);
      blijfrechts = 0;
      }
    }
  }

  if (sensorWaardes[0] <= wit[0] && sensorWaardes[0] >= wit[1] && sensorWaardes[1] <= wit[0] && sensorWaardes[1] >= wit[1] && sensorWaardes[2] <= wit[0] && sensorWaardes[2] >= wit[1] && sensorWaardes[3] <= wit[0] && sensorWaardes[3] >= wit[1] && sensorWaardes[4] <= wit[0] && sensorWaardes[4] >= wit[1]) {
    //Als alles wit is
    //Zoeken naar lijn
    motors.setSpeeds(100, 100);
  }
  
if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= wit[0] && sensorWaardes[3] <= wit[1] && sensorWaardes[4] >= wit[0] && sensorWaardes[4] <= wit[1] && sensorWaardes[1] >= wit[0] && sensorWaardes[1] <= wit[1] && sensorWaardes[0] >= wit[0] && sensorWaardes[0] <= wit[1]) {
  
  //zwarte lijn in het midden waargenomen
  //bijv maxspeed aanzetten
}

if (sensorWaardes[2] >= wit[0] && sensorWaardes[2] <= wit[1] && sensorWaardes[3] >= wit[0] && sensorWaardes[3] <= wit[1] && sensorWaardes[4] >= wit[0] && sensorWaardes[4] <= wit[1] && sensorWaardes[1] >= zwart[0] && sensorWaardes[1] <= zwart[1] && sensorWaardes[0] >= wit[0] && sensorWaardes[0] <= wit[1]) {
  
  //sturen naar links
}

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= grijs[0] && sensorWaardes[3] <= grijs[1] && sensorWaardes[4] >= grijs[0] && sensorWaardes[4] <= grijs[1]) {
  
  // volgende kruispunt rechts
} 

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[1] >= grijs[0] && sensorWaardes[1] <= grijs[1] && sensorWaardes[0] >= grijs[0] && sensorWaardes[0] <= grijs[1]) {
  
  // volgende kruispunt links
} 

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= grijs[0] && sensorWaardes[3] <= grijs[1] && sensorWaardes[4] >= grijs[0] && sensorWaardes[4] <= grijs[1] && sensorWaardes[1] >= grijs[0] && sensorWaardes[1] <= grijs[1] && sensorWaardes[0] >= grijs[0] && sensorWaardes[0] <= grijs[1]) {
  
  //Stilstaan voor WipWap en wachten op IMU = 0 (of whatever de waarde ervoor is)
} 

if (sensorWaardes[2] >= zwart[0] && sensorWaardes[2] <= zwart[1] && sensorWaardes[3] >= bruin[0] && sensorWaardes[3] <= bruin[1] && sensorWaardes[4] >= bruin[0] && sensorWaardes[4] <= bruin[1] && sensorWaardes[1] >= bruin[0] && sensorWaardes[1] <= bruin[1] && sensorWaardes[0] >= bruin[0] && sensorWaardes[0] <= bruin[1]) {

  //20 cm vooruitrijden
  //fase 2
}

if (sensorWaardes[2] >= bruin[0] && sensorWaardes[2] <= bruin[1]) {
  
}
if (sensorWaardes[2] >= rood[0] && sensorWaardes[2] <= rood[1]) {
  //niet volgen
}

if (sensorWaardes[2] >= groen[0] && sensorWaardes[2] <= groen[1]) {
  //snelheid = 50%
} 
if (Waardes1[0] <= groen[0] && Waardes1[0] >= groen[1] || Waardes1[1] <= groen[0] && Waardes1[1] >= groen[1] || Waardes1[2] <= groen[0] && Waardes1[2] >= groen[1] || Waardes1[3] <= groen[0] && Waardes1[3] >= groen[1] || Waardes1[4] <= groen[0] && Waardes1[4] >= groen[1]) {
  
  int16_t position = lineSensors.readLine(sensorWaardes);

    int16_t error = position - 2200;

     int16_t speedDifference = error / 4 + 6 * (error - lastError);

    lastError = error;

   int16_t leftSpeed = groeneSnelheid + speedDifference;
    int16_t rightSpeed = groeneSnelheid - speedDifference;

    leftSpeed = constrain(leftSpeed, 0, groeneSnelheid);
    rightSpeed = constrain(rightSpeed, 0, groeneSnelheid);

    motors.setSpeeds(leftSpeed,rightSpeed);
    Serial1.println("Rechtdoor!");
    Serial1.println(leftSpeed);
    Serial1.println(rightSpeed);
  
}
if (sensorWaardes[4] <= grijs[0] && sensorWaardes[4] >= grijs[1])  {
  // bocht naar rechts
  blijfrechts = 1;

}
//motors.setSpeeds(0, 0);
return 0;
}