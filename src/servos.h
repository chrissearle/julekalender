#ifndef __SERVOS_H__
#define __SERVOS_H__

#include <Servo.h>

class Servos
{
private:
    Servo *lowerServo;
    Servo *upperServo;

    unsigned int thresholdMillis;

    unsigned long lastLoop = 0;

public:
    Servos(int lowerPin, int upperPin, unsigned int threshold);

    void setLowerAngle(int angle);
    void beat();
};

#endif