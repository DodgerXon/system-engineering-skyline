#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4Buzzer buzzer; // in progress!!

char input;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

int snelheidLinks = 0;
int snelheidRechts = 0;



void basicControls()
{
  
  if (Serial1.available())
  { 
    input=Serial1.read();
  
  if (input == 'w') //forward = w
  {
    void moveForward()
  }
    
  if (input == 'a') // corner to the left = a
  {
      void cornerLeft()
  }
  
  if (input == 'd') // corner to the right = d
  {
      void cornerRight()
  }    
  
 
  if (input == 's') //backwards = s
  {
      void moveBackwards()
  }    

 
  if (input == 'q') // stop = q
  {
      void stopMoving()
  }   
   
    if (snelheidLinks > 400) snelheidLinks = 400; // engine safety (forward)
    if (snelheidLinks < -400) snelheidLinks = -400; // engine safety (backwards)
    if (snelheidRechts > 400) snelheidRechts = 400; // engine safety (forward)
    if (snelheidRechts < -400) snelheidRechts = -400; // engine safety (backwards)
    motors.setLeftSpeed(snelheidLinks);
    motors.setRightSpeed(snelheidRechts);
 }
}
  void moveForward() //settings to move forward
  {
    snelheidLinks = 400;
    snelheidRechts = 400; 
    Serial1.println("Vooruit!");
  }
  void cornerLeft() //settings for corner to the left
  {
      snelheidLinks = -180;
      snelheidRechts = 140; // bocht naar links
      Serial1.println("bocht naar links!");
  }
  void cornerRight() //settings for corner to the right
  {
      snelheidLinks = 140;
      snelheidRechts = -180; // bocht naar rechts
      Serial1.println("bocht naar rechts!");
  }
 void moveBackwards() // settings for backwards
 {
      snelheidLinks = -250; 
      snelheidRechts = -250;
      Serial1.println("achteruit!!");
 }
   void stopMoving() // settings for STOP
  {
      snelheidLinks = 0;
      snelheidRechts = 0;
      Serial1.println("stop!!");
  } 