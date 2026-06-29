// =========================
// MOTOR PINS
// =========================
const int ENA = 6;
const int IN3 = 7;
const int IN4 = 8;

const int ENB = 13;
const int IN1 = 12;
const int IN2 = 11;

// =========================
// ULTRASONIC
// =========================
const int trigPin = 4;
const int echoPin = 5;

// =========================
// BUZZER & LEDs
// =========================
const int buzzer = 3;
const int redLED = 2;
const int greenLED = 9;

// Distance to detect obstacle (cm)
const int obstacleDistance = 20;

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  analogWrite(ENA, 255);
  digitalWrite(ENB, HIGH);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, HIGH);
}

void loop() {

  int distance = getDistance();

  if (distance > 0 && distance <= obstacleDistance) {

    // Obstacle Found
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    tone(buzzer, 1000);
    delay(300);
    noTone(buzzer);

    stopMotors();
    delay(300);

    // Reverse
    backward();
    delay(800);

    stopMotors();
    delay(200);

    // Turn Left
    left();
    delay(700);

    stopMotors();
    delay(200);

    // Check Again
    distance = getDistance();

    if (distance > obstacleDistance || distance == 0) {

      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);

      forward();

    } else {

      // Turn Right
      right();
      delay(1400);

      stopMotors();
      delay(200);

      distance = getDistance();

      if (distance > obstacleDistance || distance == 0) {

        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);

        forward();

      } else {

        // Still blocked
        backward();
        delay(700);

      }
    }

  } else {

    // No obstacle
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    noTone(buzzer);

    forward();
  }
}

// =========================
// Distance Function
// =========================
int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
    return 999;

  int distance = duration * 0.034 / 2;

  return distance;
}

// =========================
// MOTOR FUNCTIONS
// =========================

void forward() {

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void backward() {

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void left() {

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void right() {

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void stopMotors() {

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}