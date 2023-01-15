#include <MPS20N0040D.h>

MPS20N0040D sensor;

void setup() {
  Serial.begin(9600);
  sensor.begin(A0);
}

void loop() {
  Serial.println(String(sensor.read()) + " kPa");
  delay(1000);
}
