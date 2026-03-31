# Hardware Guide

<<<<<<< HEAD
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
=======
## Selected board

For the lowest-cost setup, the recommended board is:

- **ESP32-2432S028**
- 2.8" color TFT display
- resistive touch panel
- integrated ESP32

This board is attractive because it combines:

- ESP32 microcontroller
- touch screen
- compact form factor
- low price

## Why direct servo control

The goal of this version is to keep the design:

- cheap
- simple
- easy to wire

For that reason, the servos are connected directly to the ESP32 instead of using a PCA9685 board.

## Important power rule

### Never do this

- Do not power the servos from the ESP32 5V pin.
- Do not assume the USB power input can safely power multiple servos.

### Always do this

- Use a **separate 5V power supply** for the servos.
- Connect **all grounds together**:
  - ESP32 GND
  - servo power supply GND
  - servo GND wires

## Minimal wiring concept

Each servo has 3 wires:

- **GND** -> external 5V power supply GND
- **V+** -> external 5V power supply +5V
- **Signal** -> one ESP32 GPIO

The ESP32 must share the same ground reference.

## Example wiring

### Power

- External 5V power supply -> all servo V+
- External GND -> all servo GND
- External GND -> ESP32 GND

### Signals

Example GPIO mapping to validate on the exact board revision:

- Servo 1 -> GPIO 26
- Servo 2 -> GPIO 27
- Servo 3 -> GPIO 14
- Servo 4 -> GPIO 13

> Note: this mapping is a starting point only. Some ESP32 display board variants expose different free pins. The exact board revision must be checked before final wiring.

## Current recommendation

For a small 4-servo robot:

- absolute minimum: **5V 3A** power supply
- safer choice: **5V 4A or 5V** with enough current margin

If you later use 6 servos, use a stronger supply.

## Reliability recommendations

To reduce resets and electrical noise:

- add a **1000 uF capacitor** across servo power rails
- keep servo power wires short and thick enough
- keep signal wires separate from noisy power loops if possible
- power the ESP32 independently from USB during development, or through a stable regulator in the final build

## Mechanical integration idea

A low-cost and practical layout is:

- ESP32 display mounted on top or on the side of the robot base
- servo power wires routed separately
- one external power connector for servos
- one USB connector kept accessible for firmware upload

## Parts list

### Required

- 1 x ESP32-2432S028 touch display board
- 4 x servos
- 1 x external 5V power supply
- jumper wires / Dupont wires
- common ground connection

### Recommended

- 1 x 1000 uF capacitor
- 1 x power switch
- 1 x small terminal block or power distribution point

>>>>>>> 5a4d945496969cf9e4c59adc99341d44751ceb7c
