
/*
 * Lesson 2 - Introduction to variables and for-loops and binaries
 */
 
// Required for any Arduino sketch
#include <Arduino.h> 

//Neopixel library that allows us to control the lights
#include <Adafruit_NeoPixel.h> 
 
// Number of LEDs in NeoPixel strip that you want to control
// You may not be able to control all the LEDs on a strip if you have a tiny board
// The Adafruit Gemma can not control more than 107, but you should not really go above 40
#define NUM_LEDS      17 

// NeoPixels are connected to this pin on the board
#define LED_DATA_PIN   1 

//Let the program know what kind of strip it is dealing with and how it is connected
Adafruit_NeoPixel    strip(NUM_LEDS, LED_DATA_PIN);

void setup() {
  // Allocate NeoPixel buffer
  // This sets up the LED strip
  strip.begin();         
}

void loop() {
  // Variables are declared before they are used
  // You need to describe the data type of the variable 
  // so that the computer knows how much memory to allocate to it
  // the name of the variable can be nearly anything, but you should try and make it meaningful
  // Do not use reserved keywords as variable names. If you do, you will confuse the computer
  // Try uncommenting the two lines of code below and see what happens
  // uint8_t for = 3;
  // uint8_t uint8_t = 10;
  // When you assign a value to a variable when it is declared, it is called 'initialization'
  // This is the initial value and it is a safety precaution

  // a variable called 'red' that can hold a value between 0 and 255, initialized to 0
  uint8_t red = 0; 
  
  // a variable called 'green' that can hold a value between 0 and 255, initialized to 127
  uint8_t green = 0; 

  // a variable called 'blue' that can hold a value between 0 and 255, initialized to 0
  uint8_t blue = 127; 

  // a variable called 'c' that can hold a value between 0 and 4,294,967,295
  // initialized to the value of the color strip
  uint32_t c = strip.Color(red, green, blue); 
  //mySerial.print(c);

  // a variable called 'wait' that can hold a value between 0 and 255, initialized to 50
  uint8_t wait = 50;

    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
}


/*                               --------------------
 *                              | INTEGER DATA TYPES |
 *                               --------------------
 *   C type      stdint.h type       Bits        Sign        Range
 *  ---------------------------------------------------------------
 *    char            uint8_t          8       Unsigned    0 .. 255
 *    signed char     int8_t           8       Signed      -128 .. 127
 *    unsigned short  uint16_t        16       Unsigned    0 .. 65,535
 *    short           int16_t         16       Signed      -32,768 .. 32,767
 *    unsigned int    uint32_t        32       Unsigned    0 .. 4,294,967,295
 *    int             int32_t         32       Signed      -2,147,483,648 .. 2,147,483,647
 *    unsigned long   uint64_t        64       Unsigned    0 .. 18,446,744,073,709,551,615
 *    long            int64_t         64       Signed      -9,223,372,036,854,775,808 .. 9,223,372,036,854,775,807
 *    
*/



