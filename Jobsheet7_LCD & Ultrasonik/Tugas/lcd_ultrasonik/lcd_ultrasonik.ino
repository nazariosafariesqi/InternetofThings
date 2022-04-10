#include <LiquidCrystal_I2C.h>
#define trigger_pin 2 // D4
#define Echo_pin 0 // D3

#define LedMerah 16 // D0 pin led merah
#define LedBiru 14 // D5 pin led biru
#define LedHijau 12 // D6 pin led hijau

LiquidCrystal_I2C lcd (0x27, 16,2);  //pengenalan alamat i2c

long duration;
int dis; //jarak

void  setup () {

  pinMode(trigger_pin, OUTPUT); 
  pinMode(Echo_pin, INPUT);
  pinMode(LedMerah, OUTPUT);
  pinMode(LedBiru, OUTPUT);
  pinMode(LedHijau, OUTPUT);
   
  Serial.begin(9600); 
  lcd. init ();
  lcd. backlight ();
  lcd. print ( "Test Ultrasonik" );
  lcd. backlight ();
}
 
void  Running () {
   
  digitalWrite(trigger_pin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);          
  digitalWrite(trigger_pin, LOW);
   
  duration = pulseIn(Echo_pin, HIGH); // save waktu durasi parsing data
  dis= duration*0.034/2; //ubahdurasi ke jarak
   
    
  lcd. setCursor (0, 1);
  lcd.print("Jarak: ");
  lcd.print(dis);
  lcd.print(" cm");

  
  Serial.print("Jarak: ");
  Serial.print(dis);
  Serial.println(" cm");

  delay(3000);

  if(dis >=0  && dis <=10){
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, LOW);
     digitalWrite(LedHijau, HIGH);
    }

  else if (dis > 10 && dis <=20){
     digitalWrite(LedMerah, LOW);
     digitalWrite(LedBiru, HIGH);
     digitalWrite(LedHijau, LOW);
    }
  
  else if (dis > 20 && dis <=30){
    digitalWrite(LedMerah, HIGH);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedHijau, LOW);
    }

  else if(dis > 30 && dis < 6969){
    digitalWrite(LedBiru, HIGH);
    digitalWrite(LedHijau, HIGH);
    digitalWrite(LedMerah, HIGH);
    delay(500);
    digitalWrite(LedBiru, LOW);
    digitalWrite(LedHijau, LOW);
    digitalWrite(LedMerah, LOW);
    delay(500);
    }
}

void loop() {
Running();
}
