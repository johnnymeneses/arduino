#include <Arduino.h>

// Preparação do Arduino, este código irá rodar uma única vez
void setup() 
{
   pinMode(13, OUTPUT); 
   pinMode(12, OUTPUT);  
   pinMode(11, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
}

// Este código é chamado automáticamente pelo Arduino, ficará em
// loop até que seu Arduino seja desligado
void loop() 
{

    //Vermelho1 - Desligado
    digitalWrite(13, HIGH);
    
    
    //Verde 2 - Ligado
    digitalWrite(5, HIGH);
    delay(2000);
    
    //Verde 2 - Desligado
    digitalWrite(5, LOW);
    delay(2000);
    
    //Amarelo 2 - Ligado
    digitalWrite(6, HIGH);
    delay(2000);
    
    //Amarelo 2 - Desligado
    digitalWrite(6, LOW);
    delay(2000);
    
    //Vermelho 2 - Ligado
    digitalWrite(7, HIGH);
    delay(2000);
    
    //Vermelho 1 - Desligado
    digitalWrite(13, LOW);
    delay(2000);
    
    //Verde 1 - Ligado
    digitalWrite(11, HIGH);
    delay(2000);
    
    //Verde 1 - Desligado
    digitalWrite(11, LOW);
    delay(2000);
    
    //Amarelo 1 - Ligado
    digitalWrite(12, HIGH);
    delay(2000);
    
    //Amarelo 1 - Desligado
    digitalWrite(12, LOW);
    delay(2000);
    
    //Vermelho 1 - Ligado
    digitalWrite(13, HIGH);
    delay(2000);
  
  
      //Todos Ligados
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
      delay(1000);
  
  
  
      //Todos Desigados
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
      delay(3000);
  
  
    //Amarelo Piscante
    digitalWrite(12, HIGH);
    digitalWrite(06, LOW);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(06, HIGH);
    delay(1000);
  
      digitalWrite(12, HIGH);
    digitalWrite(06, LOW);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(06, HIGH);
    delay(1000);
  
      digitalWrite(12, HIGH);
    digitalWrite(06, LOW);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(06, HIGH);
    delay(1000);
  
  
      digitalWrite(12, HIGH);
    digitalWrite(06, LOW);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(06, HIGH);
    delay(1000);
  
      digitalWrite(12, HIGH);
    digitalWrite(06, LOW);
    delay(1000);
    digitalWrite(12, LOW);
    digitalWrite(06, HIGH);
    delay(1000);
  
  
      //Todos Desigados
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
      delay(4000);
  
  
  
}
