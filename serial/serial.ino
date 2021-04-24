
char a;
String s;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(D0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
s="";
while(Serial.available())
{
  a = Serial.read();
  s=s+a;
  if(s=="OFF")
{
  digitalWrite(D4,LOW);
  s="";
}
else if(s=="ON")
{
  digitalWrite(D4,HIGH);
  s="";
}
else
{
  //this is the condition if something else is taken other than ON/OFF example ASHHA it takes as only last letter A igore first part if it is AAAA it takes AA and igore rest this maintains
  if(s.length()>3)
  {
    s=""+s[2];
  }
}
}

}
