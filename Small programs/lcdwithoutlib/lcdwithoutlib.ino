int commandvalues[]={0x38,0x0E,0x0F,0x06,0x01,0xc5};
int displaymessage[]={'L','O','V','E','L','Y'};
void command(unsigned int x)
{
  PORTD=commandvalues[x];
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(250);
  digitalWrite(8,LOW);
}
void lcddata1(unsigned int y)
{
  PORTD=displaymessage[y];
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(250);
  digitalWrite(8,LOW);
}  
void setup() {
  DDRD=0xFF;
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
for(int x=0;x<=5;x++)
{
  command(x);
  delay(250);
}
for(int y=0;y<=5;y++)
{
  lcddata1(y);
  delay(250);
}
}
