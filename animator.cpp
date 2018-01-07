#include "animator.hpp"

static unsigned long g_offset;

Animator::Animator(Adafruit_NeoPixel& neopixels, int frames_per_second)
    : neopixels_(neopixels),
    frame_delay_ (1000 / frames_per_second)
{
}


void Animator::start(AnimationCycle& cycle) {
    Animation* animation = cycle.get_next_animation();

    unsigned long last_update_time = millis();
    unsigned long animation_start_time = last_update_time;
    

    while (animation != nullptr) {
        unsigned long now = millis();
        g_offset = now;


        if((now - last_update_time) > frame_delay_) {
            unsigned long animation_time = now - animation_start_time;
            
            update(animation_time, *animation);

            if (animation->is_finished(animation_time)) {
                memcpy(base_color_, current_color_, sizeof(base_color_));
                animation = cycle.get_next_animation();
                animation_start_time = now;
            }

            last_update_time = now;
        }
    } 
}

void Animator::update(unsigned long ms_since_animation_start, Animation& animation) {
    for (uint8_t i = 0; i < neopixels_.numPixels(); ++i){
        uint16_t pixel_index = (i + g_offset / 120) % neopixels_.numPixels();// + current_position_animation_.get_position_offset(frame_number)) % neopixels_.numPixels();
        current_color_[pixel_index] = animation.get_color(i, neopixels_, ms_since_animation_start, base_color_);

        neopixels_.setPixelColor(pixel_index, current_color_[i]);
    }
    neopixels_.show();
}