int odczyt = 0;
int prog = 0;
bool turnedOff = false;

void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  odczyt = analogRead(A5);
  prog = analogRead(A4);
  prog = map(prog, 0, 1023, 0, 400);

  
  if (odczyt < prog){
    if (turnedOff == true){
      Serial.println(prog);
    }
    digitalWrite(8, HIGH);
    turnedOff = false;
  } else {
    digitalWrite(8, LOW);
    turnedOff = true;
  }

  delay(50);
}
