#include "animation-random-cycle.hpp"
#include "ring-presets.hpp"

const Ring_t& AnimationRandomCycle::get_random_color() {
    //exclude current color
    int old_color_index = color_index_;
    while (color_index_ == old_color_index) {
        color_index_ = random(0, RingPresets::instance().get_preset_count() - 1);
    }
    return RingPresets::instance().get(color_index_);
}

Animation* AnimationRandomCycle::generate_new_animation() {
    AnimationCycleBuilder builder;

    const Ring_t& color = get_random_color();
    const int transition_index = random(0, 2);
    switch (transition_index) {
        case 0:
            builder.fade_to(color, random(1000, 10000));
            break;
        case 1:
            builder.flicker_to(color);
            break;
    }

    builder.wait(random(5000, 30000));

    return builder.get_first_animation();
}

Animation* AnimationRandomCycle::get_next_animation() {
    if (animation_ != nullptr && animation_->next() != nullptr) {
        return animation_ = animation_->next();
    }
    delete first_animation_;
    return animation_ = first_animation_ = generate_new_animation();
}