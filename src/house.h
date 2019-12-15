#ifndef __HOUSE_H__
#define __HOUSE_H__

class House
{
private:
    int pin;
    unsigned int thresholdMillis;

    unsigned long lastLoop = 0;

public:
    House(int pin, unsigned int threshold);

    void day();
    void night();
};

#endif