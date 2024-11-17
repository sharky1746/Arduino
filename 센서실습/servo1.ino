#include <Servo.h>

const int servoPin = 10;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(servoPin);
  myservo.write(0);

  delay(1000);

  for(int i=0; i<=3; i++){
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
