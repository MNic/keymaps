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
[_BASE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOTE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, LA_MEDIA, XXXXXXX,          XXXXXXX,   LA_NAV,  KC_LSFT,     KC_SPC,   LA_SYM,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------
  ),

[_CDH] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOTE,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I, KC_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   LA_MEDIA, XXXXXXX,         XXXXXXX,  LA_NAV,  KC_LSFT,     KC_SPC,   LA_SYM,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------
  ),

[_SYM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_ESC, KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,                     KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRAVE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MINUS, KC_ASTR, KC_EQUAL, KC_UNDS, KC_DOLLAR,                 KC_HASH, OS_CMD,   OS_ALT,OS_CTRL, OS_SHFT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PLUS, KC_PIPE, KC_AT, KC_BSLS, KC_PERCENT,                      _______, KC_AMPR, KC_SCLN, KC_COLN, KC_EXLM, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TRNS, KC_TRNS,         KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS
                                      //`--------------------------'  `--------------------------
  ),

[_NAV] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_TAB,  _______, _______,  _______, KC_VOLU,                      _______,  KC_HOME,  KC_PGUP,  _______,  KC_DEL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, OS_SHFT, OS_CTRL,   OS_ALT,   OS_CMD,   KC_VOLD,                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_BSPC,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SLSH, XXXXXXX, KC_MPRV,   KC_MNXT,   KC_MPLY,                      KC_CAPS,  KC_END,   KC_PGDN,  KC_PGUP,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_TRNS, KC_TRNS,       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,          KC_TRNS,   KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------
  ),
[_NUM] = LAYOUT(
  //,-----------------------------------------------------.                    ,------------------------------------------------------------------------------.
      XXXXXXX ,   KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                      KC_6,     KC_7,    KC_8,     KC_9,      KC_0,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |-----------+--------------+--------------+-------------+-----------+-----------|
      XXXXXXX,   OS_SHFT,  OS_CTRL,   OS_ALT,   OS_CMD,   KC_F11,                KC_F10,   OS_CMD,  OS_ALT,  OS_CTRL,  OS_SHFT,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |-----------+--------------+--------------+-------------+-----------+-----------|
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,                        KC_F6,    KC_F7,   KC_F8,    KC_F9,     KC_F12,    XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+-----------+--------------+--------------+-------------+-----------+-----------|
      XXXXXXX, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,        KC_TRNS,                     XXXXXXX,     XXXXXXX,     XXXXXXX
                                      //`--------------------------'  `--------------------------
  ),
[_MEDIA] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPLY, KC_MUTE, KC_MSTP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_TRNS, LA_RESET,          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,          XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------
  ),
[_RESET] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, TG(_CDH), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_TRNS, KC_TRNS,          KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,          XXXXXXX,   XXXXXXX,  XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}



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

#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_NUMBAK,
    COMBO_TAB_QWERTY,
    COMBO_ENT_QWERTY,
    COMBO_ESC,
    COMBO_TAB_CDH,
    COMBO_ENT_CDH,
    COMBO_BSPC_QWERTY,
    COMBO_BSPC_CDH
};

const uint16_t PROGMEM combo_esc[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
// Qwerty
const uint16_t PROGMEM combo_tab_qwerty[]    = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo_ent_qwerty[] = {KC_L, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo_bspc_qwerty[] = {KC_O, KC_P, COMBO_END};

// CDH
const uint16_t PROGMEM combo_tab_cdh[]    = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM combo_ent_cdh[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bspc_cdh[] = {KC_Y, KC_QUOTE, COMBO_END};


combo_t key_combos[] = {
    [COMBO_TAB_QWERTY] = COMBO(combo_tab_qwerty, KC_TAB),
    [COMBO_ENT_QWERTY] = COMBO(combo_ent_qwerty, KC_ENT),
    [COMBO_BSPC_QWERTY] = COMBO(combo_bspc_qwerty, KC_BSPC),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
    [COMBO_TAB_CDH] = COMBO(combo_tab_cdh, KC_TAB),
    [COMBO_ENT_CDH] = COMBO(combo_ent_cdh, KC_ENT),
    [COMBO_BSPC_CDH] = COMBO(combo_bspc_cdh, KC_BSPC),
    [COMBO_NUMBAK] = COMBO(combo_numbak, KC_BSPC)
};
#endif
