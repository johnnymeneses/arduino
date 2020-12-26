#include <Arduino.h>

//Configuracao dos pinos do LED de 7 segmentos

const int G = 12;
const int F = 4;
const int A = 3; // Primeiramente setamos os 7 pinos dos segmentos
const int B = 2;

const int E = 8;
const int D = 7;
const int C = 6;
const int PT = 5; // setemaos o ponto do display

const int buzzer = 13;


const int RR = 11;
const int GG = 10;
const int BB = 9;


boolean ligaPonto = false;

const int l = 0, d = 1; // Display 7 segmentos (anodo comum)



void beep(int note, int duration)
{
  tone(buzzer, note,duration);

}

void candle()
{
    analogWrite(RR, random(120)+135);
    analogWrite(GG, random(120)+135);
    analogWrite(BB, random(120)+135);
    delay(random(500));

}






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


void contagemRegressiva()
{
    digitalWrite(RR,LOW);
    digitalWrite(GG,LOW);
    digitalWrite(BB,LOW);
    
    
    blinkDP();
    numero9();
    beep(500,500);
    delay(1000);

    numero8();
    beep(500,500);
    delay(1000);

    numero7();
    beep(500,500);
    delay(1000);

    numero6();
    beep(500,500);
    delay(1000);

    numero5();
    beep(500,500);
    delay(1000);

    numero4();
    beep(500,500);
    delay(1000);
    
    numero3();
    beep(500,500);
    delay(1000);
    
    numero2();
    beep(500,500);
    delay(1000);

    numero1();
    beep(500,500);
    delay(1000);

    numero0();
    beep(500,500);
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
  
    pinMode(RR, OUTPUT);
    pinMode(GG, OUTPUT);
    pinMode(BB, OUTPUT);

    pinMode(buzzer,OUTPUT);         //buzzer
  
}


void loop()
{
    
  desligado();
  contagemRegressiva();
  desligado() ;
  
  for (int i=0;i<=10000;i++)
  {
    candle();  
  }
  

}