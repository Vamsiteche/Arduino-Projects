#include<SPI.h>

char buff[]="MS Dhoni";
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<sizeof  buff;i++)
{
  SPI.transfer(buff[i]);
}
delay(1000);
}
