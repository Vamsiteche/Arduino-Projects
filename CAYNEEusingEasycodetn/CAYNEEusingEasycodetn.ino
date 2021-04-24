/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

String  ClientRequest;
IPAddress staticIP200_10(192,168,1,10);
IPAddress gateway200_10(192,168,1,1);
IPAddress subnet200_10(255,255,255,0);

#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>//IMPPORT LIBRARY FROM http://easycoding.tn/index.php/resources/

char Cayenneusername[] = "a8251410-23e4-11eb-883c-638d8ce4c23d";
char Cayennepassword[] = "5cc9993e6a1f3cdeecf80ef3fb021af8ca784fc1";
char CayenneclientID[] = "7bd4ae20-23e9-11eb-883c-638d8ce4c23d";
void setup()
{
  ClientRequest = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("my-net","");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  WiFi.config(staticIP200_10, gateway200_10, subnet200_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  Cayenne.begin(Cayenneusername, Cayennepassword, CayenneclientID);

}


void loop()
{

    Cayenne.virtualWrite(0,(random(0,100)));
    Cayenne.virtualWrite(1,(random(101,200)));

}
