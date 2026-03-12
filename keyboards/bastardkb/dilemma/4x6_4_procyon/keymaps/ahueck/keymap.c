#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config;

#include "support.h"

enum dilemma_keymap_layers {
    LAYER_QWERTY = 0,
    LAYER_SYMB,
    LAYER_SYMB_EXT,
    LAYER_ADJUST,
    LAYER_STD,
    LAYER_POINTER,
};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

enum custom_keycodes {
  ASC_SAR = SAFE_RANGE,
  ASC_VERS,
  M_AE,
  M_OE,
  M_UE,
  M_ESZ,
  M_MU,
  M_EUR
};

#ifdef TAP_DANCE_ENABLE
// Tap dance keycodes
enum tap_dance { TD_ESC_CAPS = 0 };

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};
#endif

// Send custom strings
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (record->event.pressed) {
    const uint8_t mods = get_mods();

    switch (keycode) {
      case ASC_SAR:
        AH_SEND_KEY_OR_SHIFT_THEN("->", "=>")
        return false;
      case ASC_VERS:
        SEND_STRING(QMK_BUILDDATE ":" QMK_VERSION);
        return false;
      case M_AE:
        SEND_STRING(SS_RALT(SS_LSFT("'")) "a");
        return false;
      case M_OE:
        SEND_STRING(SS_RALT(SS_RSFT("'")) "o");
        return false;
      case M_UE:
        SEND_STRING(SS_RALT(SS_RSFT("'")) "u");
        return false;
      case M_ESZ:
        SEND_STRING(SS_RALT("ss"));
        return false;
      case M_MU:
        SEND_STRING(SS_RALT("/u"));
        return false;
      case M_EUR:
        SEND_STRING(SS_RALT("c="));
        return false;
    }
  }
  return true;
};

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#define KC_BKSL KC_BSLASH
#define SYM_L MO(LAYER_SYMB)

#define KC_SYSP LT(LAYER_SYMB, KC_SPC)
#define KC_SYBS LT(LAYER_SYMB, KC_BSPC)
#define KC_SYEEN LT(LAYER_SYMB_EXT, KC_ENT)
#define KC_SYEDE LT(LAYER_SYMB_EXT, KC_DEL)
#define KC_ADEN LT(LAYER_ADJUST, KC_END)
#define KC_ADPU LT(LAYER_ADJUST, KC_PGUP)

#define KC_HS LT(LAYER_SYMB, KC_H)
#define KC_GS LT(LAYER_SYMB, KC_G)

#define KC_RSBS RSFT_T(KC_BSLS)
#define TDKC_ESC TD(TD_ESC_CAPS)
#define KC_CTSP LCTL(KC_SPC)
#define KC_CTQU RCTL_T(KC_QUOT)
#define KC_VOLM KC_AUDIO_MUTE
#define KC_CALC KC_CALCULATOR
#define KC_CTME MT(MOD_LCTL | MOD_LGUI, KC_TILD)
#define KC_CTSH MT(MOD_LCTL | MOD_LSFT, KC_PMNS)
#define KC_CTAL MT(MOD_LCTL | MOD_LALT, KC_PPLS)
#define OC_CTSH OSM(MOD_LCTL | MOD_LSFT)
#define OC_CTAL OSM(MOD_LCTL | MOD_LALT)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)
#define KC_CPY LCTL(KC_C)
#define KC_PST LCTL(KC_V)
#define KC_CUT LCTL(KC_X)
#define TO_BASE TO(LAYER_QWERTY)
#define TO_STD TO(LAYER_STD)
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_CAPS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_EQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_TAB,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_GS,      KC_HS,   HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_CTQU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  PT_SLSH, KC_RSBS,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         KC_LALT, KC_LCTL, KC_SYBS, KC_SYEDE,  KC_SYEEN, KC_SYSP, KC_RCTL, KC_RALT
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [LAYER_SYMB] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_CTME,  KC_TILD, KC_HASH, KC_LPRN, KC_RPRN,   KC_T,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_CTSH,  KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR,   KC_P,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_CTAL,  KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC,   KC_CTSP, ASC_SAR, SELWORD, SELWBAK, SELLINE, SELLUP,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    _______, _______, _______, _______
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [LAYER_SYMB_EXT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_CLEAR, KC_BSPC, XXXXXXX, M_EUR,  XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_REDO, KC_CUT,  KC_CPY,  KC_PST,  KC_UNDO,    KC_PAST, KC_KP_7, KC_KP_8, KC_KP_9, KC_CALC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_CTSH, KC_ENT,  KC_SPC,  KC_BSPC, KC_DEL,     KC_PSLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PCMM, KC_PENT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_CTAL, M_AE,    M_OE,    M_UE,    M_ESZ,      KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    _______, _______, KC_PPLS, KC_KP_0
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [LAYER_ADJUST] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, CM_ON,   CM_OFF,  CM_TOGG, ASC_VERS, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         DT_UP ,  DT_DOWN, DT_UP   , XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [LAYER_STD] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, KC_END,  _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, KC_BSPC, KC_DEL,     KC_ENT,  KC_SPC,  _______, _______
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, EE_CLR,  QK_BOOT,    QK_BOOT, EE_CLR,  SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         XXXXXXX, MS_BTN2, MS_BTN1, MS_BTN3,    MS_BTN3, MS_BTN1, MS_BTN2, XXXXXXX
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),
};

// clang-format on

enum combos {
  DF_ESC,
  JK_TAB,
  FJ_ENTER,
  UI_LINE,
};
const uint16_t PROGMEM esc_combo[]   = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM tab_combo[]   = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {HOME_F, HOME_J, COMBO_END};
const uint16_t PROGMEM line_combo[]  = {KC_U, KC_I, COMBO_END};
combo_t key_combos[]                 = {
    [DF_ESC]   = COMBO(esc_combo, KC_ESC),
    [JK_TAB]   = COMBO(tab_combo, KC_TAB),
    [FJ_ENTER] = COMBO(enter_combo, KC_ENTER),
    [UI_LINE]  = COMBO(line_combo, SELLINE),
};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

// clang-format off

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_QWERTY]   = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_SYMB]     = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_SYMB_EXT] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_ADJUST]   = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
    [LAYER_STD]      = {ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [LAYER_POINTER]  = {ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU)},
};
#endif

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       'L',     'L',     'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R',     'R',     'R',
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         'L',     'L',     'L',     'L',        'R',     'R',     'R',     'R'
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
);

// clang-format on
