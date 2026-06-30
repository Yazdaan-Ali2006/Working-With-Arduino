// Pins
const int gasSensor = A0;
const int redLED = 3;
const int buzzer = 11;

// Smoke threshold 
const int threshold = 400;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasSensor);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    // Smoke detected
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);   // 1000 Hz sound
    delay(300);

    digitalWrite(redLED, LOW);
    noTone(buzzer);
    delay(300);
  } else {
    // No smoke
    digitalWrite(redLED, LOW);
    noTone(buzzer);
  }
}