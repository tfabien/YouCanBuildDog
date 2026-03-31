# Hardware Guide

## Goal

Use an inexpensive **ESP32 touch board** and drive the servos **directly from GPIO**.

## Recommended architecture

- ESP32 touch display board
- external 5V power supply for servos
- common ground between ESP32 and servo supply
- servo control signal from ESP32 GPIO

## Example signal mapping

Update these pins to match your board and free GPIOs:

- Servo 1 -> GPIO 13
- Servo 2 -> GPIO 14
- Servo 3 -> GPIO 26
- Servo 4 -> GPIO 27

## Power warning

Never use the ESP32 5V line to power all servos directly.

Required wiring:
- servo V+ -> external 5V
- servo GND -> external GND
- ESP32 GND -> external GND
- servo signal -> ESP32 GPIO

## Mechanical recommendation

Mount the display where a child can touch it safely without putting fingers near the moving legs.
