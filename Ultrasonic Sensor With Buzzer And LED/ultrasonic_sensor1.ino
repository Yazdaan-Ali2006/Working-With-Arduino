const int trigPin = 6;
const int echoPin = 5;
const int buzzer = 13;

const int redLED = 8;
const int greenLED = 9;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= 15) {

    // Obstacle detected
    tone(buzzer, 1000);

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

  } else {

    // No obstacle
    noTone(buzzer);

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

  }

  delay(100);
}