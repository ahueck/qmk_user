/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// From vendor config
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define ENCODER_RESOLUTION 4

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE

// One shot toggle tap count
#define ONESHOT_TAP_TOGGLE 3

// Caps word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define TAPPING_TERM 200
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define SPECULATIVE_HOLD

#define EXTRA_SHORT_COMBOS
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 40
#define COMBO_STRICT_TIMER
