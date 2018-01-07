#pragma once

#include <Adafruit_NeoPixel.h>
#include "ring.hpp"

class RingPresets {
public:
    init(Adafruit_NeoPixel& neopixels);

    const Ring_t& blue_red();
    const Ring_t& blue();
    const Ring_t& red();
    const Ring_t& purple();
    const Ring_t& dark();

private:
    Ring_t blue_red_;
    Ring_t blue_;
    Ring_t red_;
    Ring_t purple_;
    Ring_t dark_;
};