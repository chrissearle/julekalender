#ifndef __SERVOS_H__
#define __SERVOS_H__

#include <Servo.h>

class Servos
{
private:
    Servo *lowerServo;
    Servo *upperServo;

public:
    Servos(int lowerPin, int upperPin);

    void setLowerAngle(int angle);
    void setUpperAngle(int angle);
};

#endif