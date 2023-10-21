#include <Arduino.h>
int n,x=0,y=1,z=1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  do{
    Serial.print("Digite la cantidad de digitos de la serie: ");
    while (!Serial.available()) {}
    n = Serial.parseInt();
  }while(n<=0);
  
  Serial.print("1 ");
  for(int i=1;i<n;i++){
    z = x + y;
    Serial.print(z);
    Serial.print(" ");
    x = y;
    y = z;    
  }
  
  Serial.println();
}