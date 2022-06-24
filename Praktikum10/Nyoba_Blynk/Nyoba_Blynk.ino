#define BLYNK_TEMPLATE_ID "TMPLGgJIq2M-"
#define BLYNK_DEVICE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "M0wRMuan5GDy0PmEDL89vT9U07NHQmcX"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>

#define LED1 5
#define LED2 4
 
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Widjaya Cell 1";  
char pass[] = "275351928";  
 
void setup()
{     
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);    
  pinMode(LED1,OUTPUT);
}

void setup2()
{     
  pinMode(LED2,OUTPUT);
  }

void loop()
{
  Blynk.run(); 
}
