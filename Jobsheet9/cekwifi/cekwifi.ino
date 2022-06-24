#include <ESP8266WiFi.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "Widjaya Cell 2";
const char* password = "275351928";

WiFiServer server(80);
LiquidCrystal_I2C lcd (0x27, 16,2); 

void setup() {

  Serial.begin(9600);
  delay(2000);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid , password);

 
  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WIFI connected");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
    
 }

void loop() {

}
