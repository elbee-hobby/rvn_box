// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "effects.hpp"
#include "ring.hpp"
#include "neopixel.hpp"


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
  Effects effects(Neopixels::instance, Ring::Red);
  while (true) {
      // .flash(Ring::Blue, 2, 4, 100, 300)
      // .display(BlueRing).pause(2000)
      // .fade(Ring::Red, 20).pause(2000)
      // .fade(Ring::Blue, 20).pause(2000)
      // .fade(Ring::BlueRed, 20)
      // .rotate(3, 120)
      // .fade(Ring::Purple, 20);
  }
}


