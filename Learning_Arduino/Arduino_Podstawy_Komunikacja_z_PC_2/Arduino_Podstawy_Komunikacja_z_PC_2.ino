#define diodRed 8
#define diodGreen 9
#define button 10


void setup() {
  Serial.begin(9600); //predkosc transmisji

  pinMode(diodRed, OUTPUT);
  pinMode(diodGreen, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  digitalWrite(diodRed, LOW);
  digitalWrite(diodGreen, LOW);

}

void loop() {
  if(digitalRead(button) == LOW){
    digitalWrite(diodGreen, HIGH);
    digitalWrite(diodRed, LOW);
  }
  else{
    digitalWrite(diodGreen, LOW);
    digitalWrite(diodRed, HIGH);
    Serial.println("UWAGA! Przycisk nie jest wcisniety => Okno otwarte!");
    while ( digitalRead(button) == HIGH ){ 
      delay(25);
    }
  }

}
