//#include "TM1637.h"
#include <TM1637Display.h>
#include <IRremote.h>

#define IR_RECEIVE_PIN 3
const byte CLK = 6;
const byte DIO = 5;
#define DEF_DELAY 5

TM1637Display display(CLK, DIO);


void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  display.setBrightness(0,true);

//  tm1637.init();
//  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

}


int buttonRead = 0;

void loop(){
if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0){
        switch (IrReceiver.decodedIRData.decodedRawData){
          case 0xFF00FF02:
            buttonRead = 0;
            break;
          case 0xFD02FF02:
            buttonRead = 111;
            break;
          case 0xFB04FF02:
            buttonRead = 10;
            break;
          case 0xFA05FF02:
            buttonRead = 20;
            break;
          case 0xF906FF02:
            buttonRead = 30;
            break;
          case 0xF708FF02:
            buttonRead = 40;
            break;
          case 0xF609FF02:
            buttonRead = 50;
            break;
          case 0xF50AFF02:
            buttonRead = 60;
            break;
          case 0xF30CFF02:
            buttonRead = 70;
            break;
          case 0xF20DFF02:
            buttonRead = 80;
            break;
          case 0xF10EFF02:
            buttonRead = 90;
            break;
          case 0xEF10FF02:
            buttonRead = 222;
            break;
          case 0xEE11FF02:
            buttonRead = 333;
            break;
          case 0xED12FF02:
            buttonRead = 444;
            break;
          default:
            break;
        }
        Serial.println(buttonRead);
        
        
    }
    
    IrReceiver.resume();
//    doCoolAnimations();
    display.showNumberDec(buttonRead, false);
  }
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
