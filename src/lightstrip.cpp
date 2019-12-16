#include <Arduino.h>

#include <Adafruit_NeoPixel.h>

#include "lightstrip.h"

LightStrip::LightStrip(int pin, unsigned int threshold)
{
    thresholdMillis = threshold;

    strip = new Adafruit_NeoPixel(2, pin, NEO_GRB + NEO_KHZ800);

    red = strip->Color(153, 0, 0);
    green = strip->Color(0, 153, 0);
    blue = strip->Color(93, 173, 226);
    yellow = strip->Color(244, 208, 63);

    strip->begin();
    strip->show();
}

void LightStrip::setColors(uint32_t one, uint32_t two)
{
    unsigned long current = millis();

    if ((current - lastLoop) >= thresholdMillis)
    {
        if (random(100) % 2 == 0)
        {
            strip->setPixelColor(0, one);
            strip->setPixelColor(1, two);
        }
        else
        {
            strip->setPixelColor(0, two);
            strip->setPixelColor(1, one);
        }

        strip->show();

        lastLoop = current;
    }
}

void LightStrip::day()
{
    setColors(blue, yellow);
}

void LightStrip::night()
{
    setColors(red, green);
}
