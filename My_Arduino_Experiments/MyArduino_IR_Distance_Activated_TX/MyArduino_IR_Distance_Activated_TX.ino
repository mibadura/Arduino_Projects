#include <IRremote.h>
#include "buttonToHex.h"
#include "interpretReceived.h"

#define IR_RECEIVE_PIN 7
#define IR_TX_PIN 3
#define trigPin 12
#define echoPin 11

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  IrSender.begin(IR_TX_PIN, true);
}

int zmierzOdleglosc(){
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;

  return dystans;
}

void zakres(int a, int b) {
  int jakDaleko = zmierzOdleglosc();
  if ((jakDaleko > a) && (jakDaleko < b)) {
      digitalWrite(2, HIGH); //Włączamy buzzer
  } else {
      digitalWrite(2, LOW); //Wyłączamy buzzer, gdy obiekt poza zakresem
  }
}




void loop(){
//  Serial.println(buttonToHex(buttonNr), HEX);
  Serial.println(zmierzOdleglosc());
  delay(2000);
}
