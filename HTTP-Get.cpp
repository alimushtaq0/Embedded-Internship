/*The Hypertext Transfer Protocol (HTTP) works as a request-response protocol between a client and server. The ESP32 (client) submits an HTTP request to a Server (for example: OpenWeatherMap.org). The server returns a response to the ESP32 (client). Finally, the response contains status information about the request and may also contain the requested content.*/

#include <WiFi.h>
#include <HTTPClient.h>
const char ssid[] = "HUAWEI-5G-f69D";
const char pass[] = "QuH8439Q";
String serverName = "http://1.1.1.1:1880/update-sensor";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  if (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi with IP Address:");
  Serial.print(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  if (WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    String serverPath = serverName + "?temp=25";
    http.begin(serverPath.c_str());
    int HTTPRespCode = http.GET();
    if (HTTPRespCode>0){
      Serial.print("Your HTTP response code is : ");
      Serial.println(HTTPRespCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else{
    Serial.print("Your ERROR code is : ");
    Serial.println(HTTPRespCode);
    }
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected!");
  }
}
