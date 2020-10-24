/*=============================================================================
Autor:        Johnny Meneses [bilbo_vader@outlook.com]
Descrição:    Arvore de Natal com duas sequências de LED.
                O botão esquedo aciona uma sequencia padrão de pisca pisca
                O botão da direita aciona uma sequencia frenética

Lista de Componentes
[1] Arduino Uno R3
[2] Yellow LED
[1] LED RGB
[4] Green LED
[2] Red LED
[8] 220 Ω Resistor
[3] 330 Ω Resistor
[2] Pushbutton

 *===========================================================================*/  

const int led1 = 13; 
const int led2 = 2; 
const int led3 = 3; 
const int led4 = 4;

const int azul = 5;
const int verde = 6;
const int vermelho = 9;

const int led5 = 8; 
const int led6 = 7; 
const int led7 = 10; 
const int led8 = 11;

int botao = 0;


#define botaoBasico 0
#define botaoPisca 12 

void setup()
{
  Serial.begin(9600);  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
   pinMode(azul, OUTPUT);
   pinMode(verde, OUTPUT);
   pinMode(vermelho, OUTPUT);
  
  
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  pinMode(botaoPisca, INPUT_PULLUP);
  
}

void loop()
{


if(digitalRead(botaoPisca) == LOW)
 {

   for (int i=0; i<100; i++)
   {
    anima1();
   }
 
 }


if(digitalRead(botaoBasico) == LOW)
 {


  for (int i=0; i<100; i++)
   {
    anima7();
    anima2();
    anima3(); 
    anima4();
    anima5();
    anima6();        
    
  
   }
   
 }



  
    
}



//Tudo Ligado
void ligado()
{
  
  digitalWrite(led1, HIGH);        
  digitalWrite(led2, HIGH);       
  digitalWrite(led3, HIGH);       
  digitalWrite(led4, HIGH);       
  
  digitalWrite(azul, HIGH);       
  digitalWrite(verde, HIGH);      
  digitalWrite(vermelho, HIGH);
  
  
  digitalWrite(led5, HIGH);       
  digitalWrite(led6, HIGH);       
  digitalWrite(led7, HIGH); 
  digitalWrite(led8, HIGH);   
}


//Tudo Desligado
void desligado()
{
  
  digitalWrite(led1, LOW);        
  digitalWrite(led2, LOW);       
  digitalWrite(led3, LOW);       
  digitalWrite(led4, LOW);       
  
  
  digitalWrite(led5, LOW);       
  digitalWrite(led6, LOW);       
  digitalWrite(led7, LOW); 
  digitalWrite(led8, LOW);   
}      




//Animações
void anima1()
{
  for(int i=0; i<10; i++)
  {
    piscaPisca();
    desligado();
    rgbDesligado();
  }
}


void anima2()
{
  for(int i=0; i<4; i++)
  {
    rgbStar();
    sobeDesce();  
    desligado();
    rgbDesligado();
  }
}

void anima3()
{
  for(int i=0; i<4; i++)
  {
    rgbCombina();  
    desligado();
    rgbDesligado();
  }
}

void anima4()
{
  for(int i=0; i<4; i++)
  {
    inicioFim();
    desligado();
    rgbDesligado();
  }
}

void anima5()
{
   for(int i=0; i<6; i++)
   {
     sobeDesce();     
     desligado();
    rgbDesligado();
   }
}

void anima6()
{
   for(int i=0; i<4; i++)
   {
     rgbStar();
     esquerdaDireita(); 
     desligado();
    rgbDesligado();
   }
    
  
}


void anima7()

{
  for(int i=0; i<6; i++)
  {
    ligaUm();
  }
}






//Animação Sobe e Desce

void sobeDesce()
{
  
  
  digitalWrite(led1, HIGH);      
  digitalWrite(led5, HIGH);      
  delay(50);
  desligado();
  
  digitalWrite(led2, HIGH);      
  digitalWrite(led6, HIGH);      
  delay(50);
  desligado();
  
  digitalWrite(led3, HIGH);      
  digitalWrite(led7, HIGH);      
  delay(50);
  desligado();
  
  digitalWrite(led4, HIGH);      
  digitalWrite(led8, HIGH);      
  delay(50);
  desligado();
  
  digitalWrite(led4, HIGH);      
  digitalWrite(led8, HIGH);      
  delay(50);
  desligado();
  
  
  digitalWrite(led3, HIGH);      
  digitalWrite(led7, HIGH);      
  delay(50);
  desligado();
  
  digitalWrite(led2, HIGH);      
  digitalWrite(led6, HIGH);      
  delay(50);
  desligado();
  
  digitalWrite(led1, HIGH);      
  digitalWrite(led5, HIGH);      
  delay(50);
  desligado();
  
}



void esquerdaDireita()
{
  digitalWrite(led1, HIGH);      
  digitalWrite(led2, HIGH);      
  digitalWrite(led3, HIGH);      
  digitalWrite(led4, HIGH);      
  delay(120);
  desligado();

  digitalWrite(led5, HIGH);      
  digitalWrite(led6, HIGH);      
  digitalWrite(led7, HIGH);      
  digitalWrite(led8, HIGH);      
  delay(120);
  desligado();


  digitalWrite(led1, HIGH);      
  digitalWrite(led6, HIGH);      
  digitalWrite(led3, HIGH);      
  digitalWrite(led8, HIGH);      
  delay(120);
  desligado();

  digitalWrite(led2, HIGH);      
  digitalWrite(led4, HIGH);      
  digitalWrite(led5, HIGH);      
  digitalWrite(led7, HIGH);      
  delay(120);
  desligado();


  

}


