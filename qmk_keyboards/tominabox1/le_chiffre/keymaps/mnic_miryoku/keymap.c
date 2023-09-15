/* Copyright 2020 tominabox1
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
#include "./rgb.c"

enum layers {
    _BASE,
    _CDH,
    _SYM,
    _NAV,
    _NUM,
    _MEDIA,
    _FN
};

#define KC_SYM_SPC LT(_SYM, KC_SPC)
#define KC_NAV_ENT LT(_NAV, KC_ENT)
#define KC_NUM_BSPC LT(_NUM, KC_BSPC)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GQUOTE RGUI_T(KC_QUOTE)

#define KC_AR LALT_T(KC_R)
#define KC_CS LCTL_T(KC_S)
#define KC_ST LSFT_T(KC_T)
#define KC_SN RSFT_T(KC_N)
#define KC_CE RCTL_T(KC_E)
#define KC_AI RALT_T(KC_I)
#define KC_GO RGUI_T(KC_O)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,  KC_MPLY,  KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
   KC_GA,  KC_AS,  KC_CD,  KC_SF,   KC_G,            KC_H,  KC_SJ,   KC_CK,  KC_AL, KC_GQUOTE,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,            KC_N,   KC_M, KC_COMM, KC_DOT,  KC_SLSH,
                         MO(_MEDIA), KC_NAV_ENT,            KC_SYM_SPC, KC_NUM_BSPC
  ),
  [_CDH] = LAYOUT(
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,  KC_MPLY,  KC_J,   KC_L,    KC_U,   KC_Y,  KC_GQUOTE,
    KC_GA,   KC_AR,   KC_CS,   KC_ST,   KC_G,            KC_M,   KC_SN,    KC_CE,   KC_AI,  KC_GO,
    KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,            KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                         MO(_MEDIA), KC_NAV_ENT,            KC_SYM_SPC, KC_NUM_BSPC
  ),
  [_NAV] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,  KC_TRNS,  LGUI(LSFT(KC_Z)),  LGUI(KC_V),  LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z),
    KC_GA,   KC_AR,   KC_CS,   KC_ST,   KC_G,                       KC_LEFT,  KC_DOWN,   KC_UP, KC_RIGHT,  KC_CAPS,
    _______,   _______,   _______,   _______,   _______,            KC_INS,   KC_HOME,   KC_PGDN, KC_PGUP, KC_END,
                         KC_LCTL, KC_TRNS,            KC_SYM_SPC, KC_BSPC
  ),
    [_MEDIA] = LAYOUT(
    _______,   _______,   _______,   _______,   _______,  KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,  _______,            _______,  KC_MPRV,   KC_VOLU, KC_VOLD,  KC_MNXT,
    _______,   _______,   _______,   _______,   _______,            _______,   _______,   _______, _______, _______,
                         KC_TRNS, MO(_FN),            KC_MPLY, KC_MSTP
  ),
    [_NUM] = LAYOUT(
    KC_LBRC,   KC_7,   KC_8,   KC_9,   KC_RBRC,  KC_TRNS,  _______,  _______,  _______, _______, _______,
    KC_SCLN,   KC_4,   KC_5,   KC_6,   KC_EQUAL,           _______,  KC_RSFT,   KC_RCTL, KC_RALT,  KC_RGUI,
    KC_GRV,    KC_1,   KC_2,   KC_3,   KC_BSLS,            _______,   _______,   _______, _______, _______,
                       KC_0,   KC_MINUS,            MO(_FN), KC_TRNS
  ),
  [_SYM] = LAYOUT(
    KC_LCBR,   KC_AMPR,   KC_ASTR,  KC_LPRN,  KC_RCBR,   KC_TRNS,   _______,  _______,  _______,  _______,  _______,
    KC_COLON,  KC_DOLLAR, KC_PERC,  KC_CIRC,  KC_PLUS,              _______,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,
    KC_TILD,   KC_EXLM,   KC_AT,    KC_HASH,  KC_PIPE,              _______,  _______,  _______,  _______,  _______,
                                    KC_RPRN,  KC_UNDS,              KC_TRNS,  MO(_FN)
  ),
    [_FN] = LAYOUT(
    KC_F12,   KC_F7,   KC_F8,  KC_F9,    KC_PSCR,   TG(_CDH),   _______,  _______,  _______,  _______,  QK_BOOT,
    KC_F11,   KC_F4,   KC_F5,  KC_F6,    KC_SCRL,               _______,  KC_RSFT,  KC_RCTL,  KC_RALT,  KC_RGUI,
    KC_F10,   KC_F1,   KC_F2,  KC_F3,    KC_PAUS,               _______,  _______,  _______,  _______,  _______,
                               KC_TRNS,  KC_TRNS,               KC_TRNS,  KC_TRNS
  ),

//   [_NAV] = LAYOUT(
//       QK_BOOT,  _______,  AG_NORM,  AG_SWAP,  DB_TOGG, KC_TRNS,   KC_GRV,  KC_PGDN,    KC_UP,  KC_PGUP,  KC_SCLN,
//     RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_NO,           KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
//     RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_NO,           KC_MINS,    KC_INT1,  KC_COMM,   KC_DOT,  KC_BSLS,
//                                   KC_TRNS,KC_TRNS,           KC_TRNS,  KC_TRNS
//   )
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =  {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_CDH] =  {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MEDIA] =  {ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_NUM] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_SYM] = { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_NAV] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_FN] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) }
};
#endif

#ifdef COMBO_ENABLE
enum combo_events {
    COMBO_DEL,
    COMBO_NUMBAK,
//    COMBO_BSPC_QWERTY,
    COMBO_TAB_QWERTY,
    COMBO_ESC,
//    COMBO_BSPC_CDH,
    COMBO_TAB_CDH
};

const uint16_t PROGMEM combo_del[]    = {KC_CUT, KC_UNDO, COMBO_END};
const uint16_t PROGMEM combo_esc[]    = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};


// Qwerty
// const uint16_t PROGMEM combo_bspc_qwerty[]   = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_tab_qwerty[]    = {KC_GA, KC_AS, COMBO_END};

// CDH
//const uint16_t PROGMEM combo_bspc_cdh[]   = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tab_cdh[]    = {KC_GA, KC_AR, COMBO_END};


combo_t key_combos[] = {
//    [COMBO_BSPC_QWERTY] = COMBO(combo_bspc_qwerty, KC_BSPC),
    [COMBO_TAB_QWERTY] = COMBO(combo_tab_qwerty, KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
//    [COMBO_BSPC_CDH] = COMBO(combo_bspc_cdh, KC_BSPC),
    [COMBO_TAB_CDH] = COMBO(combo_tab_cdh, KC_TAB),
    [COMBO_DEL] = COMBO(combo_del, KC_DEL),
    [COMBO_NUMBAK] = COMBO(combo_numbak, KC_BSPC)
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {0, 255, 255};

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _FN:
          hsv = hsv_color_helper(HSV_RED);
          hsv.v = 30;
          break;
        case _SYM:
          hsv = hsv_color_helper(HSV_GREEN);
          hsv.v = 30;
          break;
        case _NUM:
          hsv = hsv_color_helper(HSV_PURPLE);
          hsv.v = 30;
          break;
        case _MEDIA:
          hsv = hsv_color_helper(HSV_MAGENTA);
          hsv.v = 30;
          break;
        case _NAV:
          hsv = hsv_color_helper(HSV_AZURE);
          hsv.v = 30;
          break;
        default:
          hsv = hsv_color_helper(HSV_OFF);
          break;
    }

    // if (layer_state_is(layer_state, 1)) {
    //     hsv = {130, 255, 255};
    // } else {
    //     hsv = {30, 255, 255};
    // }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_GA: 
            return TAPPING_TERM + 50;
        case KC_GQUOTE:
            return TAPPING_TERM + 50;
        case KC_SF:
            return TAPPING_TERM - 50;
        case KC_SJ:
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
}}