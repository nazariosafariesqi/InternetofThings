#include <LiquidCrystal.h> 
int Contrast=25;
 LiquidCrystal lcd(5,4,14,12,13,15); 

void setup(){
  digitalWrite(0,Contrast);
  lcd.begin(16, 2);
} 

void loop(){ 
lcd.setCursor(0, 0);
lcd.print("Test");
   
lcd.setCursor(0, 1);
lcd.print("123");
}
