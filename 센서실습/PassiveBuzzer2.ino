const int passiveB = 10;

int melody[] = {392, 330, 330, 349, 294, 294, // 나비야 나비야
                262, 294, 330, 350, 392, 392, 392,//이리 날아 오너라
                392, 330, 330, 330, 349, 294, 294,//노랑나비 흰 나비
                262, 330, 392, 392, 330, 330, 330};//춤을 추며 오너라
int beat[] = {1, 1, 2, 1, 1, 2, // 나비야 나비야
              1, 1, 1, 1, 1, 1, 2,//이리 날아 오너라
              1, 1, 1, 1, 1, 1, 2,//노랑나비 흰 나비
              1, 1, 1, 1, 1, 1, 2};//춤을 추며 오너라
int melodyNum = 27;

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<melodyNum; i++){
    tone(passiveB, melody[i]);
    delay(500*beat[i]);
    noTone(passiveB);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
