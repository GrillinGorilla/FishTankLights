// Fish Tank Lights
// This code controls 8 rows of 85 pixels (680 total) and serves as a lighting fixture for a 200 gallon aquarium.
// There are also 4 additional LEDs on a separate data pin used to illuminate the XBOX360 power button.
// This solution offers an asynchronous web page GUI to control the LEDs.

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin will output data?
#define LED_PIN     21

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  682

// How many LEDs (pixels) per row? 
#define NUM_OF_PIXELS_PER_ROW 85

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50  // Set BRIGHTNESS to about 1/5 (max = 255)

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

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
// Define Some Colors
uint32_t OFF = strip.Color(0,0,0,0);
uint32_t RED = strip.Color(255,0,0,0);
uint32_t ORANGE = strip.Color(255,165,0,0);
uint32_t YELLOW = strip.Color(255,255,0,0);
uint32_t GREEN = strip.Color(0,255,0,0);
uint32_t BLUE = strip.Color(0,0,255,0);
uint32_t INDIGO = strip.Color(75,0,130,0);
uint32_t VIOLET = strip.Color(238,130,238,0);
uint32_t PURPLE = strip.Color(255,0,255,0);
uint32_t RGB_WHITE = strip.Color(255,255,255,0);
uint32_t PURE_WHITE = strip.Color(0,0,0,255);
uint32_t MAGENTA = strip.Color(255,0,255,0);
uint32_t TEAL = strip.Color(0,128,128,0);
uint32_t GREENISH_WHITE = strip.Color(0,64,0,64);
uint32_t PINK = strip.Color(255,26,102,0);
uint32_t BROWN = strip.Color(150,75,0,0);
uint32_t SWEDISH_FLAG_BLUE = strip.Color(0,106,169,0);
uint32_t SWEDISH_FLAG_YELLOW = strip.Color(254,205,0,0);

//#########################################
// Define Color Arrays
int RAINBOW[7] = { RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET };

//#########################################
// Define Row  Arrays
int FIRST_ROW[NUM_OF_PIXELS_PER_ROW] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86 };
int SECOND_ROW[NUM_OF_PIXELS_PER_ROW] = { 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87 };
int THIRD_ROW[NUM_OF_PIXELS_PER_ROW] = { 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256 };
int FOURTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331, 330, 329, 328, 327, 326, 325, 324, 323, 322, 321, 320, 319, 318, 317, 316, 315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 303, 302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257};
int FIFTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426 };
int SIXTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 511, 510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496, 495, 494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, 482, 481, 480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, 466, 465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, 452, 451, 450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436, 435, 434, 433, 432, 431, 430, 429, 428, 427 };
int SEVENTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 512, 513, 514, 515, 516, 517, 518, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596 };
int EIGHTH_ROW[NUM_OF_PIXELS_PER_ROW] = { 681, 680, 679, 678, 677, 676, 675, 674, 673, 672, 671, 670, 669, 668, 667, 666, 665, 664, 663, 662, 661, 660, 659, 658, 657, 656, 655, 654, 653, 652, 651, 650, 649, 648, 647, 646, 645, 644, 643, 642, 641, 640, 639, 638, 637, 636, 635, 634, 633, 632, 631, 630, 629, 628, 627, 626, 625, 624, 623, 622, 621, 620, 619, 618, 617, 616, 615, 614, 613, 612, 611, 610, 609, 608, 607, 606, 605, 604, 603, 602, 601, 600, 599, 598, 597 };

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "removed";
const char* password = "removed";

