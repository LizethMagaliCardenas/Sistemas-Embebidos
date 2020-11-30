/*///////////////////////////////Master/////////////////////////////
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
 *   Nombre: Magali Cardenas 
 *   Sistemas Embebidos
 */
#include <Wire.h>  
#include <Keypad.h>
#include<LiquidCrystal.h>
 

const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char dato;  
String caracter;
String datoDig;
void setup() {
  Wire.begin();  
  Serial.begin(9600);  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Digite palabra");
  lcd.setCursor(0,1);
  Wire.onReceive(receiveEvent); 
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.read();  
    Wire.beginTransmission(4); 
    Wire.write(dato); 
    Wire.endTransmission();  
  }
  lcd.setCursor(0,1);
  delay(1000);
}

void receiveEvent(){
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
   lcd.print(datoDig);
}
