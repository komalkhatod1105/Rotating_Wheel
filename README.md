# Rotating_Wheel
# 🌀 Rotating Wheel Animation using C Graphics

This project is a **rotating wheel animation** built using the **C language with Turbo C++ graphics library**. It draws a circle (wheel) with 12 spokes and continuously rotates them to create a spinning illusion using simple delay and redraw logic.

---

## 🎯 Features

- Smooth rotating wheel effect using basic graphics
- Console-based graphical animation
- Uses `circle()`, `line()`, `putpixel()`, `delay()`, and `initgraph()` from the BGI graphics library
- Simple and easy-to-understand logic

---

## 🛠️ Technologies Used

- **Language:** C (Turbo C++)
- **Graphics Library:** BGI (Borland Graphics Interface)
- **Functions Used:** `circle`, `line`, `putpixel`, `delay`, `kbhit`, `initgraph`, etc.
- **Compiler:** Turbo C++ or DOSBox setup

---

## 📌 How It Works

- The wheel (circle) is drawn using the `circle()` function.
- The `calcPoints()` function calculates 12 points on the circle at every 30° interval.
- Spokes are drawn from the center to these points.
- Using alternate sets of lines and `delay()`, the spokes are quickly erased and redrawn in a new position to simulate rotation.
- The rotation continues until a key is pressed.

---

## 🚀 How to Compile and Run

### 🖥️ Turbo C++ Setup:

- Install [Turbo C++](https://archive.codeplex.com/?p=turboc) or use DOSBox + Turbo C++
- Make sure the BGI path is correct:
  ```c
  initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
  
🔧 Compilation Steps:
Open Turbo C++

Paste the code into Rotating_Wheel.cpp

Press Ctrl + F9 to compile and run.

-------

File Structure

Rotating_Wheel/
<br>
├── Rotating_Wheel.cpp
<br>
├── README.md
<br>
└── (TurboC3/BGI should be in correct path)

