#include <Servo.h> //Biblioteka odpowiedzialna za serwa
 
Servo serwomechanizm;  //Tworzymy obiekt, dzięki któremu możemy odwołać się do serwa 
int pozycja = 0; //Aktualna pozycja serwa 0-180
int zmiana = 6; //Co ile ma się zmieniać pozycja serwa?
int opoznienie = 200;
int zmiana_opoznienia = 50;
 
void setup() 
{ 
  serwomechanizm.attach(9);  //Serwomechanizm podłączony do pinu 9
  
} 
 
void loop() 
{  
  if (pozycja < 180) { //Jeśli pozycja mieści się w zakresie
    serwomechanizm.write(pozycja); //Wykonaj ruch
  } else { //Jeśli nie, to powrót na początek
    pozycja = 0;
  }    
  
  pozycja = pozycja + zmiana; //Zwiększenie aktualnej pozycji serwa
  if(opoznienie < 1000){
    opoznienie = opoznienie + zmiana_opoznienia;
  } else {
    opoznienie = 200;
  }
  delay(opoznienie); //Opóźnienie dla lepszego efektu                        
}
