#pragma once

#include <Adafruit_NeoPixel.h>
#include "animation.hpp"
#include "animation-cycle-builder.hpp"

class AnimationCycle {
public:
    AnimationCycle();
    ~AnimationCycle();

    AnimationCycleBuilder start_from(const Ring_t& start_color);
    virtual Animation* get_next_animation();
    
protected:
    Animation *first_animation_;
    Animation *animation_;
};