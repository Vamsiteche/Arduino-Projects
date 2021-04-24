const int led=13;
const int but=2;
int x;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(but,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  x=digitalRead(2);
  if(x==HIGH)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  

}
