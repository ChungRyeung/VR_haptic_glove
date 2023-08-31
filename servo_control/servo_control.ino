#include<Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
int value=0;
int servoPin1 = 13;
int servoPin2 = 12;
int servoPin3 = 11;
int servoPin4 = 10;
int servoPin5 = 9;
void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  Serial.begin(9600); // 시리얼 통신 시작, 보드레이트는 Unity와 일치시키거나 설정


}

void loop() {
  if (Serial.available()) { // 시리얼 버퍼에 데이터가 있는지 확인
    char receivedChar = Serial.read(); // 문자 하나 읽기

    if (receivedChar == '1') {
       // 충돌시 서보각도
      servo1.write(140);
      servo2.write(150);
      servo3.write(40);
      servo4.write(40);
      servo5.write(40);
    } else if (receivedChar == '0') {
       //  충돌안할떄 서보각
      servo1.write(30);
      servo2.write(30);
      servo3.write(150);
      servo4.write(150);
      servo5.write(150);
    }
  }
}
