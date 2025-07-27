/*In this code we made the second ESP32 as the Wi-Fi station that lets the client ESP32 connect to it via Wi-Fi signals*/

#include<ESPAsyncWebServer.h>
#include<WiFi.h>
#include<DHT11.h>
DHT11 dht11(12);
const char ssid[]="alidon";
const char pass[]="123";
AsyncWebServer server(80);
void setup() {
  // put your setup code here, to run once:
WiFi.softAP(ssid,pass);
IPAddress local_ip(192,111,1,1);
IPAddress gateway(192,111,1,1);
IPAddress subnet(255,255,255,0);
WiFi.softAPConfig(local_ip,gateway,subnet);
server.on("/temp",HTTP_GET,[](AsyncWebServerRequest *request){request->send_P(200,"text/plain",gettemp().c_str());});
server.on("/humd",HTTP_GET,[](AsyncWebServerRequest *request){request->send_P(200,"text/plain",gethumd().c_str());});
server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
//  server.handleClient();
}
String gettemp()
{
  int temp=0;
  int humd=0;
  int res=dht11.readTemperatureHumidity(temp,humd);
  if(res==0)
  {
    return String(temp);
  }
  else
  {
    Serial.println("error!");
  }
}
String gethumd()
{
   int temp=0;
  int humd=0;
  int res=dht11.readTemperatureHumidity(temp,humd);
  if(res==0)
  {
    return String(humd);
  }
  else
  {
    Serial.println("error!");
  }
}

