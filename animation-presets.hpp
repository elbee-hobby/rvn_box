#pragma once

#include "animation.hpp"
#include "ring.hpp"

class StaticRing: public Animation {
public:
    StaticRing(const Ring_t& ring);

    bool is_finished(unsigned int ms_since_animation_start);

    uint32_t get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color);
private:
    Ring_t* ring_;
};

class Wait: public Animation {
public:
    Wait(unsigned int ms_wait);

    bool is_finished(unsigned int ms_since_animation_start);

    uint32_t get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color);
private:
    unsigned int ms_wait_;
};

class Fade: public Animation {
public:
    Fade(const Ring_t& ring, unsigned int ms);

    bool is_finished(unsigned int ms_since_animation_start);

    uint32_t get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color);
private:
    Ring_t* ring_;
    unsigned int ms_;
};

class Flash: public Animation {
public:
    Flash(const Ring_t& ring, unsigned int ms_flash);

    bool is_finished(unsigned int ms_since_animation_start);

    uint32_t get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color);
private:
    Ring_t* ring_;
    unsigned int ms_flash_;
};