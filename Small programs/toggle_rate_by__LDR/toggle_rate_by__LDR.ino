/*write a program to toggle the led on pon 13 with the delay defined by LDR connected to pin A0*/
int val;
int val1;
bool n;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  // syntax for map funtion is map(val,from min,from max,to min,to max)
  // LDR produce values from 200 to 800
  n=0;
}

void loop() {
  val=analogRead(A0);
  val1=map(val,200,800,0,1000);
  delay(val);
  n=!n;
  digitalWrite(13,n);
  
  // put your main code here, to run repeatedly:

}
