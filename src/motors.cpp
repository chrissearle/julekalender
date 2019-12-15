#include <Arduino.h>

#include "motors.h"

Motors::Motors(int pinA, int pinB)
{
    inA = pinA;
    inB = pinB;

    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
}

void Motors::day()
{
    motorTarget = 0;
}

void Motors::night()
{
    unsigned long current = millis();

    if ((current - lastLoop) > thresholdMillis)
    {
        if (random(100) % 2 == 0)
        {
            if (motorRunning)
            {
                motorTarget = 0;
                motorRunning = false;
            }
            else
            {
                motorTarget = random(127, 255);
                motorRunning = true;
            }

            if (motorCurrent != motorTarget)
            {
                digitalWrite(inA, LOW);

                if (motorCurrent < motorTarget)
                {
                    motorCurrent = motorCurrent + motorStep;

                    if (motorCurrent > motorTarget)
                    {
                        motorCurrent = motorTarget;
                    }
                }
                else
                {
                    motorCurrent = motorCurrent - motorStep;
                    if (motorCurrent < motorTarget)
                    {
                        motorCurrent = motorTarget;
                    }
                }

                analogWrite(inB, motorCurrent);
            }

            lastLoop = current;
        }
    }
}