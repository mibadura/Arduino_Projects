//#include "TM1637.h"
#include <TM1637Display.h>
#include <IRremote.h>

#define IR_RECEIVE_PIN 3
const byte CLK = 6;
const byte DIO = 5;
float message = 50.0;
#define DEF_DELAY 5

TM1637Display display(CLK, DIO);


void setup(){
}


int buttonRead = 0;

void loop(){
}

uint8_t SEGMENT_nothing = 0b00000000;
uint8_t SEGMENT_left = 0b00111001;
uint8_t SEGMENT_right = 0b00001111;
uint8_t SEGMENT_empty = 0b00001001;
uint8_t SEGMENT_full = 0b00111111;

uint8_t SCREEN_X1[4] = {SEGMENT_nothing,SEGMENT_nothing,SEGMENT_nothing,SEGMENT_nothing};
uint8_t SCREEN_X2[4] = {0b00110000,SEGMENT_nothing,SEGMENT_nothing,SEGMENT_nothing};
uint8_t SCREEN_X3[4] = {SEGMENT_left,SEGMENT_empty,SEGMENT_nothing,SEGMENT_nothing};
uint8_t SCREEN_X4[4] = {SEGMENT_left,SEGMENT_empty,SEGMENT_empty,SEGMENT_nothing};
uint8_t SCREEN_X5[4] = {SEGMENT_left,SEGMENT_empty,SEGMENT_empty,SEGMENT_empty};


uint8_t SCREEN_1[4] = {SEGMENT_left,SEGMENT_empty,SEGMENT_empty,SEGMENT_right};
uint8_t SCREEN_2[4] = {SEGMENT_full,SEGMENT_empty,SEGMENT_empty,SEGMENT_right};
uint8_t SCREEN_3[4] = {SEGMENT_full,SEGMENT_left,SEGMENT_empty,SEGMENT_right};
uint8_t SCREEN_4[4] = {SEGMENT_full,SEGMENT_full,SEGMENT_empty,SEGMENT_right};
uint8_t SCREEN_5[4] = {SEGMENT_full,SEGMENT_full,SEGMENT_left,SEGMENT_right};
uint8_t SCREEN_6[4] = {SEGMENT_full,SEGMENT_full,SEGMENT_full,SEGMENT_right};
uint8_t SCREEN_7[4] = {SEGMENT_full,SEGMENT_full,SEGMENT_full,SEGMENT_full};

void doCoolAnimations()
{
  
  display.setSegments(SCREEN_X1);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_X2);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_X3);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_X4);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_X5);
  delay(DEF_DELAY);


  display.setSegments(SCREEN_1);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_2);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_3);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_4);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_5);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_6);
  delay(DEF_DELAY);
  display.setSegments(SCREEN_7);
  delay(DEF_DELAY);
  
}
