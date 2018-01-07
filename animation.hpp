#pragma once
#include "ring.hpp"


class Animation {
public:
    Animation();
    virtual ~Animation();

    virtual bool is_finished(unsigned int ms_since_animation_start) = 0;
    virtual uint32_t get_color(uint8_t pixel_index, unsigned int time_ms, const Ring_t& base_color) = 0;

    Animation* next();
    void set_next(Animation *next);

private:
    Animation* next_;
};