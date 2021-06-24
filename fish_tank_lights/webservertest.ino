
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
#define LED_PIN     17

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
  Complete project details at http://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "RedMonkeys24";
const char* password = "honeychicken";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  // Neopixel
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(BRIGHTNESS);
  
  // Webservertest
  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /rgbw/apply") >= 0) {
              Serial.println("Applying RGBW settings");
              int redAmt = 0;
              int greenAmt = 128;
              int blueAmt = 128;
              int whiteAmt = 0;
              Serial.print("The Red Amount is:");
              Serial.println("");
              set_entire_strip_color_dynamic(10, redAmt, greenAmt, blueAmt, whiteAmt);
            } else if (header.indexOf("GET /red/apply") >= 0) {
              Serial.println("Applying Red settings");
              set_entire_strip_color(1, RED);
            } else if (header.indexOf("GET /green/apply") >= 0) {
              Serial.println("Applying Green settings");
              set_entire_strip_color(1, GREEN);
            } else if (header.indexOf("GET /blue/apply") >= 0) {
              Serial.println("Applying Blue settings");
              set_entire_strip_color(1, BLUE);
            } else if (header.indexOf("GET /rainbow/apply") >= 0) {
              Serial.println("Applying Rainbow settings");
              rainbowCycle(1);
            } else if (header.indexOf("GET /rgbwhite/apply") >= 0) {
              Serial.println("Applying RGB White settings");
              set_entire_strip_color(1, RGB_WHITE);
            } else if (header.indexOf("GET /purewhite/apply") >= 0) {
              Serial.println("Applying Pure White settings");
              set_entire_strip_color(1, PURE_WHITE);
            } else if (header.indexOf("GET /pink/apply") >= 0) {
              Serial.println("Applying Pink settings");
              set_entire_strip_color(1, PINK);
            } else if (header.indexOf("GET /violet/apply") >= 0) {
              Serial.println("Applying Violet settings");
              set_entire_strip_color(1, VIOLET);
            } else if (header.indexOf("GET /purple/apply") >= 0) {
              Serial.println("Applying Purple settings");
              set_entire_strip_color(1, PURPLE);
            } else if (header.indexOf("GET /sfb/apply") >= 0) {
              Serial.println("Applying SFB settings");
              set_entire_strip_color(1, SWEDISH_FLAG_BLUE);
            } else if (header.indexOf("GET /sfy/apply") >= 0) {
              Serial.println("Applying SFY settings");
              set_entire_strip_color(1, SWEDISH_FLAG_YELLOW);
            } else if (header.indexOf("GET /swedishparty/apply") >= 0) {
              Serial.println("Starting the Swedish Party");
              swedish_party(10);
            } else if (header.indexOf("GET /off/apply") >= 0) {
              Serial.println("Applying Off settings");
              set_entire_strip_color(1, OFF);
            } 
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Fish Tank Lights</h1>");

//            //################################## RGBW Inputs
//            client.println("<p><label for='RedValue'>Red Value:</label><input type='text' id='RedValue' name='RedValue' value='0'></p>");
//            client.println("<p><label for='GreenValue'>Green Value:</label><input type='text' id='GreenValue' name='GreenValue' value='0'></p>");
//            client.println("<p><label for='BlueValue'>Blue Value:</label><input type='text' id='BlueValue' name='BlueValue' value='0'></p>");
//            client.println("<p><label for='WhiteValue'>White Value:</label><input type='text' id='WhiteValue' name='WhiteValue' value='0'></p>");
//            
//            client.println("<p><a href=\"/rgbw/apply\"><button class=\"button\">Apply RGBW Settings</button></a></p>");
            

            //################################## RED BUTTON
            client.println("<p><a href=\"/red/apply\"><button class=\"button\">Red</button></a></p>");
            
            //################################## GREEN BUTTON
            client.println("<p><a href=\"/green/apply\"><button class=\"button\">Green</button></a></p>");
            
            //################################## BLUE BUTTON
            client.println("<p><a href=\"/blue/apply\"><button class=\"button\">Blue</button></a></p>");

            //################################## RAINBOW BUTTON
            client.println("<p><a href=\"/rainbow/apply\"><button class=\"button\">Start Rainbow</button></a></p>");

            //################################## RGB WHITE BUTTON
            client.println("<p><a href=\"/rgbwhite/apply\"><button class=\"button\">RGB White</button></a></p>");

            //################################## PURE WHITE BUTTON
            client.println("<p><a href=\"/purewhite/apply\"><button class=\"button\">Pure White</button></a></p>");

            //################################## PINK BUTTON
            client.println("<p><a href=\"/pink/apply\"><button class=\"button\">Pink</button></a></p>");
            
            //################################## VIOLET BUTTON
            client.println("<p><a href=\"/violet/apply\"><button class=\"button\">Violet</button></a></p>");
            
            //################################## PURPLE BUTTON
            client.println("<p><a href=\"/purple/apply\"><button class=\"button\">Purple</button></a></p>");

            //################################## SFB BUTTON
            client.println("<p><a href=\"/sfb/apply\"><button class=\"button\">SFB</button></a></p>");

            //################################## SFY BUTTON
            client.println("<p><a href=\"/sfy/apply\"><button class=\"button\">SFY</button></a></p>");

            //################################## SWEDISH PARTY BUTTON
            client.println("<p><a href=\"/swedishparty/apply\"><button class=\"button\">Start Swedish Party</button></a></p>");

            //################################## OFF BUTTON
            client.println("<p><a href=\"/off/apply\"><button class=\"button\">OFF</button></a></p>");

            client.println("</body></html>");
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }

//  rainbowCycle(1);
//  whiteOverRainbow(75, 5);
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
