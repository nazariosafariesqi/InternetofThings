#include "DHT.h"

#define GPIO14 14    
#define DHTTYPE DHT11   // DHT 11
#define LedMerah 16 // D0 pin led merah
#define LedBiru 0 // D3 pin led biru
#define LedHijau 4 // D2 pin led hijau

DHT dht(GPIO14, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  pinMode(LedMerah, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  dht.begin();
}

void Running() {
  delay(3000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.println((String)t + " °C");

  Serial.println("Temperature: ");
  Serial.print((float)t*5/4);
  Serial.println("°R");

  Serial.println("Temperature: ");
  Serial.print((float)t+273);
  Serial.println("K");
    
  if(t > 0 && t <= 16){
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, LOW);
     digitalWrite(LedHijau, HIGH);
     Serial.println("Suhu Dingin");
  }

  else if (t >= 25 && t <= 37){
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, HIGH);
     digitalWrite(LedHijau, LOW);
     Serial.println("Suhu Normal");
  }
  
  else if (t >= 38 && t <= 100){
    digitalWrite(LedMerah, HIGH);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedHijau, LOW);
    Serial.println("Suhu Panas");
  }
 }

void loop() {
Running();
}
