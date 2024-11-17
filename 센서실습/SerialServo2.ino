#include <Servo.h>

const int servoPin = 10;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  myservo.attach(servoPin);
  myservo.write(0);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
    int angle = Serial.parseInt();
    for(int i=0; i<=angle; i++){
      myservo.write(i);
      delay(10);
    }
    delay(1000);
    myservo.write(0);
  }
}
