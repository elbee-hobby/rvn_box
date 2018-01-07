#include "animation-presets.hpp"

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
