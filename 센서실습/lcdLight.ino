#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp mylcd;

void setup() {
  // put your setup code here, to run once:
  mylcd.init();
  mylcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);

  mylcd.clear();
  mylcd.setCursor(0,0);
  mylcd.print("Light : ");
  mylcd.setCursor(0,1);
  mylcd.print(light);
  delay(1000);
}
