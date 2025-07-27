/*In this code we set one ESP32 as the Wi-Fi client that will be ultimately connected to the station or router*/

#include<HTTPClient.h>
#include<WiFi.h>
#define led 12
int state =0;
const char ssid[]="alidon";
const char pass[]="123";
const char* hyper1="http://192.111.1.1/temp";
const char* hyper2="http://192.111.1.1/humd";
void setup() {
  pinMode(led,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED)
  {
    digitalWrite(led,state);
    state=!state;
    delay(1000);
  }
  digitalWrite(led,HIGH);
}
String getresponse(const char* a)
{
  HTTPClient http;
  WiFiClient client;
  http.begin(client,a);
   int b =http.GET();
   if(b>0)
   {
    return http.getString();
   }
   http.end();
}
void loop() {
  // put your main code here, to run repeatedly:
HTTPClient c;
if(WiFi.status()==WL_CONNECTED)
{
String temp=getresponse(hyper1);
String humd=getresponse(hyper2);
Serial.println("TEMPERATURE:"+temp);
Serial.println("---------------------------------");
Serial.println("HUMIDITY:"+humd);
}
}
