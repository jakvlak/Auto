#include <Arduino.h>

int totalSeg,horas,minu,seg;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digita la cantidad de segundos: ");
  while (!Serial.available()) {}
  totalSeg = Serial.parseInt();
  
  horas = totalSeg/3600;
  totalSeg %= 3600;
  minu = totalSeg/60;
  seg = totalSeg%60; 
  
  Serial.print("\nHoras: ");
  Serial.println(horas);
  Serial.print("Minutos: ");
  Serial.println(minu);
  Serial.print("Segundos: ");
  Serial.println(seg);
}