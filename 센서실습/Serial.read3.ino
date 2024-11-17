const int led = 10;

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
      case '0' :
           analogWrite(led, 0);
           break;
           
      case '1' :
           analogWrite(led, 50*1);
           break;
                
      case '2' :
           analogWrite(led, 50*2);
           break;
                
      case '3' :
           analogWrite(led, 50*3);
           break;
                
      case '4' :
           analogWrite(led, 50*4);
           break;
                
      case '5' :
           analogWrite(led, 50*5);
           break;
           
      default:
           break;     
    }
  }
}
