This repository contains the Arduino source code (MOLASM.ino) used in the study:

"Far-Field Wireless Power Transmission Module with MEMS-Based Laser Steering for Optogenetic Applications"
Published in iScience, Cell Press
[[DOI will be available]]

System Overview

The MOLASM (Mobile Laser Steering Module) is a MEMS-based wireless optical power transmitter designed to enable far-field battery-less sensor operation.
This system integrates:

Electrothermal MEMS Micromirror for 2D laser beam steering

650 nm Laser Diode for optical power transmission

PWM-controlled actuation via Attiny85

Bluetooth Low Energy (BLE) for wireless control

Inductive Wireless Power Supply (HiPDiM) for fully untethered operation


Contents

MOLASM.ino – Arduino sketch that controls the MEMS micromirror with PWM signals for 1-axis beam steering.

The code receives BLE commands and adjusts laser direction accordingly.

Used in real-time optical alignment and beam tracking experiments in the paper.


Contact

For any questions regarding hardware integration or experimental replication, please contact:

Prof. Yongdae Kim
Department of Mechanical & Automotive Engineering, Kyungil University
ydkim@kiu.kr

