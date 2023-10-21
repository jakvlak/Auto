#include <Arduino.h>

float temperatura,suma_temperatura=0,temperatura_media;
float temperatura_alta=0,temperatura_baja=999;

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<24;i+=4){ //vamos aumentando de 4 en 4 horas
    Serial.print("Digite la temperatura a las ");
    Serial.print(i);
    Serial.print(": ");
    while (!Serial.available()) {}
    temperatura = Serial.parseFloat();
    
    suma_temperatura += temperatura;
    
    if(temperatura > temperatura_alta){
      temperatura_alta = temperatura;
    }
    if(temperatura < temperatura_baja){
      temperatura_baja = temperatura;
    }
  }
  
  temperatura_media = suma_temperatura / 6; //entre 6 porque son 6 temperaturas al dia
  
  Serial.print("\nLa temperatura media del dia es: ");
  Serial.println(temperatura_media);
  Serial.print("La temperatura mas alta es: ");
  Serial.println(temperatura_alta);
  Serial.print("La temperatura mas baja es: ");
  Serial.println(temperatura_baja);  
}