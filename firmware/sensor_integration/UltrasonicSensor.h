#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>
#include <ESP32Servo.h>

extern const int TRIG_PIN;
extern const int ECHO_PIN;
extern const int SERVO_PIN;

void initUltrasonic();
float readDistanceCM();
void scanEnvironment(float &leftDist, float &rightDist);

#endif
