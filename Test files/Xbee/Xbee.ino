/*
De main Xbee code
*/
#include <Zumo32U4.h> // de zumo library word ge-include
#include "XBee.h" // de header file word ge-include

XBeeBesturing xbeeControls;

void setup() {
  xbeeControls.setup();
}

void loop() {
  xbeeControls.XbeeInput();
}