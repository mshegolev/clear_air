#include <Time.h>
#include <TimeAlarms.h>
#include "MQ135.h"

void setup () {
  Serial.begin (9600);
  setTime(1, 29, 0, 31, 3, 19); // set time to Saturday 8:29:00am Jan 1 2011

  Serial.println("rzero,ppm,date");
}

void loop() {
  MQ135 gasSensor = MQ135(A0); // Attach sensor to pin A0
  float rzero = gasSensor.getRZero();
  float ppm = gasSensor.getPPM();
  Serial.print(rzero);
  print(rzero);
  Serial.print(",");
  Serial.print(ppm);
  //Serial.print(",");
  //  digitalClockDisplay();
  Serial.print(",");
  printD();
  Serial.println();

  delay(1000);
}
// 2196 -work

void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(year());
  printDigits(month());
  printDigits(day());
  printDigits(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println();
}
void printDigits(int digits)
{
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
void printD() {
  String oss = String(year());
  oss += "-";
  oss += rs(month());
  oss += "-";
  oss += rs(day());
  oss += " ";
  oss += rs(hour());
  oss += ":";
  oss += rs(minute());
  oss += ":";
  oss += rs(second());
  Serial.print(oss);
}
String rs(int digits) {
  String s = String(digits);
  if (digits < 10)
    s = "0" + String(digits);
  return s;
}
