#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <Arduino.h>

// L298N Motor Driver Pin Declarations[cite: 2]
extern const int ENA;
extern const int ENB;
extern const int IN1;
extern const int IN2;
extern const int IN3;
extern const int IN4;

// Function Prototypes
void initMotors();
void moveForward(int speed);
void moveBackward(int speed);
void turnLeft(int speed);
void turnRight(int speed);
void stopMotors();

#endif
