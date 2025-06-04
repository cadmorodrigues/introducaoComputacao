const int seq2 = 2;
const int seq3 = 3;
const int seq4 = 4;
const int seq5 = 5;
const int seq6 = 6;

void setup() {
  pinMode(seq2, OUTPUT);
  pinMode(seq3, OUTPUT);
  pinMode(seq4, OUTPUT);
  pinMode(seq5, OUTPUT);
  pinMode(seq6, OUTPUT);
  
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, LOW);
  digitalWrite(seq5, LOW);
  digitalWrite(seq6, LOW);
}

void loop() {

for (int i=0;i<=random(1,15);i++)
{
  digitalWrite(seq2, HIGH);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, LOW);
  digitalWrite(seq5, LOW);
  digitalWrite(seq6, LOW);
  delay(20);
  digitalWrite(seq2,LOW);
  delay(20);
} 

for (int i=0;i<=random(1,15);i++)
{
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, HIGH);
  digitalWrite(seq4, LOW);
  digitalWrite(seq5, LOW);
  digitalWrite(seq6, LOW);
  delay(20);
  digitalWrite(seq3,LOW);
  delay(20);
} 


for (int i=0;i<=random(1,15);i++)
{
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, HIGH);
  digitalWrite(seq5, LOW);
  digitalWrite(seq6, LOW);
  delay(20);
  digitalWrite(seq4,LOW);
  delay(20);
} 


for (int i=0;i<=random(1,15);i++)
{
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, LOW);
  digitalWrite(seq5, HIGH);
  digitalWrite(seq6, LOW);
  delay(20);
  digitalWrite(seq5,LOW);
  delay(20);
} 


for (int i=0;i<=random(1,15);i++)
{
  digitalWrite(seq2, LOW);
  digitalWrite(seq3, LOW);
  digitalWrite(seq4, LOW);
  digitalWrite(seq5, LOW);
  digitalWrite(seq6, HIGH);
  delay(20);
  digitalWrite(seq6,LOW);
  delay(20);
} 

}
