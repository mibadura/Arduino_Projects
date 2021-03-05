int odczytanaWartosc = 0;
float delayInSec = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  odczytanaWartosc = analogRead(A5);
  delayInSec = odczytanaWartosc / 1000.0;
  Serial.println(delayInSec);
 
  digitalWrite(2, HIGH);
  delay(odczytanaWartosc);
  
  digitalWrite(2, LOW);
  delay(odczytanaWartosc);

}
