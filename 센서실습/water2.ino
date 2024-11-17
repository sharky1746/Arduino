int waterPin = A5;
int led1 = 2;
int led2 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(waterPin);

  if(value<50){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  else if(value<= 500){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);  
  }
  delay(100);
}
