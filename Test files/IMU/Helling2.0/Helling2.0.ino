#include <Wire.h>
#include <L3G.h>

L3G gyro;

int y_axis = gyro.g.x;
int degreesPerSecond = map(y_axis, -32768, 32768, -180, 180);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }
  gyro.enableDefault();
}

void loop() {
  gyro.read();
  Serial.print(degreesPerSecond);
  delay(100);
}
