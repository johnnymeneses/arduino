/*=============================================================================
Autor:        Johnny Meneses [bilbo_vader@outlook.com]
Descrição:    Configuracao dos pinos do LED de 7 segmentos
              Loop com sequencia Crescente e Decrescente
              
Lista de Componentes
[1] Display 7 Segmentos
[1]	Arduino Uno R3
[1] 220 Ω Resistor

 *===========================================================================*/  

#include <Arduino.h>

const int G = 12;
const int F = 11;
const int A = 10; // Primeiramente setamos os 7 pinos dos segmentos
const int B = 9;

const int E = 7;
const int D = 6;
const int C = 5;
const int PT = 4; // setemaos o ponto do display

boolean ligaPonto = false;

const int l = 0, d = 1; // Display 7 segmentos (anodo comum)



//Desliga todas as luzes
void desligado() 
{
  digitalWrite(A, d); 
  digitalWrite(B, d);
  digitalWrite(C, d);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, d); 
}


void numero1()
{
  digitalWrite(A, d); //acende os leds que representam o número 1
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, d);
  
}

void numero2()
{
  
  digitalWrite(A, l); //acende os leds que representam o número 2
  digitalWrite(B, l);
  digitalWrite(C, d);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, d);
  digitalWrite(G, l);
  
}

void numero3()
{
  digitalWrite(A, l); //acende os leds que representam o número 3
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, l);
  

}

void numero4()
{
  
  digitalWrite(A, d); //acende os leds que representam o número 4
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, l);
  digitalWrite(G, l);
  
}

void numero5()
{
  digitalWrite(A, l); //acende os leds que representam o número 5
  digitalWrite(B, d);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, d);
  digitalWrite(F, l);
  digitalWrite(G, l);


}

void numero6()
{
  digitalWrite(A, d); //acende os leds que representam o número 6
  digitalWrite(B, d);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, l);
  digitalWrite(G, l);

}

void numero7()
{
  digitalWrite(A, l); //acende os leds que representam o número 6
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, d);
  
}


void numero8()
{
  digitalWrite(A, l); //acende os leds que representam o número 6
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, l);
  digitalWrite(G, l);

}


void numero9()
{
  digitalWrite(A, l); //acende os leds que representam o número 6
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, d);
  digitalWrite(F, l);
  digitalWrite(G, l);
  
}

void numero0()
{
  digitalWrite(A, l); //acende os leds que representam o número 6
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, l);
  digitalWrite(E, l);
  digitalWrite(F, l);
  digitalWrite(G, d);

 
}


void blinkDP() { // Faz o DP piscar 2 vezes.
  for (int i=0; i<=3; i++) {
    if (ligaPonto)  {
      digitalWrite(PT, l);
    }   else  {
      digitalWrite(PT, d);
    }
    ligaPonto = !ligaPonto;
    delay(1000);
  }

} 

void contagemCrescente()
{
    numero0();
    delay(1000);

    numero1();
     delay(1000);

    numero2();
    delay(1000);

    numero3();
    delay(1000);

    numero4();
    delay(1000);

    numero5();
    delay(1000);
    
    numero6();
    delay(1000);
    
    numero7();
    delay(1000);

    numero8();
    delay(1000);

    numero9();
    delay(1000);
}


void contagemRegressiva()
{
      
    numero9();
    delay(1000);

    numero8();
     delay(1000);

    numero7();
    delay(1000);

    numero6();
    delay(1000);

    numero5();
    delay(1000);

    numero4();
    delay(1000);
    
    numero3();
    delay(1000);
    
    numero2();
    delay(1000);

    numero1();
    delay(1000);

    numero0();
    delay(1000);


}

void setup()
{
    Serial.begin(9600);
    
    pinMode(A, OUTPUT); // seta todos as portas que estão os leds do display como saída
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(PT, OUTPUT);

  
}


void loop()
{ 
  contagemCrescente();
  delay(1000);
  desligado();
  delay(1000);
  contagemRegressiva();
}