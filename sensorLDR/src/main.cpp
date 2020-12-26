#include <Arduino.h>

//FotoResistor
const int pinoLDR = A0; //PINO ANALÓGICO UTILIZADO PELO LDR


void setup() 
{
  
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT); //DEFINE O PINO COMO ENTRADA
  
}
 

void loop() 
{  

  if (analogRead(pinoLDR) >400) 
    {
      Serial.println(analogRead(pinoLDR));                
    }else
    {
      Serial.println(analogRead(pinoLDR));                
    }
  

}