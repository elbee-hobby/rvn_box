#pragma once

#include "animation.hpp"
#include "ring.hpp"

class AnimationCycleBuilder {
public:
    AnimationCycleBuilder();

    Animation* init(const Ring_t& start_color);

    AnimationCycleBuilder& wait(unsigned int ms_wait);
    AnimationCycleBuilder& set_color(const Ring_t& ring);
    AnimationCycleBuilder& fade_to(const Ring_t& ring, unsigned int ms_to_fade);
    AnimationCycleBuilder& flicker_to(const Ring_t& ring);

    
    AnimationCycleBuilder& then(Animation* animation);

private:
    Animation* last_animation_;
};