void setup() {

  Serial.begin(9600); //predkosc transmisji
  Serial.println("Witaj");
}

void loop() {
  delay(5000);
  Serial.println("Minelo 5 sekund");
}
