#include <Arduino.h>

/*=============================================================================
Autor:        Johnny Meneses [bilbo_vader@outlook.com]
Descrição:    LED - Efeito de Luz - Velas

Lista de Componentes
[1]	Arduino Uno R3
[3]	330 Ω Resistor
[2]	Yellow LED
[1]	Red LED

 *===========================================================================*/  

const int ledAmarelo1 = 11;              //LED Amarelo em uma saida PWM
const int ledVermelho = 10;              //LED Vermelho em uma saida PWM
const int ledAmarelo2 = 9;               //LED Amarelo em uma saida PWM

void setup()
{
    Serial.begin(9600);  
    pinMode(ledAmarelo1, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledAmarelo2, OUTPUT);
  
}


//Função que liga as LED alternando a intensidade da luz.
                                                     
void candle()
{
    analogWrite(ledAmarelo1, random(120)+135);
    analogWrite(ledVermelho, random(120)+135);
    analogWrite(ledAmarelo2, random(120)+135);
    delay(random(500));

}


void loop()
{
  
  candle();
    
}
