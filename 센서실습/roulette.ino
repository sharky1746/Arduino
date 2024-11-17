int led[6] = {7,6,5,4,3,2};
int bt = 8;

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<6; i++){
     pinMode(led[i], OUTPUT);
  }

  pinMode(bt, INPUT);

  for(int i=0; i<6; i++){//6개의 LED가 모두 off된 상태에서 시작
      digitalWrite(led[i], LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int btState = digitalRead(bt);

  if(btState == HIGH){//버튼이 눌려있는 상태
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);

      btState = digitalRead(bt);
      if(btState == LOW)
        break;
      else{
        delay(500);
        digitalWrite(led[i], LOW);
      }
    }
  }
}
