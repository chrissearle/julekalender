#include <Arduino.h>

#include "lightstrip.h"
#include "houselights.h"
#include "motors.h"
#include "servos.h"

// Pins and values
// Using define so that they end up inlined but are collected here in one location
#define MILLIS_CAROUSEL 250
#define MILLIS_CURVED_ROOF 750
#define MILLIS_LARGE 360
#define MILLIS_LIGHTSTRIP 500
#define MILLIS_MOTORS 3000
#define MILLIS_SERVOS 200
#define MILLIS_SMALL 400
#define PIN_CAROUSEL 8
#define PIN_CURVED_ROOF 7
#define PIN_LARGE 10
#define PIN_LDR 2
#define PIN_LIGHTSTRIP 11
#define PIN_MOTORS_INA 3
#define PIN_MOTORS_INB 5
#define PIN_SERVO_LOWER 6
#define PIN_SERVO_UPPER 9
#define PIN_SMALL 2
#define THRESHOLD_LDR 800
// End of pins and values

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
  strip = new LightStrip(PIN_LIGHTSTRIP, MILLIS_LIGHTSTRIP);
  houseLights = new HouseLights(PIN_SMALL, MILLIS_SMALL,
                                PIN_CURVED_ROOF, MILLIS_CURVED_ROOF,
                                PIN_CAROUSEL, MILLIS_CAROUSEL,
                                PIN_LARGE, MILLIS_LARGE);
  motors = new Motors(PIN_MOTORS_INA, PIN_MOTORS_INB, MILLIS_MOTORS);
  servos = new Servos(PIN_SERVO_LOWER, PIN_SERVO_UPPER, MILLIS_SERVOS);

  servos->setLowerAngle(90);
}

void loop()
{
  servos->beat();

  if ((analogRead(PIN_LDR)) > THRESHOLD_LDR)
  {
    night();
  }
  else
  {
    day();
  }

  delay(50);
}