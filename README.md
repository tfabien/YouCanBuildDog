# YouCanBuildDog ESP32 Touch Fork Plan

This documentation package describes a **low-cost ESP32 touch replacement** for the original Arduino Uno + buttons user interface.

## Goal

Replace the original button-based programming interface with a **kid-friendly touch interface**:
- large colorful buttons
- clear icons
- minimal text on the main screens
- advanced text only for setup and calibration
- no external servo driver board
- direct servo control from ESP32 GPIO
- external 5V power supply for servos

## Design principles

The graphical interface is intentionally designed for children:
- **big touch targets**
- **strong color coding**
- **one icon = one action**
- **very little text on the main screens**
- **predictable navigation**
- **fun but simple visual language**

The advanced pages (calibration, setup, diagnostics) may still contain text because they are intended for an adult.

## Suggested hardware

- ESP32-2432S028 or similar low-cost 2.8" ESP32 touch display
- 4 small servos (or adapt later to 6 if the full original design is kept)
- external regulated 5V power supply for servos
- common ground between ESP32 and servo power

## Included documents

- `docs/hardware.md` — wiring and power recommendations
- `docs/ui.md` — child-friendly user interface proposal
- `docs/migration-plan.md` — recommended migration steps
- `docs/assets/` — wiring diagram and screen mockups

## Important note

This package is a **documentation and design starter**.  
It does not yet contain the ESP32 firmware implementation.

The recommended next step is to build:
1. a minimal ESP32 servo control prototype,
2. a touch UI with large icon-based actions,
3. a sequence editor,
4. optional setup/calibration pages for adults.
