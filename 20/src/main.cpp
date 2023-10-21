#include <Arduino.h>

int edad;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // Esperar a que el puerto serie se conecte. Necesario para los tableros basados en Leonardo y Micro.
  }
}

void loop() {
  Serial.print("Digite su edad: ");
  while (Serial.available() == 0) {
    // Esperar a que el usuario ingrese un número
  }
  edad = Serial.parseInt();
  if ((edad >= 18) && (edad <= 25)) {
    Serial.println("Su edad esta en el rango de [18-25]");
  } else {
    Serial.println("Su edad esta fuera de rango");
  }
}
