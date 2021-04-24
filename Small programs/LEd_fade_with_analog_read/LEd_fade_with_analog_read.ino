int l;
int i;
void setup() {
  // put your setup code here, to run once:
  //fadeding of LED without using analogread funtion
  pinMode(11,OUTPUT);
  i=0;
  l=5;
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(11,i);
    i+5;
    delay(80);
    if(i==254||i==0)
    l=-5;
  }
