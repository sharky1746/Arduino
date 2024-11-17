const int led[3] ={9,10,11};
const int bt = 2;

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<=2; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(bt, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btState = digitalRead(bt);
  
  if(btState == HIGH){
    for(int i=0; i<=2; i++){
        analogWrite(led[i], HIGH);
        delay(100);
    }
  }
  else{
     for(int i=0; i<=2; i++){
        analogWrite(led[i], LOW);
        delay(100);
    }
  }
  
}
