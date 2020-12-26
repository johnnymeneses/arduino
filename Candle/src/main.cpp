#include <Arduino.h>

const int RR = 11;
const int GG = 10;
const int BB = 9;

void candle()
{
    analogWrite(RR, random(120)+135);
    analogWrite(GG, random(120)+135);
    analogWrite(BB, random(120)+135);
    delay(random(500));

}



void setup()
{
    pinMode(RR, OUTPUT);
    pinMode(GG, OUTPUT);
    pinMode(BB, OUTPUT); 
}

void loop()
{

  for (int i=0;i<=10000;i++)
  {
    candle();  
  }
  

}