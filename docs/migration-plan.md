# Migration Plan

<<<<<<< HEAD
## Objective

Preserve the original robot behavior while replacing the physical buttons with a touch interface designed for children.

## Step 1 — Servo proof of concept
- boot ESP32
- attach the servos
- reproduce a simple move
- verify power stability

## Step 2 — Movement engine port
- keep the original movement logic as close as possible
- keep the same motion identifiers
- keep timing and transitions stable
- do not redesign the gait yet

## Step 3 — Child-friendly home screen
- build a home screen with large icon-based buttons
- avoid text-heavy navigation
- validate touch usability with real fingers, not only a stylus

## Step 4 — Sequence editor
- create 8 large movement slots
- allow one-tap action selection
- show movement using icons and colors
- support clear and replay

## Step 5 — Adult setup pages
- add calibration
- add diagnostics
- add brightness and sound options if used
- optionally add persistent storage

## Step 6 — Final enclosure integration
- mount the screen where a child can easily reach it
- secure the wires
- separate servo power and logic power physically

## Important non-goal

Do not make the user interface more complex than the original system.  
The added screen should make the robot easier to use, not harder.
=======
## Goal

Move from the original Arduino Uno implementation to an ESP32 touch display board while preserving the original robot behavior as much as possible.

## Migration strategy

The safest approach is incremental.

## Step 1 - Port servo control to ESP32

Keep the motion logic as close as possible to the original sketch.

Tasks:

- replace the Uno servo library with an ESP32-compatible one
- confirm PWM output on selected GPIOs
- validate neutral servo positions
- keep original timing and motion constants initially unchanged

Expected result:

- the robot performs the same basic movements as before

## Step 2 - Replace physical buttons with a software state model

Before building the full touch UI, replace direct button reads with internal software commands.

Tasks:

- convert button-triggered logic into callable actions
- keep the same sequence model
- preserve reset and playback behavior

Expected result:

- the robot logic is independent from physical buttons

## Step 3 - Add the touch screen UI

Tasks:

- implement home screen
- implement sequence editor
- implement playback screen
- implement reset action

Expected result:

- the original programming workflow is now performed on screen

## Step 4 - Add calibration support

Tasks:

- expose servo offsets in a simple UI
- apply offsets before writing pulse widths
- verify the robot posture after restart

Expected result:

- easier assembly tuning and maintenance

## Step 5 - Add persistence

Tasks:

- save movement sequence in flash memory
- save servo offsets in flash memory
- reload configuration at startup

Expected result:

- the programmed sequence survives reboot or power loss

## What should not change at first

To reduce regression risk, do not change initially:

- motion semantics
- sequence size
- action meanings
- timing constants
- motion interpolation logic

## Main risks

### Electrical risk

Servo current peaks may reset the ESP32.

Mitigation:

- external servo power supply
- common ground
- capacitor on servo rail

### GPIO conflict risk

Some display board pins may already be used internally.

Mitigation:

- confirm the exact board revision
- test each servo output one by one

### Mechanical risk

Servo offsets may need adjustment after rewiring or rebuild.

Mitigation:

- provide a calibration screen early

## Recommended implementation order

1. Servo test sketch
2. Minimal motion engine port
3. Internal software commands
4. Touch UI
5. Persistent storage
6. Final enclosure and cable routing

>>>>>>> 5a4d945496969cf9e4c59adc99341d44751ceb7c
