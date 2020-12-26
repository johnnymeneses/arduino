#include <Arduino.h>
 
#define LED_VERMELHO 2
#define LED_AMARELO 3
#define LED_VERDE 4
#define LED_AZUL 5

#define botaoVermelho 8
#define botaoAmarelo 9
#define botaoVerde 10
#define botaoAzul 11

#define INDEFINIDO -1

#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

#define TAMANHO_SEQUENCIA 99

int sequenciaLuzes[TAMANHO_SEQUENCIA]; //Matriz com LEDS
int rodada = 0;
int leds_respondidos=0;

enum Estados
{
  PRONTO_PARA_PROXIMA_RODADA,
  USUARIO_RESPONDENDO,
  JOGO_FINALIZADO_SUCESSO,
  JOGO_FINALIZADO_FALHA
};




 

//Declaração dos LEDS e Botões
void iniciaPortas() 
{
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);  
  
  pinMode(botaoVerde, INPUT_PULLUP);
  pinMode(botaoAmarelo, INPUT_PULLUP);
  pinMode(botaoAzul, INPUT_PULLUP);
  pinMode(botaoVermelho, INPUT_PULLUP);
}

void ligaTudo(){
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARELO, HIGH);  
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_VERMELHO, HIGH);
    delay(200);   
}


void desligaTudo()
{
  digitalWrite(LED_VERDE, LOW); 
    digitalWrite(LED_AMARELO, LOW); 
    digitalWrite(LED_AZUL, LOW);  
    digitalWrite(LED_VERMELHO, LOW);  
    delay(200);
}

int sorteiaCor()
{
    return random(LED_VERMELHO,LED_VERDE+1); //Sortear um cor entre LED_VERMELHO(2) e LED_VERDE(5) + 1
}


void iniciaJogo() 
{

  int jogo = analogRead(0); //Porta aberta em contato com o ar para variações de 
  randomSeed(jogo);//pega a leitura da porta Analoga e faz a geração dos numeros aleatorios
  
  for(int indice = 0; indice < TAMANHO_SEQUENCIA; indice ++) //de 0 a 4, sortear um LED
  {
    sequenciaLuzes[indice] = sorteiaCor(); //Matriz recebe a combinação com 4 LEDS sorteadas pelo sorteiaCor
  }

  //Serial.println(jogo);
}






int piscaLed(int portaLed) // Função que irá receber um inteiro para acender e apagar um LED
{
    digitalWrite(portaLed,HIGH);
    delay (UM_SEGUNDO);
    digitalWrite(portaLed,LOW);
    delay (MEIO_SEGUNDO);    
    return portaLed;
}





void tocaLedsRodada ()
{
  
  for(int i=0; i < rodada;i++) //Looping para percorrer a matriz com os numeros sorteados
  {
    piscaLed(sequenciaLuzes[i]); //PiscaLED informa um inteiro e executa a função de acender e apagar LED
  }
     
}





int checaRespostaJogador() 
{
  
  if (digitalRead(botaoVerde) == LOW) 
  {
      return piscaLed(LED_VERDE);
  }
   
  if (digitalRead(botaoAmarelo) == LOW) 
  {
      return piscaLed(LED_AMARELO);
  }      
        
  if (digitalRead(botaoVermelho) == LOW) 
  {
      return piscaLed(LED_VERMELHO);
  }
     
  
  if (digitalRead(botaoAzul) == LOW) 
  {
      return piscaLed(LED_AZUL);
  }
  
  
    return INDEFINIDO;
}


int estadoAtual() {
  if(rodada <= TAMANHO_SEQUENCIA) 
  {
     if(leds_respondidos == rodada)  {
       return PRONTO_PARA_PROXIMA_RODADA;
     }else {
       return USUARIO_RESPONDENDO;
     }
  }else if(rodada == TAMANHO_SEQUENCIA + 1){
      return JOGO_FINALIZADO_SUCESSO;
    }else {
      return JOGO_FINALIZADO_FALHA;
    }

}




void preparaNovaRodada()
{
  rodada++;
  leds_respondidos=0;
  if( rodada <= TAMANHO_SEQUENCIA)
  {
    tocaLedsRodada();
  }
}




void processaRespostaUsuario() {
  int resposta = checaRespostaJogador();

  if(resposta == INDEFINIDO)  {
    return;
  }

  if(resposta == sequenciaLuzes[leds_respondidos]) {
    leds_respondidos++;  
  }else  {
    Serial.println("resposta errada"); 
    rodada =  TAMANHO_SEQUENCIA + 2;
  }   
}


//Controle de Luzes

void sequencia12() {
    digitalWrite(LED_AZUL, HIGH);
    delay(50);
    digitalWrite(LED_AZUL, LOW);  
    delay(50);
        
    
    digitalWrite(LED_VERDE, HIGH);
    delay(50);
    digitalWrite(LED_VERDE, LOW); 
    delay(50);
  
    digitalWrite(LED_AMARELO, HIGH);
    delay(50);
    digitalWrite(LED_AMARELO, LOW); 
    delay(50);  
        
  
    digitalWrite(LED_VERMELHO, HIGH);
    delay(50);
    digitalWrite(LED_VERMELHO, LOW);  
    delay(50);
  
    digitalWrite(LED_VERMELHO, HIGH);
    delay(50);
    digitalWrite(LED_VERMELHO, LOW);  
    delay(50);
  
    digitalWrite(LED_AMARELO, HIGH);
    delay(50);
    digitalWrite(LED_AMARELO, LOW); 
    delay(50);
      
    digitalWrite(LED_VERDE, HIGH);
    delay(50);
    digitalWrite(LED_VERDE, LOW); 
    delay(50);

    digitalWrite(LED_AZUL, HIGH);
    delay(50);
    digitalWrite(LED_AZUL, LOW);  
    delay(50);
  
    
}


void transicao()
{
 for (int s=0;s<2;s++)
 {
  sequencia12();
 }
 ligaTudo();
 desligaTudo();
  
}







void jogoFinalizadoSucesso()
{
  for (int i=0; i<200; i++){
     digitalWrite(LED_VERDE, HIGH); 
     delay(200);
     digitalWrite(LED_VERDE, LOW);  
     delay(200);
  }
}


 void jogoFinalizadoFalha() {
   for (int i=0; i<200; i++){
    digitalWrite(LED_VERMELHO, HIGH); 
   delay(200);
  digitalWrite(LED_VERMELHO, LOW);  
   delay(200);
 }
 }
   


void setup()
{
  Serial.begin(9600);
  iniciaPortas();
  iniciaJogo();
}

void loop()
{

switch (estadoAtual()) 
  {
    case PRONTO_PARA_PROXIMA_RODADA:
      Serial.println("Pronto para a proxima rodada");
      preparaNovaRodada();
      break;
    case USUARIO_RESPONDENDO:
      Serial.println("Usuario respondendo");
      processaRespostaUsuario(); //novo
      break;
    case JOGO_FINALIZADO_SUCESSO:
      Serial.println("Jogo finalizado com sucesso");
      transicao();
      jogoFinalizadoSucesso();
      break;
    case JOGO_FINALIZADO_FALHA:
      Serial.println("Jogo finalizado com falha");
     transicao();
      jogoFinalizadoFalha();
      break;
  }
  delay(MEIO_SEGUNDO);


}
