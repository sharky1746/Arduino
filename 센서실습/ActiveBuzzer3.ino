const int activeB =10;
const int bt = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(activeB, OUTPUT);
  pinMode(bt, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btState = digitalRead(bt);
  digitalWrite(activeB, btState);
}
