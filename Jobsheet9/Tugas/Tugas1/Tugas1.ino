#include <LiquidCrystal_I2C.h>

#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "Widjaya Cell 2";
const char *password = "275351928";
const uint16_t port = 58;
const char *host = "192.168.0.58";

WiFiClient client;

#include "DHT.h"
#define GPIO0 0         //D3 pin data dht11
#define DHTTYPE DHT11   
DHT dht(GPIO0, DHTTYPE);

#define PIN_LDR A0

#define LedMerah 5      //D1 pin led merah
#define LedBiru 4       // D2 pin led biru
#define LedPutih 2      // D4 pin led putih

void connect_wifi(){
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  delay(300);
}

void connect_server(){
  while (!client.connect(host, port)){
    Serial.printf("\n[Connecting to %s ... ", host);
    delay(1000);
    return;
  }
  Serial.println("connected");
  delay(1000);
}

void setup(){
  Serial.begin(9600);
  pinMode(LedMerah, OUTPUT);
  pinMode(LedPutih, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  connect_wifi();
  connect_server();
}

void loop1(){
    if (client.connected()){

    Serial.print("[Response:]");
    String line = client.readStringUntil('\n');
    Serial.println(line);

    //Menyalakan & Mematikan Lampu
    if (line.equalsIgnoreCase("led-on")){
      digitalWrite(LedMerah, HIGH);
    }
    else if (line.equalsIgnoreCase("led-off")){
      digitalWrite(LedMerah, LOW);
    }
  }
  
  else{
    connect_server();
  }
  delay(300);
}

void loop2(){
    //Perintah Untuk DHT11
      if(line.equalsIgnoreCase("cek-suhu")){
   
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      
      if (isnan(h) || isnan(t) ) {
        Serial.println("Failed to read from DHT sensor");
        return;
      }
      
      Serial.print("Humidity: ");
      Serial.print(h);
      
      Serial.print(" %\t");
      Serial.print("Temperature: ");
      Serial.println((String)t + " °C");
        
      Serial.print((float)t*(9/5)+32);
      Serial.println("°F");
      }

      else{
        connect_server();
      }
      delay(300);
  }
  
void loop3(){
  //Perintah Untuk LDR Sensor
    if(line.equalsIgnoreCase("cek-cahaya")){

    float t = dht.readTemperature();
    float a = analogRead(A0);
      Serial.print("Nilai Sensor: ");
      Serial.println(a);
        
      if(t >= 0 && t <= 16 && a >700 ){
        digitalWrite(LedPutih, HIGH);
        Serial.println("Cahaya Gelap");
        Serial.println(" Suhu Dingin");
      }
    
      else if (t < 0 && t > 16 && a <= 700){
        digitalWrite(LedPutih, LOW);
      }

      else if( t >= 17 && t <= 30 && a >=400 && a < 700 ){
        digitalWrite(LedBiru, HIGH);
        Serial.println("Cahaya Redup");
        Serial.println(" Suhu Normal");
      }

      else if (t < 17 && t > 30 && a<400 && a >= 700){
        digitalWrite(LedBiru, LOW);
      }

      else if (t >= 38 && t >= 100 && a >= 0 && a < 400 ){
        digitalWrite(LedBiru, HIGH);
        digitalWrite(LedPutih, HIGH);
        Serial.println("Cahaya Terang");
        Serial.println(" Suhu Panas");
      }

      else if (t < 38 && t > 100 && a >= 400){
      digitalWrite(LedBiru, LOW);
      digitalWrite(LedPutih, LOW);
      }

      else if (a >= 1000){
      digitalWrite(LedPutih, HIGH);
      }
  }
  
  else{
    connect_server();
  }
  delay(300);
 }
}
