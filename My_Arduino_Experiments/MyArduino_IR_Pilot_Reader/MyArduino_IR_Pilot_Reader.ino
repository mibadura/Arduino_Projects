#include <IRremote.h>

#define IR_RECEIVE_PIN 7

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop(){
  if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0){
        switch (IrReceiver.decodedIRData.decodedRawData){
          case 0xFF00FF02:
            Serial.println("On/Off");
            break;
          case 0xFD02FF02:
            Serial.println("Light Max");
            break;
          case 0xFB04FF02:
            Serial.println("10%");
            break;
          case 0xFA05FF02:
            Serial.println("20%");
            break;
          case 0xF906FF02:
            Serial.println("30%");
            break;
          case 0xF708FF02:
            Serial.println("40%");
            break;
          case 0xF609FF02:
            Serial.println("50%");
            break;
          case 0xF50AFF02:
            Serial.println("60%");
            break;
          case 0xF30CFF02:
            Serial.println("70%");
            break;
          case 0xF20DFF02:
            Serial.println("80%");
            break;
          case 0xF10EFF02:
            Serial.println("90%");
            break;
          case 0xEF10FF02:
            Serial.println("Flash");
            break;
          case 0xEE11FF02:
            Serial.println("Button +");
            break;
          case 0xED12FF02:
            Serial.println("Button -");
            break;
          default:
            Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
            break;
        }
    }
    IrReceiver.resume();
  }
}
