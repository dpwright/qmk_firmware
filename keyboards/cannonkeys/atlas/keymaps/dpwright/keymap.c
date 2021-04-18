/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#include "keymap_jp.h"
#include "sendstring_jis.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _FUNCTION
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | - =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift | <-- Tap for _
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Brite| Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12( \
  KC_ESC,        JP_1,    JP_2,    JP_3,    JP_4,                    JP_5,    JP_6,    JP_7,                    JP_8,    JP_9,    JP_0,    JP_MINS,         \
  KC_TAB,        JP_Q,    JP_W,    JP_E,    JP_R,                    JP_T,    JP_Y,    JP_U,                    JP_I,    JP_O,    JP_P,    KC_BSPC,         \
  KC_LCTL,       JP_A,    JP_S,    JP_D,    JP_F,                    JP_G,    JP_H,    JP_J,                    JP_K,    JP_L,    JP_SCLN, KC_ENT,          \
  KC_LSFT,       JP_Z,    JP_X,    JP_C,    JP_V,                    JP_B,    JP_N,    JP_M,                    JP_COMM, JP_DOT,  JP_SLSH, RSFT_T(JP_BSLS), \
  MO(_FUNCTION), RGB_MOD, KC_LALT, KC_LGUI, LT(_FUNCTION, JP_MEISU), KC_SPC,  KC_SPC,  LT(_FUNCTION, JP_MKANA), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT          \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |RESET |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  ^ ~ | ¥ |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | @ `  | [ {  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Vol- | Vol+ | Mute |      |      |      |      |      |      | : *  | ] }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  _   | ¥ |  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | PgDn | PgUp |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_5x12( \
  RESET,   KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   JP_CIRC, JP_YEN,  \
  _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, JP_AT,   JP_LBRC, \
  KC_DEL,  KC__VOLD, KC__VOLU, KC__MUTE, _______, _______, _______, _______, _______, _______, JP_COLN, JP_RBRC, \
  _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, JP_BSLS, JP_YEN,  \
  _______, _______,  _______,  _______,  _______, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______  \
)
}
;
