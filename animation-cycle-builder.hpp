#pragma once

#include "animation.hpp"
#include "ring.hpp"

class AnimationCycleBuilder {
public:
    AnimationCycleBuilder();

    Animation* get_first_animation();
    Animation* get_last_animation();

    AnimationCycleBuilder& wait(unsigned int ms_wait);
    AnimationCycleBuilder& set_color(const Ring_t& ring);
    AnimationCycleBuilder& fade_to(const Ring_t& ring, unsigned int ms_to_fade);
    AnimationCycleBuilder& flash(const Ring_t& ring, unsigned ms_flash);
    AnimationCycleBuilder& flicker_to(const Ring_t& ring);
    
private:
    AnimationCycleBuilder& then(Animation* animation);

    Animation* first_;
    Animation* last_;
};