# Development of an Unmanned Ground Vehicle (UGV) for Autonomous Surveillance and Weapon Detection (AS-WD)

**Authors:** Obaje Anthony Ojonimi, Aliyu Habibu, Salama Yashim Shemang, Obidoo Jeremiah Ginikachukwu  
**Institution:** Air Force Institute of Technology (AFIT), Kaduna – Department of Mechatronics Engineering, Faculty of Air Engineering[cite: 2]  
**Supervisor:** Col. Prof. A.S Imam[cite: 2]  
**Date:** March 2025[cite: 2]  

---

## 📋 Abstract
The Unmanned Ground Vehicle (UGV) for autonomous surveillance and weapon detection is a wireless platform engineered to relay critical environmental data across distances without physical electrical connections[cite: 2]. Designed to secure highly sensitive areas from intruders and suspicious activities, the system improves military and perimeter security operations in high-risk regions[cite: 2]. The methodology employs hardware implementation supported by an ESP32 microcontroller, ESP32-CAM, and Arduino framework, integrated with OpenCV for video surveillance, a GSM module for SMS alerts, and a GPS module for precise location tracking[cite: 2]. Field and experimental evaluations demonstrate real-time wireless surveillance transmission, automated firearm detection (achieving an 84.7% true positive rate), and reliable GPS coordinate transmission upon threat identification[cite: 2].

---

## 1. Introduction & Problem Statement
Modern security threats, particularly in conflict-prone and high-risk environments, demand intelligent, responsive, and autonomous technologies[cite: 2]. Conventional static surveillance systems (such as fixed CCTV cameras) suffer from limited coverage, reliance on manual monitoring, and inability to adapt to dynamic threats like armed banditry and insurgency[cite: 2]. 

This project addresses these gaps by designing an integrated UGV system combining:
1. **Real-Time Firearm Detection:** Edge-based deep learning models capable of identifying rifles and handguns.
2. **Autonomous Navigation:** Reliable path planning, obstacle avoidance, and heading stability using ultrasonic sensors and an inertial measurement unit (IMU)[cite: 2].
3. **IoT-Enabled Telemetry:** Rapid communication of threat coordinates via GSM and GPS modules to minimize latency compared to traditional cloud-dependent infrastructure[cite: 2].

---

## 2. System Architecture & Methodology

The system is structured into four primary functional subsystems[cite: 2]:

### 2.1 Mechanical Design & Chassis
* **Chassis Material:** Fabricated using lightweight yet durable acrylic sheets chosen for cost-effectiveness and structural rigidity[cite: 2].
* **CAD Modeling:** Detailed 3D CAD models were developed in SolidWorks to optimize component placement, maintain a low center of gravity, and ensure robust housing for electronics[cite: 2].
* **Mobility:** Powered by a 4-wheel differential drive setup controlled via an L298N dual H-Bridge motor driver[cite: 2].

### 2.2 Machine Vision & Detection Subsystem
* **Hardware:** ESP32-CAM module featuring an integrated OV2640 camera for image and video capture[cite: 2].
* **AI Model:** Trained using the **Ultralytics YOLOv11** framework on a curated dataset of firearm imagery via Google Colab (PyTorch backend)[cite: 2].
* **Inference Pipeline:** Processes video frames in real-time, applying Non-Maximum Suppression (NMS) to eliminate overlaps and output bounding boxes with class labels and confidence scores[cite: 2].

### 2.3 Navigation & Obstacle Detection Subsystem
* **Primary Controller:** ESP32-WROOM-32 dual-core microcontroller acting as the central processing hub[cite: 2].
* **Obstacle Avoidance:** HC-SR04 ultrasonic sensors configured for continuous distance measurement (0–80 cm range), triggering immediate avoidance maneuvers (stopping, reversing, or turning) upon encountering obstacles[cite: 2].
* **Heading Stability:** MPU6050 6-axis IMU providing accelerometer and gyroscope feedback to maintain straight-line tracking and trajectory precision[cite: 2].

### 2.4 IoT & Communication Subsystem
* **GPS Tracking:** NEO-6M GPS module interfaced via UART using the `TinyGPS++` library to parse real-time NMEA positional data (latitude, longitude, and altitude)[cite: 2].
* **Cellular Alerts:** SIM800L GSM module utilizing AT commands to automatically transmit SMS emergency alert notifications containing precise location coordinates and threat confidence levels to security personnel[cite: 2].

---

## 3. Power Management & Electrical Design

* **Battery Assembly:** Four 3.7V 18650 lithium-ion cells configured in series (4S) delivering a nominal output of 14.8V[cite: 2].
* **BMS Protection:** Integrated 4S 40A Battery Management System (BMS) ensuring overcharge, over-discharge, and short-circuit protection[cite: 2].
* **Voltage Regulation:** An LM2596 DC-DC buck converter steps down the 14.8V supply to a stabilized 5V rail for the microcontroller, sensors, and communication modules[cite: 2].
* **Operational Endurance:** The system delivers approximately **6.2 hours** of mixed operational runtime and supports a peak power draw of 13.3W[cite: 2].

---

## 4. Results & Performance Evaluation

Rigorous testing across multiple subsystems yielded the following performance metrics[cite: 2]:

* **Detection Accuracy:** The YOLOv11 model achieved a mean average precision ($\text{mAP}@0.5$) of **0.8717** and an overall weapon detection True Positive Rate of **84.7%**[cite: 2].
* **Processing Speed:** Maintained an average inference time of 130–180 ms per frame (approx. 5.5–15 FPS depending on lighting and Wi-Fi streaming conditions)[cite: 2].
* **Obstacle Avoidance:** Demonstrated a **94.2% success rate** against static obstacles and **86.3%** in complex navigation scenarios[cite: 2].
* **Alert Latency:** Average end-to-end response time from firearm detection to SMS coordinate dispatch was measured at **4.9 seconds**[cite: 2].

---

## 5. Conclusion
The development of this autonomous UGV successfully validates the integration of edge AI, IoT communication, and mobile robotics for perimeter security[cite: 2]. By combining YOLOv11 weapon detection with reliable autonomous navigation and automated SMS telemetry, the system provides a scalable, cost-effective solution to enhance security monitoring in high-risk and remote environments[cite: 2].
