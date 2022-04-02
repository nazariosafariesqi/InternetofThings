#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11
#define LedMerah 16 // D0 pin led merah
#define LedBiru 4 // D2 pin led biru
#define LedPutih 0 // D3 pin led putih

#define GPIO5 5
#define PIN_LDR A0

DHT dht(GPIO5, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("LDR & DHT11 Test!");
  pinMode(LedMerah, OUTPUT);
  pinMode(LedPutih, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  dht.begin();
}

void Running() {
 int a = analogRead(A0);
 
 Serial.print("Nilai Sensor: ");
 Serial.println(a);
  
delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.println("Humidity: ");
  Serial.print(h);

  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.println((String)t + " °C");
    
  if(t >= 0 && t <= 16 && a >700 ){
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, LOW);
     digitalWrite(LedPutih, HIGH);
     Serial.println("Cahaya Gelap");
     Serial.println(" Suhu Dingin");
    }
    
  else if (t < 0 && t > 16 && a && a <= 700){
    digitalWrite(LedPutih, LOW);
    }

  else if( t >= 17 && t <= 30 && a >=400 && a < 700 ){
    
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, HIGH);
     digitalWrite(LedPutih, LOW);
     Serial.println("Cahaya Redup");
     Serial.println(" Suhu Normal");
     delay(300);
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, LOW);
     digitalWrite(LedPutih, LOW);
     Serial.println("Cahaya Redup");
     Serial.println(" Suhu Normal");
     delay(300);
    }

  else if (t >= 38 && t >= 100 && a >= 0 && a < 400 ){
    digitalWrite(LedMerah, HIGH);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedPutih, LOW);
    Serial.println("Cahaya Terang");
    Serial.println(" Suhu Panas");
    }

  else if (t < 38 && t > 100 && a >= 400){
    digitalWrite(LedMerah, LOW);
    }
}

void loop() {
Running();
}
