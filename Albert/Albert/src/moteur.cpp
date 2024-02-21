#include <Arduino.h>
#include <Servo.h>

#define PIN_PPM 5

Servo motor1;

void setup() {
    motor1.attach(PIN_PPM);
}

void loop() {
    motor1.writeMicroseconds(2000); //full speed
    delay(2000);
    motor1.writeMicroseconds(1500); //zero
    delay(2000);
    motor1.writeMicroseconds(1000); //full speed back
    delay(2000);
}