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

  Serial.println("Calibreer zwart!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, zwart[0], zwart[1]);
  buzzer.play(">g32>>c32");

  Serial.println("Calibreer grijs!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, grijs[0], grijs[1]);
  buzzer.play(">g32>>c32");

  Serial.println("Calibreer groen!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, groen[0], groen[1]);
  buzzer.play(">g32>>c32");

  Serial.println("Calibreer rood!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, rood[0], rood[1]);
  buzzer.play(">g32>>c32");

  Serial.println("Calibreer bruin!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, bruin[0], bruin[1]);
  buzzer.play(">g32>>c32");

  Serial.println("Calibreer wit!");
  ButtonA.waitForButton();
  lineSensors.read(sensorWaardes);
  vindHoogsteLaagste(sensorWaardes, wit[0], wit[1]);
  buzzer.play(">g32>>c32");

  Serial.println("Calibratie voltooid! Druk knop 'A' om verder te gaan!");
  ButtonA.waitForButton();
}

void Line::vindHoogsteLaagste(int sensorWaardes[], int& max, int& min) {
 
  for(int i = 0; i <= 5; i++) {
    if (sensorWaardes[i] > max) {
      max = sensorWaardes[i];
    }
    if (sensorWaardes[i] < min) {
      min = sensorWaardes[i];
    }
  }
  Serial.print("Hoogste waarde is: ");
  Serial.println(max);
  Serial.print("Kleinste waarde is: ");
  Serial.println(min);
}

void Line::LineRijden() {
  delay(2000);
  buzzer.play(">g32>>c32");
  int lastError = 0;

  while (sensorWaardes[0] <= zwart[0] && sensorWaardes[0] >= zwart[1] || sensorWaardes[1] <= zwart[0] && sensorWaardes[1] >= zwart[1] || sensorWaardes[2] <= zwart[0] && sensorWaardes[2] >= zwart[1] || sensorWaardes[3] <= zwart[0] && sensorWaardes[3] >= zwart[1] || sensorWaardes[4] <= zwart[0] && sensorWaardes[4] >= zwart[1]) {
    //Als er minimaal 1 sensor zwart detecteert
    
    int16_t position = lineSensors.readLine(sensorWaardes);

    int16_t error = position - 2000;

     int16_t speedDifference = error / 4 + 6 * (error - lastError);

    lastError = error;

   int16_t leftSpeed = (int16_t)maxSpeed + speedDifference;
    int16_t rightSpeed = (int16_t)maxSpeed - speedDifference;

    leftSpeed = constrain(leftSpeed, 0, (int16_t)maxSpeed);
    rightSpeed = constrain(rightSpeed, 0, (int16_t)maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
  }

  while (sensorWaardes[0] <= wit[0] && sensorWaardes[0] >= wit[1] && sensorWaardes[1] <= wit[0] && sensorWaardes[1] >= wit[1] && sensorWaardes[2] <= wit[0] && sensorWaardes[2] >= wit[1] && sensorWaardes[3] <= wit[0] && sensorWaardes[3] >= wit[1] && sensorWaardes[4] <= wit[0] && sensorWaardes[4] >= wit[1]) {
    //Als alles wit is
    //Zoeken naar lijn
    
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
if (sensorWaardes[2] >= grijs[0] && sensorWaardes[2] <= grijs[1]) {
  
}
}