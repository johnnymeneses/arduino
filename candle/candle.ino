/*=============================================================================
 |    Autor:        Johnny Meneses [bilbo_vader@outlook.com]
 |    Descrição:    LED - Efeito de Luz - Velas                    
 |    VersãO:       1.0 [01/10/20]
 *===========================================================================*/


const int ledAmarelo1 = 11;                                        //LED Amarelo
const int ledVermelho = 10;                                        //LED Vermelho
const int ledAmarelo2 = 9;                                         //LED Amarelo

void setup()
{
    Serial.begin(9600);  
    pinMode(ledAmarelo1, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledAmarelo2, OUTPUT);
  
}



void loop()
{
  
  candle();
    
}



                                                     
void candle()                                                       //Função que liga as LED alternando a intensidade da luz.
{
    analogWrite(ledAmarelo1, random(120)+135);
    analogWrite(ledVermelho, random(120)+135);
    analogWrite(ledAmarelo2, random(120)+135);
    delay(random(500));

}




  
