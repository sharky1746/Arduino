int waterPin = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(waterPin);

  Serial.print("water : ");
  Serial.println(value);

  delay(100);
}
