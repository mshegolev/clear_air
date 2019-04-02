#include "MQ135.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup () {
  Serial.begin (9600);
  lcd.begin();
  lcd.backlight();
  Serial.println("rzero,ppm,time");
}

void loop() {
  MQ135 gasSensor = MQ135(A0); // Attach sensor to pin A0
  float rzero = gasSensor.getRZero();
  float ppm = gasSensor.getPPM();
  Serial.print(rzero);
  Serial.print(",");
  Serial.print(ppm);
  Serial.print(",");
  Serial.println();
  
  delay(1000);
  lcd.home();
  lcd.print("PPM: ");
  lcd.print(gasSensor.getPPM());
  
  lcd.setCursor(0,1);
  lcd.print("RZERO: ");
  lcd.print(gasSensor.getRZero());
  
}
