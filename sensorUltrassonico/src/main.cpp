#include <Arduino.h>

//Importando a biblioteca do Sensor de Distância
#include "Ultrasonic.h"


//Inicialização do Buzz na porta 10
const int buzzer = 10;
 
//Sensor
const int echoPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)

Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS

int distancia; //CRIA UMA VARIÁVEL CHAMADA "distancia" DO TIPO INTEIRO






//Metodo para calculo de distancia
void medeDistancia()
{
  digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
  delayMicroseconds(2); // DELAY DE 2 MICROSSEGUNDOS

  digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
  delayMicroseconds(10); // DELAY DE 10 MICROSSEGUNDOS
  digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE

  // FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
  //RESPOSTA DO ECHO EM CENTÍMETROS E ARMAZENA
  //NA VARIÁVEL "distancia"
  distancia = (ultrasonic.Ranging(CM)); // VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
  delay(50); //INTERVALO DE 500 MILISSEGUNDOS

  
}





void alarme()
{
  
  //Ligando o Buzz
  tone(buzzer,1500);   
  delay(50);
   
  //Desligando o buzzer.
  noTone(buzzer);
  delay(50); 
}



void setup() 
{
  Serial.begin(9600);
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAÍDA (ENVIA)
  pinMode(buzzer,OUTPUT);
}
 

void loop() 
{  
  medeDistancia();
  Serial.println(distancia); 

  if(distancia <10)
  {
    alarme();
  }
}