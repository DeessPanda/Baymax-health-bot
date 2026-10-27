# 🤖 Baymax-Inspired Mobile Health Monitoring Robot

📌 Project Overview
This project is a low-cost, wheeled health-monitoring robot designed to assist in rural Indian clinics and elderly care. Inspired by Baymax from Big Hero 6, the goal is to create a friendly, non-invasive companion that automates vital sign monitoring and provides empathetic interaction.

Aligned with UN SDG 3 (Good Health and Well-being) and SDG 10 (Reduced Inequalities), this robot aims to bridge the gap caused by severe healthcare worker shortages by acting as an autonomous triage assistant.

🏗️ System Architecture
The project utilizes a three-tier architecture designed for scalability and edge processing:

Edge Layer (ESP32): Reads non-invasive sensors via I2C, logs data locally (SPIFFS), and transmits real-time JSON data over Bluetooth Classic.

Application Layer (Web/App UI): A responsive dashboard that visualizes live vitals, features a placeholder for computer vision (wound scanning), and hosts an AI chat interface.

AI & Mobility Layer (Raspberry Pi - Future Phase): Will handle autonomous navigation (motor control) and run a localized, fine-tuned Language Model for bilingual (Tamil/English) voice interaction.

🛠️ Tech Stack & Components
Microcontroller: ESP32 (Bluetooth Classic & Wi-Fi)

Sensors:

MAX30102 (Heart Rate & SpO2 via Photoplethysmography)

MLX90614 (Non-contact Infrared Temperature)

AD8232 (ECG - Phase 2 Integration)

Frontend: HTML5, CSS3, Vanilla JavaScript (Web Dashboard)

Future AI: Raspberry Pi 4, Qwen3-1.7B (Fine-tuned for Tamil/English medical reasoning via QLoRA)

📂 Repository Structure
main.ino - The core ESP32 firmware. Handles sensor initialization, local data logging, and Bluetooth JSON transmission.

index.html - The Web Dashboard UI. Can be opened directly in any browser to view the telemetry interface.

LICENSE - MIT License.

🚀 How to Run (Phase 1 Prototype)
1. The Web UI Dashboard
No installation required.

Clone this repository or download index.html.

Double-click index.html to open it in Chrome, Edge, or Safari.

The interface includes a built-in simulation script that automatically updates the vital signs to demonstrate how the UI reacts to live data.

2. The ESP32 Firmware
Prerequisites: Arduino IDE, ESP32 Board Manager installed.

Install the required libraries via Arduino Library Manager:

MAX30105 (by SparkFun)

Adafruit MLX90614 Library

Wire the sensors to the ESP32:

SDA -> GPIO 21

SCL -> GPIO 22

VCC -> 3.3V

GND -> GND

Open main.ino, compile, and upload to your ESP32.

Open the Serial Monitor (115200 baud).

Pair your phone to the Bluetooth device named "Baymax_Health_Bot" and use any Serial Bluetooth Terminal app to view the incoming JSON data payload.

🗺️ Roadmap

☑ Phase 1 (Current): Software architecture, ESP32 JSON payload logic, UI dashboard design.

□ Phase 2 (Hardware Assembly): Physical wiring validation, battery integration, and mounting on a 4WD chassis.

□ Phase 3 (AI & Vision): Raspberry Pi integration, camera module for face recognition, and deploying the bilingual AI model.

📜 License
This project is licensed under the MIT License - see the LICENSE file for details.

👥 Contributors
Raagavendan R - Electronics And Communication Engineering Student (Previous NEET Repeater)
