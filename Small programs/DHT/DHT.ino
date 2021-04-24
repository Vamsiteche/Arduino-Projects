#include<LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(D0,D1,D2,D3,D4,D5);
float t,h;


void setup() {
  
  Serial.begin(9600);
  dht.begin();
  

}  

void loop() {

  /* - DHT sensor reading - */
  t = dht.readTemperature();
  lcd.setCursor(0,0);
  Serial.println("Temperature in celcuis");
  lcd.setCursor(0,1);
  Serial.println(t,DEC);
  delay(2000);
  lcd.clear();
    h = dht.readHumidity();
    lcd.setCursor(0,0);
   Serial.println("Humidity is ");
  lcd.setCursor(0,1);
  Serial.println(t,DEC);
  delay(2000);
  lcd.clear();
}
 
