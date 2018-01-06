#include "ring.hpp"
#include "colors.hpp"

#if NUMPIXELS == 16

struct Pixel {
    static const uint32_t Dark;
    static const uint32_t Blue;
    static const uint32_t Red;
    static const uint32_t Purple;
};

const uint32_t Pixel::Dark = 0;

const uint32_t Pixel::Blue = Neopixels::instance.Color(0, 0, MaxBrightness, 0);

const uint32_t Pixel::Red = Neopixels::instance.Color(MaxBrightness, 0, 0, 0);

const uint32_t Pixel::Purple = Neopixels::instance.Color(
    MaxBrightness / 6,
    0, 
    MaxBrightness / 2, 
    0);

const Ring_t Ring::BlueRed = {
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Dark
};

const Ring_t Ring::Blue = {
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue,
    Pixel::Blue
};

const Ring_t Ring::Red = {
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red,
    Pixel::Red
};


const Ring_t Ring::Purple = {
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple,
    Pixel::Purple
};


const Ring_t Ring::Dark = {
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark,
    Pixel::Dark
};

#endif