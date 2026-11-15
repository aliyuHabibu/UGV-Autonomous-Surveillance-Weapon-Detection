#include "TelemetryModule.h"

HardwareSerial gpsSerial(1); 
HardwareSerial gsmSerial(2); 

const int GPS_RX_PIN = 32; //[cite: 2]
const int GPS_TX_PIN = 33; //[cite: 2]
const int GSM_RX_PIN = 26; //[cite: 2]
const int GSM_TX_PIN = 27; //[cite: 2]

TinyGPSPlus gps;
double currentLat = 9.0211;  //[cite: 2]
double currentLon = 7.4233;  //[cite: 2]
const String SECURITY_PHONE = "+2347062373253";

void initTelemetry() {
  gpsSerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, GPS_TX_PIN);
  gsmSerial.begin(9600, SERIAL_8N1, GSM_RX_PIN, GSM_TX_PIN);
  delay(1500);
  gsmSerial.println("AT+CMGF=1"); // Text mode[cite: 2]
}

void pollGPS() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read()) && gps.location.isValid()) {
      currentLat = gps.location.lat();
      currentLon = gps.location.lng();
    }
  }
}

void dispatchEmergencyAlert(float confidence) {
  gsmSerial.println("AT+CMGF=1");
  delay(200);
  gsmSerial.println("AT+CMGS=\"" + SECURITY_PHONE + "\"");
  delay(300);
  gsmSerial.println("ALERT: Weapon detected!");
  gsmSerial.printf("Location: Lat: %.4f, Lon: %.4f\n", currentLat, currentLon);
  gsmSerial.print("Confidence: ");
  gsmSerial.print(confidence, 1);
  gsmSerial.println("%");
  gsmSerial.print("Status: Active surveillance");
  delay(200);
  gsmSerial.write(26); // CTRL+Z
}
