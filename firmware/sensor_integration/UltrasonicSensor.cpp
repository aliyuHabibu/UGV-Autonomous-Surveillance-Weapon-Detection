#include "UltrasonicSensor.h"

const int TRIG_PIN = 12;
const int ECHO_PIN = 13;
const int SERVO_PIN = 19;

Servo scanServo;

void initUltrasonic() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  scanServo.attach(SERVO_PIN);
  scanServo.write(90); // Center position[cite: 2]
}

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 25000);
  if (duration == 0) return 400.0;
  return (duration * 0.0343) / 2.0;
}

void scanEnvironment(float &leftDist, float &rightDist) {
  scanServo.write(150); // Scan Left[cite: 2]
  delay(350);
  leftDist = readDistanceCM();

  scanServo.write(30);  // Scan Right[cite: 2]
  delay(350);
  rightDist = readDistanceCM();

  scanServo.write(90);  // Return Center
  delay(200);
}
