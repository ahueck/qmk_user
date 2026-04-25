CAPS_WORD_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
COMBO_ENABLE = yes

SRC += ahueck.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += combo.c
#     INTROSPECTION_KEYMAP_C = combo.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dance.c
endif
