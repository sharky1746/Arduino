#define SOUND  A0
#define LED 3

int vol=0;
int light = 0;   
void setup() {
 pinMode(LED, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
  vol = analogRead(SOUND);

  if(vol > 40) {     
    if(light ==0){
      light = 50;
      analogWrite(LED, light);
      delay(100);
    }
    else if(light ==50){
      light = 255;
      analogWrite(LED, light);
      delay(100);
    }
    else{
      light = 0;
      analogWrite(LED, light);
      delay(100);
    }
  }
}
