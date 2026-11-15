#ifndef TELEMETRY_MODULE_H
#define TELEMETRY_MODULE_H

#include <Arduino.h>
#include <TinyGPS++.h>

extern double currentLat;
extern double currentLon;

void initTelemetry();
void pollGPS();
void dispatchEmergencyAlert(float confidence);

#endif
