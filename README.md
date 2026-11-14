# Autonomous Unmanned Ground Vehicle (UGV) for Surveillance and Weapon Detection (AS-WD)

[![Status](https://img.shields.io/badge/Status-Completed-success.svg)]()
[![Institution](https://img.shields.io/badge/Institution-Air%20Force%20Institute%20of%20Technology%20(AFIT)-blue.svg)]()
[![Degree](https://img.shields.io/badge/Degree-B.Eng.%20Mechatronics%20Engineering-orange.svg)]()

## 📌 Project Overview
This repository contains the hardware firmware, computer vision models, and system integration code for an **Unmanned Ground Vehicle (UGV) designed for Autonomous Surveillance and Weapon Detection (AS-WD)**. Developed as an undergraduate final year thesis project at the Air Force Institute of Technology (AFIT), Kaduna, this system addresses modern security and perimeter monitoring challenges by combining autonomous mobile robotics with real-time edge AI.

---

## 🚀 Key Technical Features & Capabilities

* **Real-Time Edge AI Detection:** Integrates an embedded **YOLOv11** deep learning model for high-accuracy, real-time object recognition and automated firearm/weapon detection.
* **Autonomous Navigation & Sensor Fusion:** Implements robust multi-sensor fusion combining **Inertial Measurement Units (IMUs)** and **ultrasonic feedback** to achieve stable autonomous navigation, precise path planning, and dynamic obstacle avoidance.
* **IoT & Wireless Telemetry:** Utilizes robust wireless communication frameworks to transmit immediate emergency alert transmissions and telemetry data to a remote monitoring base station.
* **Embedded Control Architecture:** Powered by microcontrollers (ESP32/Arduino) handling low-level motor drives, sensor polling, and hardware actuation.

---

## 🛠️ Tech Stack & Tools

* **Programming Languages:** Python, C, C++
* **Computer Vision & AI:** PyTorch, OpenCV, YOLOv11[cite: 1]
* **Embedded Systems:** ESP32, Arduino IDE / PlatformIO, UART/I2C communication protocols
* **Hardware & Mechanical Design:** SolidWorks CAD modeling, ultrasonic sensors, IMUs, DC gear motors, and custom UGV chassis fabrication.
* **Version Control:** Git & GitHub

---

## 📂 Repository Structure

```text
Autonomous-UGV-Surveillance-Weapon-Detection/
│
├── README.md                  # Project documentation
├── firmware/                  # Microcontroller source code (ESP32 / Arduino)
│   ├── motor_control/         # Motor driver and PWM configuration
│   └── sensor_integration/    # IMU and ultrasonic sensor polling
│
├── computer_vision/           # AI model deployment and vision scripts
│   ├── inference/             # Real-time YOLOv11 detection scripts (Python/OpenCV)
│   └── weights/               # Trained model weights / configuration files
│
├── hardware/                  # Circuit schematics and mechanical layouts
│   └── cad_drawings/          # SolidWorks schematics and design files
│
└── docs/                      # Thesis reports and technical documentation
    └── thesis_abstract.pdf    # Official project summary
