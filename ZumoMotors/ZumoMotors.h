#include <Wire.h>
#include <Zumo32U4.h>

/* speedL is voorwaartse snelheid van de linker motor
speedR is voorwaartse snelheid van de rechter motor
negSpeedL is achterwaartse snelheid van de linker motor
negSpeedR is achterwaartse snelheid van de rechter motor
*/

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

class ZumoRijden{
  public:
  void voorwaarts (int Speed);
  void achterwaarts (int SpeedBackwards);
  void bochtLinksom (int SpeedBackwards, int RightmotorTurn);
  void bochtRechtsom (int LeftmotorTurn, int SpeedBackwards);
  void Stop (int Stop, int Stop);

  private:
  int Speed = 400;                              
  int HalveSpeed = 250;
  int SpeedBackwards = -400;
  int HalveSpeedBackwards = -250;
  int LeftmotorTurn = 300;
  int RightmotorTurn = -300;
  int Stop = 0;
}