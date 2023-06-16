#include "ArduinoDing1.h"

ArduinoDing motors;
ArduinoDing buttonA;
ArduinoDing buttonB;
ArduinoDing buttonC;
ArduinoDing encoders;
ArduinoDing buzzer;
void setup(){}

void loop(){

delay(1000); //Zodat je je klauwen weg kan krijgen

  motors.Voorwaarts();
  motors.LangzaamVoorwaarts();
  motors.StoP();
  motors.AchterWaarts();
  motors.LangzaamAchterwaarts();
  motors.StoP();
  motors.AchterWaartsLinks();
  motors.StoP();
  motors.AchterWaartsRecht();
  motors.StoP();
  motors.RechtsVoorwaarts();
  motors.StoP();
  motors.LinksVoorwaarts();
  motors.StoP();
  motors.DraaiRondjes();
  motors.StoP();

}
