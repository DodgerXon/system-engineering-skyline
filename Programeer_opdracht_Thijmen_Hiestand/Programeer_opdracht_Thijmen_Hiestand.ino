#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
// hier declareer ik de voorwaartse snelheid van de ZUMO
const uint8_t Speed = 400;                              

// hier declareer ik de tragere voorwaartse snelheid van de ZUMO
const uint8_t HalveSpeed = 250;

// hier declareer ik de achterwaartse snelheid van de ZUMO
const uint8_t SpeedBackwards = -400;

// hier declareer ik de tragere achterwaartse snelheid van de ZUMO
const uint8_t HalveSpeedBackwards = -250;

// hier heb ik een snelheid aangemaakt die ik gebruik voor het draaien van de ZUMO, 
// is de zelfde snelheid als voorwaarts alleen is dit voor overzichtelijkheid
const uint8_t LeftmotorTurn = 300;

// dit is eht zelfde als bij LeftmotorTurn dus puur voor de overzichtelijkheid van de code
const uint8_t RightmotorTurn = -300;

// hier declareer ik de snelheid nul die ik gebruik om de zumo stil te laten staan
const uint8_t Stop = 0;                                                                                        


// deze functie laat de ZUMO voorwaarts rijden, de Speed komt van de eerder gedeclareerde snelheid.
void rechteLijnVoorwaarts()
{  
  motors.setSpeeds(Speed, Speed);
  delay(1000);
}

// met deze methode wil ik eerst de ZUMO laten vertragen naar een lagere snelheid dit zorgt voor een vloeierende overgang
void halveSpeedVoorwaarts()
{
  motors.setSpeeds(HalveSpeed, HalveSpeed);
  delay(1000);
}

// hier laat ik de ZUMO achterwaarts in een rechtelijn rijden
void rechteLijnAchterwaarts()
{
  motors.setSpeeds(SpeedBackwards, SpeedBackwards);
  delay(1000);
}

// zelfde als bij de vorige functie, dus voor een mooiere overgang in functies.
void halveSpeedAchterwaarts()
{
  motors.setSpeeds(HalveSpeedBackwards, HalveSpeedBackwards);
  delay(1000);
}

// hier geef ik bijde motoren een andere snelehid zodat de ZUMO draait op zijn plaats.
void Draai()
{
  motors.setSpeeds(LeftmotorTurn, RightmotorTurn);
  delay(400);
}

// zoals al eerder gedeclareerd geef ik hier de ZUMO de snelheid nul.
// hiermee staat de zumo dus stil voor een aangegeven tijd.
void STOP()
{ 
  motors.setSpeeds(Stop, Stop);
  delay(500);
}

// setup geeft de start van de code aan, dus wat eerst gedaan moet worden voordat
// de code daadwerkelijk wordt uitgevoerd door de ZUMO
void setup()
{
  buttonA.waitForButton();
  delay(1000);
}

// in de loop worden alle voorgaande gemaakte functie achter één volgens uitgevoerd.
// hier maakt de ZUMO dus het vierkantje die ik wilde programmeren.
void loop()
{
  rechteLijnVoorwaarts();
  halveSpeedVoorwaarts();
  STOP();
  Draai();
  STOP();
  rechteLijnAchterwaarts();
  halveSpeedAchterwaarts();
  STOP();
  Draai();
  STOP();
}

