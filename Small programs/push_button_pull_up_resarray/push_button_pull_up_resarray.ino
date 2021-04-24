 int led[]={2,3,4,5};
 int but[]={10,11,12,13};
void setup() {
  // put your setup code here, to run once:
for(int IN=0;IN<4;IN++)
{pinMode(led[IN],OUTPUT);
pinMode(but[IN],INPUT);
digitalWrite(but[IN],HIGH);
}

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int IN=0;IN<4;IN++)
  {
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
  

}
