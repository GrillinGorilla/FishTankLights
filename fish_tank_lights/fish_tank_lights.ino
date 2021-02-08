#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 21

#define NUM_OF_PIXELS 300

#define NUM_OF_PIXELS_PER_ROW 10

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_OF_PIXELS, PIN, NEO_GRBW + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

//#########################################
// Define Colors
uint32_t OFF = strip.Color(0,0,0,0);
uint32_t RED = strip.Color(255,0,0,0);
uint32_t ORANGE = strip.Color(255,165,0,0);
uint32_t YELLOW = strip.Color(255,255,0,0);
uint32_t GREEN = strip.Color(0,255,0,0);
uint32_t BLUE = strip.Color(0,0,255,0);
uint32_t INDIGO = strip.Color(75,0,130,0);
uint32_t VIOLET = strip.Color(238,130,238,0);
uint32_t RGB_WHITE = strip.Color(255,255,255,0);
uint32_t PURE_WHITE = strip.Color(0,0,0,255);
uint32_t MAGENTA = strip.Color(255,0,255,0);
uint32_t TEAL = strip.Color(0,128,128,0);
uint32_t GREENISH_WHITE = strip.Color(0,64,0,64);
uint32_t PINK = strip.Color(255,26,102,0);

//#########################################
// Define Color Arrays
int RAINBOW[7] = { RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET };

//#########################################
// Define Row  Arrays
int FIRST_ROW[NUM_OF_PIXELS_PER_ROW] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int SECOND_ROW[NUM_OF_PIXELS_PER_ROW] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
int THIRD_ROW[NUM_OF_PIXELS_PER_ROW] = { 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 };
int FOURTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 };
int FIFTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 };
int SIXTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 };

//#########################################
// Define Wheel
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

//#########################################
// Setup

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
}

//#########################################
// Loop

void loop() {
  // put your main code here, to run repeatedly:
  //set_entire_strip_color(10);
  //set_single_pixel(0);
  rainbow_chase(100);
  //bright_sunny_day_no_clouds();
}


//###########################################################
// Support functions

void bright_sunny_day_no_clouds()
{
  strip.setBrightness(200);
  strip.fill(RGB_WHITE, 0, NUM_OF_PIXELS);
  strip.show();
}

void rainbow_chase(int wait)
{
  int COUNTER = 0;
  while(COUNTER<10)
  {
     strip.setPixelColor(FIRST_ROW[COUNTER], RED);
     strip.setPixelColor(SECOND_ROW[COUNTER], ORANGE);
     strip.setPixelColor(THIRD_ROW[COUNTER], YELLOW);
     strip.setPixelColor(FOURTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(FIFTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(SIXTH_ROW[COUNTER], INDIGO);

     if (COUNTER>0)
     {
        strip.fill(OFF, FIRST_ROW[0], COUNTER);
        strip.fill(OFF, SECOND_ROW[0], COUNTER);
        strip.fill(OFF, THIRD_ROW[0], COUNTER);
        strip.fill(OFF, FOURTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTH_ROW[0], COUNTER);
        strip.fill(OFF, SIXTH_ROW[0], COUNTER);
     }


     
     strip.show();
     delay(wait); 
     COUNTER++;
  }
  strip.clear();
}

void set_single_pixel(int pixel)
{
  strip.setPixelColor(pixel, RED);
  strip.show();
}

void set_entire_strip_color(int wait)
{
  for(int i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, RED);   
    strip.show();
    delay(wait);
  }
}
