# Arduino-PID-Motor-Controller
A closed-loop discrete PID velocity controller simulated in C++ for a DC motor# Closed-Loop PID Motor Controller ⚙️

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Arduino%20%2F%20Tinkercad-00979D.svg)
![Control Theory](https://img.shields.io/badge/Focus-Control%20Systems-orange.svg)

## 📌 Project Overview
This repository contains the C++ source code and system architecture for a discrete, closed-loop Proportional-Integral-Derivative (PID) velocity controller. The system was designed and simulated using Tinkercad to validate the control logic before scaling up to physical hardware or more complex multi-phase simulations.

The controller utilizes a hardware interrupt service routine (ISR) to read quadrature encoder ticks in real-time, calculates the RPM, and dynamically adjusts the PWM duty cycle to an L293D H-bridge to maintain a target velocity regardless of simulated load variations.

## 🧰 System Architecture
* **Microcontroller:** Arduino Uno R3
* **Motor Driver:** L293D Quadruple Half-H Driver
* **Actuator:** Standard DC Motor
* **Sensor:** Built-in Quadrature Encoder (Channel A connected to Hardware Interrupt Pin D2)
* **Input:** 10kΩ Potentiometer (Target RPM Setpoint)

## 🧮 The Control Theory
The core of this project is the discrete PID algorithm. The controller calculates an output $u(t)$ based on the error $e(t)$ between the desired target RPM and the actual measured RPM.

$$u(t) = K_p e(t) + K_i \int_{0}^{t} e(\tau) d\tau + K_d \frac{de(t)}{dt}$$

* **Proportional ($K_p$):** Drives the motor based on the current absolute error.
* **Integral ($K_i$):** Accumulates past errors to eliminate steady-state offset and overcome physical friction. Anti-windup logic is implemented to cap the integral term at an 8-bit maximum (255).
* **Derivative ($K_d$):** Predicts future error based on the rate of change, acting as a damping factor to prevent system overshoot.

## 🚀 How to Run the Simulation
1. Open the https://www.tinkercad.com/things/cqC1AoN3TTT-cool-migelo-leelo?sharecode=B6EXGwiPHdRo1RC4jDb5eKFb8TODOrOXvYrKrgTc6Wg
2. Click **Start Simulation**.
3. Open the **Serial Monitor** and click the **Serial Plotter** icon.
4. Adjust the potentiometer dial to change the target RPM.
5. Observe the actual RPM curve stabilizing on the target setpoint via the serial plotter.

## 🔭 Future Scope
This discrete logic serves as the foundational timing and feedback architecture for upcoming advanced projects, including:
* Transitioning this feedback methodology into MATLAB/Simulink for a full Brushless DC (BLDC) motor commutation model.
* Translating the sequential C++ control loop into parallel hardware description logic (Verilog) for deployment on a Spartan 3E FPGA.

---
*Documented for engineering portfolio demonstration.*
