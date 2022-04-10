#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "DHT.h"

#define GPIO0 0    
#define DHTTYPE DHT11   // DHT 11
#define LedMerah 14 // D5 pin led merah
#define LedBiru 12 // D6 pin led biru
#define LedHijau 13 // D7 pin led hijau

DHT dht(GPIO0, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  pinMode(LedMerah, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  pinMode(LedHijau, OUTPUT);
  dht.begin();

  lcd.init();
  lcd.backlight();
  
}

void Running() {
  delay(1000);
  
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
  
  Serial.print((float)t*(9/5)+32);
  Serial.println("°F");
    
  if(t >= 0 && t <= 16){
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, LOW);
     digitalWrite(LedHijau, HIGH);
     Serial.println("Suhu Dingin");
    }
    
  else if (t < 0 && t > 16){
    digitalWrite(LedHijau, LOW);
    }

  else if (t >= 25 && t <= 37){
     
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, HIGH);
     digitalWrite(LedHijau, LOW);
     Serial.println("Suhu Normal");
     delay(100);
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, LOW);
     digitalWrite(LedHijau, LOW);
     delay(100);
    }

  else if(t < 25 && t > 37){
    digitalWrite(LedBiru, LOW);
    }
  
  else if (t >= 38 && t <= 100){
    digitalWrite(LedMerah, HIGH);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedHijau, LOW);
    Serial.println("Suhu Panas");
    }

  else if (t < 38 && t > 100){
    digitalWrite(LedMerah, LOW);
    }
 
 lcd.setCursor(0,0);
 lcd.print(t);
 lcd.print(" C");
 
 lcd.setCursor(9,0);
 lcd.print(t*(9/5)+32);
 lcd.print(" F");
 
}

void loop() {
Running();
}
