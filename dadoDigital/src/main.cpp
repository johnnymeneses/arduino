/*=============================================================================
Autor:        Johnny Meneses [bilbo_vader@outlook.com]
Descrição:    Dado digital
VersãO:       1.0 [01/10/20]

Lista de Componentes
[1] Arduino Uno R3
[1] 220 Ω Resistor
[1] Pushbutton
[11 Anode 7 Segment Display


 *===========================================================================*/ 

#include <Arduino.h>

//Pontos de cima
const int G = 12;
const int F = 11;
//resistor 
const int A = 10;
const int B = 9;

//Pontos de baixo
const int E = 7;
const int D = 6;
const int C = 5;
const int PT = 4; // setemaos o ponto do display

boolean ligaPonto = false;

#define botao 8


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


void instalaDisplay()
{
  
    pinMode(A, OUTPUT); // seta todos as portas que estão os leds do display como saída
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(PT, OUTPUT);
}


void animacao()
{
  for(int i=0;i<=3;i++)
  {
    digitalWrite(A, 0);
    delay(075);
    desligado();

    digitalWrite(B, 0);
    delay(075);
    desligado();

    digitalWrite(C, 0);
    delay(075);
    desligado();

    digitalWrite(D, 0);
    delay(075);
    desligado();

    digitalWrite(E, 0);
    delay(075);
    desligado();

    digitalWrite(F, 0);
    delay(075);
    desligado(); 
  }
    
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




void numero1()
{
  digitalWrite(A, d); //acende os leds que representam o número 1
  digitalWrite(B, l);
  digitalWrite(C, l);
  digitalWrite(D, d);
  digitalWrite(E, d);
  digitalWrite(F, d);
  digitalWrite(G, d);
  blinkDP();
  
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
  blinkDP();
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
  blinkDP();

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
  blinkDP();
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
  blinkDP();

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
  blinkDP();
}


void sorteiaDado()
{
  switch(random(1, 6)) // Escolhe um numero aleatorio entre 0 e 9
    {
      case 1 :
        numero1();
        delay(2000);
        break;
      case 2 :
        numero2();
        delay(2000);
        break;
      case 3 :
        numero3();
        delay(2000);
        break;
      case 4 :
        numero4();
        delay(2000);
        break;
      case 5 :
        numero5();
        delay(2000);
        break;
      case 6 :
        numero6();
        delay(2000);
        break;
    
    }

}
    

void setup()
{
    Serial.begin(9600);
    instalaDisplay();    
    pinMode(botao, INPUT_PULLUP); //seta porta do botão 
  
}

void loop()
{
  desligado();
  
  if (digitalRead(botao) == LOW) 
  {
    animacao();
    sorteiaDado();  
  }

}