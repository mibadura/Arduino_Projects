#define diodaPIN 3

byte wypelnienie = 0;
int zmiana = 1;

void setup() {
  Serial.begin(9600);
  pinMode(diodaPIN, OUTPUT);
}

void loop() {
  analogWrite(diodaPIN, wypelnienie);

  if ( wypelnienie > 100 and zmiana > 0 ){
    zmiana = (-1)*zmiana;
  } else if ( wypelnienie < 5 and zmiana < 0 ) {
    zmiana = (-1)*zmiana;
  }

  Serial.println(zmiana);
  wypelnienie = wypelnienie + zmiana;


  delay(30);
}
