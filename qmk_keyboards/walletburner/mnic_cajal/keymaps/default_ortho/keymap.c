/* Copyright 2020 Worldspawn <mcmancuso@gmail.com>
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

/*#include QMK_KEYBOARD_H */
#include "cajal.h"

#define CTRL_ESC MT(MOD_LCTL, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT
#define CTRL_TAB MT(MOD_LCTL, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // qwerty
    [0] = LAYOUT_ortho(
        KC_GESC,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,    KC_BSPC,        RGB_TOG,
        CTRL_TAB, KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,    KC_ENT,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,                    KC_UP,
        MO(5),          MO(6),      KC_LALT,    KC_LGUI,    MO(3),      KC_SPC,     KC_SPC,     MO(2),     KC_RGUI,     MO(6),      MO(5),                         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Colemak Mod-DH
    [1] = LAYOUT_ortho(
        KC_TAB,         KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,       KC_BSPC,    KC_BSPC,        RGB_TOG,
        CTRL_TAB, KC_A,       KC_R,       KC_S,       KC_T,       KC_G,       KC_M,       KC_N,       KC_E,       KC_I,       KC_O,    KC_ENT,    KC_ENT,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,                    KC_UP,
        MO(5),          MO(6),      KC_LALT,    KC_LGUI,    MO(3),      KC_SPC,     KC_SPC,     MO(2),      KC_RGUI,     MO(6),      MO(5),                         KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // num
    [2] = LAYOUT_ortho(
        KC_GRV,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,    KC_BSPC,     _______,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   XXXXXXX,    XXXXXXX,    _______,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PGUP,    KC_PGDN,    KC_HOME,    KC_END,     XXXXXXX,    XXXXXXX,                 _______,
        _______,        _______,    _______,    _______,    MO(4),      _______,     _______,     _______,      _______,    _______,    _______,                  _______, _______, _______
    ),
    // symbol
    [3] = LAYOUT_ortho(
        KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,     KC_DEL,      _______,
        _______,        KC_QUES,    KC_PIPE,    KC_QUOT,    KC_DQT,    XXXXXXX,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_GRV,    _______,
        _______,        KC_SLSH,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    _______,    KC_TILD,                 _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    MO(4),    _______,    _______,    _______,                      _______, _______, _______
    ),
    // ShiftIt window manipulation shortcuts OSX
    [4] = LAYOUT_ortho(
        TG(1),          KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,    LCAG(KC_M),     LCAG(KC_1),     LCAG(KC_UP),    LCAG(KC_2),     LCAG(KC_F),    XXXXXXX,     _______,    _______,
        XXXXXXX,        KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,   LCAG(KC_N),     LCAG(KC_LEFT),  LCAG(KC_C),     LCAG(KC_RGHT),  XXXXXXX,    XXXXXXX,     XXXXXXX,
        MO(7),          XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  LCAG(KC_P),     LCAG(KC_3),     LCAG(KC_DOWN),  LCAG(KC_4),     XXXXXXX,       XXXXXXX,                 _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,                       _______, _______, _______
    ),
    // Media controls
    [5] = LAYOUT_ortho(
        RGB_TOG,        RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BRIU,     _______,
        RGB_TOG,        RGB_RMOD,   RGB_HUD,    RGB_SAD,    RGB_VAD,    BL_INC,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_BRID,
        BL_TOGG,        BL_STEP,    BL_BRTG,    BL_ON,      BL_OFF,     BL_DEC,     XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                    _______, _______, _______
    ),
    // RGB
    [6] = LAYOUT_ortho(
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_VOLU,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     _______,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,    KC_MPRV,    KC_VOLD,    KC_MNXT,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    _______,    KC_MPLY,    KC_MUTE,    KC_MSTP,    XXXXXXX,    XXXXXXX,                 _______,
        MO(7),          _______,   _______,    _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,                    _______, _______, _______
    ),
    [7] = LAYOUT_ortho(
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     RESET,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                 _______,
        _______,        _______,   _______,    _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,                    _______, _______, _______
    ),
    [8] = LAYOUT_ortho(
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                 _______,
        _______,        _______,   _______,    _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,                    _______, _______, _______
    ),

};

//code for LED Brightness fix
void matrix_init_user(void) {
  // set  LED 1 to output and low
  setPinOutput(B5);
  writePinLow(B5);
  // set LED 2 to output and low
  setPinOutput(B6);
  writePinLow(B6);
  // set LED 3 to output and low
  setPinOutput(B7);
  writePinLow(B7);
}

// Update pin LEDs based on layer. Repurpose CAPS LOCK LED.
// B5 Middle LED
// B6 Top LED
// B7 Bottom LED
layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    writePinLow(B5);
    switch (get_highest_layer(state)) {
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B5);
        break;
    case 4:
        writePinHigh(B7);
        break;
    case 5:
        writePinHigh(B5);
        writePinHigh(B6);
        break;
    case 6:
        writePinHigh(B6);
        writePinHigh(B7);
        break;
    }
    return state;
}

// Comment out to disable capslock LED functionality
// bool led_update_user(led_t led_state) {
//     writePin(B5, led_state.caps_lock);
//     return false;
// }

// Update encoder rotation functionality for each layer
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)){
            case 6:
            if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
                break;
            case 5:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            // skip 3 for now, access is more awkward
            case 3:
                if (clockwise) {
                    rgblight_increase_hue(); 
                } else {
                    rgblight_decrease_hue();
                }
                break;
            case 2:
                if (clockwise) {
                    rgblight_step();
                } else {
                    rgblight_step_reverse();
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
    }}
    return true;
};
