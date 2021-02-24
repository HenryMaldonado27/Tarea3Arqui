#include <SoftwareSerial.h>

int pinATemperatura = A0;
float temperatura;  
int temperaturaObtenida;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temperaturaObtenida = analogRead(pinATemperatura); 
  temperatura = (temperaturaObtenida * 5.0)*100.0/ 1024.0;

  if(Serial.available()>=1) {
    delay(10);

    String entradaBT = ""; 
    while (Serial.available()>0) {
      entradaBT += (char)Serial.read();
   } 

   if(entradaBT == "2") {
    Serial.println(temperatura);
   }
 
  }
  
  
}
