#include "neopixel.hpp"
#include "neopixel-ring-config.h"

#define PIN 6

Adafruit_NeoPixel Neopixels::instance = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);