#include "ahueck.h"
#include "version.h"

// override for specific keyboard (extension point)
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
  return process_record_keymap(keycode, record);
}
