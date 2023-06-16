#ifndef ARDUINODING1_H
#define ARDUINODING1_H

#include <Wire.h>
#include <Zumo32U4.h>

class ArduinoDing {

  public:
    
    void Voorwaarts();
    void LangzaamVoorwaarts();
    void StoP();
    void AchterWaarts();
    void LangzaamAchterwaarts();
    void AchterWaartsRecht();
    void AchterWaartsLinks();
    void LinksVoorwaarts();
    void RechtsVoorwaarts();
    void DraaiRondjes();

  private:
    
    Zumo32U4Motors motors;
    Zumo32U4ButtonA buttonA;
    Zumo32U4ButtonB buttonB;
    Zumo32U4ButtonC buttonC;
    Zumo32U4Encoders encoders;
    Zumo32U4Buzzer buzzer;
    bool DrukOpKnopA;
    bool DrukOpKnopB;
    const uint16_t SnelHeid = 300;           //De max snelheid
    const uint16_t NsnelHeid = -300;         //De Max negatieve snelheid
    const uint16_t STOP = 0;                 //De ZUMO stopt
    const uint16_t DraaiSnelHeid = 175;      //De snelheid waarbij de ZUMO draait
    const uint16_t SlowReverse = -150;       //De Halve snelheid achterwaarts
  

};

#endif