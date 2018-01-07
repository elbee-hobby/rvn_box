#include "animation-cycle.hpp"

static unsigned long g_offset;

AnimationCycle::AnimationCycle()
    : first_animation_(nullptr)
{
}

AnimationCycle::~AnimationCycle() {
    if (first_animation_ != nullptr) {
        delete first_animation_;
    }
}

AnimationCycleBuilder AnimationCycle::start_from(const Ring_t& start_color) {
    AnimationCycleBuilder builder;
    first_animation_ = builder.set_color(start_color).get_last_animation();
    animation_ = first_animation_;
    return builder;
}

Animation* AnimationCycle::get_next_animation() {
    return animation_ = animation_->next();
}