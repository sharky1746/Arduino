const int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if(Serial.available()){
    char a = Serial.read();
    
    switch(a){
      case 'o' :
           digitalWrite(led, HIGH);
           break;
           
      case 'f' :
           digitalWrite(led, LOW);
           break;
           
      default:
           break;     
    }
  }
}
