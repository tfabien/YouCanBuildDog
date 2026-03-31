#pragma once

#include <Arduino.h>

/**
 * @brief Supported robot actions.
 */
enum class DogAction : uint8_t {
    NONE = 0,
    FORWARD = 1,
    BACKWARD = 2,
    LEFT = 3,
    RIGHT = 4
};

/**
 * @brief Simple fixed-size sequence model for up to 12 actions.
 */
struct DogSequence {
    static constexpr uint8_t MAX_ACTIONS = 12;

    DogAction items[MAX_ACTIONS];
    uint8_t count = 0;
    uint8_t currentIndex = 0;

    /**
     * @brief Reset the sequence content and playback position.
     */
    void clear() {
        count = 0;
        currentIndex = 0;
        for (uint8_t i = 0; i < MAX_ACTIONS; ++i) {
            items[i] = DogAction::NONE;
        }
    }

    /**
     * @brief Append one action if there is still room.
     * @return true when the action is added, false when the sequence is full.
     */
    bool add(const DogAction action) {
        if (count >= MAX_ACTIONS) {
            return false;
        }
        items[count++] = action;
        return true;
    }

    /**
     * @brief Get the current action or NONE when playback is finished.
     */
    DogAction current() const {
        return currentIndex < count ? items[currentIndex] : DogAction::NONE;
    }

    /**
     * @brief Move to the next action.
     * @return true when there is another action to play, false otherwise.
     */
    bool advance() {
        if (currentIndex + 1 < count) {
            ++currentIndex;
            return true;
        }
        currentIndex = count;
        return false;
    }

    /**
     * @brief Restart playback from the first action.
     */
    void restart() {
        currentIndex = 0;
    }

    /**
     * @brief Return the number of remaining actions including the current one.
     */
    uint8_t remaining() const {
        return currentIndex < count ? count - currentIndex : 0;
    }
};

/**
 * @brief Convert one action to a user-facing label.
 */
static inline const char* actionLabel(const DogAction action) {
    switch (action) {
        case DogAction::FORWARD: return "GO";
        case DogAction::BACKWARD: return "BACK";
        case DogAction::LEFT: return "LEFT";
        case DogAction::RIGHT: return "RIGHT";
        default: return "NONE";
    }
}
