#pragma once

#include <Adafruit_NeoPixel.h>

static const uint8_t MaxBrightness = 255;

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