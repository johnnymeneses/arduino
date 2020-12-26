/*=============================================================================
  Autor:        Johnny Meneses [bilbo_vader@outlook.com]
  Descrição:    Beat Sync que liga uma determinada LED dependendo da altura do barulho que o sensor se som é capaz de captar
  VersãO:       1.0 [12/12/20]

  Lista de Componentes
  [1] Arduino Uno R3
  [1] Sensor de Som
  [2] LED Verde
  [2] LED Vermelha
  [2] LED Azul
  [2] LED Amarela
  [8] 220 Ω Resistor
  [3] 330 Ω Resistor
  

  ===========================================================================*/

#include <Arduino.h>

#define red1  6
#define red2  7
#define yel1  8
#define yel2  9
#define gre1  10 
#define gre2  11
#define blu1  12 
#define blu2  13

const int PINO_SENSOR = A0; // Pino A0 conectado ao sensor de som



void setupSensor()
{
  pinMode(PINO_SENSOR, INPUT); // Pino A0 definido como saida

}


void setupLed()
{
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);  
  pinMode(yel1, OUTPUT); 
  pinMode(yel2, OUTPUT); 
  pinMode(gre1, OUTPUT); 
  pinMode(gre2, OUTPUT); 
  pinMode(blu1, OUTPUT); 
  pinMode(blu2, OUTPUT); 
}

void desligaLED()
{
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yel1, LOW);
  digitalWrite(yel2, LOW);
  digitalWrite(gre1, LOW);
  digitalWrite(gre2, LOW);
  digitalWrite(blu1, LOW);
  digitalWrite(blu2, LOW);
}



void barraMusical()
{
  int barulho;
  barulho = analogRead(PINO_SENSOR);
  Serial.println(barulho); // Le as informacoes obtidas do sensor

  if (barulho > 200)
  {
      digitalWrite(red1, HIGH);
      delay(10);
      desligaLED();
  }

  if (barulho > 300)
  {
      digitalWrite(red2, HIGH);
      delay(10);
      desligaLED();
  }

  if (barulho > 400)
  {
      digitalWrite(yel1, HIGH);
      delay(10);
      desligaLED();
  }

  if (barulho > 500)
  {
      digitalWrite(yel2, HIGH);
      delay(10);
      desligaLED();
  }

  if (barulho > 600)
  {
      digitalWrite(gre1, HIGH);
      delay(10);
      desligaLED();
  }

  if (barulho > 700)
  {
      digitalWrite(gre2, HIGH);
      delay(10);
      desligaLED();
  }

  if (barulho > 800)
  {
      digitalWrite(blu1, HIGH);
      delay(10);
      desligaLED();
  }

    if (barulho > 900)
  {
      digitalWrite(blu2, HIGH);
      delay(10);
      desligaLED();
  }

  else
    {
      desligaLED();
    }  
  }



void setup()
{
  setupLed();
  setupSensor();
  Serial.begin(9600); // Inicializa a comunicacao serial
}

void loop()
{
  barraMusical();

}