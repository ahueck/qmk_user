#pragma once

#include "quantum.h"

enum tap_dance { TD_ESC_CAPS = 0, TAP_DANCE_MAX };

#define TDKC_ESC TD(TD_ESC_CAPS)

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_MAX];

#define AH_SINGLE_TD(_name_, key1, key2)                                       \
  void dance_finished_##_name_(qk_tap_dance_state_t* state, void* user_data) { \
    if (state->count == 1) {                                                   \
      register_code(key1);                                                     \
    } else {                                                                   \
      register_code(key2);                                                     \
      register_code(key1);                                                     \
    }                                                                          \
  }                                                                            \
  void dance_reset_##_name_(qk_tap_dance_state_t* state, void* user_data) {    \
    if (state->count == 1) {                                                   \
      unregister_code(key1);                                                   \
    } else {                                                                   \
      unregister_code(key2);                                                     \
      unregister_code(key1);                                                   \
    }                                                                          \
  }
