#include <Arduino.h>

#include "house.h"

House::House(int housePin, unsigned int houseThreshold)
{
    pin = housePin;
    thresholdMillis = houseThreshold;

    pinMode(pin, OUTPUT);
}

void House::day()
{
    digitalWrite(pin, LOW);
}

void House::night()
{
    unsigned long current = millis();

    if (current - lastLoop >= thresholdMillis)
    {
        PinStatus pinState = digitalRead(pin);
        digitalWrite(pin, pinState == LOW ? HIGH : LOW);
        lastLoop = current;
    }
}
