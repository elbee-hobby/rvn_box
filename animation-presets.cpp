#include "animation-presets.hpp"
#include "colors.hpp"

static uint8_t component_interpolation(uint8_t start, uint8_t end, float percent) {
  return start + ((end - start) * percent);
}


static uint32_t pixel_interpolation(Adafruit_NeoPixel& neopixels, uint32_t start, uint32_t end, float percent) {
  return neopixels.Color(
    component_interpolation(red(start), red(end), percent),
    component_interpolation(green(start), green(end), percent),
    component_interpolation(blue(start), blue(end), percent),
    0);
}

StaticRing::StaticRing(const Ring_t& ring)
    : Animation(),
    ring_(&ring)
{}

bool StaticRing::is_finished(unsigned int ms_since_animation_start) {
    return true;
}

uint32_t StaticRing::get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color) {
    return (*ring_)[pixel_index];
}

Wait::Wait(unsigned int ms_wait)
    : Animation(),
    ms_wait_(ms_wait)
{}

bool Wait::is_finished(unsigned int ms_since_animation_start) {
    return ms_since_animation_start > ms_wait_;
}

uint32_t Wait::get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color) {
    return base_color[pixel_index];
}


Fade::Fade(const Ring_t& ring, unsigned int ms)
    : Animation(),
    ring_(&ring),
    ms_(ms)
{}

bool Fade::is_finished(unsigned int ms_since_animation_start) {
    return ms_since_animation_start > ms_;
}

uint32_t Fade::get_color(uint8_t pixel_index, Adafruit_NeoPixel& neopixels, unsigned int ms_since_animation_start, const Ring_t& base_color) {
    return pixel_interpolation(neopixels, base_color[pixel_index], (*ring_)[pixel_index], float(ms_since_animation_start) / float(ms_));
}
