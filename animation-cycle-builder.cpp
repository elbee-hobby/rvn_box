#include "animation-cycle-builder.hpp"
#include "animation-presets.hpp"

AnimationCycleBuilder::AnimationCycleBuilder()
: first_(nullptr),
  last_(nullptr)
{}

AnimationCycleBuilder& AnimationCycleBuilder::then(Animation* animation)
{
    if (first_ == nullptr) {
        first_ = animation;
    }

    if (last_ != nullptr) {
        last_->set_next(animation);
    }

    last_ = animation;
    return *this;
}

Animation* AnimationCycleBuilder::get_first_animation() {
    return first_;
}

Animation* AnimationCycleBuilder::get_last_animation() {
    return last_;
}

AnimationCycleBuilder& AnimationCycleBuilder::wait(unsigned int ms_wait) {
    return then(new Wait(ms_wait));
}

AnimationCycleBuilder& AnimationCycleBuilder::set_color(const Ring_t& ring) {
    return then(new StaticRing(ring));
}

AnimationCycleBuilder& AnimationCycleBuilder::fade_to(const Ring_t& ring, unsigned int ms_to_fade) {
    return then(new Fade(ring, ms_to_fade));
}

AnimationCycleBuilder& AnimationCycleBuilder::flash(const Ring_t& ring, unsigned ms_flash) {
    return then(new Flash(ring, ms_flash));
}

AnimationCycleBuilder& AnimationCycleBuilder::flicker_to(const Ring_t& ring) {
    for (int i = 0; i < random(1, 2); ++i) {
        flash(ring, random(30, 100));
        wait(random(1000, 3000));
    }
    for (int i = 0; i < random(2, 4); ++i) {
        flash(ring, random(30, 100));
        wait(random(50, 200));
    }
    wait(random(500, 1000));
    for (int i = 0; i < random(1, 3); ++i) {
        flash(ring, random(30, 100));
        wait(random(300, 1000));
    }
    flash(ring, random(300, 600));
    for (int i = 0; i < random(1, 3); ++i) {
        flash(ring, random(500, 2000));
        wait(random(30, 100));
    }
    set_color(ring);
    return *this;
}


