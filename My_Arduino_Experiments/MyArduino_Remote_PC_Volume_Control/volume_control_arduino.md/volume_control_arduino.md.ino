#include "TM1637.h"
//#include <TM1637Display.h>
#include <IRremote.h>

#define IR_RECEIVE_PIN 3
const byte CLK = 6;
const byte DIO = 5;
float message = 50.0;
float last_message = 0.0;
#define DEF_DELAY 5

TM1637 tm1637(CLK, DIO);


void setup(){
  Serial.begin(9600);
  Serial.setTimeout(100);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
//  display.setBrightness(0,true);

  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;

}


int buttonRead = 50;
byte brightness = 2;

void loop(){
if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0){
        switch (IrReceiver.decodedIRData.decodedRawData){
          case 0xFF00FF02:
            buttonRead = 0;
            break;
          case 0xFD02FF02:
            if(brightness<7){
              brightness += 1;
            } else {
              brightness = 0;
            }
            buttonRead = 0;
            tm1637.set(brightness);
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
    
  }
  if (Serial.available() > 0) {
    message = (Serial.readString()).toFloat();
    
    if(message != 255){
      tm1637.displayNum(message);
      last_message = message;
    } else {
      tm1637.displayNum(last_message);
      message = last_message;
    }
  }
  
}
