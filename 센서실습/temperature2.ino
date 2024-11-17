const int temperature = A0;
const int led = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(temperature);
  
  float volt = value * 5.0 / 1024.0;
  float tempC = (volt -0.5)*100;
  Serial.print(tempC);
  Serial.println("C");
  
  if(tempC < 27.0){
    digitalWrite(led,HIGH);
  } 
  else{
    digitalWrite(led,LOW);
  }
  delay(500);
}
