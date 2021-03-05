int odczyt = 0;

void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  odczyt = analogRead(A5);

  if (odczyt < 150){
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  delay(50);
}
