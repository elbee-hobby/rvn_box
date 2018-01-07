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
#include "ring-presets.hpp"

RingPresets presets;

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  randomSeed(analogRead(0));
  Neopixels::instance.begin(); // This initializes the NeoPixel library.
  presets.init(Neopixels::instance);
}


void loop() {

  AnimationCycle cycle(Neopixels::instance, 60);
  cycle.build_from(presets.blue_red())
    .wait(1000)
    .set_color(presets.red())
    .wait(1000);

  while (true) {
    cycle.start();
  }
}


