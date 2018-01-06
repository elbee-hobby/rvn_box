#pragma once

#include <Adafruit_NeoPixel.h>

static const uint8_t MaxBrightness = 255;

struct Pixel {
    static const uint32_t Dark;
    static const uint32_t Blue;
    static const uint32_t Red;
    static const uint32_t Purple;
};

// Returns the Red component of a 32-bit color
inline uint8_t red(uint32_t color)
{
    return (color >> 16) & 0xFF;
}

// Returns the Green component of a 32-bit color
inline uint8_t green(uint32_t color)
{
    return (color >> 8) & 0xFF;
}

// Returns the Blue component of a 32-bit color
inline uint8_t blue(uint32_t color)
{
    return color & 0xFF;
}