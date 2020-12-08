/*   
 * Universidad Tecnica del Norte 
 * Facultad de ingeniería en ciencias aplicadas
 * Nombre: Magali Cardenas
 * Memoria EPROM    
 * OBJETIVO: Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM. 
 * Como estado inicial, la contraseña es de 4 dígitos que son: 4563.
 * 
 */
#include <EEPROM.h>

int clave=4563;//inicializacion de variables
String dato;
int nuevo;
int CONT;
int on=0;

void setup() {
  Serial.begin(9600);
  EEPROM.get(0,CONT);
  attachInterrupt(0,activacion,LOW);
}

void loop() {
  if(on==1){
    if(Serial.available()>0){
      dato=Serial.readString();
      nuevo=dato.toInt();
    }
    CONT=nuevo;
  }
  if(on==2){
    if(CONT==clave){
      Serial.println("Clave ingresada correcta");
      delay(5000);
    }
    else{
      Serial.println("La clave que ha ingresado es incorrecta");
      delay(5000);
    }
  }
  if(on==3){
      if(Serial.available()>0){
        dato=Serial.readString();
        nuevo=dato.toInt();
      }
      EEPROM.update(0,CONT);
      CONT=nuevo;  
      clave=CONT;
  }
}

void activacion(){ //método de activación de interrupción
  switch(on){
    case 0:
      Serial.println("INICIO DE SISTEMA");
      Serial.println("Digite Clave: ");
      on++;
    break;
    case 1:
      Serial.println(" ");    
      Serial.println("Validar clave");
      on++;
    break;
    case 2:
      Serial.println(" ");
      Serial.println("Cambiar la clave");
      Serial.println("Ingrese nueva clave: ");
      on++;
    break;
    case 3:
      Serial.println("Registro de clave exitoso! ");
      CONT=0;  //Inicialización de variables
      on=0;    //Inicialización de variables
      nuevo=0;  //Inicialización de variables
    break;
  }
}
