#include <Wire.h>
#include <Zumo32U4.h>
//oproepen van de juiste library
Zumo32U4Motors motors;
Zumo32U4Buzzer buzzer; // wil ik misschien nog extra toevoegen om bij input een geluidje aftespelen

char input; // deze variable word gebruikt om de ingedrukte waarde van de toetsenbord aantegeven als de variable "input"

void setup()
{
  Serial.begin(9600); // de baudrate voor USB verbinding
  Serial1.begin(9600); // de baudrate voor de Bluetooth verbinding
}

int snelheidLinks = 0; // beide motoren worden hier op een standaard waarde gezet van 0, dit word veranderd op basis van de toets die de bestuurder indrukt
int snelheidRechts = 0; // beide motoren worden hier op een standaard waarde gezet van 0, dit word veranderd op basis van de toets die de bestuurder indrukt



void basicControls() // Deze klasse kijkt naar welke toets erin gedrukt word door de besturder zodra deze ingetoets is zal de klasse dmv: de If statements de juiste klasse pakken om de juiste code uittevoeren.
{
  
  if (Serial1.available())
  { 
    input=Serial1.read(); //dit stukje code leest de waarde van de char input uit de Bluetooth verbinding 
  
  if (input == 'w') //forward = w
  {
    void moveForward() // roept klasse moveForward op
  }
    
  if (input == 'a') // corner to the left = a
  {
      void cornerLeft() // roept klasse cornerLeft op
  }
  
  if (input == 'd') // corner to the right = d
  {
      void cornerRight() // roept klasse cornerRight op
  }    
  
  if (input == 's') //backwards = s
  {
      void moveBackwards() // roept klasse moveBackwards op
  }    

  if (input == 'q') // stop = q
  {
      void stopMoving() // roept klasse stopMoving op
  }   
   
    if (snelheidLinks > 400) snelheidLinks = 400; // engine safety (forward)
    if (snelheidLinks < -400) snelheidLinks = -400; // engine safety (backwards)
    if (snelheidRechts > 400) snelheidRechts = 400; // engine safety (forward)
    if (snelheidRechts < -400) snelheidRechts = -400; // engine safety (backwards)
    motors.setLeftSpeed(snelheidLinks); // defineerd de motor variable
    motors.setRightSpeed(snelheidRechts); // defineerd de motor variable
 }
}
  void moveForward() //settings to move forward
  {
    snelheidLinks = 400; // geeft de motor een waarde
    snelheidRechts = 400; // geeft de motor een waarde
    Serial1.println("Vooruit!"); // Extra om aan de besturder aan te geven wat de ingedrukte actie is
  }
  void cornerLeft() //settings for corner to the left
  {
      snelheidLinks = -180; // geeft de motor een waarde
      snelheidRechts = 140; // geeft de motor een waarde
      Serial1.println("bocht naar links!"); // Extra om aan de besturder aan te geven wat de ingedrukte actie is
  }
  void cornerRight() //settings for corner to the right
  {
      snelheidLinks = 140; // geeft de motor een waarde
      snelheidRechts = -180; // geeft de motor een waarde
      Serial1.println("bocht naar rechts!"); // Extra om aan de besturder aan te geven wat de ingedrukte actie is
  }
 void moveBackwards() // settings for backwards
 {
      snelheidLinks = -250; // geeft de motor een waarde
      snelheidRechts = -250; // geeft de motor een waarde
      Serial1.println("achteruit!!"); // Extra om aan de besturder aan te geven wat de ingedrukte actie is
 }
   void stopMoving() // settings for STOP
  {
      snelheidLinks = 0; // de linker motor helemaal uitzetten voor een volledige STOP
      snelheidRechts = 0; // de rechter motor helemaal uitzetten voor een volledige STOP
      Serial1.println("stop!!"); // Extra om aan de besturder aan te geven wat de ingedrukte actie is
  } 