# Inspectorobot - Arduino & ESP32 Camera Based 4WD Robot

## Overview
Inspectorobot is a 4WD inspection robot built using:
- **Arduino UNO** for motor control
- **ESP32-CAM** for real-time video streaming
- **L298N Motor Driver** for movement
- **18650 Batteries** for power
- **Windows Forms App** for remote control & live video feed

This project enables real-time surveillance and remote control via a custom-built Windows application that utilizes **WebView2** for displaying the camera feed and **arrow key inputs** for navigation.

---

## Features
✅ Live video streaming via **ESP32-CAM**  
✅ Control movement using **arrow keys** in the Windows app  
✅ Stable **5V power supply** using a **buck converter**  
✅ Simple assembly using a **4WD chassis kit**  
✅ **Bidirectional control** using **L298N Motor Driver**  
✅ Fully open-source and customizable  

---

## Components Used
### Hardware:
- **Arduino UNO**
- **ESP32-CAM**
- **L298N Motor Driver**
- **4WD Chassis Kit**
- **18650 Batteries & Holder**
- **Buck Converter (5V)**
- **Jumper Wires & Connectors**

### Software:
- **Arduino IDE** (For programming Arduino & ESP32-CAM)
- **Windows Forms (.NET Framework)** (For remote control application)
- **WebView2** (For live video streaming in the app)

---

## Circuit Diagram
![Inspectorobot](https://github.com/user-attachments/assets/617ea9b2-70d9-4cda-8cda-878eb4191e74)

---

## Installation & Usage
### 1. Flash ESP32-CAM
- Open Arduino IDE
- Install ESP32 board support
- Flash `ESP_CAM.ino` to ESP32-CAM
- Note the IP address from the serial monitor

### 2. Flash Arduino UNO
- Open Arduino IDE
- Flash `Inspectrobot.ino` to Arduino UNO

### 3. Setup Windows Application
- Open `Inspectrobot.sln` in Visual Studio
- Build and run the application
- Enter ESP32-CAM's IP in the settings
- Use arrow keys to control the robot

---

## How It Works
1. **ESP32-CAM** streams live video over Wi-Fi.
2. **Windows app** loads the video stream in **WebView2**.
3. **Arrow keys** send movement commands to Arduino over serial.
4. **Arduino UNO** controls motors using **L298N Motor Driver**.

---

## Demo
![Inspectorobot Preview]((https://youtu.be/meLO_pPPLLU))  
🎥 [Watch Full Tutorial on YouTube]((https://youtu.be/meLO_pPPLLU))

---

## Contributing
Feel free to fork the repo, submit issues, or contribute enhancements!

---

## License
This project is licensed under the **MIT License**.
