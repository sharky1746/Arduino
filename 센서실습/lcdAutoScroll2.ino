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
  mylcd.setCursor(0,0);
  for(int i=0; i<20; i++){
    mylcd.print(i);
    delay(500);
  }

  mylcd.setCursor(16,1);
  mylcd.autoscroll();
  for(int i=0; i<20; i++){
    mylcd.print(i);
    delay(500);
  }

  mylcd.noAutoscroll();
  mylcd.clear();
}
