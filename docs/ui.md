<<<<<<< HEAD
# Child-Friendly User Interface Proposal

## Main goal

The interface should be usable by children even if they cannot read much text.

For that reason, the **main experience relies on color, icons, and position** more than words.

## General design rules

- use **large buttons**
- use **very high contrast**
- use **one strong color per action**
- prefer **emoji-like icons** or simple pictograms
- keep the main screens almost text-free
- use text mostly in advanced pages such as setup and calibration

## Core action mapping

Suggested action tiles for the sequence editor:

- **Forward** → green tile → arrow up icon
- **Backward** → orange tile → arrow down icon
- **Turn left** → blue tile → left turn icon
- **Turn right** → purple tile → right turn icon
- **Play** → bright green triangle icon
- **Stop** → red square icon
- **Home** → house icon
- **Delete/Clear** → trash icon

## Main screens

### 1. Home screen
For children:
- big colorful mode buttons
- no paragraph text
- only a small label under each icon if needed

Suggested buttons:
- Create sequence
- Play sequence
- Dance / Demo
- Adult setup

### 2. Sequence editor
This is the most important screen.

Principles:
- 8 large slots
- each slot shows a big icon
- tap a slot to choose an action
- selected slot is highlighted
- bottom bar contains Play, Clear, and Home

This lets children build a movement path visually.

### 3. Action picker
When a child taps a slot, open a full-screen action picker with four large choices:
- forward
- backward
- turn left
- turn right

No complicated menus.

### 4. Play screen
Large status area showing:
- current step number
- large action icon
- progress dots
- big Play/Pause and Stop buttons

### 5. Calibration / setup
This page can use text because it is intended for an adult:
- servo offset
- touch calibration
- brightness
- diagnostics
- reset settings

## Accessibility choices

- avoid relying only on color: each action must also have a distinct icon
- maintain fixed positions for actions so children learn spatially
- make buttons large enough for quick tapping
- use friendly rounded shapes
- avoid tiny text in the main flow

## Recommended visual style

- sky blue background for navigation pages
- white cards
- bright green, orange, blue, purple action colors
- thick rounded buttons
- happy playful look
- simple status bar with battery/power icon if available
=======
# Touch UI Proposal

## Design goals

The new interface should remain:

- simple
- cheap to implement
- close to the original project behavior
- usable without external computer access

## Functional idea

The original project uses physical buttons to build a short movement sequence.

The touch version replaces those buttons with on-screen controls while preserving the same behavior:

- choose an action
- assign it to a sequence slot
- replay the sequence
- reset the sequence

## Main screens

## 1. Home screen

Purpose:

- central entry point
- quick access to programming and playback

Suggested buttons:

- **Program**
- **Play**
- **Calibration**
- **Reset**

## 2. Sequence editor screen

Purpose:

- create or modify a short movement sequence

Suggested layout:

- 8 numbered slots
- each slot stores one action
- action buttons at the bottom

Actions:

- **Forward**
- **Backward**
- **Turn Left**
- **Turn Right**

Suggested interactions:

- tap a slot to select it
- tap an action to assign it
- highlight the current slot
- provide a clear visual label for each stored action

## 3. Playback screen

Purpose:

- run the sequence
- show progression while the robot moves

Suggested controls:

- **Start**
- **Stop**
- **Home**

Suggested indicators:

- current step index
- current action label
- running / idle state

## 4. Calibration screen

Purpose:

- adjust servo offsets
- make leg positioning easier after assembly

Suggested controls:

- Servo 1 offset minus / plus
- Servo 2 offset minus / plus
- Servo 3 offset minus / plus
- Servo 4 offset minus / plus
- **Save**

## Visual style

Recommended style:

- large buttons
- high contrast labels
- simple colors
- no complex animations
- readable while standing near the robot

## UX recommendations

To keep the UI robust:

- avoid tiny touch targets
- avoid deep menus
- make the most common actions reachable in one tap
- show explicit labels instead of icons only
- keep the sequence length fixed at first

## Future improvements

Possible later improvements:

- more than 8 sequence steps
- named sequences
- save/load multiple programs
- speed adjustment
- manual servo positioning screen
- Wi-Fi export/import

>>>>>>> 5a4d945496969cf9e4c59adc99341d44751ceb7c
