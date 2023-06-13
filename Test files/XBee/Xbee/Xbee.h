#ifndef XBEE_CONTROLLER_H
#define XBEE_CONTROLLER_H

#include <Zumo32U4.h>
#include <XBee.h>

class XBeeController {
private:
  Zumo32U4Motors motors;
  Zumo32U4Buzzer buzzer;
  XBee xbee;
  int snelheidLinks;
  int snelheidRechts;

public:
  XBeeController();
  void setup();
  void processInput();
};

#endif
