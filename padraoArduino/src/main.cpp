#include <Arduino.h>

#define led_vermelho 4
#define botaoliga 10

int estadoBotao;


void setup()
{
    Serial.begin(9600);
    pinMode(4, OUTPUT);    
    pinMode(10,INPUT_PULLUP);
    
}

void loop()
{
  
  estadoBotao = digitalRead(10);
    
    if(estadoBotao==0)
    {
      digitalWrite(4,HIGH);
      Serial.println("Ligado");
    }else
    {
      digitalWrite(4,LOW);
      Serial.println("Desligado");
    }

}
