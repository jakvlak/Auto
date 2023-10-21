#include <Arduino.h>

float cateto1, cateto2, hipotenusa;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Esperar a que el puerto serie se conecte. Necesario para los tableros basados en Leonardo y Micro.
  }
}

void loop() {
  Serial.print("Digite el cateto 1: ");
  while (Serial.available() == 0) {
    // Esperar a que el usuario ingrese un número
  }
  cateto1 = Serial.parseFloat();
  
  Serial.print("Digite el cateto 2: ");
  while (Serial.available() == 0) {
    // Esperar a que el usuario ingrese un número
  }
  cateto2 = Serial.parseFloat();
  
  hipotenusa = sqrt(pow(cateto1,2)+pow(cateto2,2));
  
  Serial.print("\nEl resultado de la hipotenusa es: ");
  Serial.println(hipotenusa);
}
