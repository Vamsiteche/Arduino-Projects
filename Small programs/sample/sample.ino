
void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
pinMode(D0,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:navjot.16885@lpu.co.in
    Serial.println("Vamsi");
    digitalWrite(D0,HIGH);
    digitalWrite(D4,LOW);
    delay(1000);
    digitalWrite(D0,LOW);
    digitalWrite(D4,HIGH);
    delay(1000);
}
