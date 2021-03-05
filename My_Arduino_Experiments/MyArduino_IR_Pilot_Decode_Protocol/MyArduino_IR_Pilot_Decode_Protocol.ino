#include <IRremote.h>

#define IR_RECEIVE_PIN 7

void setup(){
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop(){
  if (IrReceiver.decode()){
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        switch (IrReceiver.decodedIRData.decodedRawData){
            case NEC: Serial.println("NEC"); break ;
            case SONY: Serial.println("SONY"); break ;
            case RC5: Serial.println("RC5"); break ;
            case RC6: Serial.println("RC6"); break ;
            case DISH: Serial.println("DISH"); break ;
            case SHARP: Serial.println("SHARP"); break ;
            case JVC: Serial.println("JVC"); break ;
            case SAMSUNG: Serial.println("SAMSUNG"); break ;
            case LG: Serial.println("LG"); break ;
            case WHYNTER: Serial.println("WHYNTER"); break ;
            case PANASONIC: Serial.println("PANASONIC"); break ;
            case DENON: Serial.println("DENON"); break ;
          default:
            case UNKNOWN: Serial.println("UNKNOWN"); break ;
          }
        IrReceiver.resume();
 }
}
