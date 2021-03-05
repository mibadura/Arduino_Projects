void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  digitalWrite(8, LOW);
}

void loop() {
  if (digitalRead(7) == LOW){
    digitalWrite(8, HIGH);
    delay(10000);
    digitalWrite(8, LOW);
  }
}
