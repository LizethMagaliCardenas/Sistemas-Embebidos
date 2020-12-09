/*UNIVERSIDAD TÉCNICA DEL NORTE 
 *FICA - CITEL- SISTEMAS EMBEBIDOS
 *COD 15: MANEJO DE INTERRUPCIONES Y TIMER 2
 *OBJETIVO:Realizar un reloj con alarma ingresada por comunicación serial.  Los números sean vistos en displays.
 *Nombre: Magali Cárdenas
 */
#include<MsTimer2.h>

  const int unid1=4;
  const int dec1=5;
  const int led1=7;

  const int A=13;
  const int B=12;
  const int C=11;
  const int D=10;
  const int E=9;
  const int F=8;
  const int G=7;
  const int H=6;

  int segundos=0;
  int minutos=0;
  int horas=0;
  int uni;
  int dec;
  int on=0;
  int i=0;
  int j;
  String dato;

  void setup() {
  Serial.begin(9600);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  pinMode(led1,OUTPUT);
  pinMode(unid1,OUTPUT);
  pinMode(dec1,OUTPUT);

  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  attachInterrupt(0,activacion,LOW);
  attachInterrupt(1,contador,LOW);
 }

void loop() {
  if(on==2){
    delay(200);
  String dato=Serial.readString();
  int ingreso1=dato.toInt();
    int mnts=dato.toInt();
    if(mnts<10){
      uni=mnts;
    }else{
      dec=mnts/10;
      uni=mnts-dec*10;
      }
      for(j=0;j<10;j++){
      digitalWrite(unid1,HIGH); 
      digitalWrite(dec1,LOW); 
      contador(uni);
      delay(200);
      digitalWrite(unid1,LOW);
      digitalWrite(dec1,HIGH);
      contador(dec);
      delay(200);
      }
      digitalWrite(dec1,LOW);
      dec=0;
      uni=0;
      delay(200);
      Serial.println(ingreso1);
  }

      if(on==3){
      String dato=Serial.readString();
  int ingreso2=dato.toInt();
    int mnts=dato.toInt();
    if(mnts<10){
      uni=mnts;
    }else{
      dec=mnts/10;
      uni=mnts-dec*10;
      }
      for(j=0;j<10;j++){
      digitalWrite(unid1,HIGH); 
      digitalWrite(dec1,LOW); 
      contador(uni);
      delay(300);
      digitalWrite(unid1,LOW);
      digitalWrite(dec1,HIGH);
      contador(dec);
      delay(300);
      }
      dec=0;
      uni=0;
      digitalWrite(dec1,LOW);
      Serial.println(ingreso2);
      }
        if(minutos==0&& segundos==5)
        digitalWrite(led1,HIGH);
        delay(3000);
        digitalWrite(led1,LOW);  
   }
   

void contador (int i){
  switch(i){
      case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      break;
      case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      break;
      case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      break;
      case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);    
      break;
      case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);    
      break;
      case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);    
      break;
      case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);    
      break;
      case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);    
      break;
      case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);    
      break;
      case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);    
      break;
      }
  }
void activacion(){
  switch(on){
    case 0:
    Serial.println("INICIO DE SISTEMA");
    on++;
    break;
    case 1:
    Serial.println("Regule el valor de las horas: ");
    Serial.println();
    on++;
    break;
    case 2:
    Serial.println("Regule el valor de los minutos: ");
    Serial.println();
    on++;
    break;
    case 3:
    Serial.println("FIN DE SISTEMA");
    Serial.println();
    i=0;
    j=0;
    on=0;
    break;
    }
}

 void reloj(){
  
  if(segundos<59)
  segundos++;
  else{
    segundos=0;
    if(minutos<59)
      minutos++;
  else{
      minutos=0;
        if(horas<24)
          horas++;
          else
            horas=0;
      }
   }
}  
