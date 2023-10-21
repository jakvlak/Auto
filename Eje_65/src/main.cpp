#include <Arduino.h>

struct tiempo_ciclista{
  int horas;
  int minutos;
  int segundos;
}etapa[10];

int n_etapas,horasT=0,minutosT=0,segundosT=0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Digite el numero de etapas: ");
  while (!Serial.available()) {}
  n_etapas = Serial.parseInt();
  
  Serial.println("\nDigite el tiempo Obtenido:");
  
  for(int i=0;i<n_etapas;i++){
    //Pedimos las horas en cada etapa
    Serial.print(i+1);
    Serial.print(". Horas: ");
    while (!Serial.available()) {}
    etapa[i].horas = Serial.parseInt();
    
    Serial.print(i+1);
    Serial.print(". Minutos: ");
    while (!Serial.available()) {}
    etapa[i].minutos = Serial.parseInt();
    
    Serial.print(i+1);
    Serial.print(". Segundos: ");
    while (!Serial.available()) {}
    etapa[i].segundos = Serial.parseInt();
    
    horasT = horasT+etapa[i].horas; //Sacamos las horas totales empleadas
    minutosT = minutosT+etapa[i].minutos;
    if(minutosT>=60){//Si los minutos son mayores a 60, significa que ha pasado
      minutosT-=60;//mas de 1 hora, entonces disminuimos en 60 los minutos
      horasT++;//y aumentamos las horas en 1
    }
    segundosT = segundosT+etapa[i].segundos;
    if(segundosT>=60){//y lo mismo hacemos con los segundos
      segundosT-=60;
      minutosT++;
    }
    Serial.println();
  }
  
  //Por ultimo mostramos los totales de tiempos en pantalla
  Serial.println("\nEl tiempo total es: ");
  Serial.print("Horas: ");
  Serial.println(horasT);
  Serial.print("Minutos: ");
  Serial.println(minutosT);
  Serial.print("Segundos: ");
  Serial.println(segundosT);
}
