#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4IMU imu;
char report[120];
// hier include je de library en maak je een object


void setup() {
Wire.begin();
//Anders werkt de IMU niet
  
  if (!imu.init())
  {
    // Failed to detect the compass.
    ledRed(1);
    while(1)
    {
      Serial.println(F("Failed to initialize IMU sensors."));
      delay(100);
    }
  }
  //Dit is geeft aan wanneer de imu kapot is of dat de pin nummers niet goed zijn.
  

  imu.configureForBalancing();

  // Dit doet letterlijk wat het zegt lol




}

void loop() {
  imu.read();
  // Leest de IMU waarde uit
  Serial.println(imu.a.x);
  // print de waarde uit van de accelerometer
  delay(500);

}
