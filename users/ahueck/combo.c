#include "ahueck.h"
#include "combo.h"

const uint16_t PROGMEM esc_combo[]   = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM tab_combo[]   = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {HOME_F, HOME_J, COMBO_END};
const uint16_t PROGMEM line_combo[]  = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [DF_ESC]   = COMBO(esc_combo, KC_ESC),
    [JK_TAB]   = COMBO(tab_combo, KC_TAB),
    [FJ_ENTER] = COMBO(enter_combo, KC_ENTER),
    [UI_LINE]  = COMBO(line_combo, SELLINE),
};
