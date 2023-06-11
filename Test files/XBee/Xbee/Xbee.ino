#include <Zumo32U4.h>
#include <XBee.h>
#include "XBeeController.h"

XBeeController xbeeController;

void setup() {
  xbeeController.setup();
}

void loop() {
  xbeeController.processInput();
}
