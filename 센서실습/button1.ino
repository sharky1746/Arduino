const int led =13;
const int bt = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(bt, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btState = digitalRead(bt);
  digitalWrite(led, btState);
}
