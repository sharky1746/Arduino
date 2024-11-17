int led[12] = {8, 7, 15, 6, 16, 5, 17, 4, 18, 3, 19, 2};
// A1 -> 15 / A2 -> 16 / A3 -> 17 / A4 -> 18 / A5 -> 19 

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<12; i++){
    pinMode(led[i], OUTPUT);
  }

  for(int i=0; i<12; i++){
    digitalWrite(led[i], HIGH);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
