#define LEDMerah 16
#define LEDHijau 5
#define LEDBiru 4

void setup() {
  Serial.begin(9600);
  pinMode(LEDMerah, OUTPUT);
  pinMode(LEDHijau, OUTPUT);
  pinMode(LEDBiru, OUTPUT);
}

void RunningLED() {
  digitalWrite(LEDMerah, HIGH);
  digitalWrite(LEDHijau, LOW);
  digitalWrite(LEDBiru, LOW);
  Serial.println("LED Merah nyala");
  delay(1000);

  digitalWrite(LEDMerah, LOW);
  digitalWrite(LEDHijau, HIGH);
  digitalWrite(LEDBiru, LOW);
  Serial.println("LED Hijau nyala");
  delay(1000);

  digitalWrite(LEDMerah, LOW);
  digitalWrite(LEDHijau, LOW);
  digitalWrite(LEDBiru, HIGH);
  Serial.println("LED Biru nyala");
  delay(1000);

  Serial.println();
}

void loop() {
  RunningLED();
}
