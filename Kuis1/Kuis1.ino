#define LedMerah 16 //D0 pin led merah
#define LedKuning 5 //D1 pin led kuning
#define LedHijau 4 //D2 pin led hijau


void setup() {
Serial.begin(9600);
pinMode(LedMerah, OUTPUT);
pinMode(LedKuning, OUTPUT);
pinMode(LedHijau, OUTPUT); // atur pin digital sebagai output.
}

void RunningLED() {
 digitalWrite(LedMerah, HIGH);
 digitalWrite(LedKuning, LOW);
 digitalWrite(LedHijau, LOW);
 Serial.println("LED Merah menyala");
 delay(10500);

 digitalWrite(LedMerah, LOW);
 digitalWrite(LedKuning, HIGH);
 digitalWrite(LedHijau, LOW);
 Serial.println("LED Kuning menyala");
 delay(1500);

 digitalWrite(LedMerah, LOW);
 digitalWrite(LedKuning, LOW);
 digitalWrite(LedHijau, HIGH);
 Serial.println("LED Hiijau menyala");
 delay(5500);
 Serial.println();
}

void loop() {
RunningLED();
}
