#include "playback_ui.h"

/**
 * @brief Convert an action to a small hint line.
 */
const char* PlaybackUi::hintForAction(const DogAction action) const {
    switch (action) {
        case DogAction::FORWARD: return "forward";
        case DogAction::BACKWARD: return "backward";
        case DogAction::LEFT: return "turn left";
        case DogAction::RIGHT: return "turn right";
        default: return "";
    }
}

/**
 * @brief Apply consistent toy-like styles depending on the action.
 */
void PlaybackUi::applyActionStyle(lv_obj_t* obj, const DogAction action, const bool large) {
    lv_color_t bg = lv_palette_lighten(LV_PALETTE_GREY, 2);

    switch (action) {
        case DogAction::FORWARD:
            bg = lv_color_hex(0x4CD964);
            break;
        case DogAction::BACKWARD:
            bg = lv_color_hex(0xFF9500);
            break;
        case DogAction::LEFT:
            bg = lv_color_hex(0x5AC8FA);
            break;
        case DogAction::RIGHT:
            bg = lv_color_hex(0xAF52DE);
            break;
        default:
            break;
    }

    lv_obj_set_style_radius(obj, large ? 28 : 18, 0);
    lv_obj_set_style_bg_color(obj, bg, 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(obj, 0, 0);
    lv_obj_set_style_shadow_width(obj, large ? 20 : 8, 0);
    lv_obj_set_style_shadow_opa(obj, LV_OPA_20, 0);
    lv_obj_set_style_shadow_spread(obj, 0, 0);
    lv_obj_set_style_shadow_ofs_y(obj, 6, 0);
}

/**
 * @brief Build the whole playback screen.
 */
void PlaybackUi::begin(lv_obj_t* parent) {
    root_ = lv_obj_create(parent);
    lv_obj_remove_style_all(root_);
    lv_obj_set_size(root_, lv_pct(100), lv_pct(100));
    lv_obj_set_style_bg_color(root_, lv_color_hex(0xF5FAFF), 0);
    lv_obj_set_style_bg_opa(root_, LV_OPA_COVER, 0);

    lv_obj_t* title = lv_label_create(root_);
    lv_label_set_text(title, "Robot Dog Playback");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_24, 0);
    lv_obj_align(title, LV_ALIGN_TOP_LEFT, 20, 16);

    currentCard_ = lv_obj_create(root_);
    lv_obj_set_size(currentCard_, 300, 250);
    lv_obj_align(currentCard_, LV_ALIGN_LEFT_MID, 20, -10);
    applyActionStyle(currentCard_, DogAction::FORWARD, true);

    currentLabel_ = lv_label_create(currentCard_);
    lv_label_set_text(currentLabel_, "GO");
    lv_obj_set_style_text_color(currentLabel_, lv_color_white(), 0);
    lv_obj_set_style_text_font(currentLabel_, &lv_font_montserrat_32, 0);
    lv_obj_align(currentLabel_, LV_ALIGN_CENTER, 0, -10);

    currentHint_ = lv_label_create(currentCard_);
    lv_label_set_text(currentHint_, "forward");
    lv_obj_set_style_text_color(currentHint_, lv_color_white(), 0);
    lv_obj_set_style_text_font(currentHint_, &lv_font_montserrat_18, 0);
    lv_obj_align(currentHint_, LV_ALIGN_CENTER, 0, 34);

    lv_obj_t* nextTitle = lv_label_create(root_);
    lv_label_set_text(nextTitle, "Up next");
    lv_obj_set_style_text_font(nextTitle, &lv_font_montserrat_20, 0);
    lv_obj_align(nextTitle, LV_ALIGN_TOP_RIGHT, -220, 36);

    const int16_t startX = 360;
    const int16_t y = 150;
    const int16_t width = 90;
    const int16_t height = 90;
    const int16_t gap = 14;

    for (uint8_t i = 0; i < 5; ++i) {
        nextCards_[i] = lv_obj_create(root_);
        lv_obj_set_size(nextCards_[i], width, height);
        lv_obj_align(nextCards_[i], LV_ALIGN_TOP_LEFT, startX + i * (width + gap), y);
        applyActionStyle(nextCards_[i], DogAction::NONE, false);

        nextLabels_[i] = lv_label_create(nextCards_[i]);
        lv_label_set_text(nextLabels_[i], "-");
        lv_obj_set_style_text_color(nextLabels_[i], lv_color_white(), 0);
        lv_obj_set_style_text_font(nextLabels_[i], &lv_font_montserrat_16, 0);
        lv_obj_center(nextLabels_[i]);
    }

    progressBar_ = lv_bar_create(root_);
    lv_obj_set_size(progressBar_, 760, 18);
    lv_obj_align(progressBar_, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_bar_set_range(progressBar_, 0, DogSequence::MAX_ACTIONS);
    lv_obj_set_style_radius(progressBar_, 12, 0);
    lv_obj_set_style_bg_color(progressBar_, lv_color_hex(0xDCEBFA), LV_PART_MAIN);
    lv_obj_set_style_bg_color(progressBar_, lv_color_hex(0x5B8DEF), LV_PART_INDICATOR);
}

/**
 * @brief Update current action, next actions and progress bar.
 */
void PlaybackUi::refresh(const DogSequence& sequence) {
    const DogAction current = sequence.current();

    applyActionStyle(currentCard_, current, true);
    lv_label_set_text(currentLabel_, actionLabel(current));
    lv_label_set_text(currentHint_, hintForAction(current));

    for (uint8_t i = 0; i < 5; ++i) {
        const uint8_t sequenceIndex = sequence.currentIndex + 1 + i;
        const DogAction action = sequenceIndex < sequence.count ? sequence.items[sequenceIndex] : DogAction::NONE;

        applyActionStyle(nextCards_[i], action, false);
        lv_label_set_text(nextLabels_[i], action == DogAction::NONE ? "-" : actionLabel(action));
    }

    lv_bar_set_value(progressBar_, sequence.currentIndex + (sequence.currentIndex < sequence.count ? 1 : 0), LV_ANIM_ON);
}