// Define some variables
String PARAM_INPUT_1 = "output";
String PARAM_INPUT_2 = "redval";
String PARAM_INPUT_3 = "greenval";
String PARAM_INPUT_4 = "blueval";
String PARAM_INPUT_5 = "whiteval";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>Fish Tank Lights</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    html {font-family: Arial; display: inline-block; text-align: center;}
    h2 {font-size: 3.0rem;}
    h3 {line-height: 1.0rem;}
    p {margin: 3px;}
    body {margin:0px auto; padding-bottom: 25px; background-color: #f2f2f2;}
    .button {background-color: #4CAF50; border: none; border-radius: 5px; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 5px; cursor: pointer;}
    .button2 {background-color: #555555;}
    .custom_tile {width: 220px; background-color: #4CAF50; color: #ffffff; padding: 10px 10px 10px 10px; border-radius: 5px; text-align:left; margin: 5px;}
    .custom_button {background-color: #ffffff; border: none; border-radius: 5px; color: 4CAF50; padding: 8px 20px; text-decoration: none; cursor: pointer;}
    .custom_text_box {text-align: center; width: 90px; padding: 1px;}
    .custom_label {margin-right: 5px; width: 100px;}
  </style>
</head>
<body>
  <h2>Fish Tank Lights</h2>
  <input type='button' id='off' value='Off' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='ultra_low_bright' value='Ultra Low Brightness' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='low_bright' value='Low Brightness' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='med_bright' value='Medium Brightness' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='high_bright' value='High Brightness' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='ultra_high_bright' value='Ultra High Brightness' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='rainbow' value='Rainbow' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='red_wipe' value='Red Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='blue_wipe' value='Blue Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='green_wipe' value='Green Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='pink_wipe' value='Pink Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='violet_wipe' value='Violet Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='rgb_white_wipe' value='RGB White Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='pure_white_wipe' value='Pure White Wipe' class='button' onclick='runColorFunction(this)'>
  <input type='button' id='rainbow_chase' value='Rainbow Chase' class='button' onclick='runColorFunction(this)'>
  <div class='custom_tile'>
    <h3>Custom Color Builder</h3>
    <p><span class='custom_label'>Red Value:</span><input type='text' id='red_value' name='red_value' placeholder='Enter 0-255' class='custom_text_box'></p>
    <p><span class='custom_label'>Green Value:</span><input type='text' id='green_value' name='green_value' placeholder='Enter 0-255' class='custom_text_box'></p>
    <p><span class='custom_label'>Blue Value:</span><input type='text' id='blue_value' name='blue_value' placeholder='Enter 0-255' class='custom_text_box'></p>
    <p><span class='custom_label'>White Value:</span><input type='text' id='white_value' name='white_value' placeholder='Enter 0-255' class='custom_text_box'></p>
    <input type='button' id='custom_color_button' value='Build Color' class='custom_button' onclick='buildCustomColor()'>
  </div>
<script>
  function runColorFunction(element) 
  {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/update?output="+element.id, true);
    xhr.send();
  }

  function buildCustomColor()
  {
    var redval = document.getElementById("red_value").value
    var greenval = document.getElementById("green_value").value
    var blueval = document.getElementById("blue_value").value
    var whiteval = document.getElementById("white_value").value
    
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/update?output="+element.id+"&redval="+redval+"&greenval="+greenval+"&blueval="+blueval+"&whiteval="+whiteval, true);
    xhr.send();
  }
</script>
</body>
</html>
)rawliteral";

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  // turn xbox power leds on
  turn_power_button_leds_on();
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  // Route for building custom colors
  //    xhr.open("GET", "/update?output="+element.id+"&redval="+redval+"&greenval="+greenval+"&blueval="+blueval+"&whiteval="+whiteval
  server.on("/custom", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
    
    String inputMessage1;
    String valred;
    String valgreen;
    String valblue;
    String valwhite;

    inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
    valred = request->getParam(PARAM_INPUT_2)->value();
    valgreen = request->getParam(PARAM_INPUT_3)->value();
    valblue = request->getParam(PARAM_INPUT_4)->value();
    valwhite = request->getParam(PARAM_INPUT_5)->value();
    
    uint32_t CUSTOM_COLOR = strip.Color(valred.toInt(),valgreen.toInt(),valblue.toInt(),valwhite.toInt());

    set_entire_strip_color(20, CUSTOM_COLOR);
    
  });

  // Route for recieving built-in functions
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request){
    String inputMessage1;
    if (request->hasParam(PARAM_INPUT_1)) 
    {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      
      if (inputMessage1 == "off")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, OFF);
      }
      
      if (inputMessage1 == "ultra_low_bright")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        strip.setBrightness(25);
        strip.show();
      }
      
      if (inputMessage1 == "low_bright")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        strip.setBrightness(50);
        strip.show();
      }
      
      if (inputMessage1 == "med_bright")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        strip.setBrightness(100);
        strip.show();
      }
      
      if (inputMessage1 == "high_bright")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        strip.setBrightness(200);
        strip.show();
      }
      
      if (inputMessage1 == "ultra_high_bright")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        strip.setBrightness(255);
        strip.show();
      }
      
      if (inputMessage1 == "rainbow")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        rainbowCycle(1);
      }
      
      if (inputMessage1 == "red_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, RED);
      }
      
      if (inputMessage1 == "blue_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, BLUE);
      }
      
      if (inputMessage1 == "green_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, GREEN);
      }
      
      if (inputMessage1 == "pink_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, PINK);
      }
      
      if (inputMessage1 == "violet_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, VIOLET);
      }
      
      if (inputMessage1 == "rgb_white_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, RGB_WHITE);
      }
      
      if (inputMessage1 == "pure_white_wipe")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        all_column_wipe_with_color(20, PURE_WHITE);
      }
      
      if (inputMessage1 == "rainbow_chase")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        rainbow_chase(20);
      }
      
    }
    else 
    {
      inputMessage1 = "No message sent";
    }
    
    request->send(200, "text/plain", "OK");
  });
  
  // Start server
  server.begin();

  // Run these functions to indicate website is ready
  rainbow_chase(1);
  rainbow_chase(1);
}

