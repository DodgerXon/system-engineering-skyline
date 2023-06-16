#include "ArduinoDing1.h"

  // Rijd naar voren
  void ArduinoDing::Voorwaarts(){
  motors.setSpeeds(SnelHeid, SnelHeid);
  delay(2000);    //Duratie van 2 seconden
  }
   
  //Vertraagd voorwaarts
  void ArduinoDing::LangzaamVoorwaarts(){
  motors.setSpeeds(SnelHeid / 2, SnelHeid /2);
  delay(2000);   //Duratie van 2 seconden
  }

  //stopt
  void ArduinoDing::StoP(){
  motors.setSpeeds(STOP, STOP);
  delay(2000);   //Duratie van 2 seconden
  }

  //Reversed
  void ArduinoDing::AchterWaarts(){
  motors.setSpeeds(NsnelHeid, NsnelHeid);
  delay(2000);   //Duratie van 2 seconden
  }

  //Vertraagd Reverse
  void ArduinoDing::LangzaamAchterwaarts(){
  motors.setSpeeds(SlowReverse, SlowReverse);
  delay(3000);   //Duratie van 3 seconden
  }

  //Draait achteruit naar rechts
  void ArduinoDing::AchterWaartsRecht(){
  motors.setSpeeds(NsnelHeid, DraaiSnelHeid);
  delay(1000);    //Duratie van 1 seconden
  }

  //Draait achteruit naar Links
  void ArduinoDing::AchterWaartsLinks(){
  motors.setSpeeds(DraaiSnelHeid, NsnelHeid);
  delay(500);    //Duratie van 0,5 seconden
  }

  //Draait naar voorwaarts naar links
  void ArduinoDing::LinksVoorwaarts(){
  motors.setSpeeds(SlowReverse, SnelHeid);
  delay(500);    //Duratie van 0,5 seconden
  }

  //Draait naar voorwaarts naar rechts
  void ArduinoDing::RechtsVoorwaarts(){
  motors.setSpeeds(SnelHeid, SlowReverse);
  delay(500);    //Duratie van 0,5 seconden
  }

  //Spinned
  void ArduinoDing::DraaiRondjes(){
  motors.setSpeeds(NsnelHeid, SnelHeid);
  delay(2000);   //Duratie van 2 seconden
  }
