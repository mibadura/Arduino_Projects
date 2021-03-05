String guess = "";
int guessInt = 0;
int prog = 0;
int try_num = 0;
int try_max = 3;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  Serial.println("Podaj liczbę: ");
  while (Serial.available() <= 0){
    delay(100);  
  }
  guess = Serial.readStringUntil('\n');
  if (guess == "reset"){
    try_num = 0;
  } else {
    guessInt = guess.toInt();
    prog = analogRead(A4);
    Serial.println("Odczytano liczbę: " + guess + " a próg to: " + prog);
    delay(100);
    try_num = try_num + 1;
    if ( guessInt <= (prog + 50) && guessInt >= (prog - 50) && try_num < try_max) {
  
        Serial.println("WOHOOO!!!");
        digitalWrite(8, HIGH);
        delay(1000);
        digitalWrite(8, LOW);
        if (try_num > 0){
          try_num = try_num - 1;
        }
        
    } else if (try_num < try_max) {
      digitalWrite(9, HIGH);
      delay(1000);
      digitalWrite(9, LOW);
    } else {
      digitalWrite(10, HIGH);
      delay(1000);
      digitalWrite(10, LOW);
      Serial.println("Wpisz 'reset' by zacząć od nowa!");
    }
  }

  delay(50);
}
