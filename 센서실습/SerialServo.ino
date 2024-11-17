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
    char a = Serial.read();
    
    switch(a){
      case '1' :
           myservo.write(45);
           delay(1000);
           myservo.write(0);
           break;
           
      case '2' :
           myservo.write(90);
           delay(1000);
           myservo.write(0);
           break;
                
      case '3' :
           myservo.write(180);
           delay(1000);
           myservo.write(0);
           break;
           
      default:
           break;     
    }
  }
}
