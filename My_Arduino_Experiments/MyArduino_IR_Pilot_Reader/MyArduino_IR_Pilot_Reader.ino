#include <IRremote.h>

#define IR_RECEIVE_PIN 7

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop(){
  if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0){
        Serial.println(IrReceiver.decodedIRData.decodedRawData, BIN);
        IrReceiver.resume();
    }
    IrReceiver.resume();
  }
}
