#define ledPin 5 //D1 pin LED

void setup()
{
 // atur pin digital sebagai output
 pinMode(ledPin, OUTPUT);
}

void loop(){
  
 // 3 dits (3 titik atau huruf S)
 for (int x=0; x<3; x++) {
 digitalWrite(ledPin, HIGH); // LED nyala
 delay(150); // delay selama 150ms
 digitalWrite(ledPin, LOW); // LED mati
 delay(100); // delay selama 150ms
 }
 delay(100);
 // 3 dahs (3 garis atau huruf O)
 for (int x=0; x<3; x++) {
 digitalWrite(ledPin, HIGH); // LED nyala
 delay(400); // delay selama 400ms
 digitalWrite(ledPin, LOW); // LED mati
 delay(100); // delay selama 100ms
 }
 // 100ms delay to cause slight gap between letters
 delay(100);
 // 3 dits again (3 titik atau huruf S)
 for (int x=0; x<3; x++) {
 digitalWrite(ledPin, HIGH); // LED nyala
 delay(150); // delay selama 150ms
 digitalWrite(ledPin, LOW); // LED mati
 delay(100); // delay selama 100ms
 }
 // wait 5 seconds before repeating the SOS signal
 delay(5000);
}
