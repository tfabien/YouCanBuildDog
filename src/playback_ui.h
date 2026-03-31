#pragma once

#include <lvgl.h>
#include "motion_engine.h"

/**
 * @brief Small LVGL playback screen controller.
 */
class PlaybackUi {
public:
    /**
     * @brief Create all widgets for the playback screen.
     */
    void begin(lv_obj_t* parent);

    /**
     * @brief Refresh the visible state from the sequence.
     */
    void refresh(const DogSequence& sequence);

private:
    lv_obj_t* root_ = nullptr;
    lv_obj_t* currentCard_ = nullptr;
    lv_obj_t* currentLabel_ = nullptr;
    lv_obj_t* currentHint_ = nullptr;
    lv_obj_t* nextCards_[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    lv_obj_t* nextLabels_[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    lv_obj_t* progressBar_ = nullptr;

    void applyActionStyle(lv_obj_t* obj, DogAction action, bool large);
    const char* hintForAction(DogAction action) const;
};
