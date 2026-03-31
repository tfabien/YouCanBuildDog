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

