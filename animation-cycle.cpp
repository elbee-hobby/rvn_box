#include "animation-cycle.hpp"

static unsigned long g_offset;

AnimationCycle::AnimationCycle(Adafruit_NeoPixel& neopixels, int frames_per_second)
    : neopixels_(neopixels),
    frame_delay_ (1000 / frames_per_second)
{
}

AnimationCycle::~AnimationCycle() {
    delete first_animation_;
}

AnimationCycleBuilder AnimationCycle::build_from(const Ring_t& start_color) {
    AnimationCycleBuilder builder;
    first_animation_ = builder.init(start_color);
    animation_ = first_animation_;
    return builder;
}

void AnimationCycle::start() {
    last_update_time_ = millis();
    Animation* last_frame_animation = nullptr;

    while (true) {
        unsigned long now = millis();
        g_offset = now;

        if((now - last_update_time_) > frame_delay_) {
            if (update(now - animation_start_time_)) {
                return;
            }
            last_update_time_ = now;
        }
    } 
}

bool AnimationCycle::update(unsigned int ms_since_animation_start) {
    for (uint8_t i = 0; i < neopixels_.numPixels(); ++i){
        uint16_t pixel_index = (i + g_offset / 120) % neopixels_.numPixels();// + current_position_animation_.get_position_offset(frame_number)) % neopixels_.numPixels();
        current_color_[pixel_index] = animation_->get_color(i, neopixels_, ms_since_animation_start, base_color_);

        neopixels_.setPixelColor(pixel_index, current_color_[i]);
    }
    neopixels_.show();

    if (animation_->is_finished(ms_since_animation_start)) {
        memcpy(base_color_, current_color_, sizeof(base_color_));
        animation_ = animation_->next();
        animation_start_time_ = millis();
    }

    return animation_ == nullptr;
}