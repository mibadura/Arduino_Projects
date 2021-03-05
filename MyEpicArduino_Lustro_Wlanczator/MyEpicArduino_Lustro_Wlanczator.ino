#define trigPin 12
#define echoPin 11
int lowCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(2, OUTPUT);

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
      digitalWrite(2, HIGH);
      lowCount = 0;
  } else {
      if (lowCount >= 3){
        digitalWrite(2, LOW);
      }
      else{
        lowCount += 1;
        Serial.print("Increasing lowCount ");
        Serial.println(lowCount);
      }
      
  }
}



void loop() {
  
  Serial.println(zmierzOdleglosc());
  zakres(5, 75);
  
  delay(500);
}
