# OpenDecapper

![License: CC BY-NC 4.0](https://img.shields.io/badge/License-CC_BY--NC_4.0-lightgrey.svg)(https://creativecommons.org/licenses/by-nc/4.0/)
![Build: Alpha](https://img.shields.io/badge/Status-Alpha-orange)

**OpenDecapper** is an open-source, automated hardware solution for decapping fired brass. This project aims to provide a reliable, high-speed alternative to manual decapping by leveraging 3D-printed mechanics and Arduino-based control.

---

## 📂 Repository Structure

* **/code**: Source code (`.ino`) for the microcontroller. Handles motor control, cycle timing, and sensor feedback.
* **/stl**: STL files for all structural and functional components.
* **/cad**: Original source files (STEP/Fusion 360) for design modifications and community forks.

---

## 🛠 Features

* **Automated Cycling:** Continuous feeding and de-priming.
* **Open Hardware:** Fully customizable to fit different bench setups.
* **Adjustable Speed:** Code-based control for different brass conditions.
* **Modular Toolheads:** Quick-swap heads for different calibers.

---

## 🖨️ Print Instructions

For maximum durability and mechanical precision, use the following settings:

| Setting | Value |
| :--- | :--- |
| **Material** | PETG |
| **Infill** | 20% Gyroid |
| **Walls** | 5 |
| **Top Layers** | 5 |
| **Bottom Layers** | 5 |

---

## 🚀 Getting Started

### 1. Hardware Requirements
* **Electronics:** Arduino (Nano/Uno), NEMA 17 Stepper Motor, Stepper Driver (TMC2209 or TMC2208).
* **Tools:** 3D Printer (PETG recommended), M3/M5 Bolt kit, 8mm Linear Rails.

### 2. Software Setup
1.  Clone this repository:
    ```bash
    git clone [https://github.com/EggCe/OpenDecapper.git](https://github.com/EggCe/OpenDecapper.git)
    ```
2.  Open `/Arduino/OpenDecapper.ino` in the Arduino IDE.
3.  Install necessary libraries (e.g., `AccelStepper`).
4.  Upload to your board.

---

## 📅 Upcoming Milestones

- [ ] **Comprehensive BOM:** Detailed list of all off-the-shelf parts and fasteners.
- [ ] **Assembly Manual:** Step-by-step instructions with wiring diagrams.
- [ ] **Calibration Guide:** Tips for timing the stroke and sensor alignment.

---

## 🤝 Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create.

1.  Fork the Project.
2.  Create your Feature Branch (`git checkout -b feature/ImprovedFeeder`).
3.  Commit your Changes (`git commit -m 'Add improved case feeder'`).
4.  Push to the Branch (`git push origin feature/ImprovedFeeder`).
5.  Open a Pull Request.

---

## ⚖️ License

This project is licensed under the **Creative Commons Attribution-NonCommercial 4.0 International (CC BY-NC 4.0)**. 

**Summary:** You are free to share and adapt this material for non-commercial purposes only. If you remix or build upon this work, you must give appropriate credit. Commercial use of these designs or code is prohibited without explicit permission.

---

**Safety Warning:** *Operating mechanical machinery involves inherent risks. Always use safe