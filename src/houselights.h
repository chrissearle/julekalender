#ifndef __HOUSELIGHTS_H__
#define __HOUSELIGHTS_H__

#include "house.h"

class HouseLights
{
private:
    House *small;
    House *curvedRoof;
    House *carousel;
    House *large;

public:
    HouseLights(int smallPin, unsigned int smallThreshold,
                int curvedRoofPin, unsigned int curvedRoofThreshold,
                int carouselPin, unsigned int carouselThreshold,
                int largePin, unsigned int largeThreshold);

    void day();
    void night();
};

#endif