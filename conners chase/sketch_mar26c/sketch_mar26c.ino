#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_PIXELS 30

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
   strip.begin();
   strip.setBrightness(255);
   strip.show(); // Initialize all pixels to 'off'
}

void loop(){
  uint32_t c = strip.Color(0,0,245);
  
  for(int i = 0; i < 30; i++){
   strip.setPixelColor(i, c);
  strip.setPixelColor(i + 1,c);
  strip.setPixelColor(i -1,0);
 strip.show();
  delay(100); 
  
    strip.setBrightness(255 - (i*11));
    strip.show();
  if(i == 29){
  strip.setPixelColor(i,0);
  strip.show();
  }
  }
  }


static void setAll(uint32_t c){
  for(int i=0; i < strip.numPixels(); i++){
    strip.setPixelColor(i, c);
    strip.show();
  }
}


