#include <SoftwareSerial.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

// LCD 초기화 (I2C 주소 0x27, 16x2 크기)
hd44780_I2Cexp mylcd;

SoftwareSerial Bluetooth(2, 3);  // Bluetooth 모듈과의 통신 (RX, TX)

const int enA = 5;
const int in1 = 7;
const int in2 = 6;
const int enB = 9;
const int in3 = 8;
const int in4 = 10;

// 초음파 센서 핀
const int trigPin = 4;
const int echoPin = 12;

// 거리 제한 (단위: cm)
const int distanceThreshold = 10;

// 현재 상태를 저장할 변수
char currentState = 'S';  // 초기 상태는 정지

void setup() {
  // 핀 모드 설정
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

    // 초음파 센서 핀 모드 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // 초기 모터 속도 설정
  analogWrite(enA, 200);  // 속도 조절 (0~255)
  analogWrite(enB, 200);

  // 블루투스 시리얼 통신 시작
  Bluetooth.begin(9600);
  Serial.begin(9600);  // 디버깅용 시리얼 모니터

// LCD 셋업
  mylcd.init();
  mylcd.backlight();

}

void loop() {

  int distance = measureDistance();  // 거리 측정

  // 거리 정보 시리얼 모니터와 LCD에 출력


  mylcd.clear();
  mylcd.setCursor(0,0);
  mylcd.print("Distance : ");
  mylcd.print(distance);
 mylcd.print("cm");
  mylcd.setCursor(0,1);
    mylcd.print("State : ");
  mylcd.print(currentState);
  delay(1000);

  // 거리 정보 시리얼 모니터에 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print("State: ");
  Serial.println(currentState);

    // 장애물 감지 시 우회전 및 타이머 추가**
      if (currentState == 'F' && distance <= distanceThreshold) {
    Serial.println("Object detected! Turning right until clear.");

    unsigned long startTime = millis();  // 우회전 시작 시간 기록

    // 장애물이 10cm 이상이 되거나 5초가 지나기 전까지 우회전
    while (distance <= distanceThreshold) {
      turnRight();
      delay(100);  // 약간의 딜레이로 회전 속도 조절
      distance = measureDistance();
      
      // 거리 다시 출력
      if (distance != 999) {
          mylcd.clear();
  mylcd.setCursor(0,0);
  mylcd.print("Distance : ");
  mylcd.print(distance);
 mylcd.print("cm");
  mylcd.setCursor(0,1);
    mylcd.print("State : ");
  mylcd.print(currentState);
        Serial.print("Distance while turning: ");
        Serial.print(distance);
        Serial.println(" cm");
        Serial.print("State: ");
        Serial.println(currentState);
      }

      // 5초가 지나면 정지
      if (millis() - startTime >= 3000) {
        stopMotors();

        Serial.println("Turning timeout! Stopping.");

    
               mylcd.clear();
  mylcd.setCursor(0,0);
  mylcd.print("Distance : ");
  mylcd.print(distance);
 mylcd.print("cm");
  mylcd.setCursor(0,1);
    mylcd.print("State : ");
  mylcd.print(currentState);
        Serial.print("Distance while turning: ");
        Serial.print(distance);
        Serial.println(" cm");
        Serial.print("State: ");
        Serial.println(currentState);
                delay(10000); 
            return;
      }
    }

    // 장애물이 사라지면 전진
    moveForward();
    Serial.println("Path is clear! Moving forward.");
  }


  // 블루투스 또는 시리얼 모니터에서 명령 확인
  char command = 0;
  if (Bluetooth.available()) {
    command = Bluetooth.read();
    Serial.print("Received from Bluetooth: ");
    Serial.println(command);
  } else if (Serial.available()) {
    command = Serial.read();
    Serial.print("Received from Serial Monitor: ");
    Serial.println(command);
  }


  // 명령어에 따른 동작 수행
  switch (command) {
    case 'F':  // Forward
      moveForward();
      break;
    case 'B':  // Backward
      moveBackward();
      break;
    case 'L':  // Left
      turnLeft();
      break;
    case 'R':  // Right
      turnRight();
      break;
    case 'S':  // Stop
      stopMotors();
      break;
  }

  
}

// 초음파 거리 측정 함수
int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;  // 거리 계산 (cm 단위)

    // 0cm와 같이 잘못된 측정값을 필터링
  if (distance == 0) {
    return 998;  // 임의로 999cm를 반환하여 무시하도록 설정
  }
  return distance;
}

// 모터 제어 함수들
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
      currentState = 'F';
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
      currentState = 'B';
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  currentState = 'L';
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  currentState = 'R';
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  currentState = 'S';
}
