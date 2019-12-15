#ifndef __LIGHTSTRIP_H__
#define __LIGHTSTRIP_H__

#include <Adafruit_NeoPixel.h>

class LightStrip
{
private:
    Adafruit_NeoPixel *strip;

    const unsigned int thresholdMillis = 500;

    unsigned long lastLoop = 0;

    uint32_t red;
    uint32_t green;
    uint32_t blue;
    uint32_t yellow;

    void setColors(uint32_t one, uint32_t two);

public:
    LightStrip(int pin);

    void day();
    void night();
};

#endif