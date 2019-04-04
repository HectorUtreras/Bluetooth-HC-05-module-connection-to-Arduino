#include <SoftwareSerial.h>

SoftwareSerial wirelessNetworkYT(0, 1);

char DAT;
int LED1 = 2;
int LED2 = 3;
int cont1=0;
int cont2=0;
void setup() {
  wirelessNetworkYT.begin(38400);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  //digitalWrite(GREENLED,HIGH);
  if (wirelessNetworkYT.available()){
    DAT = wirelessNetworkYT.read();
    if (DAT == '1'){
      if(cont1==0){digitalWrite(LED1, HIGH);cont1=1;}
      else {
        digitalWrite(LED1, LOW);
        cont1=0;}
      }
      
    if (DAT == '2'){
      if(cont2==0){digitalWrite(LED2, HIGH);cont2=1;}
      else {
        digitalWrite(LED2, LOW);
        cont2=0;}
      }

    
  }
}
