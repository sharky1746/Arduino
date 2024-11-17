const int led =10;
const int bt = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(bt, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btState = digitalRead(bt);
  
  if(btState == HIGH){
    for(int i=0; i<=255; i++){
        analogWrite(led, i);
        delay(10);
    }
  }
  else{
        analogWrite(led,0);
  }
}
