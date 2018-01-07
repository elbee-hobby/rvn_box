#pragma once

#include <Adafruit_NeoPixel.h>
#include "ring.hpp"

class RingPresets {
public:
    static RingPresets& instance();

    init(Adafruit_NeoPixel& neopixels);

    int get_preset_count();
    const Ring_t& get(unsigned int i);

    const Ring_t& blue_red();
    const Ring_t& blue();
    const Ring_t& red();
    const Ring_t& purple();
    const Ring_t& dark();

private:
    RingPresets() = default;

    Ring_t blue_red_;
    Ring_t blue_;
    Ring_t red_;
    Ring_t purple_;
    Ring_t light_;
    Ring_t dark_;

    Ring_t* presets_[5];
};