void loop() {

}

//##################################################
// Start of supporting functions

void turn_power_button_leds_on()
{
  strip.clear();
  strip.fill(GREEN, 0, 2);
  strip.show();
}

// All columns wipe
void all_column_wipe_with_color(int wait, uint32_t color)
{
  // turn xbox power leds on
  turn_power_button_leds_on();

  // start of function
  int COUNTER = 0;
  while(COUNTER<=84)
  {

    // Set strip settings for this iteration of loop
    strip.setPixelColor(FIRST_ROW[COUNTER], color);
    strip.setPixelColor(SECOND_ROW[COUNTER], color);
    strip.setPixelColor(THIRD_ROW[COUNTER], color);
    strip.setPixelColor(FOURTH_ROW[COUNTER], color);
    strip.setPixelColor(FIFTH_ROW[COUNTER], color);
    strip.setPixelColor(SIXTH_ROW[COUNTER], color);
    strip.setPixelColor(SEVENTH_ROW[COUNTER], color);
    strip.setPixelColor(EIGHTH_ROW[COUNTER], color);

    strip.show();
    delay(wait); 
    COUNTER++;
  }
}

void rainbow_chase(int wait)
{
  // turn xbox power leds on
  turn_power_button_leds_on();

  // start of function
  int COUNTER = 0;
  while(COUNTER<=84)
  {
    // Clear strip settings
    strip.clear();

    // Set strip settings for this iteration of loop
    strip.setPixelColor(FIRST_ROW[COUNTER], RED);
    strip.setPixelColor(SECOND_ROW[COUNTER], ORANGE);
    strip.setPixelColor(THIRD_ROW[COUNTER], YELLOW);
    strip.setPixelColor(FOURTH_ROW[COUNTER], GREEN);
    strip.setPixelColor(FIFTH_ROW[COUNTER], BLUE);
    strip.setPixelColor(SIXTH_ROW[COUNTER], VIOLET);
    strip.setPixelColor(SEVENTH_ROW[COUNTER], PINK);
    strip.setPixelColor(EIGHTH_ROW[COUNTER], RED);

    strip.show();
    delay(wait); 
    COUNTER++;
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) 
{
  // turn xbox power leds on
  turn_power_button_leds_on();

  // start of function
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
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

void set_entire_strip_color_dynamic(int wait, uint32_t redAmt, uint32_t greenAmt, uint32_t blueAmt, uint32_t whiteAmt)
{
  // turn xbox power leds on
  turn_power_button_leds_on();

  // start of function
  for(int i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, redAmt, greenAmt, blueAmt, whiteAmt);   
    strip.show();
    delay(wait);
  }
}

void instant_entire_strip_color(uint32_t stripcolor)
{
  strip.fill(stripcolor, 0, strip.numPixels());
  strip.show();
}

void color_chase(int wait, uint32_t stripcolor)
{
  for(int i=0; i<strip.numPixels(); i++) 
  {
    strip.fill(stripcolor, i, 3);  
    strip.fill(OFF, 0, i);
    strip.show();
    delay(wait);
  }
}

void color_chase_reverse(int wait, uint32_t stripcolor)
{
  for(int i=strip.numPixels(); i>(0-3); i--) 
  {
    strip.fill(OFF, 0, strip.numPixels());
    strip.fill(stripcolor, i, 3);  
    strip.show();
    delay(wait);
  }
}

void bounce_fill_two_colors(int wait, uint32_t stripcolor, uint32_t stripcolortwo)
{
  for(int i=1; i<strip.numPixels(); i++) 
  {
    strip.fill(stripcolortwo, 0, strip.numPixels());  
    if (i!=0) 
    {
      strip.fill(stripcolor, 0, i); 
    }    
    
    strip.show();
    delay(wait);
  }
  
  for(int i=strip.numPixels(); i>0; i--) 
  {
    strip.fill(stripcolortwo, 0, strip.numPixels());  
    strip.fill(stripcolor, 0, i);
    strip.show();
    delay(wait);
  }
}

void swedish_party(int loops)
{
  for(int i=0; i<loops;i++)
  {
    instant_entire_strip_color(SWEDISH_FLAG_BLUE);
    delay(100);
    instant_entire_strip_color(SWEDISH_FLAG_YELLOW);
    delay(100);
  }
}
