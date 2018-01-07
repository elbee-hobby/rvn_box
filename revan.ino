// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#include "effects.hpp"
#include "ring.hpp"
#include "neopixel.hpp"
#include "animation-cycle.hpp"



struct Pixel {
    static const uint32_t Dark;
    static const uint32_t Blue;
    static const uint32_t Red;
    static const uint32_t Purple;
};

struct Ring {
    static const Ring_t BlueRed;
    static const Ring_t Blue;
    static const Ring_t Red;
    static const Ring_t Purple;
    static const Ring_t Dark;
};

const uint32_t Pixel::Dark = 0;

const uint32_t Pixel::Blue = Neopixels::instance.Color(0, 0, 0, MaxBrightness);

const uint32_t Pixel::Red = Neopixels::instance.Color(0, 0, MaxBrightness, 0);

const uint32_t Pixel::Purple = Neopixels::instance.Color(
    MaxBrightness / 6,
    0, 
    MaxBrightness / 2, 
    0);

#if NUMPIXELS == 16
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

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  randomSeed(analogRead(0));
  Neopixels::instance.begin(); // This initializes the NeoPixel library.
}


void loop() {

  AnimationCycle cycle(Neopixels::instance, 60);
  cycle.set_up(Ring::Red)
    .then(new Wait(1000))
    .then(new StaticRing(Ring::Blue))
    .then(new Wait(1000));
  while (true) {
    cycle.start();
  }
}


