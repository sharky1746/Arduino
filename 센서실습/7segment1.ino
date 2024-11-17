const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int dp = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //켜기
  digitalWrite(a,LOW);
  delay(300);
  digitalWrite(b,LOW);
  delay(300);
  digitalWrite(c,LOW);
  delay(300);
  digitalWrite(d,LOW);
  delay(300);
  digitalWrite(e,LOW);
  delay(300);
  digitalWrite(f,LOW);
  delay(300);
  digitalWrite(g,LOW);
  delay(300);
  digitalWrite(dp,LOW);
  delay(300);

  //끄기
  digitalWrite(a,HIGH);
  delay(300);
  digitalWrite(b,HIGH);
  delay(300);
  digitalWrite(c,HIGH);
  delay(300);
  digitalWrite(d,HIGH);
  delay(300);
  digitalWrite(e,HIGH);
  delay(300);
  digitalWrite(f,HIGH);
  delay(300);
  digitalWrite(g,HIGH);
  delay(300);
  digitalWrite(dp,HIGH);
  delay(300);

  
}
