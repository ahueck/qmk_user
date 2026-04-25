#pragma once

#include "quantum.h"

enum combos {
  DF_ESC = 0,
  JK_TAB,
  FJ_ENTER,
  UI_LINE,
  COMBO_MAX
};

extern combo_t key_combos[COMBO_MAX];
