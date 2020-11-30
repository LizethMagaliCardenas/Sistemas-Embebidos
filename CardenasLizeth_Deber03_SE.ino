/*
 * CAPÍTULO III: MÓDULOS DE COMUNICACIÓN 
 * DEBER 3: Envío y recepción de datos 
 * OBJETIVO: Realizar un programa de juego de preguntas. Se debe tener mínimo 8 preguntas que deben observarse en orden aleatorio. La forma de visualización es por medio de comunicación serial. Su respuesta solo debe ser "SI" y "NO" ingresadas de la misma forma por comunicación serial.
 * Al final de mostrar solo 5 de las 8 preguntas. Se presentan el puntaje (respuestas acertadas) en un display.
 * Nombre: Magali Cardenas
 * Sistemas Embebidos
 *           
 */
String dat0;
String dat1;
String dat2;
String dat3;
String dat4;
String dat5;
String dat6;
String dat7;
String dat8;

int preg0 =0;
int preg1 =0;
int preg2 =0;
int preg3 =0;
int preg4 =0;
int preg5 =0;
int preg6 =0;
int preg7 =0;
int preg8 =0;

const int A= 8; // pin 8 conectado a decodificador
 const int B= 9; // pin 9 conectado a decodificador
 const int C=10; // pin 10 conectado a decodificador
 const int D=11; // pin 11 conectado a decodificador
 
int result=0;
int AB=1;



void setup() {

  pinMode(A,OUTPUT); // pin8 declarado como salida
  pinMode(B,OUTPUT); // pin9 declarado como salida
  pinMode(C,OUTPUT); // pin10 declarado como salida
  pinMode(D,OUTPUT); // pin11 declarado como salida
  
  Serial.begin(9600);
  Serial.println("Responda las siguientes preguntas segun correspoda non SI/NO:");
  Serial.println("Las respuestas deben estar en mayuscula");
  }

void loop() {
  delay(1000);
  if(AB==1){
    AB=0;
    int num,i;
    for (i=0;i<5;i++){
      delay(3);
      randomSeed(millis());// CODIGO DE ALEACIÓN
      num=random(8);
      Serial.print(num);
        if(num==0){
        delay(1000);
         Serial.println(""); 
        Serial.println(" *Dulce es un tipo de sabor primario");
        delay(5000);
        if(Serial.available()>0){
          dat0=Serial.readString();
          if(dat0=="SI"){
            preg0=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else ; 
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==1){
        delay(1000);
        Serial.println(" *2+2 son 4");
        delay(5000);
        if(Serial.available()>0){
          dat1=Serial.readString();
          if(dat1=="SI"){
            preg1=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else 
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==2){
        delay(1000);
        Serial.println(" *La antartida es el lugar más cálido de la tierra ");
        delay(5000);
        if(Serial.available()>0){
          dat2=Serial.readString();
          if(dat2=="NO"){
            preg2=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else 
           Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==3){
        delay(1000);
        Serial.println(" *Bogota es la capital de Ecuador");
        delay(5000);
        if(Serial.available()>0){
          dat3=Serial.readString();
          if(dat3=="NO"){
            preg3=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else  
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==4){
        delay(1000);
        Serial.println(" *Ecuador se encuentra en el continente Americano ");
        delay(5000);
        if(Serial.available()>0){
          dat4=Serial.readString();
          if(dat4=="SI"){
            preg4=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else 
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==5){
        delay(1000);
        Serial.println(" *El cuerpo humano tiene 206 huesos ");
        delay(5000);
        if(Serial.available()>0){
          dat5=Serial.readString();
          if(dat5=="SI"){
            preg5=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else  
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==6){
        delay(1000);
        Serial.println(" *La cartografía es el estudio del espacio ");
        delay(5000);
        if(Serial.available()>0){
          dat6=Serial.readString();
          if(dat6=="NO"){
            preg6=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==7){
        delay(1000);
        Serial.println(" *Italia es un país con forma de bota ");
        delay(5000);
        if(Serial.available()>0){
          dat7=Serial.readString();
          if(dat7=="SI"){
            preg7=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else
           Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
        if(num==8){
        delay(1000);
        Serial.println(" *El sol sale en el dia");
        delay(5000);
        if(Serial.available()>0){
          dat8=Serial.readString();
          if(dat8=="SI"){
            preg8=1;
             Serial.println(""); 
            Serial.println(" Correcto");
          }else
          Serial.println(" Incorrecto");
        }
        Serial.println(""); 
        }
             
    result = preg0+preg1+preg2+preg3+preg4+preg5+preg6+preg7+preg8;
    // DISPLAY
    if(result==0){
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
    }
    if(result==1){
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
    }
    if(result==2){
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
    }
    if(result==3){
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,LOW);
    }
    if(result==4){
        digitalWrite(A,LOW);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
    }
    if(result==5){
        digitalWrite(A,HIGH);
        digitalWrite(B,LOW);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
   }
    Serial.println(String("El puntaje obtenido es: ")+String(result));
  }
}
}
