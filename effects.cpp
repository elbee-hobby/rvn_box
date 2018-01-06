#include "effects.hpp"
#include "colors.hpp"

static uint8_t component_interpolation(uint8_t start, uint8_t end, uint8_t percent) {
  return start + ((end - start) * percent) / 100;
}


static uint32_t pixel_interpolation(Adafruit_NeoPixel& neopixels, uint32_t start, uint32_t end, uint8_t percent) {
  return neopixels.Color(
    component_interpolation(red(start), red(end), percent),
    component_interpolation(green(start), green(end), percent),
    component_interpolation(blue(start), blue(end), percent),
    0);
}

Effects::Effects(Adafruit_NeoPixel& pixels, const Ring_t& ring) {
    display(ring, 0);
}

static void display_colors(Adafruit_NeoPixel& neopixels, const Ring_t& ring) {
    for (uint8_t i = 0; i < neopixels.numPixels(); ++i) {
      neopixels.setPixelColor(i, ring[i]);
    }
    neopixels.show();
}

Effects& Effects::display(const Ring_t& ring, int time) {
    display_colors(neopixels, ring);
    current_ring = &ring;
    delay(time);
    return *this;
}

Effects& Effects::rotate(uint8_t rotations, int dt) {
    for (uint8_t offset = 0; offset < neopixels.numPixels() * rotations; ++offset) {
      for (uint8_t i = 0; i < neopixels.numPixels(); ++i){
          neopixels.setPixelColor(i, (*current_ring)[(i + offset) % neopixels.numPixels()]);
      }

      neopixels.show();
      delay(dt);
    }
    return *this;
}

Effects& Effects::fade(const Ring_t& end_ring, int dt) {
    for (uint8_t percent = 0; percent < 100; ++percent) {
      for (uint8_t i = 0; i < neopixels.numPixels(); ++i){
        neopixels.setPixelColor(i, pixel_interpolation(neopixels, (*current_ring)[i], end_ring[i], percent));
        neopixels.setPixelColor(i, pixel_interpolation(neopixels, (*current_ring)[i], end_ring[i], percent));
      }
      neopixels.show();
      delay(dt);
    }
    current_ring = &end_ring;
    return *this;
}

Effects& Effects::flash(const Ring_t& flash_ring,
       uint8_t min_flash_count, uint8_t max_flash_count,
       int min_flash_delay, int max_flash_delay)
{
    uint8_t count = random(min_flash_count, max_flash_count + 1);
    for (uint8_t i = 0; i < count; ++i) {
        display_colors(neopixels, flash_ring);
        delay(random(30, 101));
        display_colors(neopixels, *current_ring);
        delay(random(min_flash_delay, max_flash_count + 1));
    }
           
    return *this;
}

Effects& Effects::pause(int dt) {
    delay(dt);
    return *this;
}