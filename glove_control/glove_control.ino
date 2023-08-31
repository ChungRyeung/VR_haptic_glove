#include <MPU9250.h>
#include <Wire.h>

MPU9250 mpu;

int flexpin1 = A0; 
int flexpin2 = A1; 
int flexpin3 = A2; 
int flexpin4 = A3; 
int flexpin5 = A4; 

float xfirst=0;
float yfirst=0;
float zfirst=0;

const int numValues = 5;  // 입력할 값의 개수
int values[numValues];    // 값을 저장할 배열



void setup() {
  Serial.begin(9600);
  Wire.begin();

  // xfirst=mpu.getAccX();
  // yfirst=mpu.getAccY();
  // zfirst=mpu.getAccZ();


  if (!mpu.setup(0x68)) {  // change to your own address
    while (1) {
      Serial.print("error");
      delay(5000);
    }
  }
}

void loop() {
   //센서값을 저장할 변수 설정
    float flexVal1; 
    float flexVal2; 
    float flexVal3; 
    float flexVal4; 
    float flexVal5; 

    // 센서로 부터 보내오는 값을 입력 받는다.(0-1023)
    flexVal1 = analogRead(flexpin1); 
    flexVal2 = analogRead(flexpin2);
    flexVal3 = analogRead(flexpin3);
    flexVal4 = analogRead(flexpin4);
    flexVal5 = analogRead(flexpin5);

    // 유티니에서 값을 사용하기 위해 -100 ~ 100사이 값으로 매핑
    flexVal1 = map(flexVal1, 0, 511, -350, 350); // 엄지는 절반의 값
    flexVal2 = map(flexVal2, 0, 1023, -190, 190);
    flexVal3 = map(flexVal3, 0, 1023, -180, 240);
    flexVal4 = map(flexVal4, 0, 1023, -290, 290);
    flexVal5 = map(flexVal5, 0, 511, -240, 240);

    // 유니티에서 읽을 수 있도록 값,값,값 형태로 출력 

    if (mpu.update()) {
      static uint32_t prev_ms = millis();
      if (millis() > prev_ms + 25) {
        Serial.print(flexVal1);
        Serial.print(",");
        Serial.print(flexVal2);
        Serial.print(",");
        Serial.print(flexVal3);
        Serial.print(",");
        Serial.print(flexVal4);
        Serial.print(",");
        Serial.print(flexVal5);
        Serial.print(",");
        
        Serial.print(mpu.getPitch(), 2);
        Serial.print(",");
        Serial.print(mpu.getYaw(), 2);
        Serial.print(",");
        Serial.print(mpu.getRoll(), 2);
        Serial.println("");

        prev_ms = millis();
        
        // Serial.print(mpu.getAccX() - xfirst);
        // Serial.print(",");
        // Serial.print(mpu.getAccY()-yfirst);
        // Serial.print(",");
        // Serial.println(mpu.getAccZ()-zfirst);

      }
    }

  delay(100);
}