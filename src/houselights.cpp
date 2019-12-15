#include <Arduino.h>

#include "houselights.h"
#include "house.h"

HouseLights::HouseLights(int smallPin, unsigned int smallThreshold,
                         int curvedRoofPin, unsigned int curvedRoofThreshold,
                         int carouselPin, unsigned int carouselThreshold,
                         int largePin, unsigned int largeThreshold)
{
    small = new House(smallPin, smallThreshold);
    curvedRoof = new House(curvedRoofPin, curvedRoofThreshold);
    carousel = new House(carouselPin, carouselThreshold);
    large = new House(largePin, largeThreshold);
}

void HouseLights::day()
{
    small->day();
    curvedRoof->day();
    carousel->day();
    large->day();
}

void HouseLights::night()
{
    small->night();
    curvedRoof->night();
    carousel->night();
    large->night();
}