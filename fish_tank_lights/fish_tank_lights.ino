#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 21

#define NUM_OF_PIXELS 600

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
int SEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 };
int EIGHTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 70, 71, 72, 73, 74, 75, 76, 77, 78, 79 };
int NINTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 };
int TENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };
int ELEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
int TWELVTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
int THIRTEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 120, 121, 122, 123, 124, 125, 126, 127, 128, 129 };
int FOURTEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 130, 131, 132, 133, 134, 135, 136, 137, 138, 139 };
int FIFTEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 140, 141, 142, 143, 144, 145, 146, 147, 148, 149 };
int SIXTEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 150, 151, 152, 153, 154, 155, 156, 157, 158, 159 };
int SEVENTEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 160, 161, 162, 163, 164, 165, 166, 167, 168, 169 };
int EIGHTEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 170, 171, 172, 173, 174, 175, 176, 177, 178, 179 };
int NINETEENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 180, 181, 182, 183, 184, 185, 186, 187, 188, 189 };
int TWENTIETH_ROW[NUM_OF_PIXELS_PER_ROW] = { 190, 191, 192, 193, 194, 195, 196, 197, 198, 199 };
int TWENTYFIRST_ROW[NUM_OF_PIXELS_PER_ROW] = { 200, 201, 202, 203, 204, 205, 206, 207, 208, 209 };
int TWENTYSECOND_ROW[NUM_OF_PIXELS_PER_ROW] = { 210, 211, 212, 213, 214, 215, 216, 217, 218, 219 };
int TWENTYTHIRD_ROW[NUM_OF_PIXELS_PER_ROW] = { 220, 221, 222, 223, 224, 225, 226, 227, 228, 229 };
int TWENTYFOURTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 230, 231, 232, 233, 234, 235, 236, 237, 238, 239 };
int TWENTYFIFTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 240, 241, 242, 243, 244, 245, 246, 247, 248, 249 };
int TWENTYSIXTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 250, 251, 252, 253, 254, 255, 256, 257, 258, 259 };
int TWENTYSEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 260, 261, 262, 263, 264, 265, 266, 267, 268, 269 };
int TWENTYEIGHTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 270, 271, 272, 273, 274, 275, 276, 277, 278, 279 };
int TWENTYNINTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 280, 281, 282, 283, 284, 285, 286, 287, 288, 289 };
int THIRTIETH_ROW[NUM_OF_PIXELS_PER_ROW] = { 290, 291, 292, 293, 294, 295, 296, 297, 298, 299 };
int THIRTYFIRST_ROW[NUM_OF_PIXELS_PER_ROW] = { 300, 301, 302, 303, 304, 305, 306, 307, 308, 309 };
int THIRTYSECOND_ROW[NUM_OF_PIXELS_PER_ROW] = { 310, 311, 312, 313, 314, 315, 316, 317, 318, 319 };
int THIRTYTHIRD_ROW[NUM_OF_PIXELS_PER_ROW] = { 320, 321, 322, 323, 324, 325, 326, 327, 328, 329 };
int THIRTYFOURTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 330, 331, 332, 333, 334, 335, 336, 337, 338, 339 };
int THIRTYFIFTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 340, 341, 342, 343, 344, 345, 346, 347, 348, 349 };
int THIRTYSIXTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 350, 351, 352, 353, 354, 355, 356, 357, 358, 359 };
int THIRTYSEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 360, 361, 362, 363, 364, 365, 366, 367, 368, 369 };
int THIRTYEIGHTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 370, 371, 372, 373, 374, 375, 376, 377, 378, 379 };
int THIRTYNINTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 380, 381, 382, 383, 384, 385, 386, 387, 388, 389 };
int FORTIETH_ROW[NUM_OF_PIXELS_PER_ROW] = { 390, 391, 392, 393, 394, 395, 396, 397, 398, 399 };
int FORTYFIRST_ROW[NUM_OF_PIXELS_PER_ROW] = { 400, 401, 402, 403, 404, 405, 406, 407, 408, 409 };
int FORTYSECOND_ROW[NUM_OF_PIXELS_PER_ROW] = { 410, 411, 412, 413, 414, 415, 416, 417, 418, 419 };
int FORTYTHIRD_ROW[NUM_OF_PIXELS_PER_ROW] = { 420, 421, 422, 423, 424, 425, 426, 427, 428, 429 };
int FORTYFOURTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 430, 431, 432, 433, 434, 435, 436, 437, 438, 439 };
int FORTYFIFTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 440, 441, 442, 443, 444, 445, 446, 447, 448, 449 };
int FORTYSIXTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 450, 451, 452, 453, 454, 455, 456, 457, 458, 459 };
int FORTYSEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 460, 461, 462, 463, 464, 465, 466, 467, 468, 469 };
int FORTYEIGHTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 470, 471, 472, 473, 474, 475, 476, 477, 478, 479 };
int FORTYNINTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 480, 481, 482, 483, 484, 485, 486, 487, 488, 489 };
int FIFTIETH_ROW[NUM_OF_PIXELS_PER_ROW] = { 490, 491, 492, 493, 494, 495, 496, 497, 498, 499 };
int FIFTYFIRST_ROW[NUM_OF_PIXELS_PER_ROW] = { 500, 501, 502, 503, 504, 505, 506, 507, 508, 509 };
int FIFTYSECOND_ROW[NUM_OF_PIXELS_PER_ROW] = { 510, 511, 512, 513, 514, 515, 516, 517, 518, 519 };
int FIFTYTHIRD_ROW[NUM_OF_PIXELS_PER_ROW] = { 520, 521, 522, 523, 524, 525, 526, 527, 528, 529 };
int FIFTYFOURTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 530, 531, 532, 533, 534, 535, 536, 537, 538, 539 };
int FIFTYFIFTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 540, 541, 542, 543, 544, 545, 546, 547, 548, 549 };
int FIFTYSIXTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 550, 551, 552, 553, 554, 555, 556, 557, 558, 559 };
int FIFTYSEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 560, 561, 562, 563, 564, 565, 566, 567, 568, 569 };
int FIFTYEIGHTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 570, 571, 572, 573, 574, 575, 576, 577, 578, 579 };
int FIFTYNINTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 580, 581, 582, 583, 584, 585, 586, 587, 588, 589 };
int SIXTIETH_ROW[NUM_OF_PIXELS_PER_ROW] = { 590, 591, 592, 593, 594, 595, 596, 597, 598, 599 };



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
  set_entire_strip_color(1, PURE_WHITE);
  //set_single_pixel(0);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  set_entire_strip_color(1, GREEN);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  set_entire_strip_color(1, BLUE);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  rainbow_chase(100);
  set_entire_strip_color(1, RED);
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
     strip.setPixelColor(SEVENTH_ROW[COUNTER], RED);
     strip.setPixelColor(EIGHTH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(NINTH_ROW[COUNTER], YELLOW);
     strip.setPixelColor(TENTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(ELEVENTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(TWELVTH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(THIRTEENTH_ROW[COUNTER], RED);
     strip.setPixelColor(FOURTEENTH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(FIFTEENTH_ROW[COUNTER], YELLOW);
     strip.setPixelColor(SIXTEENTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(SEVENTEENTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(EIGHTEENTH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(NINETEENTH_ROW[COUNTER], RED);
     strip.setPixelColor(TWENTIETH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(TWENTYFIRST_ROW[COUNTER], YELLOW);
     strip.setPixelColor(TWENTYSECOND_ROW[COUNTER], GREEN);
     strip.setPixelColor(TWENTYTHIRD_ROW[COUNTER], BLUE);
     strip.setPixelColor(TWENTYFOURTH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(TWENTYFIFTH_ROW[COUNTER], RED);
     strip.setPixelColor(TWENTYSIXTH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(TWENTYSEVENTH_ROW[COUNTER], YELLOW);
     strip.setPixelColor(TWENTYEIGHTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(TWENTYNINTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(THIRTIETH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(THIRTYFIRST_ROW[COUNTER], RED);
     strip.setPixelColor(THIRTYSECOND_ROW[COUNTER], ORANGE);
     strip.setPixelColor(THIRTYTHIRD_ROW[COUNTER], YELLOW);
     strip.setPixelColor(THIRTYFOURTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(THIRTYFIFTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(THIRTYSIXTH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(THIRTYSEVENTH_ROW[COUNTER], RED);
     strip.setPixelColor(THIRTYEIGHTH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(THIRTYNINTH_ROW[COUNTER], YELLOW);
     strip.setPixelColor(FORTIETH_ROW[COUNTER], GREEN);
     strip.setPixelColor(FORTYFIRST_ROW[COUNTER], BLUE);
     strip.setPixelColor(FORTYSECOND_ROW[COUNTER], INDIGO);
     strip.setPixelColor(FORTYTHIRD_ROW[COUNTER], RED);
     strip.setPixelColor(FORTYFOURTH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(FORTYFIFTH_ROW[COUNTER], YELLOW);
     strip.setPixelColor(FORTYSIXTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(FORTYSEVENTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(FORTYEIGHTH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(FORTYNINTH_ROW[COUNTER], RED);
     strip.setPixelColor(FIFTIETH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(FIFTYFIRST_ROW[COUNTER], YELLOW);
     strip.setPixelColor(FIFTYSECOND_ROW[COUNTER], GREEN);
     strip.setPixelColor(FIFTYTHIRD_ROW[COUNTER], BLUE);
     strip.setPixelColor(FIFTYFOURTH_ROW[COUNTER], INDIGO);
     strip.setPixelColor(FIFTYFIFTH_ROW[COUNTER], RED);
     strip.setPixelColor(FIFTYSIXTH_ROW[COUNTER], ORANGE);
     strip.setPixelColor(FIFTYSEVENTH_ROW[COUNTER], YELLOW);
     strip.setPixelColor(FIFTYEIGHTH_ROW[COUNTER], GREEN);
     strip.setPixelColor(FIFTYNINTH_ROW[COUNTER], BLUE);
     strip.setPixelColor(SIXTIETH_ROW[COUNTER], INDIGO);




     if (COUNTER>0)
     {
        strip.fill(OFF, FIRST_ROW[0], COUNTER);
        strip.fill(OFF, SECOND_ROW[0], COUNTER);
        strip.fill(OFF, THIRD_ROW[0], COUNTER);
        strip.fill(OFF, FOURTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTH_ROW[0], COUNTER);
        strip.fill(OFF, SIXTH_ROW[0], COUNTER);
        strip.fill(OFF, SEVENTH_ROW[0], COUNTER);
        strip.fill(OFF, EIGHTH_ROW[0], COUNTER);
        strip.fill(OFF, NINTH_ROW[0], COUNTER);
        strip.fill(OFF, TENTH_ROW[0], COUNTER);
        strip.fill(OFF, ELEVENTH_ROW[0], COUNTER);
        strip.fill(OFF, TWELVTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTEENTH_ROW[0], COUNTER);
        strip.fill(OFF, FOURTEENTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTEENTH_ROW[0], COUNTER);
        strip.fill(OFF, SIXTEENTH_ROW[0], COUNTER);
        strip.fill(OFF, SEVENTEENTH_ROW[0], COUNTER);
        strip.fill(OFF, EIGHTEENTH_ROW[0], COUNTER);
        strip.fill(OFF, NINETEENTH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTIETH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYFIRST_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYSECOND_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYTHIRD_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYFOURTH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYFIFTH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYSIXTH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYSEVENTH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYEIGHTH_ROW[0], COUNTER);
        strip.fill(OFF, TWENTYNINTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTIETH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYFIRST_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYSECOND_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYTHIRD_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYFOURTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYFIFTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYSIXTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYSEVENTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYEIGHTH_ROW[0], COUNTER);
        strip.fill(OFF, THIRTYNINTH_ROW[0], COUNTER);
        strip.fill(OFF, FORTIETH_ROW[0], COUNTER);
        strip.fill(OFF, FORTYFIRST_ROW[0], COUNTER);
        strip.fill(OFF, FORTYSECOND_ROW[0], COUNTER);
        strip.fill(OFF, FORTYTHIRD_ROW[0], COUNTER);
        strip.fill(OFF, FORTYFOURTH_ROW[0], COUNTER);
        strip.fill(OFF, FORTYFIFTH_ROW[0], COUNTER);
        strip.fill(OFF, FORTYSIXTH_ROW[0], COUNTER);
        strip.fill(OFF, FORTYSEVENTH_ROW[0], COUNTER);
        strip.fill(OFF, FORTYEIGHTH_ROW[0], COUNTER);
        strip.fill(OFF, FORTYNINTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTIETH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYFIRST_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYSECOND_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYTHIRD_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYFOURTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYFIFTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYSIXTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYSEVENTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYEIGHTH_ROW[0], COUNTER);
        strip.fill(OFF, FIFTYNINTH_ROW[0], COUNTER);
        strip.fill(OFF, SIXTIETH_ROW[0], COUNTER);


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

void set_entire_strip_color(int wait, uint32_t stripcolor)
{
  for(int i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, stripcolor);   
    strip.show();
    delay(wait);
  }
}
