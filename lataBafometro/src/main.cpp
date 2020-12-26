#include <Arduino.h>

/*

Bafometro com duas versões: Saída analógica e digital
Digital detecta sim ou não
Analógica detecta concentração de alcool

*/
#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);

const int pinoLed = 12;
const int pinoSensor = 3;


 
// Tempo de aquecimento
int tempo_aquecimento = 300;
int valor_sensor = 0;
unsigned long time;
int status = 1;
String estado;
int posicao1;
 
void draw()
{
  // Comandos graficos para o display devem ser colocados aqui
  // Seleciona a fonte de texto
  u8g.setFont(u8g_font_8x13B);
  // Mensagens iniciais
  u8g.drawRFrame(0, 18, 128, 46, 4);
  u8g.drawStr( 30, 15, "Bafometro");
  u8g.drawStr( 10, 37, "Johnny");
 
  // Animacao caneca
  if (status == 1)
  {
    u8g.drawBox(80, 25, 20, 30);
    u8g.drawHLine(77, 24, 26);
    u8g.drawRFrame(78, 25 , 24, 32, 0);
    u8g.drawRFrame(77, 25 , 26, 32, 0);
    u8g.drawHLine(76, 57, 28);
    u8g.drawHLine(76, 58, 28);
    u8g.drawRFrame(102, 30 , 7, 20, 2);
    u8g.drawRFrame(102, 28 , 9, 24, 2);
    u8g.setColorIndex(0);
    if (time == 0)
    {
      time = 1;
    }
    u8g.drawBox(79, 25, 22, time);
    u8g.setColorIndex(1);
  }
 
  // Apos o aquecimento, exibe dados do sensor
  if (status == 0)
  {
    u8g.setFont(u8g_font_fub20);
    u8g.setColorIndex(0);
    u8g.drawBox(10, 25, 110, 33);
    u8g.setColorIndex(1);
    // Centraliza o valor na tela
    if (valor_sensor <= 99)
    {
      posicao1 = 50;
    }
    else
    {
      posicao1 = 43;
    }
    // Mostra valor do sensor
    u8g.setPrintPos(posicao1, 45);
    u8g.print(valor_sensor);
    u8g.setFont(u8g_font_ncenB08);
    // Imprime mensagem no rodape
    int tamanho = estado.length();
    int posicao = (128 / 2 - 3) - ((tamanho * 5) / 2);
    u8g.setPrintPos(posicao, 60);
    u8g.print(estado);
  }
}
 
void setup(void)
{
  Serial.begin(9600);
  pinMode(A1, INPUT);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255, 255, 255);
  }
}
 
void loop(void)
{
  // Leitura do valor do sensor
  valor_sensor = analogRead(A1);
  time = millis() / 1000;
  u8g.firstPage();
  // Tempo de aquecimento
  if (time <= tempo_aquecimento)
  {
    time = map(time, 0, tempo_aquecimento, 0, 30);
    status = 1;
  }
  else
  {
    status = 0;
  }
  // Mensagem rodape
  if (valor_sensor >= 0 and valor_sensor <= 50)
  {
    estado = "Voce nao bebeu...";
  }
  else if (valor_sensor >= 51 and valor_sensor <= 200)
  {
    estado = "Bebeu 1 cerveja ?";
  }
  else if (valor_sensor >= 201 and valor_sensor <= 400)
  {
    estado = "Bebeu 2 cervejas ?";
  }
  else if (valor_sensor >= 401 and valor_sensor <= 600)
  {
    estado = "Voce cheira a 51 !";
  }
  else if (valor_sensor >= 601)
  {
    estado = "Voce esta bebado !!";
  }
 
  // Chama a rotina de desenho na tela
  do
  {
    draw();
  }
  while ( u8g.nextPage() );
 
  delay(50);
}

