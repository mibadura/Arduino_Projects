#include <IRremote.h>
#include "buttonToHex.h"
#include "interpretReceived.h"

#define IR_RECEIVE_PIN 7
#define IR_TX_PIN 3
#define trigPin 12
#define echoPin 11

#define lowCutoff 25
#define highCutoff 100
#define unchangedCounterDefault 3
#define lowestButton 2
#define highestButton 10
#define offButton 0
#define maxButton 1

#define mainDelay 100

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  IrSender.begin(IR_TX_PIN, true);
}

int measureDistance(){
  long timePassed, distance;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  timePassed = pulseIn(echoPin, HIGH);
  distance = timePassed / 58;

  return distance;
}

int distance = 0;
byte buttonNr = 3;
byte currentButton = 0;
bool hasButtonChanged = false;
byte unchangedCounter = unchangedCounterDefault;

void loop(){
//  Serial.println(buttonToHex(buttonNr), HEX);
  distance = measureDistance();
  buttonNr = map(distance, lowCutoff, highCutoff, lowestButton, highestButton);
  if (buttonNr > highestButton){
    buttonNr = maxButton;
  } else if (buttonNr <= lowestButton){
    buttonNr = lowestButton;
  }

  if(currentButton == buttonNr){
    hasButtonChanged = false;
  } else {
    hasButtonChanged = true;
  }

  Serial.print(distance);
  Serial.print(" --- ");

  if(hasButtonChanged){
    unchangedCounter--;
    if(unchangedCounter <= 0){
      
      Serial.print(buttonToHex(buttonNr), HEX);
      Serial.print(" --- ");
      IrSender.sendNECRaw(buttonToHex(buttonNr));
      currentButton = buttonNr;
      unchangedCounter = unchangedCounterDefault;
    }
  }
  Serial.print(buttonNr-1);
  Serial.println("0% power ");

  delay(mainDelay);
}
