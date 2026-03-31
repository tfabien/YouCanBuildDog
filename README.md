# YouCanBuildDog ESP32 Touch Kit

This package contains a starter kit for a **low-cost ESP32 touch migration** of the original `YouCanBuildDog` project.

Included:

- a **minimal toy-like icon pack**
- a **LVGL playback screen** example
- an **Arduino `.ino` sketch** for ESP32
- hardware and UI documentation
- notes about integration and limitations

## Package structure

- `assets/icons/` — icon pack in SVG and PNG
- `src/RobotDogTouch.ino` — Arduino sketch entry point
- `src/playback_ui.h` — LVGL playback UI API
- `src/playback_ui.cpp` — LVGL playback UI implementation
- `src/motion_engine.h` — simple motion data model
- `docs/hardware.md` — wiring and power guide
- `docs/ui.md` — UI explanation
- `docs/integration.md` — how the files fit together

## Important notes

This package is designed to be:
- simple
- cheap
- easy to adapt

It does **not** try to fully reimplement the original robot gait logic.  
Instead, it gives you a clean structure to plug your existing movement logic into an ESP32 + LVGL front end.

## Servo power

Do **not** power the servos from the ESP32 board.  
Use a dedicated 5V supply for the servos, with a **common ground** shared with the ESP32.
