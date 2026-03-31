#include <Arduino.h>
#include <ESP32Servo.h>
#include <lvgl.h>
#include "motion_engine.h"
#include "playback_ui.h"

/**
 * @brief Demo servo count used in this simplified starter kit.
 */
static constexpr uint8_t SERVO_COUNT = 4;

/**
 * @brief Update these pins to match your display board and free GPIOs.
 */
static constexpr int SERVO_PINS[SERVO_COUNT] = {13, 14, 26, 27};

/**
 * @brief Servo neutral angle used on startup.
 */
static constexpr int SERVO_NEUTRAL_ANGLE = 90;

/**
 * @brief Time spent on one action before advancing to the next one.
 */
static constexpr uint32_t ACTION_DURATION_MS = 900;

Servo servos[SERVO_COUNT];
DogSequence sequence;
PlaybackUi playbackUi;

uint32_t lastActionChangeMs = 0;
bool isPlaying = false;

/**
 * @brief Placeholder LVGL display callback integration.
 *
 * Replace this whole section with the display driver setup matching your
 * exact ESP32 touch board.
 */
static void initDisplayAndTouch() {
    lv_init();

    // TODO:
    // - initialize your real TFT display
    // - initialize your touch controller
    // - register LVGL display and input drivers
}

/**
 * @brief Attach all servos on their configured GPIO pins.
 */
static void initServos() {
    for (uint8_t i = 0; i < SERVO_COUNT; ++i) {
        servos[i].attach(SERVO_PINS[i], 500, 2400);
        servos[i].write(SERVO_NEUTRAL_ANGLE);
    }
}

/**
 * @brief Build one demo sequence with up to 12 actions.
 */
static void loadDemoSequence() {
    sequence.clear();
    sequence.add(DogAction::FORWARD);
    sequence.add(DogAction::LEFT);
    sequence.add(DogAction::FORWARD);
    sequence.add(DogAction::RIGHT);
    sequence.add(DogAction::BACKWARD);
    sequence.add(DogAction::FORWARD);
    sequence.add(DogAction::LEFT);
    sequence.add(DogAction::FORWARD);
    sequence.add(DogAction::RIGHT);
    sequence.add(DogAction::FORWARD);
    sequence.add(DogAction::BACKWARD);
    sequence.add(DogAction::FORWARD);
    sequence.restart();
}

/**
 * @brief Run one high-level action.
 *
 * Replace the placeholder movements below with the original robot gait logic.
 * Keep this method as the single integration point to avoid scattering motion
 * code across the sketch.
 */
static void runMotionStep(const DogAction action) {
    switch (action) {
        case DogAction::FORWARD:
            servos[0].write(70);
            servos[1].write(110);
            servos[2].write(70);
            servos[3].write(110);
            break;

        case DogAction::BACKWARD:
            servos[0].write(110);
            servos[1].write(70);
            servos[2].write(110);
            servos[3].write(70);
            break;

        case DogAction::LEFT:
            servos[0].write(75);
            servos[1].write(75);
            servos[2].write(105);
            servos[3].write(105);
            break;

        case DogAction::RIGHT:
            servos[0].write(105);
            servos[1].write(105);
            servos[2].write(75);
            servos[3].write(75);
            break;

        case DogAction::NONE:
        default:
            for (uint8_t i = 0; i < SERVO_COUNT; ++i) {
                servos[i].write(SERVO_NEUTRAL_ANGLE);
            }
            break;
    }
}

/**
 * @brief Prepare the first screen and initial state.
 */
void setup() {
    Serial.begin(115200);

    initDisplayAndTouch();
    initServos();
    loadDemoSequence();

    playbackUi.begin(lv_scr_act());
    playbackUi.refresh(sequence);

    lastActionChangeMs = millis();
    isPlaying = true;
}

/**
 * @brief Main loop:
 * - service LVGL
 * - play the current step
 * - advance every ACTION_DURATION_MS
 */
void loop() {
    lv_timer_handler();
    delay(5);

    if (!isPlaying) {
        return;
    }

    runMotionStep(sequence.current());

    const uint32_t now = millis();
    if (now - lastActionChangeMs < ACTION_DURATION_MS) {
        return;
    }

    lastActionChangeMs = now;

    if (!sequence.advance()) {
        isPlaying = false;
        runMotionStep(DogAction::NONE);
    }

    playbackUi.refresh(sequence);
}
