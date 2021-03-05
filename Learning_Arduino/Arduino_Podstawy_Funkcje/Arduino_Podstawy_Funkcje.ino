#define trigPin 12
#define echoPin 11

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(2, OUTPUT); //Wyjście dla buzzera

}

int zmierzOdleglosc(){
  long czas, dystans;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;

  return dystans;
}

void zakres(int a, int b) {
  int jakDaleko = zmierzOdleglosc();
  if ((jakDaleko > a) && (jakDaleko < b)) {
      digitalWrite(2, HIGH); //Włączamy buzzer
  } else {
      digitalWrite(2, LOW); //Wyłączamy buzzer, gdy obiekt poza zakresem
  }
}



void loop() {
  
  Serial.println(zmierzOdleglosc());
  zakres(10, 25);
  
  delay(100);
}
