/* 
*CAP II: PUERTOS DIGITALES
*DEBER I: Puertos digitales
*Objetivos: Juego de leds
*Funciones:
*      PinMode(pin, MODO)
*            MODO->(pin,ESTADO)
*      DigitalWrite(pin,ESTADO)
*            ESTADO->HIGH, LOW
*      delay(ms)
*             ms->tiempo en milisegundos
*/
const int led1=8;
const int led2=9;
const int led3=10;
const int led4=11;
const int led5=12;
const int led6=13;

const int sw1=5;
const int sw2=6;
const int sw3=7;
const int sw4=4;

int i=0; // variable para ciclo if
int j=0; // variable para ciclo while

void setup() {
  pinMode(led1,OUTPUT);//pin 8 como salida
  pinMode(led2,OUTPUT);//pin 9 como salida
  pinMode(led3,OUTPUT);//pin 10 como salida
  pinMode(led4,OUTPUT);//pin 11 como salida
  pinMode(led5,OUTPUT);//pin 12 como salida
  pinMode(led6,OUTPUT);//pin 13 como salida
  
  pinMode(sw1,INPUT);//pin 8 como salida
  pinMode(sw2,INPUT);//pin 9 como salida
  pinMode(sw3,INPUT);//pin 10 como salida
  pinMode(sw4,INPUT);//pin 11 como salida


}

void loop() {
  // JUEGO 1
  // Enciende leds pares mediante la activación de un switch(sw1)
  for(i=0;i<=10;i++){
if(digitalRead(sw1)==HIGH){
  digitalWrite(led2,HIGH);
  
}
else
digitalWrite(led2,LOW);
if(digitalRead(sw1)==HIGH){
  digitalWrite(led4,HIGH);
  
}
else
digitalWrite(led4,LOW);

if(digitalRead(sw1)==HIGH){
  digitalWrite(led6,HIGH);
  
}
else
digitalWrite(led6,LOW);
  }
  //JUEGO 2
// Enciende leds impares mediante la activación de un switch(sw2)
for(i=0;i<=10;i++){
if(digitalRead(sw2)==HIGH){
  digitalWrite(led1,HIGH);
  
}
else
digitalWrite(led1,LOW);
if(digitalRead(sw2)==HIGH){
  digitalWrite(led3,HIGH);
  
}
else
digitalWrite(led3,LOW);

if(digitalRead(sw2)==HIGH){
  digitalWrite(led5,HIGH);
  
}
else
digitalWrite(led5,LOW);
}
// Enciende leds secuenciales mediante la activación de un switch(sw3)
//JUEGO 3
if(digitalRead(sw3)==HIGH){
  digitalWrite(led1,HIGH); 
  delay(1200);
}
else
digitalWrite(led1,LOW);

if(digitalRead(sw3)==HIGH){
  digitalWrite(led2,HIGH);
  delay(1000);
}
else
digitalWrite(led2,LOW);

if(digitalRead(sw3)==HIGH){
  digitalWrite(led3,HIGH);
  delay(800);
}
else
digitalWrite(led3,LOW);

if(digitalRead(sw3)==HIGH){
  digitalWrite(led4,HIGH);
  delay(600);
}
else
digitalWrite(led4,LOW);

if(digitalRead(sw3)==HIGH){
  digitalWrite(led5,HIGH);

 delay(400);
}
else
digitalWrite(led5,LOW);
if(digitalRead(sw3)==HIGH){
  digitalWrite(led6,HIGH);
  delay(200);
}
else
digitalWrite(led6,LOW);

// Enciende leds de par de afuera hacia adentro mediante la activación de un switch(sw4)
//JUEGO 4
if(digitalRead(sw4)==HIGH){
  digitalWrite(led1,HIGH); 
  delay(400);
}
else
digitalWrite(led1,LOW);

if(digitalRead(sw4)==HIGH){
  digitalWrite(led6,HIGH);
  delay(400);
}
else
digitalWrite(led6,LOW);

if(digitalRead(sw4)==HIGH){
  digitalWrite(led2,HIGH);
  delay(200);
}
else
digitalWrite(led2,LOW);

if(digitalRead(sw4)==HIGH){
  digitalWrite(led5,HIGH);
  delay(200);
}
else
digitalWrite(led5,LOW);

if(digitalRead(sw4)==HIGH){
  digitalWrite(led4,HIGH);

 delay(400);
}
else
digitalWrite(led4,LOW);
if(digitalRead(sw4)==HIGH){
  digitalWrite(led3,HIGH);
  delay(400);
}
else
digitalWrite(led3,LOW);
}
