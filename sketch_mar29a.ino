#include "MQ135.h"
void setup () {
  Serial.begin (9600);
}
void loop() {
  MQ135 gasSensor = MQ135(A0); // Attach sensor to pin A0
  float rzero = gasSensor.getRZero();
  float air_quality = gasSensor.getPPM();
  Serial.print("RZERO =");
  Serial.print(rzero);
  Serial.print(", the gas value is ppm=");
  Serial.println(air_quality);

  delay(1000);
}
// 2196
