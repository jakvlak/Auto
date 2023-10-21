#include <Arduino.h>

struct Nodo{
  char dato;
  Nodo *siguiente;  
};

Nodo *frente = NULL;
Nodo *fin = NULL;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int opc;
  char dato;
  
  Serial.println("\t.:MENU:.");
  Serial.println("1. Insertar un caracter a una cola");
  Serial.println("2. Mostrar todos los elementos de la cola");
  Serial.println("3. Salir");
  Serial.print("Opcion: ");
  while (!Serial.available()) {}
  opc = Serial.parseInt(); 
  
  switch(opc){
    case 1: Serial.print("\nIngrese el caracter para agregar a la cola: ");
            while (!Serial.available()) {}
            dato = Serial.read();
            insertarCola(frente,fin,dato);
            break;
    case 2: Serial.println("\nMostrando los elementos de la cola: ");
            while(frente != NULL){
              suprimirCola(frente,fin,dato);
              if(frente != NULL){
                Serial.print(dato);
                Serial.print(" , ");
              }
              else{
                Serial.print(dato);
                Serial.print(".");
              }
            }
            Serial.println();
            system("pause");
            break;
    case 3: return;
  }
}
//Función para insertar elementos en la cola
void insertarCola(Nodo *&frente,Nodo *&fin,char n){
  Nodo *nuevo_nodo = new Nodo();
  
  nuevo_nodo->dato = n;
  nuevo_nodo->siguiente = NULL;
  
  if(frente == NULL){
    frente = nuevo_nodo;
  }
  else{
    fin->siguiente = nuevo_nodo;
  }
  
  fin = nuevo_nodo;
}

//Función para determinar si la cola está vacía
bool cola_vacia(Nodo *frente){
  return (frente == NULL)? true : false; 
}

//Función para eliminar elementos de la cola
void suprimirCola(Nodo *&frente,Nodo *&fin,char &n){
  n = frente->dato;
  Nodo *aux = frente;
  
  if(frente == fin){
    frente = NULL;
    fin = NULL;
  }
  else{
    frente = frente->siguiente;
  }
  
  delete aux;
}
