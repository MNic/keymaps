#include QMK_KEYBOARD_H

#ifdef BACKLIGHT_ENABLE
#include "flicker.h"
#endif

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _CMDH,
  _RAISE,
  _LOWER,
  _ADJUST,
  _FN,
  _MEDIA,
  _RST
};

// keycodes custom to this keymap:
enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BL_FLICKER
};

// flicker state:
#ifdef BACKLIGHT_ENABLE
bool flicker_enable = true;
bool flicker_isdown = false;
const uint8_t flicker_min_levels = 2;
const uint8_t flicker_max_levels = 7;
uint8_t flicker_restore_level = 0;
#endif

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define FN MO(_FN)
#define MEDIA MO(_MEDIA)
#define CMDH TG(_CMDH)
#define RST MO(_RST)

// mod tap definitions:
#define CTRL_ESC MT(MOD_LCTL, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
// #define HYPR_SPC MT(MOD_HYPR, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_GESC,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_RSFT , \
  FN,  MEDIA,  KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC,  RAISE, KC_RGUI , KC_LEFT, KC_DOWN,    KC_RIGHT    \
),

/* Qwerty */
[_CMDH] = LAYOUT_ortho_4x12(
  KC_GESC,       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN,  KC_BSPC, \
  CTL_T(KC_TAB), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,     KC_I,    KC_O,     KC_ENT, \
  KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_UP,    KC_RSFT, \
  FN,  MEDIA,  KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC,  RAISE, KC_RGUI , KC_LEFT, KC_DOWN,    KC_RIGHT    \
),

/* RAISE */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,      KC_0,    KC_BSPC, \
  _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT,  XXXXXXX, XXXXXXX, \
  _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP, KC_PGDN,    KC_HOME,    KC_END,    XXXXXXX, XXXXXXX, \
  _______, _______, _______, KC_LGUI, ADJUST,   KC_SPC,  KC_SPC,  _______,    _______,    _______,   _______, _______  \
),

/* LOWER */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL, \
  _______,        KC_QUES,    KC_PIPE,    KC_QUOT,    KC_DQT,     XXXXXXX,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_GRV, \
  _______,        KC_SLSH,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,    KC_TILD, \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    ADJUST,      _______,    _______,    _______,    _______  \
),


/* ADJUST (LOWER + RAISE) */
[_ADJUST] = LAYOUT_ortho_4x12(
  CMDH,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      LCAG(KC_M),     LCAG(KC_1),     LCAG(KC_UP),    LCAG(KC_2),     LCAG(KC_F),    XXXXXXX,   \
  _______,  KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     LCAG(KC_N),        LCAG(KC_LEFT),  LCAG(KC_C),     LCAG(KC_RGHT),  LCAG(KC_P),    XXXXXXX,  \
  RST,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LCAG(KC_P),        LCAG(KC_3),     LCAG(KC_DOWN),  LCAG(KC_4),     XXXXXXX,       XXXXXXX,  \
  _______,  _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,  _______ \
),
/* FN */
[_FN] = LAYOUT_ortho_4x12(
  RGB_TOG,        RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    _______,    _______,    _______,    KC_VOLU,    _______,    _______,    _______, \
  _______,        RGB_RMOD,   RGB_HUD,    RGB_SAD,    RGB_VAD,    _______,    _______,    KC_MPRV,    KC_VOLD,    KC_MNXT,    _______,    _______, \
  BL_TOGG,        BL_STEP,    BL_BRTG,    BL_ON,      BL_INC,     _______,    _______,    KC_MPLY,    KC_MUTE,    KC_MSTP,    _______,    _______, \
  _______,        _______,    _______,    BL_OFF,     BL_DEC,     _______,    _______,    _______,    _______,    _______,    _______, _______ \
),

/* MEDIA */
[_MEDIA] = LAYOUT_ortho_4x12(
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLU,    _______,    _______,    _______,                  \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_MPRV,    KC_VOLD,    KC_MNXT,    _______,    _______,                 \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY,     KC_MUTE,    KC_MSTP,    _______,    _______,                 \
  RST,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______ \
),

[_RST] = LAYOUT_ortho_4x12(
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RESET,                  \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                 \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,    _______,    _______,    _______,                 \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______ \
), 


}; // END KEYMAPS
