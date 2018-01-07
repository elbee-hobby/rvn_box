#pragma once

#include <Adafruit_NeoPixel.h>
#include "animation.hpp"
#include "animation-cycle-builder.hpp"

class AnimationCycle {
public:
    AnimationCycle(Adafruit_NeoPixel& neopixels, int frames_per_second);
    ~AnimationCycle();

    AnimationCycleBuilder build_from(const Ring_t& start_color);

    void start();
    
private:
    bool update(unsigned int ms_since_animation_start);

    Adafruit_NeoPixel& neopixels_;

    const uint8_t frame_delay_;
    unsigned long last_update_time_;
    unsigned int animation_start_time_;

    Ring_t current_color_;
    Ring_t base_color_;

    Animation *first_animation_;
    Animation *animation_;
};