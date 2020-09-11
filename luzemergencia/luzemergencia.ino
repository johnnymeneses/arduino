//Variaveis Marcha Imperial
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

//Buzzer
const int buzzer = 13;


//LEDS
const int vermelho1 = 12;
const int verde1 = 11;
const int azul1 = 10; 

const int vermelho2 = 9;
const int verde2 = 8;
const int azul2 = 7; 

const int vermelho3 = 6;
const int verde3 = 5;
const int azul3 = 4; 


//FotoResistor
const int pinoLDR = A5; //PINO ANALÓGICO UTILIZADO PELO LDR



int counter = 0;

void setup() {
  
  Serial.begin(9600);

  pinMode(buzzer,OUTPUT);   
  pinMode(azul1, OUTPUT);
  pinMode(azul2, OUTPUT);
  pinMode(azul3, OUTPUT);
  pinMode(verde1, OUTPUT);
  pinMode(verde2, OUTPUT);
  pinMode(verde3, OUTPUT);
  pinMode(vermelho1, OUTPUT);
  pinMode(vermelho2, OUTPUT);
  pinMode(vermelho3, OUTPUT);

  
  pinMode(pinoLDR, INPUT); //DEFINE O PINO COMO ENTRADA
  
}
 

void loop() 
{  


  if (analogRead(pinoLDR) >400) 
    {
      ligaVermelho();
      firstSection();
      desligaVermelho();
      ligaTudo(); 
      Serial.println(analogRead(pinoLDR));                
    }else
    {
      noTone(buzzer);
      desligaTudo();
           
      Serial.println(analogRead(pinoLDR));                
    }
  

  

}



void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzer, note, duration);

  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    delay(duration);
  }else
  {
    delay(duration);
  }

  //Stop tone on buzzerPin
  noTone(buzzer);

  delay(50);

  //Increment counter
  counter++;
}

void firstSection()
{
  
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

}


void ligaVermelho()
{
    
    digitalWrite(vermelho1, HIGH);
    digitalWrite(vermelho2, HIGH);
    digitalWrite(vermelho3, HIGH);      

}


void desligaVermelho()
{
    
    digitalWrite(vermelho1, LOW);
    digitalWrite(vermelho2, LOW);
    digitalWrite(vermelho3, LOW);      

}


void ligaTudo()
{
    digitalWrite(azul1, HIGH);
    digitalWrite(azul2, HIGH);
    digitalWrite(azul3, HIGH);
    
    digitalWrite(verde1, HIGH);
    digitalWrite(verde2, HIGH);
    digitalWrite(verde3, HIGH);
    
    digitalWrite(vermelho1, HIGH);
    digitalWrite(vermelho2, HIGH);
    digitalWrite(vermelho3, HIGH);    
    
    delay(50000);

}



void desligaTudo()
{
    digitalWrite(azul1, LOW);
    digitalWrite(azul2, LOW);
    digitalWrite(azul3, LOW);
    
    digitalWrite(verde1, LOW);
    digitalWrite(verde2, LOW);
    digitalWrite(verde3, LOW);
    
    digitalWrite(vermelho1, LOW);
    digitalWrite(vermelho2, LOW);
    digitalWrite(vermelho3, LOW);    
  

}
