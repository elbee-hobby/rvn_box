#include "ring-presets.hpp"
#include "colors.hpp"

RingPresets::init(Adafruit_NeoPixel& neopixels) {
    const uint32_t dark_pixel = 0;
    const uint32_t blue_pixel = neopixels.Color(0, 0, MaxBrightness, 0);
    const uint32_t red_pixel = neopixels.Color(MaxBrightness, 0, 0);
    const uint32_t purple_pixel = neopixels.Color(
        MaxBrightness / 4,
        0, 
        MaxBrightness / 2, 
        0);

    for (int i = 0; i < neopixels.numPixels(); ++i) {
        red_[i] = red_pixel;
        blue_[i] = blue_pixel;
        purple_[i] = purple_pixel;
        dark_[i] = dark_pixel;

        blue_red_[i] = i % 8 < 2 ? dark_pixel : i >= neopixels.numPixels() / 2 ? red_pixel : blue_pixel;
    }

}

const Ring_t& RingPresets::blue_red() {
    return blue_red_;
}

const Ring_t& RingPresets::blue() {
    return blue_;
}

const Ring_t& RingPresets::red() {
    return red_;
}

const Ring_t& RingPresets::purple() {
    return purple_;
}

const Ring_t& RingPresets::dark() {
    return dark_;
}

