#include <Arduino.h>

int nElementos, elemento[100];

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digite el numero de elementos del arreglo: ");
  while (!Serial.available()) {}
  nElementos = Serial.parseInt();
  
  for(int i=0;i<nElementos;i++){//Pedir datos al usuario para el arreglo
    Serial.print("Digite un numero[");
    Serial.print(i);
    Serial.print("]: ");
    while (!Serial.available()) {}
    elemento[i] = Serial.parseInt();
  }
  
  int dato,i;
  bool band=false;
  
  Serial.print("\nDigite el numero que quiere buscar: ");
  while (!Serial.available()) {}
  dato = Serial.parseInt();
  
  //Busqueda Secuencial
  i=0;
  while((band==false)&&(i<nElementos)){
    if(elemento[i]==dato){ //Verificar si existe el numero en el arreglo
      band = true; //Si lo encuentra bandera cambia a Verdadero
    }
    i++;
  }
  
  if(band==false){
    Serial.print("El numero ");
    Serial.print(dato);
    Serial.println(" NO ha sido encontrado");
  }
  else{
    Serial.print("El numero ");
    Serial.print(dato);
    Serial.print(" ha sido encontrado en la posicion ");
    Serial.println(i-1);
  }
}
