#include <Arduino.h>

#include <Adafruit_NeoPixel.h>
#include <Servo.h>

// Light strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, 11, NEO_GRB + NEO_KHZ800);
unsigned int colorChange = 500;
unsigned long lastLoopStrip = 0;

// Motors
unsigned int motorInA = 3;
unsigned int motorInB = 5;
unsigned long lastLoopMotor = 0;
unsigned int motorThreshold = 3000;
bool motorRunning = false;

// Servos
unsigned int lowerServoPin = 6;
Servo lowerServo;

// LDR
unsigned int lightThreshold = 800;
unsigned int lightSensorPin = 2;

// Colours
uint32_t red = strip.Color(153, 0, 0);
uint32_t green = strip.Color(0, 153, 0);
uint32_t blue = strip.Color(93, 173, 226);
uint32_t yellow = strip.Color(244, 208, 63);

// house lights - small, curved, carousel, large
unsigned int lightPins[] = {2, 7, 8, 10};
unsigned long lastLoopLights[] = {0, 0, 0, 0};
unsigned int lightThresholds[] = {400, 750, 250, 360};

void motorOn(PinStatus direction, int speed)
{
  // Currently ignoring direction - it was working but
  // my motors currently just give a whining noise in
  // one direction
  if (!motorRunning) {
    digitalWrite(motorInA, LOW);
    analogWrite(motorInB, speed);
    motorRunning = true;
  }
}

void motorOff()
{
  if (motorRunning) {
    digitalWrite(motorInA, LOW);
    digitalWrite(motorInB, LOW);
    motorRunning = false;
  }
}

void houseLightsOff()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(lightPins[i], LOW);
  }
}

void setColors(uint32_t one, uint32_t two)
{
  unsigned long current = millis();

  if ((current - lastLoopStrip) >= colorChange)
  {
    if (random(100) % 2 == 0)
    {
      strip.setPixelColor(0, one);
      strip.setPixelColor(1, two);
    }
    else
    {
      strip.setPixelColor(0, two);
      strip.setPixelColor(1, one);
    }

    strip.show();

    lastLoopStrip = current;
  }
}

void setMotors()
{
  unsigned long current = millis();

  if ((current - lastLoopMotor) > motorThreshold)
  {
    if (random(100) % 2 == 0)
    {
      if (motorRunning)
      {
        motorOff();
      }
      else
      {
        bool direction = (random(100) % 2) == 0;
        motorOn(direction ? LOW : HIGH, random(200, 255));
      }
      lastLoopMotor = current;
    }
  }
}

void checkHouseLights()
{
  unsigned long current = millis();

  for (int i = 0; i < 4; i++)
  {
    if (current - lastLoopLights[i] >= lightThresholds[i])
    {
      PinStatus pinState = digitalRead(lightPins[i]);
      digitalWrite(lightPins[i], pinState == LOW ? HIGH : LOW);
      lastLoopLights[i] = current;
    }
  }
}

void evening()
{
  setColors(red, green);
  checkHouseLights();
  setMotors();
}

void daytime()
{
  setColors(blue, yellow);
  houseLightsOff();
  motorOff();
}

void setup()
{
  strip.begin();
  strip.show();

  for (int i = 0; i < 4; i++)
  {
    pinMode(lightPins[i], OUTPUT);
  }

  pinMode(motorInA, OUTPUT);
  pinMode(motorInB, OUTPUT);

  motorOff();

  lowerServo.attach(lowerServoPin);
}

void loop()
{
  lowerServo.write(90);

  if ((analogRead(lightSensorPin)) > lightThreshold)
  {
    evening();
  }
  else
  {
    daytime();
  }

  delay(50);
}