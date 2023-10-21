#include <Arduino.h>

float precio, precioFinal, IVA;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Esperar a que el puerto serie se conecte. Necesario para los tableros basados en Leonardo y Micro.
  }
}

void loop() {
  Serial.print("Digite el precio del producto: ");
  while (Serial.available() == 0) {
    // Esperar a que el usuario ingrese un número
  }
  precio = Serial.parseFloat();
  
  IVA = precio * 0.21;
  precioFinal = precio + IVA;
  
  Serial.print("\nEl precio Final al aplicarle IVA es: ");
  Serial.println(precioFinal);
}
