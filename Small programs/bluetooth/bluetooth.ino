#include<SoftwareSerial.h>
SoftwareSerial btSerial(D2,D3);
char a;
String s;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
btSerial.begin(9600);
pinMode(D0,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
s="";
while(btSerial.available())
{
  a = btSerial.read();
  s=s+a;
  if(s=="OFF")
{
  digitalWrite(D0,LOW);
  s="";
}
else if(s=="ON")
{
  digitalWrite(D0,HIGH);
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
