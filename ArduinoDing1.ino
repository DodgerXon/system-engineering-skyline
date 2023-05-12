#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4ButtonB buttonB;
Zumo32U4ButtonC buttonC;
Zumo32U4Encoders encoders;
Zumo32U4Buzzer buzzer;


  //Bepaald de snelheid 
  const uint16_t SnelHeid = 300;           //De max snelheid
  const uint16_t NsnelHeid = -300;         //De Max negatieve snelheid
  const uint16_t STOP = 0;                 //De ZUMO stopt
  const uint16_t DraaiSnelHeid = 175;      //De snelheid waarbij de ZUMO draait
  const uint16_t SlowReverse = -150;       //De Halve snelheid achterwaarts
  
  // Rijd naar voren
  void Voorwaarts(){
  motors.setSpeeds(SnelHeid, SnelHeid);
  delay(2000);    //Duratie van 2 seconden
  }
   
  //Vertraagd voorwaarts
  void LangzaamVoorwaarts(){
  motors.setSpeeds(SnelHeid / 2, SnelHeid /2);
  delay(2000);   //Duratie van 2 seconden
  }

  //stopt
  void StoP(){
  motors.setSpeeds(STOP, STOP);
  delay(2000);   //Duratie van 2 seconden
  }

  //Reversed
  void AchterWaarts(){
  motors.setSpeeds(NsnelHeid, NsnelHeid);
  delay(2000);   //Duratie van 2 seconden
  }

  //Vertraagd Reverse
  void LangzaamAchterwaarts(){
  motors.setSpeeds(SlowReverse, SlowReverse);
  delay(3000);   //Duratie van 3 seconden
  }

  //Draait achteruit naar rechts
  void AchterWaartsRecht(){
  motors.setSpeeds(NsnelHeid, DraaiSnelHeid);
  delay(1000);    //Duratie van 1 seconden
  }

  //Draait achteruit naar Links
  void AchterWaartsLinks(){
  motors.setSpeeds(DraaiSnelHeid, NsnelHeid);
  delay(500);    //Duratie van 0,5 seconden
  }

  //Draait naar voorwaarts naar links
  void LinksVoorwaarts(){
  motors.setSpeeds(SlowReverse, SnelHeid);
  delay(500);    //Duratie van 0,5 seconden
  }

  //Draait naar voorwaarts naar rechts
  void RechtsVoorwaarts(){
  motors.setSpeeds(SnelHeid, SlowReverse);
  delay(500);    //Duratie van 0,5 seconden
  }

  //Spinned
  void DraaiRondjes(){
  motors.setSpeeds(NsnelHeid, SnelHeid);
  delay(2000);   //Duratie van 2 seconden
  }

void setup()
{
  buttonC.waitForButton();
}
void loop()
{
  bool DrukOpKnopA = buttonA.getSingleDebouncedPress();   //Als de A knop word ingedrukt word DrukOpKnopA treu
  bool DrukOpKnopB = buttonB.getSingleDebouncedPress();   //Als de B knop word ingedrukt word DrukOpKnopB treu

  if (DrukOpKnopA){

  delay(1000); //Zodat je je klauwen weg kan krijgen

  Voorwaarts();
  LangzaamVoorwaarts();
  StoP();
  AchterWaarts();
  LangzaamAchterwaarts();
  StoP();
  AchterWaartsLinks();
  StoP();
  AchterWaartsRecht();
  StoP();
  RechtsVoorwaarts();
  StoP();
  LinksVoorwaarts();
  StoP();
  DraaiRondjes();
  StoP();


  delay(500);
  }
 
  else if (DrukOpKnopB){
    delay(1000);
    Voorwaarts();
    StoP();
  }
}
