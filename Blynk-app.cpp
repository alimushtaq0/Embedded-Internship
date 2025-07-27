/*In this code we tried to connect the ESP32 to the Blynk IoT app and website to carry out basic tasks but there was some error in connecting the ESP32 with the Blynk app properly*/

#define BLYNK_TEMPLATE_ID "TMPL6JcMiPF1-"
#define BLYNK_TEMPLATE_NAME "LilyGo T PCIe"
//Include the library files
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Enter your Auth token
char auth[] = "Ub7aBmak5t1-4-7qKDefUSpqYdjPRPUW";

//Enter your WIFI SSID and password
char ssid[] = "OnePlus 9";
char pass[] = "123456890";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop()
{
  Blynk.run();
}
