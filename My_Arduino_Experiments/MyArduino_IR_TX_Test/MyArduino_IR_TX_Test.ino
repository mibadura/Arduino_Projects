#include <IRremote.h>
#include "buttonToHex.h"
#include "interpretReceived.h"

#define IR_RECEIVE_PIN 7
#define IR_TX_PIN 3


void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  IrSender.begin(IR_TX_PIN, true);
}

void receiveAndPrint(){
  if (IrReceiver.decode()){
    if(IrReceiver.decodedIRData.decodedRawData != 0){
      Serial.println(interpretReceived(IrReceiver.decodedIRData.decodedRawData));
    }
    IrReceiver.resume();
  }
}


int buttonNr = 3;

void loop(){
//  receiveAndPrint();

  Serial.println(buttonToHex(buttonNr), HEX);
  buttonNr += 1;
  if( buttonNr > 13){
    buttonNr = 3;
  }
  delay(2000);
}
