#ifndef XBEE_H
#define XBEE_H

#include <Zumo32U4.h>
#include <XBee.h>

class XBeeBesturing {
private: //declaratie van die private waardes in de XbeeBesturing klasse 
  Zumo32U4Motors motors;
  Zumo32U4Buzzer buzzer;
  XBee xbee;
  int snelheidLinks;
  int snelheidRechts;
  char input;

public:  //declaratie van die public waardes in de XbeeBesturing klasse 
  XBeeBesturing();
  void setup();
  void XbeeInput();
};

#endif
