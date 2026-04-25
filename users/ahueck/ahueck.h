#pragma once

#include "quantum.h"

#ifdef TAP_DANCE_ENABLE
#    include "tap_dance.h"
#endif

#ifdef COMBO_ENABLE
#    include "combo.h"
#endif

enum ahueck_layers {
    LAYER_QWERTY = 0,
    LAYER_SYMB,
    LAYER_SYMB_EXT,
    LAYER_ADJUST,
    LAYER_STD,
    LAYER_POINTER,
};

enum custom_keycodes {
    ASC_SAR = SAFE_RANGE,
    ASC_VERS,
    M_AE,
    M_OE,
    M_UE,
    M_ESZ,
    M_MU,
    M_EUR,
    NEW_SAFE_RANGE
};

// Layer-independent macros
#define KC_BKSL KC_BSLASH
#define KC_RSBS RSFT_T(KC_BSLS)
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

// Layer-dependent macros
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define SYM_L MO(LAYER_SYMB)
#define KC_SYSP LT(LAYER_SYMB, KC_SPC)
#define KC_SYBS LT(LAYER_SYMB, KC_BSPC)
#define KC_SYEEN LT(LAYER_SYMB_EXT, KC_ENT)
#define KC_SYEDE LT(LAYER_SYMB_EXT, KC_DEL)
#define KC_ADEN LT(LAYER_ADJUST, KC_END)
#define KC_ADPU LT(LAYER_ADJUST, KC_PGUP)
#define KC_HS LT(LAYER_SYMB, KC_H)
#define KC_GS LT(LAYER_SYMB, KC_G)
#define TO_BASE TO(LAYER_QWERTY)
#define TO_STD TO(LAYER_STD)

// Home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Utility macros from support.h
#define AH_SEND_KEY_OR_SHIFT_THEN(key, key_then)      \
  if ((mods | get_oneshot_mods()) & MOD_MASK_SHIFT) { \
    del_mods(MOD_MASK_SHIFT);                         \
    del_oneshot_mods(MOD_MASK_SHIFT);                 \
    SEND_STRING((key_then));                          \
    set_mods(mods);                                   \
  } else {                                            \
    SEND_STRING((key));                               \
  }
