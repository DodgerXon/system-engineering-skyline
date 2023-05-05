#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4Buzzer buzzer;

char input;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

int snelheidLinks = 0;
int snelheidRechts = 0;



void loop()
{
  
  if (Serial1.available())
  { 
    input=Serial1.read();
  
  
    if (input == 'w')
    {
      snelheidLinks = 400; 
      snelheidRechts = 400; //vooruit
      Serial1.println("Vooruit!");
    }
    if (input == 'a'){
      snelheidLinks = -180;
      snelheidRechts = 140; // bocht naar links
      Serial1.println("bocht naar links!");
    }
    if (input == 'd'){
      snelheidLinks = 140;
      snelheidRechts = -180; // bocht naar rechts
      Serial1.println("bocht naar rechts!");
    }
    if (input == 's') //achteruit
    {
      snelheidLinks = -250; 
      snelheidRechts = -250;
      Serial1.println("achteruit!!");
    }
    if (input == 'q'){
      snelheidLinks = 0;
      snelheidRechts = 0;
      Serial1.println("stop!!");
      ledRed(1);
      delay(100);
      ledRed(0);
    } //stop

    if (snelheidLinks > 400) snelheidLinks = 400;
    if (snelheidLinks < -400) snelheidLinks = -400;
    if (snelheidRechts > 400) snelheidRechts = 400;
    if (snelheidRechts < -400) snelheidRechts = -400;
    motors.setLeftSpeed(snelheidLinks);
    motors.setRightSpeed(snelheidRechts);
    Serial.println("a");
  }
}

