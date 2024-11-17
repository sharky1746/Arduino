const int VResistor = A0;
const int led[3] = {9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<3; i++){
      pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(VResistor);
  
  if(value >= 256){
      digitalWrite(led[0], HIGH);
  }
  else{
    digitalWrite(led[0], LOW);
  }
  
  if(value >= 512){
      digitalWrite(led[1], HIGH);
  }
  else{
    digitalWrite(led[1], LOW);
  }
  
  if(value >= 768){
      digitalWrite(led[2], HIGH);
  }
  else{
    digitalWrite(led[2], LOW);
  }
}
