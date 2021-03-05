#include <Servo.h> //Biblioteka odpowiedzialna za serwa
 
Servo serwomechanizm;  //Tworzymy obiekt, dzięki któremu możemy odwołać się do serwa 
int pozycja = 0; //Aktualna pozycja serwa 0-180
int zmiana = 2; //Co ile ma się zmieniać pozycja serwa?
int odczytanaWartosc = 0;
int srv_angle = 0;

void setup() 
{ 
  serwomechanizm.attach(9);  //Serwomechanizm podłączony do pinu 9
  Serial.begin(9600);//Uruchomienie komunikacji przez USART
} 
 
void loop() 
{  
  odczytanaWartosc = analogRead(A5);//Odczytujemy wartość napięcia
  srv_angle = (odczytanaWartosc * (180.0/1024.0));
//  Serial.println(srv_angle);//Wysyłamy ją do terminala

  
  
  if (srv_angle < 180 and srv_angle > 0 and (pozycja > (srv_angle+zmiana) or  pozycja < (srv_angle-zmiana)) ) { //Jeśli pozycja mieści się w zakresie
//    pozycja = srv_angle; //Zwiększenie aktualnej pozycji serwa
    
    while(pozycja > (srv_angle+zmiana) or  pozycja < (srv_angle-zmiana)){
      if (pozycja < srv_angle){
        pozycja = pozycja + zmiana;
      } else {
        pozycja = pozycja - zmiana;
      }
      Serial.println(" - - >"+(String)pozycja);//Wysyłamy ją do terminala
      serwomechanizm.write(pozycja); //Wykonaj ruch
      delay(5);
    }
    
  }  
  
  
 
  delay(10);        
}
