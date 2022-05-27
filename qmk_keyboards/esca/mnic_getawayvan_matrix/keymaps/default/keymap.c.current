/* Copyright 2021 Enrique Cabrera
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

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Qwerty */
    KC_GESC,       KC_Q,    KC_W,    KC_E,  KC_R, KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,  KC_F, KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,  KC_V, KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
    MO(5),       KC_LALT, KC_LGUI, LT(3, KC_SPC),        LT(2, KC_SPC), KC_RGUI,  KC_LEFT, KC_DOWN,    KC_RIGHT
  ),
  [1] = LAYOUT( /* Colemak-DH */
    KC_GESC,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_BSPC,
    CTL_T(KC_TAB), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  KC_M,    KC_N,    KC_E,    KC_I, KC_O, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, KC_K,    KC_H, KC_COMM,  KC_DOT, KC_UP,  KC_RSFT,
    MO(5),       KC_LALT, KC_LGUI, LT(3, KC_SPC),        LT(2, KC_SPC), KC_RGUI,  KC_LEFT, KC_DOWN,    KC_RIGHT
  ),
  [2] = LAYOUT( /* NUM */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TRNS, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
    KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_PGDN, KC_HOME, KC_END, XXXXXXX, XXXXXXX,
    KC_TRNS,       KC_TRNS, KC_TRNS,        LT(4, KC_SPC), KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS
  ),
  [3] = LAYOUT( /* SYM */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_TRNS, KC_QUES, KC_PIPE, KC_QUOT, KC_DQT, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    KC_TRNS, KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TILD,
    KC_TRNS,   KC_TRNS, KC_TRNS,                  KC_TRNS, LT(4, KC_SPC),   KC_TRNS,  KC_TRNS, KC_TRNS,   KC_TRNS
  ),
  [4] = LAYOUT( /* WINDOWCTRL */
    TG(1),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   LCAG(KC_M), LCAG(KC_1),    LCAG(KC_UP),   LCAG(KC_2),    LCAG(KC_F),  XXXXXXX,
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  LCAG(KC_N), LCAG(KC_LEFT), LCAG(KC_C),    LCAG(KC_RGHT), XXXXXXX,     XXXXXXX,
    MO(6), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCAG(KC_P), LCAG(KC_3),    LCAG(KC_DOWN), LCAG(KC_4),    XXXXXXX,     XXXXXXX,
    KC_TRNS,   KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS
  ),
  [5] = LAYOUT( /* RGB-VOL */
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,   XXXXXXX,   XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, BL_INC,     XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,
    BL_TOGG, BL_STEP, BL_BRTG,  BL_ON,  BL_OFF,   BL_DEC,     XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, XXXXXXX,
    KC_TRNS,   KC_TRNS, KC_TRNS,                  KC_TRNS,    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [6] = LAYOUT( /* RESET */
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  RESET,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TRNS,   KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS
  )
};
