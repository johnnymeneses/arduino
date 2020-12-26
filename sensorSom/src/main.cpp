#include <Arduino.h>

//sensor DE SOM
const int PINO_SENSOR = A0; // Pino A0 conectado ao sensor de som


void setup()
{
    Serial.begin(9600);
    pinMode(PINO_SENSOR, INPUT); // Pino A0 definido como saida  
  
  
}

void loop()
{

    analogRead(PINO_SENSOR); // Le as informacoes obtidas do sensor
    delay(50); // Tempo de atualizacao de informacoes
    Serial.println(PINO_SENSOR);


}
