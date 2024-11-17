int led[12] = {8, 7, 15, 6, 16, 5, 17, 4, 18, 3, 19, 2};
// A1 -> 15 / A2 -> 16 / A3 -> 17 / A4 -> 18 / A5 -> 19 

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<12; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<12; i++){
    digitalWrite(led[i], HIGH);
    i = i+1;
    digitalWrite(led[i], HIGH);
    delay(800);
  }
  
  for(int i=11; i>=0; i--){
    digitalWrite(led[i], LOW);
    i = i-1;
    digitalWrite(led[i], LOW);
    delay(800);
  }

}
