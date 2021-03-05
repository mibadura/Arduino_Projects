#define diodaPIN 3

byte wypelnienie = 0;
int zmiana = 5;

void setup() {
  pinMode(diodaPIN, OUTPUT);
}

void loop() {
  analogWrite(diodaPIN, wypelnienie);

  wypelnienie = wypelnienie + zmiana;


  delay(50);
}
