# 📡 MOLASM: MEMS-Based Optical Wireless Power Transmission Module

This repository contains the Arduino source code and mobile application used in the study:

> **"Far-Field Wireless Power Transmission Module with MEMS-Based Laser Steering for Optogenetic Applications"**  
> Published in *iScience*, Cell Press  
> [[DOI will be available]]

---

## 🔧 System Overview

The **MOLASM (Mobile Laser Steering Module)** is a MEMS-based wireless optical power transmitter designed to enable far-field battery-less sensor operation.

This system integrates:

- Electrothermal MEMS Micromirror for 2D laser beam steering  
- 650 nm Laser Diode for optical power transmission  
- PWM-controlled actuation via **ATtiny85**  
- Bluetooth Low Energy (BLE) for wireless control  
- Inductive Wireless Power Module (HiPDiM) for full untethered operation  

---

## 📁 Repository Contents

| File | Description |
|------|-------------|
| `MOLASM.ino` | Arduino sketch to control MEMS micromirror (1-axis) via PWM signals |
| `Multi-MOLASM.aia` | MIT App Inventor source for the BLE-based control app |
| `Multi-MOLASM.apk` | **Android app (built)** for controlling MOLASM via BLE |
| `apk_qr.png` | QR code to download and install the APK |

---

## 📱 Mobile App (Bluetooth Control)

A custom Android app was developed using MIT App Inventor to wirelessly control MOLASM modules.  
It features:

- BLE scan and connect interface  
- Directional controls via PWM duty  
- Multi-device control 

### ▶️ Download APK

Scan the QR code below to install the app directly on your Android device:

![Download APK QR](apk_qr.png)

📥 **[Download Multi-MOLASM.apk](./Multi-MOLASM.apk)**

---

## 📬 Contact

For questions and collaborations:

**Prof. Yongdae Kim**  
Dept. of Mechanical & Automotive Engineering  
Kyungil University  
📧 ydkim@kiu.kr


