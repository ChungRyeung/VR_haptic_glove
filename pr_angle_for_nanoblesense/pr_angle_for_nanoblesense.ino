#include <Arduino_LSM9DS1.h>
#include "math.h"

void setup() {
    Serial.begin(9600);
    while (!Serial);
    if (!IMU.begin()) {
        while (1);
    }

}

void loop() {
    float x, y, z;

    if (IMU.accelerationAvailable()) {
        IMU.readAcceleration(x, y, z);

        Serial.print(atan2(y, z)*180./PI);
        Serial.print(",");
        Serial.println(atan2(x, z)*180./PI);
    }
    delay(100);
}