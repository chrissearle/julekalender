#include <Arduino.h>

#include <Servo.h>

#include "servos.h"

Servos::Servos(int lowerPin, int upperPin)
{
    lowerServo = new Servo();
    lowerServo->attach(lowerPin);
    upperServo = new Servo();
    upperServo->attach(upperPin);
    upperServo->write(90);
}

void Servos::setLowerAngle(int angle)
{
    lowerServo->write(angle);
}

void Servos::beat()
{
    upperServo->write(60);
    delay(50);
    upperServo->write(90);
}
