#include "animation-cycle.hpp"
#include "colors.hpp"

Animation::Animation()
    : next_(nullptr)
{}

Animation::~Animation() {
    if (next_ != nullptr) {
        delete next_;
    }
}

Animation* Animation::next(){
    return next_;
}

void Animation::set_next(Animation *next) {
    next->next_ = next_;
    next_ = next;
}


StaticRing::StaticRing(const Ring_t& ring)
    : Animation(),
    ring_(&ring)
{}

bool StaticRing::is_finished(unsigned int ms_since_animation_start) {
    return true;
}

uint32_t StaticRing::get_color(uint8_t pixel_index, unsigned int ms_since_animation_start, const Ring_t& base_color) {
    return (*ring_)[pixel_index];
}

Wait::Wait(unsigned int ms_wait)
    : Animation(),
    ms_wait_(ms_wait)
{}

bool Wait::is_finished(unsigned int ms_since_animation_start) {
    return ms_since_animation_start > ms_wait_;
}

uint32_t Wait::get_color(uint8_t pixel_index, unsigned int ms_since_animation_start, const Ring_t& base_color) {
    return base_color[pixel_index];
}

AnimationCycleConfig::AnimationCycleConfig(Animation* first_animation)
: last_animation_(first_animation)
{}

AnimationCycleConfig& AnimationCycleConfig::then(Animation* animation)
{
    last_animation_->set_next(animation);
    last_animation_ = animation;
    return *this;
}

AnimationCycle::AnimationCycle(Adafruit_NeoPixel& neopixels, int frames_per_second)
    : neopixels_(neopixels),
    frame_delay_ (1000 / frames_per_second)
{}

AnimationCycle::~AnimationCycle() {
    delete first_animation_;
}

AnimationCycleConfig AnimationCycle::set_up(const Ring_t& start_color) {
    first_animation_ = new StaticRing(start_color);
    animation_ = first_animation_;
    return AnimationCycleConfig(first_animation_);
}

void AnimationCycle::start() {
    last_update_time_ = millis();
    Animation* last_frame_animation = nullptr;

    while (true) {
        unsigned long now = millis();

        if((now - last_update_time_) > frame_delay_) {
            if (animation_ != last_frame_animation) {
                last_frame_animation = animation_;
                animation_start_time_ = now;
            }

            if (update(now - animation_start_time_)) {
                return;
            }
            last_update_time_ = now;
        }
    } 
}

bool AnimationCycle::update(unsigned int ms_since_animation_start) {
    for (uint8_t i = 0; i < neopixels_.numPixels(); ++i){
        uint16_t pixel_index = i;// + current_position_animation_.get_position_offset(frame_number)) % neopixels_.numPixels();
        current_color_[pixel_index] = animation_->get_color(pixel_index, ms_since_animation_start, base_color_);

        neopixels_.setPixelColor(pixel_index, current_color_[pixel_index]);
    }
    neopixels_.show();

    if (animation_->is_finished(ms_since_animation_start)) {
        memcpy(base_color_, current_color_, sizeof(base_color_));
        animation_ = animation_->next();
    }

    return animation_ == nullptr;
}