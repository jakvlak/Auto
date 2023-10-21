#include <Arduino.h>

int numero;

void setup() {
  Serial.begin(9600);
}

void loop() {
  do{
    Serial.print("Digite un numero: ");
    while (!Serial.available()) {}
    numero = Serial.parseInt();
  }while(numero<=0);
  
  int suma=0;
  
  for(int i=1;i<=numero;i++){
    suma += i;
  }
  
  Serial.print("La suma es: ");
  Serial.println(suma);
}
