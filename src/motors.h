#ifndef __MOTORS_H__
#define __MOTORS_H__

class Motors
{
private:
    unsigned int inA;
    unsigned int inB;

    unsigned int thresholdMillis;

    unsigned long lastLoop = 0;

    const unsigned int motorStep = 10;

    bool motorRunning = false;

    unsigned int motorTarget = 0;

    int motorCurrent = 0;

public:
    Motors(int pinA, int pinB, unsigned int threshold);

    void day();
    void night();
};

#endif