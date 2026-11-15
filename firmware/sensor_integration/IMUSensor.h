#ifndef IMU_SENSOR_H
#define IMU_SENSOR_H

#include <Arduino.h>
#include <Wire.h>

extern float yawAngle;
extern float targetHeading;

void initIMU();
void updateIMU();

#endif
