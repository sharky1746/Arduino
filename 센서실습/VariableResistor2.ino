const int VResistor = A0;
const int led = 9;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int value = analogRead(VResistor);
  int lightValue = value/4;
  analogWrite(led, lightValue);
}
