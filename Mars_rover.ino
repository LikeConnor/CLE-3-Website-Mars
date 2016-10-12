#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 9
#define NUM_LEDS 60
#define BRIGHTNESS 100

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


const int buttonPinRA = 2;
const int buttonPinRB = 3;
const int buttonPinRC = 4;
const int buttonPinLA = 5;
const int buttonPinLB = 6;
const int buttonPinLC = 7;

int buttonStateRA = 0;
int previousStateRA =0;
int buttonStateRB = 0;
int previousStateRB =0;
int buttonStateRC = 0;
int previousStateRC =0;
int buttonStateLA = 0;
int previousStateLA =0;
int buttonStateLB = 0;
int previousStateLB =0;
int buttonStateLC = 0;
int previousStateLC =0;


void setup() {
  pinMode(buttonPinRA, INPUT);
  pinMode(buttonPinRB, INPUT);
  pinMode(buttonPinRC, INPUT);
  pinMode(buttonPinLA, INPUT);
  pinMode(buttonPinLB, INPUT);
  pinMode(buttonPinLC, INPUT);
  Serial.begin(9600);

    #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();
}

void loop () {
  buttonStateRA = digitalRead(buttonPinRA);
  if (buttonStateRA != previousStateRA && buttonStateRA == LOW) {
    triggerLEDStripR(strip.Color(0, 255, 0));
  } 
  previousStateRA = buttonStateRA;

  buttonStateRB = digitalRead(buttonPinRB);
  if (buttonStateRB != previousStateRB && buttonStateRB == LOW) {
    triggerLEDStripR(strip.Color(200, 100, 0));
  } 
  previousStateRB = buttonStateRB;

  buttonStateRC = digitalRead(buttonPinRC);
  if (buttonStateRC != previousStateRC && buttonStateRC == LOW) {
    triggerLEDStripR(strip.Color(255, 0, 0));
  } 
  previousStateRC = buttonStateRC;


  buttonStateLA = digitalRead(buttonPinLA);
  if (buttonStateLA != previousStateLA && buttonStateLA == LOW) {
    triggerLEDStripL(strip.Color(0, 255, 0));
  } 
  previousStateLA = buttonStateLA;
  
  buttonStateLB = digitalRead(buttonPinLB);
  if (buttonStateLB != previousStateLB && buttonStateLB == LOW) {
    triggerLEDStripL(strip.Color(200, 100, 0));
  } 
  previousStateLB = buttonStateLB;

  buttonStateLC = digitalRead(buttonPinLC);
  if (buttonStateLC != previousStateLC && buttonStateLC == LOW) {
    triggerLEDStripL(strip.Color(255, 0, 0));
  } 
  previousStateLC = buttonStateLC;
}


void triggerLEDStripR(uint32_t c){
  colorWipeRight(c, 10, 60);
  delay(500);
  colorWipeRight(strip.Color(0,0,0), 10, 60);
}

void triggerLEDStripL(uint32_t c){
  colorWipeLeft(c,10,0);
  delay(500);
  colorWipeLeft(strip.Color(0, 0, 0),10, 0);
}


void colorWipeRight(uint32_t c, uint8_t wait, int pixelNum) {
  for(uint16_t i=29; i<pixelNum; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void colorWipeLeft(uint32_t c, uint8_t wait, int pixelNum) {
  for(uint16_t i=28; i>pixelNum; i--) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
