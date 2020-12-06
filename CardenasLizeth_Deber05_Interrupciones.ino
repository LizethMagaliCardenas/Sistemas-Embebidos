#include <Servo.h>
 Servo servo1;// creación de objeto para servo 1
 int conversor1; // variable para conversor 1

 int on=0; // int o
 int cont;//int 1
 int i;
 int j;
 String dato;
 int giro=0;
 
void setup() {
  
  Serial.begin(9600);
  servo1.attach(5);   // configuración de servo 1
  attachInterrupt(0,activacion,LOW);
  
  

}

void loop() {
  if (on==2){
          
  if(Serial.available()>0){        // condición de recepción de datos
     dato=Serial.readString();    // almacenamiento de dato ingresado en variable
     giro=dato.toInt();           // conversión a entero
    }
  if(giro<180)                   //si cumple condición máxima de giro
      servo1.write(giro);  //    impresión de valor en servo 2
      
   else
   Serial.println("Dato Inválido");   // mensaje de error
   delay(200); // espera de estabilización
  
    
  }

}
void activacion(){
  
  switch(on){
    case 0:
    Serial.println("INICIO DE SISTEMA");
    Serial.println("Ingrese el valor de giro del motor:");
    on++;
    break;
    case 1:
    Serial.println(" ");
    Serial.println("Inicio giro");

    on++;
    break;
    case 2:
    Serial.println(String("Se da un giro de:")+String(giro+String(" grados")));
    Serial.println("Fin de giro");
    
    cont=0;
    i=0;
    j=0;
    on=0;
    break;
    
  }
}
