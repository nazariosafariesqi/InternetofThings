// #include < Wire .h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd (0x27, 16,2);  //pengalamatan 16 digit 2 baris
 
void  setup () {
  lcd. init ();
  lcd. backlight();
  lcd. print ( "Tes LCD" );
}
 
void  loop () {
    
  lcd. setCursor (0, 1);//posisi kolom 0, row 1
  lcd. print ( millis () / 1000);
  lcd. print ( "SECONDS" );
  delay (100);
}
