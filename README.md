<<<<<<< HEAD
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
=======
# YouCanBuildDog - ESP32 Touch Migration

This package is a lightweight fork-ready documentation bundle for migrating the original **YouCanBuildDog** Arduino Uno project to a **low-cost ESP32 touch board**.

## Goal

Replace the original Arduino Uno + push buttons setup with:

- an **ESP32 touch display board**
- **servos connected directly to the ESP32 GPIOs**
- a **simple touch UI** to program and replay movements

## Target approach

This bundle intentionally follows the **cheapest and simplest** architecture:

- **ESP32-2432S028** (2.8" touch display, also known as "Cheap Yellow Display")
- servos driven **directly from ESP32 PWM-capable GPIOs**
- **external 5V power supply for servos**
- shared ground between ESP32 and servo power supply
- no PCA9685, no additional driver board

## Important warning

Do **not** power the servos from the ESP32 board.

Use:

- external **5V servo power supply**
- common **GND** between servo power and ESP32
- ESP32 GPIOs only for **servo signal wires**

## Documentation included

- `docs/hardware.md` - hardware choice, wiring, power recommendations
- `docs/ui.md` - touch UI concept and screen descriptions
- `docs/migration-plan.md` - safe migration plan from the original sketch
- `docs/assets/` - simple wiring and UI mockups

## Suggested repository structure

If you want to turn this into a real Git fork, you can place these files in your repository like this:

```text
README.md
/docs
  hardware.md
  ui.md
  migration-plan.md
  /assets
```

## Recommended next step

Once the hardware is confirmed, the next practical step is to create:

- an ESP32-compatible servo layer
- a touch UI layer
- persistent storage for sequences and servo offsets

>>>>>>> 5a4d945496969cf9e4c59adc99341d44751ceb7c
