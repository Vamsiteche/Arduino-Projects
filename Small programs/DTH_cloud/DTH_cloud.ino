#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 5                       // Digital Pin 5
#define DHTTYPE DHT11                  // We are Using DHT11

String apiKey = "O4IIGTDSANH72NQW";    // 2737PEGIY2F9413T Edit this CHANNEL API key according to your Account
String Host_Name = "karthik";            // Edit Host_Name
String Password = "123456789";          // Edit Password

SoftwareSerial ser(3, 2);              // RX, TX
int i=1;
DHT dht(DHTPIN, DHTTYPE);              // Initialising Pin and Type of DHT

void setup()
{
  Serial.begin(115200);                  // enable software serial
  ser.begin(115200);                     // reset ESP8266
  ser.println("AT+RST");               // Resetting ESP8266
  dht.begin();                        // Enabling DHT11

  String cmd1 = "AT+CWMODE";
         cmd1+= "=";
         cmd1+= "3";
  ser.println(cmd1);
  Serial.println(cmd1);

  char inv ='"';
  String cmd = "AT+CWJAP";
       cmd+= "=";
       cmd+= inv;
       cmd+= Host_Name;
       cmd+= inv;
       cmd+= ",";
       cmd+= inv;
       cmd+= Password;
       cmd+= inv;

ser.println(cmd);                    // Connecting ESP8266 to your WiFi Router
Serial.println(cmd);
}

// the loop

void loop()
{
  int humidity =  dht.readHumidity();             // Reading Humidity Value
  int temperature = dht.readTemperature();        // Reading Temperature Value

  String state1=String(humidity);                 // Converting them to string
  String state2=String(temperature);              // as to send it through URL
  Serial.println(humidity);
  Serial.println(temperature);

  String cmd = "AT+CIPSTART=\"TCP\",\"";          // Establishing TCP connection
  cmd += "184.106.153.149";                       // api.thingspeak.com
  cmd += "\",80";                                 // port 80

  ser.println(cmd);
  Serial.println(cmd);

 if(ser.find("Error"))
 {
    Serial.println("AT+CIPSTART error");
    return;
 }
String getStr = "GET /update?api_key=";         // prepare GET string
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(state1);                       // Humidity Data
  getStr +="&field2=";
  getStr += String(state2);                       // Temperature Data
  getStr += "\r\n\r\n";

  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());                // Total Length of data

  ser.println(cmd);
  Serial.println(cmd);

  if(ser.find(">"))
  {
    ser.print(getStr);
    Serial.print(getStr);
  }
  else
  {
    ser.println("AT+CIPCLOSE");                  // closing connection
    Serial.println("AT+CIPCLOSE");
  }

 delay(1000);                                  // Update after every 15 seconds

}
