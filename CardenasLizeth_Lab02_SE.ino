/* 
 *  
 * Universidad Tecnica del Norte 
 * Facultad de ingeniería en ciencias aplicadas
 * Nombre: Magali Cardenas
 * LABORATORIO 02    
 * OBJETIVO: Desarrollo de sistema domótico
 * 
 */
 
#include <LiquidCrystal.h>
#include<TimerOne.h>

LiquidCrystal lcd(13,12,11,10,9,8); 

const int led1=4;//Definir variabes y pines para leds
const int led2=5;//Definir variabes y pines para leds
const int led3=6;//Definir variabes y pines para leds
const int led4=7;//Definir variabes y pines para leds

int conversor1; //variable para cad hora
int conversor2; //variable para cad minutos

unsigned long timer1=0;
unsigned long timer2=0;
int unitM=0; //variables de almacenamiento e incremento
int unitH=0;//variables de almacenamiento e incremento
int hora;
int minutos; 

int on=0; //interrupcion 0
int cont; //interrupcion 1
int incremento=0;
// variables y pines definidos para sensores
const int sw1=A2; 
const int sw2=A3; 
const int sw3=A4; 
const int sw4=A5;

//sistema randomico
int caso1=0;
int caso2=0;
int caso3=0;
int caso4=0;
 
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  attachInterrupt(0,activacion,LOW);
  attachInterrupt(1,modo,LOW);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(subrutina);
  caso1=random(1,5);
  caso2=random(6,13);
  caso3=random(14,21);
  caso4=random(22,30);
  pinMode(sw1,INPUT); 
  pinMode(sw2,INPUT); 
  pinMode(sw3,INPUT);
  pinMode(sw4,INPUT); 
}

void loop(){
  if(on==1||on==2){
    timer2=(millis()/1000);    
    if(timer1!=timer2){
      timer1=timer2;
      unitM++;         
    }     
    contador(); 
    imprimir();  
    ajustarHora();  
  }
  if(cont==3){
    if(digitalRead(sw1)==HIGH){
         digitalWrite(led4,HIGH);
         Serial.println("Activando Sensor 1");
         delay(1000);
       }else digitalWrite(led4,LOW);
       if(digitalRead(sw2)==HIGH){
         digitalWrite(led3,HIGH);
         Serial.println("Activando Sensor 2");
         delay(1000);
       }else digitalWrite(led3,LOW);
       if(digitalRead(sw3)==HIGH){
         digitalWrite(led2,HIGH);
         Serial.println("Activando Sensor 3");
         delay(1000);
       }else digitalWrite(led2,LOW);
       if(digitalRead(sw4)==HIGH){
         digitalWrite(led1,HIGH);
         Serial.println("Activando Sensor 4");
         delay(1000);
       }else digitalWrite(led1,LOW);
  }
}
  void ajustarHora(){    
 if(cont==2){
  //Horas
  conversor1=analogRead(0);//Conversión analoga digital en la hora
  hora=map(conversor1,0,1023,0,24);
  unitH=hora;
  //Minutos
  conversor2=analogRead(1);//Conversión analoga digital en minutos
  minutos=map(conversor2,0,1023,0,60);
  unitM=minutos;
 }
}
   
void contador(){ //método para incremento de horas y minutos
  // Minutos
  if(unitM==60){
    unitM=00;
    unitH++;
  } 
  // Horas
  if(unitH==24){
    unitH=0; 
  } 
}
   
void imprimir(){ //Datos a Mostrarse en pantalla lcd
  lcd.setCursor(0,1);
  lcd.print("Reloj:");
  lcd.setCursor(8,1);
  lcd.print(unitH);
  lcd.print(" ");
  lcd.setCursor(10,1);
  lcd.print(":");
  lcd.setCursor(12,1);
  lcd.print(unitM);
  lcd.print(" ");
}
   

void subrutina(){
  if(cont==1){
      incremento++;
      if(incremento==caso1){
            digitalWrite(led1,HIGH);
            digitalWrite(led3,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led4,HIGH);
      }
      if(incremento==caso2){
            digitalWrite(led2,LOW);
            digitalWrite(led1,HIGH);
            digitalWrite(led4,HIGH);
            digitalWrite(led3,LOW);
      }
      if(incremento==caso3){
            digitalWrite(led1,HIGH);
            digitalWrite(led2,HIGH);
            digitalWrite(led3,HIGH);
            digitalWrite(led4,HIGH);
      }
      if(incremento==caso4){
            digitalWrite(led1,LOW);
            digitalWrite(led2,LOW);
            digitalWrite(led3,LOW);
            digitalWrite(led4,LOW);
            caso1=0;
            caso2=0;
            caso3=0;
            caso4=0;
      }
  }
}


void modo(){
  if(on==2){
    switch(cont){
      case 0:
        Serial.println("Activado de luces");
        cont++;
      break;
      case 1:
        Serial.println("Modificacion de Hora");
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        cont++;
      break;
      case 2:
        Serial.println("Prueba de Sensores");  
       cont++;
      break;
      case 3:
        Serial.println("Reinicio");
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        caso1=random(1,3);
        caso2=random(6,9);
        caso3=random(11,15);
        caso4=random(18,23);
        incremento=0;
        cont=0;
      break;
    }
  }
}
void activacion(){
  switch(on){
    case 0:
      Serial.println("SISTEMA ENCENDIDO");
      lcd.begin(16,2);
      lcd.setCursor(1,0); 
      lcd.print("Bienvenido al sistema");
      on++;
    break;
    case 1:
      Serial.println("Seleccione modo:");
      Serial.println("Pulse una vez para encendido de luces");
      Serial.println("Pulse dos veces para configuracion de hora");
      Serial.println("Pulse tres veces para uso de sensores");
      Serial.println(" ");
      on++;
    break;
    case 2:
      Serial.println("SISTEMA APAGADO");
      cont=0;
      on=0;
      unitM=0;
      unitH=0;
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      digitalWrite(led4,LOW);
      lcd.noDisplay();
    break;
  }
}
