#include "animation-cycle-builder.hpp"
#include "animation-presets.hpp"

AnimationCycleBuilder::AnimationCycleBuilder()
: last_animation_(nullptr)
{}

AnimationCycleBuilder& AnimationCycleBuilder::then(Animation* animation)
{
    last_animation_->set_next(animation);
    last_animation_ = animation;
    return *this;
}

Animation* AnimationCycleBuilder::init(const Ring_t& ring) {
    last_animation_ = new StaticRing(ring);
    return last_animation_;
}

AnimationCycleBuilder& AnimationCycleBuilder::wait(unsigned int ms_wait) {
    return then(new Wait(ms_wait));
}

AnimationCycleBuilder& AnimationCycleBuilder::set_color(const Ring_t& ring) {
    return then(new StaticRing(ring));
}

AnimationCycleBuilder& AnimationCycleBuilder::fade_to(const Ring_t& ring) {

}

AnimationCycleBuilder& AnimationCycleBuilder::flicker_to(const Ring_t& ring) {

}


