#include <DHT.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp mylcd;
DHT mydht(A1, DHT11);

void setup() {
  // put your setup code here, to run once:
  mylcd.init();
  mylcd.backlight();

  mydht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  mylcd.clear();
  int temp = mydht.readTemperature();
  int humi = mydht.readHumidity();
  
  mylcd.setCursor(0,0);
  mylcd.print("Temp : ");
  mylcd.print(temp);
  mylcd.setCursor(0,1);
  mylcd.print("Humidity : ");
  mylcd.print(humi);
  
  delay(1000);
}
