#include "neopixel.hpp"
#include "ring.hpp"

#define PIN 6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);