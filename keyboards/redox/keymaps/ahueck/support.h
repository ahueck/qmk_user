#ifndef REDOX_AH_UTIL_MACRO_H_
#define REDOX_AH_UTIL_MACRO_H_

#ifdef RGBLIGHT_ENABLE
#define AH_STATIC_LIGHT(COLOR)                        \
  rgblight_enable_noeeprom();                         \
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); \
  rgblight_sethsv_noeeprom(COLOR);
#endif

#endif