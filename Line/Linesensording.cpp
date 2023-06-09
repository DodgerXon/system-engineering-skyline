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

  //lineSensors.read(sensorWaardes);

    //Als er minimaal 1 sensor zwart detecteert
    
    int16_t position = lineSensors.readLine(sensorWaardes);

    int16_t error = position - 2000;

    int16_t speedDifference = error / 1 + 1 * (error - lastError);

    lastError = error;

    int m1Speed = maxSpeed + speedDifference;
    int m2Speed = maxSpeed - speedDifference;

    if (m1Speed < 0) {
      m1Speed = m1Speed - 10;
    }

    if (m2Speed < 0) {
      m2Speed = m2Speed - 10;
    } 

    if (m1Speed > maxSpeed) {
      m1Speed = maxSpeed;
    }

    if (m2Speed > maxSpeed) {
      m2Speed = maxSpeed;
    }

    
    motors.setSpeeds(m1Speed, m2Speed); 
    Serial1.println(m1Speed);
    Serial1.println(m2Speed);
    Serial1.println("");
         
}