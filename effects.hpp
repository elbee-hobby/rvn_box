#pragma once

#include <Adafruit_NeoPixel.h>
#include "ring.hpp"


class Effects {
public:
    Effects(Adafruit_NeoPixel& pixels, const Ring_t& ring);

    Effects& display(const Ring_t& ring, int time);

    Effects& rotate(uint8_t rotations, int dt);
    Effects& flash(const Ring_t& flash_ring,
           uint8_t min_flash_count, uint8_t max_flash_count,
           int min_flash_delay, int max_flash_delay);
    Effects& pause(int dt);

    Effects& fade(const Ring_t& end_ring, int dt);
    Effects& flash_transition(const Ring_t& end_ring);

private:
    Adafruit_NeoPixel& neopixels;
    const Ring_t* current_ring;
};
