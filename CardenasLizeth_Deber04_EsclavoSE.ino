/*///////////////////////////////Esclavo/////////////////////////////
/*
 * CAPÍTULO III: MÓDULOS DE COMUNICACIÓN I2C
 * CÓDIGO 13: Envío y recepción de datos por cx i2c
 * OBJETIVO: Realice un sistema que codifique las vocales en palabras ingresadas por comunicación serial. 
 * Este mensaje se ingresa por comunicación serial en el master, este envía al esclavo para que realice la codificación por comunicación I2C. 
 * Luego, lo envía al master por el mismo medio y se muestra el resultado en una LCD en el master. La codificación es:
 * a=@
 * e=#
 * i= !
 * o = *
 * u= $
 * FUNCIONES: 
 *           Wire.begin()
 *           Wire.beginTransmission(address) -> ID de esclavo
 *Nombre: Cardenas Magali
 *Sistemas Embebidos
 */
#include <Wire.h>

String caracter; 
char dato;
String datoDig;

void setup() {
  Wire.begin(4);
  Serial.begin(9600);
  Wire.onReceive(receiveEvent); 
  Wire.onRequest(requestEvent);
}

void loop() {
  delay(100);    
}//end void loop

void receiveEvent(int bytes){
 while(Wire.available()){
 char palabra=Wire.read(); 
   switch(palabra){
    case 'a':
      caracter=caracter+"@";
    break;
    case 'b':
      caracter=caracter+"b";
    break;
    case 'c':
      caracter=caracter+"c";
    break;
    case 'd':
      caracter=caracter+"d";
    break;
    case 'e':
      caracter=caracter+"#";
    break;
    case 'f':
      caracter=caracter+"f";
    break;
    case 'g':
      caracter=caracter+"g";
    break;
    case 'h':
      caracter=caracter+"h";
    break;
    case 'i':
      caracter=caracter+"!";
    break;
    case 'j':
      caracter=caracter+"j";
    break;
    case 'k':
      caracter=caracter+"k";
    break;
    case 'l':
      caracter=caracter+"l";
    break;
    case 'm':
      caracter=caracter+"m";
    break;
    case 'n':
      caracter=caracter+"n";
    break;
    case 'o':
      caracter=caracter+"*";
    break;
    case 'p':
      caracter=caracter+"p";
    break;
    case 'q':
      caracter=caracter+"q";
    break;
    case 'r':
      caracter=caracter+"r";
    break;
    case 's':
      caracter=caracter+"s";
    break;
    case 't':
      caracter=caracter+"t";
    break;
    case 'u':
      caracter=caracter+"$";
    break;
    case 'v':
      caracter=caracter+"v";
    break;
    case 'w':
      caracter=caracter+"w";
    break;
    case 'x':
      caracter=caracter+"x";
    break;
    case 'y':
      caracter=caracter+"y";
    break;
    case 'z':
      caracter=caracter+"z";
    break;
    }
    
   }
   Serial.println(caracter);
   if(Serial.available()>0) {
   datoDig=Serial.read();
   }
}

void requestEvent() {
  if(Serial.available()>0){
    dato=Serial.read();  
    Wire.beginTransmission(4); 
    Wire.write(dato); 
    Wire.endTransmission();  
  }
}
