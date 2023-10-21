#include <Arduino.h>

int numeros[100][100],filas,columnas;
char band='F';

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digite el numero de filas: ");
  while (!Serial.available()) {}
  filas = Serial.parseInt();
  
  Serial.print("Digite el numero de columnas: ");
  while (!Serial.available()) {}
  columnas = Serial.parseInt();
  
  //Rellenando matriz
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      Serial.print("Digite un numero [");
      Serial.print(i);
      Serial.print("][");
      Serial.print(j);
      Serial.print("]: ");
      while (!Serial.available()) {}
      numeros[i][j] = Serial.parseInt();
    }
  }
  
  //Comprobemos si es simetrica
  if(filas==columnas){
    for(int i=0;i<filas;i++){
      for(int j=0;j<columnas;j++){
        if(numeros[i][j] == numeros[j][i]){
          band='V';
        }
      }
    }
  }

  if(band=='V'){
    Serial.println("\nEs una matriz simetrica");
  }
  else{
    Serial.println("\nNo es una matriz simetrica");
  }
}
