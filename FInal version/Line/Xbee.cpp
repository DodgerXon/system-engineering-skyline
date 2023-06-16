#include "Xbee.h" // de header file word ge-include

XBeeBesturing::XBeeBesturing() {   //constructeur XbeeBesturing bouwd de klasse XbeeBesturing
  motors.setLeftSpeed(snelheidLinks);
  motors.setRightSpeed(snelheidRechts);
}

void XBeeBesturing::setup() {
  Serial1.begin(9600); // de serial1 zorgt ervoor dat de communicatie via de Xbee gaat.
  Serial.begin(9600); // mocht ik ooit iets willen testen in de toekomst via de serial monitor laat ik de normale serial erin
}

void XBeeBesturing::XbeeInput() { // Deze methode vertaald de input vanaf de XCTU naar een instructie die de ZUMO moet voltooien
  if (Serial1.available()) {      // de input waarde is dus de waarde die de gebruiker in toets
    input=Serial1.read();
   
    if (input == 'w') {   // als input gelijk is aan w dan volle snelheid vooruit
    snelheidLinks = 400;  // hier zet ik de linker rupsband op waarde 400 (MAX waarde)
    snelheidRechts = 400; // hier zet ik de rechter rupsband op waarde 400 (MAX waarde)
    Serial1.println("Vooruit!"); //hier heb ik een beschrijving van de actie die de gebruiker kan zien in XCTU
    }

    else if (input == 'a') { // a is een bocht naar links
    snelheidLinks = -180; //door deze waardes draait de ZUMO netjes om zijn eigen as
    snelheidRechts = 140;
    Serial1.println("bocht naar links!"); //hier heb ik een beschrijving van de actie die de gebruiker kan zien in XCTU
    }

    else if (input == 'd') { // d is een bocht naar rechts
    snelheidLinks = 140; //door deze waardes draait de ZUMO netjes om zijn eigen as
    snelheidRechts = -180;
    Serial1.println("bocht naar rechts!"); //hier heb ik een beschrijving van de actie die de gebruiker kan zien in XCTU
    }

    else if (input == 's') { // s is om achteruit te rijden
    snelheidLinks = -250; //beide motoren heb ik ingesteld op -250 om rustig naar achter te rijden
    snelheidRechts = -250; //beide motoren heb ik ingesteld op -250 om rustig naar achter te rijden
    Serial1.println("achteruit!!"); //hier heb ik een beschrijving van de actie die de gebruiker kan zien in XCTU
    }

    else if (input == 'q') { //q is om te stoppen
    snelheidLinks = 0; //motorwaarde word gelijk gesteld aan 0
    snelheidRechts = 0;//motorwaarde word gelijk gesteld aan 0
    Serial1.println("stop!!"); //hier heb ik een beschrijving van de actie die de gebruiker kan zien in XCTU
    //delay(100);
    }
  motors.setLeftSpeed(snelheidLinks);
  motors.setRightSpeed(snelheidRechts);
  
    
      
    }
    }