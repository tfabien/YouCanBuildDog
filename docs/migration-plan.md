# Migration Plan

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
