String odebraneDane = "";

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  if(Serial.available() > 0){
    odebraneDane = Serial.readStringUntil('\n');
    Serial.println("Witaj " + odebraneDane + "!");
  }
}