void rgbCombina()
{
    desligado();
    
    rgbBranco();
    digitalWrite(led4, HIGH);      
    digitalWrite(led8, HIGH); 
    delay(250);
    desligado();
    
    
    rgbVermelho();
    digitalWrite(led2, HIGH);      
    digitalWrite(led6, HIGH);  
    delay(250);
    desligado();


    rgbVerde();
    digitalWrite(led1, HIGH);      
    digitalWrite(led3, HIGH);  
    digitalWrite(led5, HIGH);      
    digitalWrite(led7, HIGH);  
    delay(250);
    desligado();

    
}


void inicioFim()
{
  digitalWrite(led1, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led2, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led3, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led4, HIGH); 
  delay(50);
  desligado();

  

  digitalWrite(led8, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led7, HIGH); 
  delay(50);
  desligado();
  

  digitalWrite(led6, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led5, HIGH); 
  delay(50);
  desligado();




  digitalWrite(led5, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led6, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led7, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led8, HIGH); 
  delay(50);
  desligado();

  

  digitalWrite(led4, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led3, HIGH); 
  delay(50);
  desligado();
  

  digitalWrite(led2, HIGH); 
  delay(50);
  desligado();

  digitalWrite(led1, HIGH); 
  delay(50);
  desligado();

  rgbStar();

}



void ligaUm()
{
  
digitalWrite(led1, HIGH);  
rgbVerde();
delay(50);
desligado();
rgbDesligado();

digitalWrite(led2, HIGH); 
rgbVermelho();
delay(50);
desligado();
rgbDesligado();
  
digitalWrite(led3, HIGH); 
rgbAzul();
delay(50);
desligado();
rgbDesligado();
  
digitalWrite(led4, HIGH); 
rgbRaspberry();
delay(50);
desligado();
rgbDesligado();

digitalWrite(led5, HIGH); 
rgbBranco();
delay(50);
desligado();
rgbDesligado();

digitalWrite(led6, HIGH); 
rgbCyan();
delay(50);
desligado();
rgbDesligado();


digitalWrite(led7, HIGH); 
rgbMagenta();
delay(50);
desligado();
rgbDesligado();

digitalWrite(led8, HIGH); 
rgbYellow();
delay(50);
desligado();
rgbDesligado();   
}


void piscaPisca()
{
  desligado();
  rgbDesligado();


  rgbBranco();  
  digitalWrite(led1, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led6, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();

  rgbVerde();
  digitalWrite(led5, HIGH); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbVermelho();
  digitalWrite(led1, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led7, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbAzul();
  digitalWrite(led5, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led4, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbRaspberry();
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbCyan();
  digitalWrite(led1, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbMagenta();
  digitalWrite(led7, HIGH); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbYellow();
  digitalWrite(led4, HIGH); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led2, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();



  /*2*/
  rgbBranco();  
  digitalWrite(led7, HIGH); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();

  rgbVerde();
  digitalWrite(led1, HIGH); 
  digitalWrite(led5, HIGH); 
  digitalWrite(led6, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbVermelho();
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbAzul();
  digitalWrite(led3, HIGH); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led7, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbRaspberry();
  digitalWrite(led6, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led2, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbCyan();
  digitalWrite(led2, HIGH); 
  digitalWrite(led5, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbMagenta();
  digitalWrite(led3, HIGH); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led7, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbYellow();
  digitalWrite(led2, HIGH); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led1, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();

  /*3*/
rgbBranco();  
  digitalWrite(led2, HIGH); 
  digitalWrite(led4, HIGH); 
  digitalWrite(led7, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();

  rgbVerde();
  digitalWrite(led1, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbVermelho();
  digitalWrite(led2, HIGH); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbAzul();
  digitalWrite(led1, HIGH); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led8, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();


  rgbRaspberry();
  digitalWrite(led4, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbCyan();
  digitalWrite(led8, HIGH); 
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbMagenta();
  digitalWrite(led6, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led7, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();
  
  rgbYellow();
  digitalWrite(led4, HIGH); 
  digitalWrite(led6, HIGH); 
  digitalWrite(led2, HIGH); 
  delay(500);
  desligado();
  rgbDesligado();

}




/* -------------------------------------- RGB CODE  -------------------------------------- */

void rgbAnalog (int luzVermelha, int luzVerde, int luzAzul)
{
  analogWrite(vermelho, luzVermelha);
  analogWrite(verde, luzVerde);
  analogWrite(azul, luzAzul);  
}


//Cor Branca


void rgbDesligado()
{
  rgbAnalog(0,0,0);
};


void rgbBranco()
{
  rgbAnalog(255,255,255);
}


void rgbVerde()
{
  rgbAnalog(0, 255, 0); // Green
}

void rgbVermelho()
{
  rgbAnalog(255, 0, 0); // Red
}

void rgbAzul()
{
  rgbAnalog(0, 0, 255); // Blue
}


void rgbRaspberry()
{
  rgbAnalog(255, 255, 125); // Raspberry
}

void rgbCyan()
{
  
  rgbAnalog(0, 255, 255); // Cyan
}

void rgbMagenta()
{
  rgbAnalog(255, 0, 255); // Magenta
}

void rgbYellow()
{
  rgbAnalog(255, 255, 0); // Yellow
}



void rgbStar()
{
  rgbBranco();
  delay(50);
  rgbDesligado();
  
  rgbVerde();
  delay(50);
  rgbDesligado();
  
  rgbVermelho();
  delay(50);
  rgbDesligado();
  
  rgbAzul();
  delay(50);
  rgbDesligado();
  
  
  rgbRaspberry();
  delay(50);
  rgbDesligado();
  
  
  rgbCyan();
  delay(50);
  rgbDesligado();
  
  
  rgbMagenta();
  delay(50);
  rgbDesligado();

  rgbYellow();
  delay(50);
  rgbDesligado();
  
 
}
