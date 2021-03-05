#define zielona 9
#define czerwona 8

String odebrane = "";
bool isZielonaON = false;
bool isCzerwonaON = false;

void setup() {
  Serial.begin(9600);
  pinMode(zielona, OUTPUT);
  pinMode(czerwona, OUTPUT);

  digitalWrite(zielona, LOW);
  digitalWrite(czerwona, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    odebrane = Serial.readStringUntil('\n');

    if (odebrane == "zielona"){
      
      if(isZielonaON == true){
        isZielonaON = false;
        Serial.println("Zielona OFF");
        digitalWrite(zielona, LOW);
      } else {
        digitalWrite(zielona, HIGH);
        digitalWrite(czerwona, LOW);
        isZielonaON = true;
        isCzerwonaON = false;
      }
      
    } else if (odebrane == "czerwona"){

      if(isCzerwonaON == true){
        isCzerwonaON = false;
        Serial.println("Czerwona OFF");
        digitalWrite(czerwona, LOW);
      } else {
        digitalWrite(zielona, LOW);
        digitalWrite(czerwona, HIGH);
        isZielonaON = false;
        isCzerwonaON = true;
        }
      } else {
      Serial.println("Błędna komenda!");
      digitalWrite(zielona, LOW);
      digitalWrite(czerwona, LOW);
      isZielonaON = false;
      isCzerwonaON = false;
    }

   
  }

}
