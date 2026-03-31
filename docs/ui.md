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

