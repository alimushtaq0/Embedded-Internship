/*In this code we set this ESP32 as the receiver of the ESP-NOW protocol that is used to establish a connection between multiple ESP’s without using Wi-Fi or Bluetooth*/

#include <WiFi.h>
#include <esp_now.h>

typedef struct data{
  char name[32];
  int a;
  float c;
  bool b;
}data;

data obj;

void cbfun(const uint8_t* addr,const uint8_t* dataR,int s)
{
  memcpy(&obj, dataR, sizeof(data));
  Serial.println(obj.a);
  Serial.println(obj.b);
  Serial.println(obj.c);
  Serial.println(obj.name);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if(esp_now_init()!=ESP_OK)
  {
    Serial.println("Error Initializing");
  }
  esp_now_register_recv_cb(esp_now_recv_cb_t(cbfun));
}

void loop() {
  // put your main code here, to run repeatedly:
}
