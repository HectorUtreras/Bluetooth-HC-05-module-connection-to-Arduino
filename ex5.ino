#include <SoftwareSerial.h>

SoftwareSerial wirelessNetworkYT(0, 1);

String DAT;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;
int LED5 = 6;
int cont5=0;
int cont1=0;
int cont2=0;
int cont3=0;
int cont4=0;
void setup() {
  wirelessNetworkYT.begin(38400);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  //digitalWrite(GREENLED,HIGH);
  if (wirelessNetworkYT.available()){
    DAT = wirelessNetworkYT.readString();
    if ((DAT == "rojo uno") or (DAT == "rojos")){
      if(cont1==0){digitalWrite(LED1, HIGH);cont1=1;}
      else {
        digitalWrite(LED1, LOW);
        cont1=0;}
      }
      
    if ((DAT == "rojo 2") or (DAT == "rojos")){
      if(cont2==0){digitalWrite(LED2, HIGH);cont2=1;}
      else {
        digitalWrite(LED2, LOW);
        cont2=0;}
      }
    if (DAT == "azul"){
      if(cont3==0){digitalWrite(LED3, HIGH);cont3=1;}
      else {
        digitalWrite(LED3, LOW);
        cont3=0;}
      }
      
    if ((DAT == "naranja 1") or (DAT == "naranjas")){
      if(cont4==0){digitalWrite(LED4, HIGH);cont4=1;}
      else {
        digitalWrite(LED4, LOW);
        cont4=0;}
      }
    if ((DAT == "naranja 2") or (DAT == "naranjas")){
      if(cont5==0){digitalWrite(LED5, HIGH);cont5=1;}
      else {
        digitalWrite(LED5, LOW);
        cont5=0;}
      }

    if (DAT == "todos"){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      }
    if (DAT == "ninguno"){
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      }
    
  }
}
