#include "colors.hpp"
#include "neopixel.hpp"


const uint32_t Pixel::Dark = 0;

const uint32_t Pixel::Blue = Neopixels::instance.Color(0, 0, MaxBrightness, 0);

const uint32_t Pixel::Red = Neopixels::instance.Color(MaxBrightness, 0, 0, 0);

const uint32_t Pixel::Purple = Neopixels::instance.Color(
    MaxBrightness / 6,
    0, 
    MaxBrightness / 2, 
    0);