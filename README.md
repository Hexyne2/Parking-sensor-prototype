# Arduino Ultrasonic Parking Sensor

## Overview
This project is a simple parking sensor built with an Arduino Uno. It uses an ultrasonic distance sensor to measure how far an object is and gives real-time feedback using an RGB LED and a buzzer.

As the distance decreases, the LED shifts from green → yellow → red, and the buzzer increases its beep frequency.

---

## How it works
- The HC-SR04 ultrasonic sensor measures distance.
- The readings are smoothed using a simple moving average.
- Distance values are mapped to RGB LED output:
  - Green = safe distance
  - Yellow = medium distance
  - Red = close distance
- A buzzer provides audible feedback that becomes faster as the object gets closer.
- A state-based system controls when the buzzer is active.

---

## Components used
- Arduino Uno (Elegoo R3)
- HC-SR04 ultrasonic sensor
- RGB LED
- Active buzzer
- Breadboard
- Resistors (for LED protection)

---

## Wiring Diagram
Can be found in: Schematic of car sensor prototype.png

---

## Code
Main logic is implemented in `parking_sensor.ino`.

---

## What I learned
- Using ultrasonic sensors with Arduino
- Mapping sensor input to output signals
- Using `millis()` for non-blocking timing
- Basic state-based system design
- Signal smoothing using averaging

---

## Credits
Based on Elegoo HC-SR04 example code, modified and extended into a full parking sensor system.
