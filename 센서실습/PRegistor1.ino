const int PRegistor = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int value = analogRead(PRegistor);
  Serial.println(value);
}
