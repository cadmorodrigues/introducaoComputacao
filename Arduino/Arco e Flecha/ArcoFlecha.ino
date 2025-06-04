
const int botao = 2;     // botao no pino 2
const int flecha1 =  3; // flecha errada da esquerda
const int flecha2 =  4;  // flecha certa do meio 
const int flecha3 =  5;  // flecha errada da direita
const int elipse1 = 6;
const int elipse2 = 7;
const int elipse3 = 8;
int apertou = 0; //ler se botao foi apertado
int contador = 0;
int flecha; //valor que flecha receberá
int i; //contador para led piscar

void setup() 
{
  pinMode(botao, INPUT);   
  pinMode(flecha1, OUTPUT);      
  pinMode(flecha2, OUTPUT);  
  pinMode(flecha3, OUTPUT);    
  pinMode(elipse1, OUTPUT);      
  pinMode(elipse2, OUTPUT);  
  pinMode(elipse3, OUTPUT);   
}

void loop()
{
    digitalWrite(flecha1, LOW);   // desliga flecha 1
    digitalWrite(flecha2, LOW);   // desliga flecha 2
    digitalWrite(flecha3, LOW);   // desliga flecha 3
  while (contador==0)
  {
    digitalWrite(elipse1, HIGH);   // liga elipse 1
    digitalWrite(elipse2, LOW);   // desliga elipse 2
    digitalWrite(elipse3, LOW);   // desliga elipse 3
    delay(1000);  
    digitalWrite(elipse2, HIGH);   // liga elipse 2
    digitalWrite(elipse1, LOW);   // desliga elipse 1
    digitalWrite(elipse3, LOW);   // desliga elipse 3
    delay(1000);  
    digitalWrite(elipse3, HIGH);   // liga elipse 3
    digitalWrite(elipse1, LOW);   // desliga elipse 1
    digitalWrite(elipse2, LOW);   // desliga elipse 2
    delay(1000);  
    digitalWrite(elipse3, LOW);   // desliga elipse 3
  
    apertou = digitalRead(botao);
      delay(2000);
    if (apertou == HIGH) 
    {     
      contador++;  
      digitalWrite(elipse1, LOW);   // desliga elipse 1
      digitalWrite(elipse2, LOW);   // desliga elipse 2
      digitalWrite(elipse3, LOW);   // desliga elipse 3
    } 
    while (contador==1)
    {
      apertou = digitalRead(botao);
      delay(2000);
      if (apertou == HIGH) 
      {     
        flecha=random(1,3);
        contador=0;
        if (flecha == 1)
        {
         digitalWrite(flecha1, HIGH);   // liga flecha 1
         delay (1200);
         digitalWrite(flecha1, LOW);   // desliga flecha 1
         delay (1200);
         }
        if (flecha == 2) //Flecha Certa
        {
           digitalWrite(flecha2, HIGH);   // liga flecha 2
           delay (1200);
           digitalWrite(flecha2, LOW);   // desliga flecha 2
           delay (1);
           digitalWrite(elipse1, HIGH);   // liga elipse 1
           digitalWrite(elipse2, LOW);   // desliga elipse 2
           digitalWrite(elipse3, LOW);   // desliga elipse 3
           delay(1000);  
           digitalWrite(elipse2, HIGH);   // liga elipse 2
           digitalWrite(elipse1, LOW);   // desliga elipse 1
           digitalWrite(elipse3, LOW);   // desliga elipse 3
           delay(1000);  
           digitalWrite(elipse3, HIGH);   // liga elipse 3
           digitalWrite(elipse1, LOW);   // desliga elipse 1
           digitalWrite(elipse2, LOW);   // desliga elipse 2
           delay(1000); 
        }
         if (flecha == 3)
         {
             digitalWrite(flecha3, HIGH);   // liga flecha 3
             delay (1200);
             digitalWrite(flecha3, LOW);   // liga flecha 3
             delay (1200);
         }
        }
      } 
    }
}
