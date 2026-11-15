#include "IMUSensor.h"

const int MPU_ADDR = 0x68;
float yawAngle = 0.0;
float targetHeading = 0.0;
float gyroZOffset = 0.0;
unsigned long lastIMUTime = 0;

void initIMU() {
  Wire.begin(21, 22); // SDA = 21, SCL = 22[cite: 2]
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);

  float sum = 0;
  for (int i = 0; i < 200; i++) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x47); 
    Wire.endTransmission(false);
    Wire.requestFrom(MPU_ADDR, 2, true);
    int16_t gz = (Wire.read() << 8 | Wire.read());
    sum += gz / 131.0;
    delay(5);
  }
  gyroZOffset = sum / 200.0;
  lastIMUTime = millis();
}

void updateIMU() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x47);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 2, true);
  int16_t gzRaw = (Wire.read() << 8 | Wire.read());

  unsigned long now = millis();
  float dt = (now - lastIMUTime) / 1000.0;
  lastIMUTime = now;

  float gyroZ = (gzRaw / 131.0) - gyroZOffset;
  if (abs(gyroZ) > 0.5) {
    yawAngle += gyroZ * dt;
  }
}
