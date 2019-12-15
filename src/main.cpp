#include <Arduino.h>

#include "lightstrip.h"
#include "houselights.h"
#include "motors.h"
#include "servos.h"

// LDR
unsigned int lightThreshold = 800;
unsigned int lightSensorPin = 2;

Servos *servos;
LightStrip *strip;
Motors *motors;
HouseLights *houseLights;

void night()
{
  strip->night();
  houseLights->night();
  motors->night();
}

void day()
{
  strip->day();
  houseLights->day();
  motors->day();
}

void setup()
{
  strip = new LightStrip(11);
  houseLights = new HouseLights(2, 400, 7, 750, 8, 250, 10, 360);
  motors = new Motors(3, 5);
  servos = new Servos(6, 0);
}

void loop()
{
  servos->setLowerAngle(90);

  if ((analogRead(lightSensorPin)) > lightThreshold)
  {
    night();
  }
  else
  {
    day();
  }

  delay(50);
}