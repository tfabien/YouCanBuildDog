# Hardware Guide

## Target approach

This variant intentionally uses the **lowest-cost and simplest architecture**:

- ESP32 touch board
- servos connected directly to ESP32 GPIO pins
- no PCA9685
- external 5V power supply for the servos

## Recommended board

A low-cost **ESP32 2.8 inch touch display board** is a good fit because it combines:
- ESP32
- color display
- touch input
- compact form factor
- low price

## Power rules

This is the most important part of the build.

### Do not do this
- Do **not** power the servos from the ESP32 board
- Do **not** share high servo current through thin USB-only wiring

### Do this
- Use a dedicated **5V external power supply** for the servos
- Connect **all servo grounds** to the power supply ground
- Connect the **ESP32 ground** to the same common ground
- Send only the **signal wire** from the ESP32 GPIO to each servo

## Basic wiring concept

- ESP32 GPIO -> servo signal
- external 5V -> servo V+
- external GND -> servo GND
- external GND -> ESP32 GND

## Suggested minimal GPIO plan

Actual available pins depend on the exact display board revision.  
Treat this as a starting point that must be validated against the board you buy.

Example idea:
- Servo 1 -> GPIO 13
- Servo 2 -> GPIO 14
- Servo 3 -> GPIO 26
- Servo 4 -> GPIO 27

Keep the UI and touch pins reserved for the display board itself.

## Stability tips

- add a large capacitor on the servo power rail
- keep servo power wires short and thick enough
- keep signal wires away from noisy power loops
- test one servo first, then two, then all servos

## Why direct GPIO is acceptable here

For a small educational robot with only a few servos, direct GPIO is the cheapest option.  
It is not as robust as using a dedicated servo driver, but it keeps the bill of materials low and the wiring simple.

## Child safety and usability

Because the interface is meant for children:
- hide loose wiring as much as possible
- protect the power input
- keep moving parts visible but not easy to pinch
- mount the screen where it can be touched without reaching near the legs
