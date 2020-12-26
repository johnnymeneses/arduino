/*=============================================================================
 |    	Autor:         Johnny Meneses [bilbo_vader@outlook.com]
 |    	Descrição:    Sistema de LED simulando cruzamento de mão dupla. Após 10 execuções, o sistema entra em atenção com Amarelo Piscante
 |		Lista:
                        [1]	Arduino Uno R3
                        [4]	Red LED
                        [4]	Yellow LED
                        [4]	Green LED
                        [12]220 Ω Resistor
 *===========================================================================*/

#include <Arduino.h>

#define red1	13
#define yel1 	12
#define green1 	11

#define red2	10
#define yel2 	9
#define green2 	8

#define red3	7
#define yel3 	6
#define green3 	5

#define red4	4
#define yel4 	3
#define green4 	2



//instalação das LEDs
void instalaLed()
{	

  pinMode(red1, OUTPUT);
  pinMode(yel1, OUTPUT);
  pinMode(green1, OUTPUT);
  
  pinMode(red2, OUTPUT);
  pinMode(yel2, OUTPUT);
  pinMode(green2, OUTPUT);
  
  pinMode(red3, OUTPUT);
  pinMode(yel3, OUTPUT);
  pinMode(green3, OUTPUT);
  
  pinMode(red4, OUTPUT);
  pinMode(yel4, OUTPUT);
  pinMode(green4, OUTPUT);
	
}


//Desliga todas as LEDs
void tudoDesligado()
{
    digitalWrite(red1, LOW);
    digitalWrite(yel1, LOW);
    digitalWrite(green1, LOW);

    digitalWrite(red2, LOW);
    digitalWrite(yel2, LOW);
    digitalWrite(green2, LOW);

    digitalWrite(red3, LOW);
    digitalWrite(yel3, LOW);
    digitalWrite(green3, LOW);

    digitalWrite(red4, LOW);
    digitalWrite(yel4, LOW);
    digitalWrite(green4, LOW);

}


void amareloPiscante()
{
	digitalWrite(yel1, HIGH);
	digitalWrite(yel2, HIGH);
	digitalWrite(yel3, LOW);
	digitalWrite(yel4, LOW);
	delay(500);
	digitalWrite(yel1, LOW);
	digitalWrite(yel2, LOW);
	digitalWrite(yel3, HIGH);
	digitalWrite(yel4, HIGH);
	delay(500);
	
}


void rua1Aberto() 
{
    digitalWrite(red1, LOW);
    digitalWrite(yel1, LOW);
    digitalWrite(green1, HIGH);
    
    digitalWrite(red2, HIGH);
    digitalWrite(yel2, LOW);
    digitalWrite(green2, LOW);
    
    digitalWrite(red3, LOW);
    digitalWrite(yel3, LOW);
    digitalWrite(green3, HIGH);
    
    digitalWrite(red4, HIGH);
    digitalWrite(yel4, LOW);
    digitalWrite(green4, LOW);
}

void rua1Fechando() 
{
    digitalWrite(red1, LOW);
    digitalWrite(yel1, HIGH);
    digitalWrite(green1, LOW);
    
    digitalWrite(red2, HIGH);
    digitalWrite(yel2, LOW);
    digitalWrite(green2, LOW);
    
    digitalWrite(red3, LOW);
    digitalWrite(yel3, HIGH);
    digitalWrite(green3, LOW);
    
    digitalWrite(red4, HIGH);
    digitalWrite(yel4, LOW);
    digitalWrite(green4, LOW);
}

void tudoFechado()
{

    digitalWrite(red1, HIGH);
    digitalWrite(yel1, LOW);
    digitalWrite(green1, LOW);
    
    digitalWrite(red2, HIGH);
    digitalWrite(yel2, LOW);
    digitalWrite(green2, LOW);
    
    digitalWrite(red3, HIGH);
    digitalWrite(yel3, LOW);
    digitalWrite(green3, LOW);
    
    digitalWrite(red4, HIGH);
    digitalWrite(yel4, LOW);
    digitalWrite(green4, LOW);
}


void rua2Aberto() 
{
    digitalWrite(red1, HIGH);
    digitalWrite(yel1, LOW);
    digitalWrite(green1, LOW);
    
    digitalWrite(red2, LOW);
    digitalWrite(yel2, LOW);
    digitalWrite(green2, HIGH);
    
    digitalWrite(red3, HIGH);
    digitalWrite(yel3, LOW);
    digitalWrite(green3, LOW);
    
    digitalWrite(red4, LOW);
    digitalWrite(yel4, LOW);
    digitalWrite(green4, HIGH);
}

void rua2Fechando() 
{
    digitalWrite(red1, HIGH);
    digitalWrite(yel1, LOW);
    digitalWrite(green1, LOW);
    
    digitalWrite(red2, LOW);
    digitalWrite(yel2, HIGH);
    digitalWrite(green2, LOW);
    
    digitalWrite(red3, HIGH);
    digitalWrite(yel3, LOW);
    digitalWrite(green3, LOW);
    
    digitalWrite(red4, LOW);
    digitalWrite(yel4, HIGH);
    digitalWrite(green4, LOW);
}



//Aciona o Modo de atenção Amarelo Piscante com 10 execuções
void acionaAmareloPiscante()
{
    tudoDesligado();
    
    for (int i=0; i<10; i++)
    {
      amareloPiscante();
    }
  
  	tudoDesligado();
  	delay(1000);

}

//Aciona o fluxo normal com 10 execuções
void fluxoNormal()
{
    
     tudoDesligado();
    
    for (int i=0; i<10; i++)
    {

        rua1Aberto();
        delay(4500);
        
        rua1Fechando();
        delay(3500);
        
        tudoFechado();
        delay(2500);

        rua2Aberto();
        delay(4500);
        
        rua2Fechando();
        delay(3500);

        tudoFechado();
        delay(5500);
    }
    
    tudoDesligado();
  	delay(1000);

}





void setup()
{
	instalaLed();
  
}

void loop()
{
   
    tudoDesligado(); //Desliga Tudo
    fluxoNormal(); // Aciona o Fluxo normal
    acionaAmareloPiscante(); //Aciona o modo de atenção

}