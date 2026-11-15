#include "MotorDriver.h"
#include "UltrasonicSensor.h"
#include "IMUSensor.h"
#include "TelemetryModule.h"

const int WEAPON_TRIGGER_PIN = 23; // Trigger input from ESP32-CAM[cite: 2]
unsigned long lastAlertTime = 0;
const unsigned long ALERT_COOLDOWN = 15000; 

void setup() {
  Serial.begin(115200);

  // Initialize individual subsystems
  initMotors();
  initUltrasonic();
  initIMU();
  initTelemetry();

  pinMode(WEAPON_TRIGGER_PIN, INPUT_PULLDOWN);
  Serial.println("UGV Autonomous Surveillance System Initialized.");
}

void loop() {
  pollGPS();
  updateIMU();

  // 1. Check Weapon Detection Interrupt from ESP32-CAM[cite: 2]
  if (digitalRead(WEAPON_TRIGGER_PIN) == HIGH && (millis() - lastAlertTime > ALERT_COOLDOWN)) {
    stopMotors();
    Serial.println("[ALERT] Firearm Detected! Dispatching Coordinates...");
    dispatchEmergencyAlert(85.0);
    lastAlertTime = millis();
  }

  // 2. Obstacle Scanning & Autonomous Avoidance (0 - 70 cm range)[cite: 2]
  float frontDist = readDistanceCM();
  if (frontDist > 0 && frontDist <= 70.0) {
    stopMotors();
    delay(150);
    moveBackward(160); // Brief reverse maneuver[cite: 2]
    delay(300);
    stopMotors();

    float leftDist = 0, rightDist = 0;
    scanEnvironment(leftDist, rightDist); // Left and Right sweep[cite: 2]

    if (leftDist < 30.0 && rightDist < 30.0) {
      // Dead end: Reverse and execute 180° rotation[cite: 2]
      moveBackward(170);
      delay(400);
      turnRight(180);
      delay(900);
      targetHeading = yawAngle;
    } else if (leftDist >= rightDist) {
      // Clear path on left: turn 45° left[cite: 2]
      turnLeft(175);
      delay(350);
      targetHeading = yawAngle;
    } else {
      // Clear path on right: turn 45° right[cite: 2]
      turnRight(175);
      delay(350);
      targetHeading = yawAngle;
    }
    stopMotors();
  } else {
    // 3. Clear Path: Forward Locomotion with IMU Correction[cite: 2]
    float headingError = targetHeading - yawAngle;
    int correction = constrain((int)(headingError * 3.0), -40, 40);
    
    // Custom differential adjustment for straight-line tracking
    digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
    ledcWrite(ENA, constrain(175 - correction, 0, 255));
    ledcWrite(ENB, constrain(175 + correction, 0, 255));
  }

  delay(40);
}
