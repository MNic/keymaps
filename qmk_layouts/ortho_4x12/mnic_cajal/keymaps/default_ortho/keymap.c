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

#include QMK_KEYBOARD_H
#include "cajal.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho(
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,    KC_BSPC,        RGB_TOG,
        LCTL_T(KC_ESC), KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,
        KC_LSFT,        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,                 KC_UP,
        MO(5),          MO(4),      KC_LALT,    KC_LGUI,    MO(2),      KC_SPC,     KC_SPC,     MO(1),      KC_ENT,     MO(4),      MO(5),                     KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_ortho(
        KC_GRV,         KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,    KC_BSPC,     _______,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   XXXXXXX,    XXXXXXX,    _______,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_PGUP,    KC_PGDN,    KC_HOME,    KC_END,     XXXXXXX,    XXXXXXX,                 _______,
        _______,        _______,    _______,    KC_LGUI,    MO(3),      KC_SPC,     KC_SPC,     _______,      _______,    _______,    _______,                    _______, _______, _______
    ),

    [2] = LAYOUT_ortho(
        KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL,     KC_DEL,      _______,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    _______,    _______,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,    _______,                 _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    MO(3),    _______,    _______,    _______,                    _______, _______, _______
    ),

    [3] = LAYOUT_ortho(
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LCAG(KC_M),     LCAG(KC_1),     LCAG(KC_UP),    LCAG(KC_2),     LCAG(KC_N),    XXXXXXX,    _______,    RESET,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        LCAG(KC_LEFT),  LCAG(KC_C),     LCAG(KC_RGHT),  LCAG(KC_P),    XXXXXXX, XXXXXXX,
        _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        LCAG(KC_3),     LCAG(KC_DOWN),  LCAG(KC_4),     XXXXXXX,       XXXXXXX, _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,       _______, _______, _______
    ),

    [4] = LAYOUT_ortho(
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLU,    _______,    _______,    _______,    KC_BRIU,     _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_MPRV,    KC_VOLD,    KC_MNXT,    _______,    _______,    KC_BRID,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY,     KC_MUTE,    KC_MSTP,    _______,    _______,                 _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                    _______, _______, _______
    ),

    [5] = LAYOUT_ortho(
        RGB_TOG,        RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,
        _______,        RGB_RMOD,   RGB_HUD,    RGB_SAD,    RGB_VAD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        BL_TOGG,        BL_STEP,    BL_BRTG,    BL_ON,      BL_INC,     _______,    _______,    _______,    _______,    _______,    _______,    _______,                 _______,
        _______,        _______,    _______,    BL_OFF,     BL_DEC,     _______,    _______,    _______,    _______,    _______,    _______,                    _______, _______, _______
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(B7);
    writePinLow(B6);
    writePinLow(B5);
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(B5);
        break;
    case 2:
        writePinHigh(B6);
        break;
    case 3:
        writePinHigh(B7);
        break;
    case 4:
        writePinHigh(B5);
        writePinHigh(B6);
        break;
    case 5:
        writePinHigh(B5);
        writePinHigh(B6);
        writePinHigh(B7);
        break;
    }
    return state;
}

// bool led_update_user(led_t led_state) {
//     writePin(B5, led_state.caps_lock);
//     return false;
// }

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)){
            case 5:
                if (clockwise) {
                        rgblight_increase_sat();
                    } else {
                        rgblight_decrease_sat();
                    }
                    break;
            case 4:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            case 2:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue(); 
                }
                break;
            case 1:
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
