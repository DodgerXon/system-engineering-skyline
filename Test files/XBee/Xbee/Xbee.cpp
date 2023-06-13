#include "XBeeController.h"

XBeeController::XBeeController() {
  snelheidLinks = 0;
  snelheidRechts = 0;
}

void XBeeController::setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
}

void XBeeController::processInput() {
  
  if (Serial1.available()) {
    input=Serial1.read();
   
    if (input == 'w') {
    snelheidLinks = 400;
    snelheidRechts = 400;
    Serial1.println("Vooruit!");
    }

    else if (input == 'a') {
    snelheidLinks = -180;
    snelheidRechts = 140;
    Serial1.println("bocht naar links!");
    }

    else if (input == 'd') {
    snelheidLinks = 140;
    snelheidRechts = -180;
    Serial1.println("bocht naar rechts!");
    }

    else if (input == 's') {
    snelheidLinks = -250;
    snelheidRechts = -250;
    Serial1.println("achteruit!!");
    }

    else if (input == 'q') {
    snelheidLinks = 0;
    snelheidRechts = 0;
    Serial1.println("stop!!");
    delay(100);
    }

    if (snelheidLinks > 400) snelheidLinks = 400;
    if (snelheidLinks < -400) snelheidLinks = -400;
    if (snelheidRechts > 400) snelheidRechts = 400;
    if (snelheidRechts < -400) snelheidRechts = -400;
    motors.setLeftSpeed(snelheidLinks);
    motors.setRightSpeed(snelheidRechts);
      
    }
    }
  }
}

