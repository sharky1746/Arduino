void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(9, 255);
  analogWrite(10, 0);
  analogWrite(11,0);
  delay(2000);

  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11,0);
  delay(2000);
  
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11,255);
  delay(2000);
}
