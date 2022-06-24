#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "Widjaya Cell 1";
const char *password = "275351928";
const uint16_t port = 80;
const char *host = "192.168.0.55";

WiFiClient client;

void connect_wifi()
{
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  delay(250);
}

void connect_server()
{
  while (!client.connect(host, port))
  {
    Serial.printf("\n[Connecting to %s ... ", host);
    delay(1000);
    return;
  }
  Serial.println("connected]");
  delay(1000);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Contoh penggunaan socket client");
  connect_wifi();
  connect_server();
}

void loop(){
  if (client.connected()){
    Serial.print("[Response:]");
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line.equalsIgnoreCase("led-on"))
    {
      pinMode(LED_BUILTIN, HIGH);
      delay(3000);
      pinMode(LED_BUILTIN, LOW);
    }
  }
  
  else{
    connect_server();
  }
  delay(250);
}
