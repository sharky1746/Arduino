const int led[8] = {2,3,4,5,6,7,8,9};

byte number[10][8] =
{
  {0,0,0,0,0,0,1,1}, // 0
  {1,0,0,1,1,1,1,1}, // 1
  {0,0,1,0,0,1,0,1}, // 2  
  {0,0,0,0,1,1,0,1}, // 3  
  {1,0,0,1,1,0,0,1}, // 4  
  {0,1,0,0,1,0,0,1}, // 5  
  {0,1,0,0,0,0,0,1}, // 6  
  {0,0,0,1,1,1,1,1}, // 7  
  {0,0,0,0,0,0,0,1}, // 8  
  {0,0,0,1,1,0,0,1} // 9    
};

void setup() {
  // put your setup code here, to run once:
  for(int i =0; i<8; i++){
    pinMode(led[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i =0; i<10; i++){//0~9
    for(int j=0; j<8; j++){//각 숫자를 이루기 위한 LED각각 제어
      digitalWrite(led[j], number[i][j]);
    }
    delay(700);
  }
}
