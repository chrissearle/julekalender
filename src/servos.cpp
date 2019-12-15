#include <Arduino.h>

#include <Servo.h>

#include "servos.h"

Servos::Servos(int lowerPin, int upperPin)
{
    lowerServo = new Servo();
    lowerServo->attach(lowerPin);
}

void Servos::setLowerAngle(int angle)
{
    lowerServo->write(angle);
}

void Servos::setUpperAngle(int angle)
{
    // NOP
}
