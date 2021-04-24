int arr[]={B11111100,B01100000,B11011010,B11110010,B01100110,B10110110,B10111110,B11100000,B11111110,B11100110,B11101110,B11111110,B10011100,B11111100,B10011110,B10001110};
void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<16;i++)
    {PORTD=arr[i];
    delay(1000);
    }
   }
