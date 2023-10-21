#include <Arduino.h>

int vec[100],tam;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digite el numero de elementos del arreglo: ");
  while (!Serial.available()) {}
  tam = Serial.parseInt();
  
  for(int i=0;i<tam;i++){
    Serial.print(i+1);
    Serial.print(". Digite un numero: ");
    while (!Serial.available()) {}
    vec[i] = Serial.parseInt();
  }
  
  int suma=0;
  
  for(int i=0;i<tam;i++){
    suma += vec[i];
  }
  
  Serial.print("\nLa suma es: ");
  Serial.println(suma);
}
