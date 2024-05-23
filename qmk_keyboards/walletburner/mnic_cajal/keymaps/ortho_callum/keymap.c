/* Copyright 2020 foostan
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
#include "oneshot.h"

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_MEDIA MO(_MEDIA)
#define LA_RESET MO(_RESET)

enum layers {
    _BASE,
    _CDH,
    _SYM,
    _NAV,
    _NUM,
    _MEDIA,
    _RESET,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC, KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCTL_T(KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOTE, KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,         KC_UP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, LA_MEDIA, XXXXXXX,  LA_NAV,       KC_LSFT  , KC_SPC ,     KC_SPC,LA_SYM,   XXXXXXX, XXXXXXX,           XXXXXXX,               KC_LEFT, KC_DOWN, KC_RGHT
                                      //`--------------------------'  `--------------------------
  ),

[_CDH] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOTE,  KC_BSPC, KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL_T(KC_TAB),    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I, KC_O, KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,       KC_UP,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, LA_MEDIA, XXXXXXX,  LA_NAV,       KC_LSFT  , KC_SPC ,     KC_SPC,LA_SYM,   XXXXXXX, XXXXXXX,           XXXXXXX,               KC_LEFT, KC_DOWN, KC_RGHT
                                      //`--------------------------'  `--------------------------
  ),

[_SYM] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_ESC, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,                     KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRAVE, _______,_______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MINUS, KC_ASTR, KC_EQUAL, KC_UNDS, KC_DOLLAR,                 KC_HASH, OS_CMD,   OS_ALT,OS_CTRL, OS_SHFT, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PLUS, KC_PIPE, KC_AT, KC_BSLS, KC_PERCENT,                      _______, KC_AMPR, KC_SCLN, KC_COLN, KC_EXLM, _______,       _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,KC_TRNS, KC_TRNS,       KC_TRNS,   KC_TRNS,               _______, _______, _______
                                      //`--------------------------'  `--------------------------
  ),

[_NAV] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX,  _______, _______,  _______, KC_VOLU,                      XXXXXXX,  KC_HOME,  KC_PGUP,  XXXXXXX,  XXXXXXX, KC_DEL,_______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, OS_SHFT, OS_CTRL,   OS_ALT,   OS_CMD,   KC_VOLD,                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_BSPC,  _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SLSH, XXXXXXX, KC_MPRV,   KC_MNXT,   KC_MPLY,                      KC_CAPS,  KC_END,   KC_PGDN,  KC_PGUP,  KC_ENT, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,KC_TRNS, KC_TRNS,           KC_TRNS,   KC_TRNS, _______, _______, _______
                                      //`--------------------------'  `--------------------------
  ),
[_NUM] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,------------------------------------------------------------------------------.
      _______ ,   KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                      KC_6,     KC_7,    KC_8,     KC_9,      KC_0,    _______,_______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |-----------+--------------+--------------+-------------+-----------+-----------|
      _______,   OS_SHFT,  OS_CTRL,   OS_ALT,   OS_CMD,   KC_F11,                KC_F10,   OS_CMD,  OS_ALT,  OS_CTRL,  OS_SHFT,    _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |-----------+--------------+--------------+-------------+-----------+-----------|
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,                        KC_F6,    KC_F7,   KC_F8,    KC_F9,     KC_F12,    _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+-----------+--------------+--------------+-------------+-----------+-----------|
      XXXXXXX, KC_TRNS, KC_TRNS,               KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                          XXXXXXX,     XXXXXXX,     _______, _______, _______
                                      //`--------------------------'  `--------------------------
  ),
[_MEDIA] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, _______,_______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,                      XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_TRNS, LA_RESET,          KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,           XXXXXXX, XXXXXXX, _______, _______, _______
                                      //`--------------------------'  `--------------------------
  ),
[_RESET] = LAYOUT_ortho(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, TG(_CDH), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_TRNS, KC_TRNS,            KC_TRNS,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,           XXXXXXX,   XXXXXXX,  _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_CDH] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_SYM] =  { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD)},
    [_NAV] =  { ENCODER_CCW_CW(RGB_HUI, RGB_HUD)},
    [_NUM] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_MEDIA] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [_RESET] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
#endif

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

// This swaps to _NUM when _SYM and _NAV are held
// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYM, _NAV, _NUM);
// }

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
    // switch (get_highest_layer(state)) {
    state = update_tri_layer_state(state, _SYM, _NAV, _NUM); 
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
    // return update_tri_layer_state(state, _SYM, _NAV, _NUM);
    return state;
}

// Comment out to disable capslock LED functionality
// bool led_update_user(led_t led_state) {
//     writePin(B5, led_state.caps_lock);
//     return false;
// }

// Update encoder rotation functionality for each layer
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) {
//         switch(biton32(layer_state)){
//             case 6:
//             if (clockwise) {
//                     rgblight_increase_sat();
//                 } else {
//                     rgblight_decrease_sat();
//                 }
//                 break;
//             case 5:
//                 if (clockwise) {
//                     rgblight_increase_val();
//                 } else {
//                     rgblight_decrease_val();
//                 }
//                 break;
//             // skip 3 for now, access is more awkward
//             case 3:
//                 if (clockwise) {
//                     rgblight_increase_hue(); 
//                 } else {
//                     rgblight_decrease_hue();
//                 }
//                 break;
//             case 2:
//                 if (clockwise) {
//                     rgblight_step();
//                 } else {
//                     rgblight_step_reverse();
//                 }
//                 break;
//             default:
//                 if (clockwise) {
//                     tap_code(KC_VOLU);
//                 } else {
//                     tap_code(KC_VOLD);
//                 }
//                 break;
//     }}
//     return true;
// };


// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//     [_BASE] =  {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_CDH] =  {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_SYM] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
//     [_NAV] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
//     [_NUM] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
//     [_RGB] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) }
// };
// #endif

// #ifdef COMBO_ENABLE
// enum combo_events {
//     COMBO_NUMBAK,
//     COMBO_TAB_QWERTY,
//     COMBO_ENT_QWERTY,
//     COMBO_ESC,
//     COMBO_TAB_CDH,
//     COMBO_ENT_CDH,
//     COMBO_BSPC_QWERTY,
//     COMBO_BSPC_CDH
// };

// const uint16_t PROGMEM combo_esc[]    = {KC_Q, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
// // Qwerty
// const uint16_t PROGMEM combo_tab_qwerty[]    = {KC_A, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_ent_qwerty[] = {KC_L, KC_QUOTE, COMBO_END};
// const uint16_t PROGMEM combo_bspc_qwerty[] = {KC_O, KC_P, COMBO_END};

// // CDH
// const uint16_t PROGMEM combo_tab_cdh[]    = {KC_A, KC_R, COMBO_END};
// const uint16_t PROGMEM combo_ent_cdh[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM combo_bspc_cdh[] = {KC_Y, KC_QUOTE, COMBO_END};


// combo_t key_combos[] = {
//     [COMBO_TAB_QWERTY] = COMBO(combo_tab_qwerty, KC_TAB),
//     [COMBO_ENT_QWERTY] = COMBO(combo_ent_qwerty, KC_ENT),
//     [COMBO_BSPC_QWERTY] = COMBO(combo_bspc_qwerty, KC_BSPC),
//     [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
//     [COMBO_TAB_CDH] = COMBO(combo_tab_cdh, KC_TAB),
//     [COMBO_ENT_CDH] = COMBO(combo_ent_cdh, KC_ENT),
//     [COMBO_BSPC_CDH] = COMBO(combo_bspc_cdh, KC_BSPC),
//     [COMBO_NUMBAK] = COMBO(combo_numbak, KC_BSPC)
// };
// #endif
