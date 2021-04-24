/*brightness of LED with respect position of POT connected to A5 without using map funtion*/
void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  pinMode(A5,INPUT);
}

void loop() {
  /* put your main code here, to run repeatedly:
  ATmega is 8 bit microcontroller so it can take values of 0-255 at output PWM
  where as analog read can be done upto 1024 as it as 10 bit ADC */
  int val=analogRead(A5);
  analogWrite(11,val/4);

}
