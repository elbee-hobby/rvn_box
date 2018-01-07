#pragma once

#include <Adafruit_NeoPixel.h>

#include "ring.hpp"

class Animation {
public:
    Animation();

    virtual ~Animation();

    virtual bool is_finished(unsigned int ms_since_animation_start) = 0;

    Animation* next();

    virtual uint8_t get_color(uint8_t pixel_index, unsigned int time_ms, const Ring_t& base_color) = 0;

    void set_next(Animation *next);

private:
    Animation* next_;
};

class StaticRing: public Animation {
public:
    StaticRing(const Ring_t& ring);

    bool is_finished(unsigned int ms_since_animation_start);

    uint8_t get_color(uint8_t pixel_index, unsigned int ms_since_animation_start, const Ring_t& base_color);
private:
    Ring_t* ring_;
};

class Wait: public Animation {
public:
    Wait(unsigned int ms_wait);

    bool is_finished(unsigned int ms_since_animation_start);

    uint8_t get_color(uint8_t pixel_index, unsigned int ms_since_animation_start, const Ring_t& base_color);
private:
    unsigned int ms_wait_;
};

class AnimationCycleConfig {
public:
    AnimationCycleConfig(Animation* first_animation);

    AnimationCycleConfig& then(Animation* animation);

private:
    Animation* last_animation_;
};

class AnimationCycle {
public:
    AnimationCycle(
        Adafruit_NeoPixel& neopixels,
        int frames_per_second);

    ~AnimationCycle();

    AnimationCycleConfig set_up(const Ring_t& start_color);


    void start();
    
private:
    bool update(unsigned int ms_since_animation_start);

    Adafruit_NeoPixel& neopixels_;

    const uint8_t frame_delay_;
    unsigned long last_update_time_;
    unsigned int animation_start_time_;

    Ring_t current_color_;
    Ring_t base_color_;

    Animation *first_animation_;
    Animation *animation_;
};