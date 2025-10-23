#include <IRremote.h>
#include "buttonToHex.h"

// define pins
#define IR_RECEIVE_PIN 7
#define IR_TX_PIN 3
#define TRIG_PIN 12
#define ECHO_PIN 11

// define button cutoffs and thresholds
#define lowCutoff 10
#define highCutoff 100
#define lowestLightButton 1
#define highestLightButton 10

// define timins and fading
#define mainDelay 50
#define sendDelay 100
#define noDetectionThreshold 100  // distance above which we assume object is gone
#define fadeDelayCycles 3 // number of loop cycles to wait before decreasing brightness

void setup(){
  Serial.begin(9600); // start serial for debugging
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  IrSender.begin(IR_TX_PIN, true);  // initialize IR transmitter
}

// Function to measure median distance from multiple readings to reduce noise
int measureDistanceMedian() {
  const byte n = 5;
  int readings[n];

  // Take n measurements
  for (byte i = 0; i < n; i++) {
    long timePassed;
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    timePassed = pulseIn(ECHO_PIN, HIGH); // measure pulse duration
    readings[i] = timePassed / 58;  // convert to cm
    delay(5);
  }

  // sort the readings to find the median
  for (byte i = 0; i < n - 1; i++) {
    for (byte j = i + 1; j < n; j++) {
      if (readings[j] < readings[i]) {
        int tmp = readings[i];
        readings[i] = readings[j];
        readings[j] = tmp;
      }
    }
  }

  return readings[n / 2]; // return median value
}

int distance = 0;
int lastValidDistance = 50; // reasonable default
byte currentButton = 1;
byte stableButton = 1;
byte fadeCounter = 0;
bool objectDetected = true;
static byte lastSentButton = 1;

void loop() {
  int newDistance = measureDistanceMedian();  // read sensor

  // --- Ignore invalid readings and detect if object is present --- //
  if (newDistance >= 1 && newDistance <= noDetectionThreshold) {
    lastValidDistance = newDistance;  // update last valid distance
    objectDetected = true;  // mark object present
    fadeCounter = 0;  // reset fade counter
  } else {
    objectDetected = false;
  }
  distance = lastValidDistance; // use last valid distance for mapping

  // --- Map distance to brightness level --- //
   byte targetButton;
  if (objectDetected) {  // object present then map distance normally
    targetButton = map(lastValidDistance, lowCutoff, highCutoff,
                       highestLightButton, lowestLightButton);  // closer = brighter
  } else {
    // No object — fade down gradually
    fadeCounter++;
    if (fadeCounter >= fadeDelayCycles && stableButton > lowestLightButton) {
      stableButton--;
      fadeCounter = 0;
    }
    targetButton = stableButton;  // keep target at current stable level
  }

  targetButton = constrain(targetButton, lowestLightButton, highestLightButton);  // keep in range

  // --- Add hysteresis and smoothing to avoid flicker --- //
  const byte hysteresis = 1;
  if (targetButton > stableButton + hysteresis) {
    stableButton++;
  } else if (targetButton + hysteresis < stableButton) {
    stableButton--;
  }

  // --- Gradual stepping toward stableButton --- //
  if (currentButton < stableButton) currentButton++;
  else if (currentButton > stableButton) currentButton--;

  // --- Send IR only when level changes ---
  
  if (currentButton != lastSentButton) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | Target: ");
    Serial.print(targetButton);
    Serial.print(" | Stable: ");
    Serial.print(stableButton);
    Serial.print(" | Sending ");
    Serial.println(currentButton);

    IrSender.sendNECRaw(buttonToHex(currentButton));
    lastSentButton = currentButton;
    delay(sendDelay); // necessary - the LED IR receiver cannot keep up with faster speeds and starts skipping codes
  }

  delay(mainDelay);
}
