//codigo para teste do hardware do Proj. 01

#define bot1  2
#define bot2  3
#define LED1  7
#define LED2  6

int temp,pot;

void setup() {
  Serial.begin(9600);
  pinMode(bot1,INPUT_PULLUP);
  pinMode(bot2,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
}

void loop() {
  bool botao1 = digitalRead(bot1);
  bool botao2 = digitalRead(bot2);
  if(!botao1)
    digitalWrite(LED1,1);
  else
    digitalWrite(LED1,0);
  
  if(!botao2)
    digitalWrite(LED2,1);
  else
    digitalWrite(LED2,0);
  pot = analogRead(A2);
  temp = analogRead(A3);
  Serial.print("POT: ");
  Serial.println(pot);
  Serial.print("TEMP: ");
  Serial.println(temp);
  Serial.println("\n");
  delay(300);
}
