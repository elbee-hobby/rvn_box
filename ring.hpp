#pragma once

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 16

using Ring_t = uint32_t[NUMPIXELS];

struct Ring {
    static const Ring_t BlueRed;
    static const Ring_t Blue;
    static const Ring_t Red;
    static const Ring_t Purple;
    static const Ring_t Dark;
};