#pragma once

#include <Adafruit_NeoPixel.h>
#include "animation.hpp"
#include "animation-cycle.hpp"

class Animator {
public:
    Animator(Adafruit_NeoPixel& neopixels, int frames_per_second);

    void start(AnimationCycle& cycle);
    
private:
    void update(unsigned long ms_since_animation_start, Animation& animation);

    Adafruit_NeoPixel& neopixels_;

    const uint8_t frame_delay_;

    Ring_t current_color_;
    Ring_t base_color_;
};