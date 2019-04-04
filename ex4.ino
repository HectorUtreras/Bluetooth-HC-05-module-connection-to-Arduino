#include <SoftwareSerial.h>

SoftwareSerial wirelessNetworkYT(10, 11);

char DAT = 0;
int REDLED = 5;
int GREENLED = 3;
int cont=0;
int counter;
int lastCounter = 1;
int fadeValue;
int counter1;
int lastCounter1 = 1;
int fadeValue1;
void setup() {
  wirelessNetworkYT.begin(38400);
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
}

void loop() {
  counter = lastCounter;
  lastCounter1=counter1;
  if (wirelessNetworkYT.available()){
    DAT = wirelessNetworkYT.read();
    if (DAT == '1'){
      if(cont==0){digitalWrite(GREENLED, HIGH);
      cont=1;
      }
      else {
        digitalWrite(GREENLED, LOW);
        cont=0;}
      }
      
    if (DAT == '2'){
      counter ++;
      Serial.println(counter);
      Serial.println(fadeValue);
  }
  if (DAT == '3'){
      counter --;
      Serial.println(counter);
      Serial.println(fadeValue);
  }

  if (DAT == '4'){
      counter1 ++;
      Serial.println(counter1);
      Serial.println(fadeValue1);
  }

  if (DAT == '5'){
      counter1 --;
      Serial.println(counter1);
      Serial.println(fadeValue1);
  }
 }

 if (counter == 5){
    digitalWrite( GREENLED, HIGH);
    delay(500);
    digitalWrite( GREENLED, LOW);
    delay(100);
  }

  if (counter > 5){
    counter = 1;
  }

  if (counter < 2){
    counter = 1;
  }
  
  switch (counter){    //depending on the counter the fadevalue is sent to the led
   
  case 1:
  fadeValue = 00;
  break;
   
  case 2:
  fadeValue = 50;
  break;
   
  case 3:
  fadeValue = 120;
  break;
   
  case 4:
  fadeValue = 185;
  break;
   
  case 5:
  fadeValue = 255;
  break;
  }
   
  analogWrite(GREENLED , fadeValue);    //set led with PWM value
  lastCounter=counter;


  if (counter1 == 5){
    digitalWrite( REDLED, HIGH);
    delay(500);
    digitalWrite( REDLED, LOW);
    delay(100);
  }

  if (counter1 > 5){
    counter1 = 1;
  }

  if (counter1 < 2){
    counter1 = 1;
  }
  
  switch (counter1){    //depending on the counter the fadevalue is sent to the led
   
  case 1:
  fadeValue1 = 00;
  break;
   
  case 2:
  fadeValue1 = 50;
  break;
   
  case 3:
  fadeValue1 = 120;
  break;
   
  case 4:
  fadeValue = 185;
  break;
   
  case 5:
  fadeValue1 = 255;
  break;
  }
   
  analogWrite(REDLED , fadeValue1);    //set led with PWM value
  lastCounter1=counter1;
}
