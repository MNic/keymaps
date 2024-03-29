
 /* Copyright 2021 projectcain
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
enum layers{
  BASE,
  NUM,
  SYM,
  LIGHT,
  META
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_4space(

    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENTER,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RCTL,
         KC_LGUI,      MO(2), KC_LSFT,  KC_SPACE,       MO(1),  KC_RALT
  ),

  [NUM] = LAYOUT_split_4space(

    KC_1,    KC_2,    KC_3,      KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    S(KC_GRV),    KC_GRV,    KC_BSLS,    S(KC_BSLS),    KC_WFWD,    KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT,    KC_PPLS,
    KC_SLSH,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_0,       KC_1,    KC_2,    KC_3,    KC_PDOT,
         KC_TRNS,            MO(3),  KC_TRNS,      KC_TRNS,   KC_TRNS, KC_TRNS
  ),

  [SYM] = LAYOUT_split_4space(
    S(KC_1),     S(KC_2),     S(KC_3),   S(KC_4),     S(KC_5),    S(KC_6),      S(KC_7),  S(KC_8),    S(KC_9),    S(KC_0), KC_DEL,
    S(KC_SLSH),  S(KC_BSLS),  KC_QUOTE,  S(KC_QUOTE), KC_TRNS,    KC_MINUS,  KC_EQL,  KC_LBRC,    KC_RBRC,    KC_TRNS,  
    KC_TRNS,     KC_TRNS,     KC_SCLN,   S(KC_SCLN),  KC_TRNS,    S(KC_MINUS),     KC_PLUS,  S(KC_LBRC),   S(KC_RBRC),    KC_TRNS,
             KC_TRNS,         KC_TRNS,   KC_TRNS,     KC_TRNS,    MO(3),      KC_TRNS
  ), 

  [LIGHT] = LAYOUT_split_4space(
    RGB_TOG,   RGB_HUI,    RGB_SAI,   RGB_VAI,    RGB_MOD,    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, QK_BOOT,
    KC_TRNS,    RGB_HUD,   RGB_SAD,   RGB_VAD,    RGB_RMOD,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
            KC_TRNS,           KC_TRNS,   KC_TRNS,      KC_TRNS,        KC_TRNS,    KC_TRNS
  ),

};

enum combos {
  KL_SLSH,
  JK_MINUS,
  QW_ESC,
  LQUOTE_ENTER,
  AS_TAB,
  ZX_CUT,
  XC_COPY,
  CV_PASTE,
};

const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM lquote_combo[] = {KC_L, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
  [KL_SLSH] = COMBO(kl_combo, S(KC_SLSH)),
  [JK_MINUS] = COMBO(jk_combo, KC_MINUS),
  [QW_ESC] = COMBO(qw_combo, KC_ESC),
  [LQUOTE_ENTER] = COMBO(lquote_combo, KC_ENTER),
  [AS_TAB] = COMBO(as_combo, LCTL_T(KC_TAB)),
  [ZX_CUT] = COMBO(zx_combo, G(KC_X)),
  [XC_COPY] = COMBO(xc_combo, G(KC_C)),
  [CV_PASTE] = COMBO(cv_combo, G(KC_V)),
}
;