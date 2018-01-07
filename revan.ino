// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif


#include "ring.hpp"
#include "neopixel.hpp"
#include "animator.hpp"
#include "animation-cycle.hpp"
#include "animation-random-cycle.hpp"
#include "ring-presets.hpp"


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  randomSeed(analogRead(0));
  Neopixels::instance.begin(); // This initializes the NeoPixel library.
  RingPresets::instance().init(Neopixels::instance);
}


void loop() {
  Animator animator(Neopixels::instance, 1000);

  //AnimationCycle cycle;
  //cycle.start_from(RingPresets::instance().blue_red())
  //  .wait(random(2000, 6000))
  //  .fade_to(RingPresets::instance().red(), random(4000, 10000))
  //  .wait(random(2000, 6000))
  //  .flicker_to(RingPresets::instance().blue())
  //  .wait(random(3000, 4000))
  //  .fade_to(RingPresets::instance().blue_red(), random(1000, 10000))
  //  .wait(random(2000, 6000))
  //  .fade_to(RingPresets::instance().blue(), random(4000, 10000))
  //  .wait(random(2000, 6000))
  //  .fade_to(RingPresets::instance().blue_red(), random(1000, 10000));
  AnimationRandomCycle cycle;

  animator.start(cycle);
}


