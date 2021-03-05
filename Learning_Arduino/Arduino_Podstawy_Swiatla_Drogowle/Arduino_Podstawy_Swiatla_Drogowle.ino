void setup() {
  pinMode(10, OUTPUT);  //CZERWONA DIODKA
  pinMode(9, OUTPUT);  //ZOLTA iDIODKA
  pinMode(8, OUTPUT);  //ZIELONA DIODKA

  pinMode(7, INPUT_PULLUP);

  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}

void loop() {
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  delay(500);
  while (digitalRead(7) == HIGH){}

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  delay(500);
  while (digitalRead(7) == HIGH){}

  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);

  delay(500);
  while (digitalRead(7) == HIGH){}

  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  delay(500);
  while (digitalRead(7) == HIGH){}

}
