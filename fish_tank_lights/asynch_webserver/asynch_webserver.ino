
/*********
From Neopixel RGBWstrandtest
*********/

// NeoPixel test program showing use of the WHITE channel for RGBW
// pixels only (won't look correct on regular RGB NeoPixel strips).

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     21

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  39

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
// Define Colors
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

/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-async-web-server-espasyncwebserver-library/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "RedMonkeys24";
const char* password = "honeychicken";

String PARAM_INPUT_1 = "output";

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
    p {font-size: 3.0rem;}
    body {max-width: 600px; margin:0px auto; padding-bottom: 25px;}
    .switch {position: relative; display: inline-block; width: 120px; height: 68px} 
    .switch input {display: none}
    .slider {position: absolute; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; border-radius: 6px}
    .slider:before {position: absolute; content: ""; height: 52px; width: 52px; left: 8px; bottom: 8px; background-color: #fff; -webkit-transition: .4s; transition: .4s; border-radius: 3px}
    input:checked+.slider {background-color: #b30000}
    input:checked+.slider:before {-webkit-transform: translateX(52px); -ms-transform: translateX(52px); transform: translateX(52px)}
  </style>
</head>
<body>
  <h2>Fish Tank Lights</h2>
  %BUTTONPLACEHOLDER%
<script>
  function toggleCheckbox(element) 
  {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/update?output="+element.id, true);
    xhr.send();
  }
</script>
</body>
</html>
)rawliteral";

// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if(var == "BUTTONPLACEHOLDER"){
    String buttons = "";
    buttons += "<h4>Rainbow</h4><label class=\'switch\'><input type=\'checkbox\' onchange=\'toggleCheckbox(this)\' id=\'rainbow\'><span class=\'slider\'></span></label>";
    return buttons;
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
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
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage1;
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1)) 
    {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      
      if (inputMessage1 == "rainbow")
      {
        Serial.print("The ID is: ");
        Serial.println(inputMessage1);
        rainbowCycle(1);
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
}

void loop() {

}

//##################################################
// Start of supporting functions

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void whiteOverRainbow(int whiteSpeed, int whiteLength) {

  if(whiteLength >= strip.numPixels()) whiteLength = strip.numPixels() - 1;

  int      head          = whiteLength - 1;
  int      tail          = 0;
  int      loops         = 3;
  int      loopNum       = 0;
  uint32_t lastTime      = millis();
  uint32_t firstPixelHue = 0;

  for(;;) { // Repeat forever (or until a 'break' or 'return')
    for(int i=0; i<strip.numPixels(); i++) {  // For each pixel in strip...
      if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
         ((tail > head) && ((i >= tail) || (i <= head)))) {
        strip.setPixelColor(i, strip.Color(0, 0, 0, 255)); // Set white
      } else {                                             // else set rainbow
        int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
        strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
      }
    }

    strip.show(); // Update strip with new contents
    // There's no delay here, it just runs full-tilt until the timer and
    // counter combination below runs out.

    firstPixelHue += 40; // Advance just a little along the color wheel

    if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
      if(++head >= strip.numPixels()) {      // Advance head, wrap around
        head = 0;
        if(++loopNum >= loops) return;
      }
      if(++tail >= strip.numPixels()) {      // Advance tail, wrap around
        tail = 0;
      }
      lastTime = millis();                   // Save time of last movement
    }
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
  set_entire_strip_color(20, SWEDISH_FLAG_YELLOW);
    
  for(int i=0; i<loops;i++)
  {
    bounce_fill_two_colors(20, SWEDISH_FLAG_BLUE, SWEDISH_FLAG_YELLOW);
  }
  
  for(int i=0; i<loops;i++)
  {
    color_chase(20, SWEDISH_FLAG_BLUE);
    color_chase_reverse(20, SWEDISH_FLAG_BLUE);
    color_chase(20, SWEDISH_FLAG_YELLOW);
    color_chase_reverse(20, SWEDISH_FLAG_YELLOW);
  }
  
  for(int i=0; i<loops;i++)
  {
    instant_entire_strip_color(SWEDISH_FLAG_BLUE);
    delay(100);
    instant_entire_strip_color(SWEDISH_FLAG_YELLOW);
    delay(100);
  }
  
  for(int i=0; i<loops; i++)
  {
    set_entire_strip_color(10, SWEDISH_FLAG_BLUE);
    set_entire_strip_color(10, SWEDISH_FLAG_YELLOW);    
  }
}
