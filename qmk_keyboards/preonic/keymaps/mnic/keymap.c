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
// enum planck_keycodes {
//   QWERTY = SAFE_RANGE,
//   BL_FLICKER
// };

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
#define FN MO(_FN)
#define ADJUST MO(_ADJUST)
#define MEDIA MO(_MEDIA)

// mod tap definitions:
#define CTRL_ESC MT(MOD_LCTL, KC_ESC)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
// #define HYPR_SPC MT(MOD_HYPR, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl/ESC |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | '    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift/Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN  | MEDIA  | ALT  | GUI  |LOWER |SPACE|SPACE |RAISE | LEFT | DOWN |  UP  |RIGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTRL_ESC, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT , \
  FN,  MEDIA,  KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC,  RAISE,   KC_ENT, KC_RALT, MEDIA, FN    \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl/ESC |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | '    |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift/Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FN  | MEDIA  | ALT  | GUI  |LOWER |SPACE|SPACE |RAISE | LEFT | DOWN |  UP  |RIGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_CMDH] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  CTRL_ESC, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,     KC_K,     KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  \
  FN,      MEDIA,   KC_LALT, KC_LGUI, LOWER,   KC_SPC, KC_SPC,   RAISE,   KC_ENT,  KC_RALT, MEDIA,   FN    \
),

/* RAISE
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | HOME | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | NEXT | VOL- | VOL+ | PLAY |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,      KC_0,    KC_BSPC, \
  _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT,  XXXXXXX, XXXXXXX, \
  _______, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_PGUP, KC_PGDN,    KC_HOME,    KC_END,    XXXXXXX, XXXXXXX, \
  _______, _______, _______, KC_LGUI, ADJUST,   KC_SPC,  KC_SPC,  _______,    _______,    _______,   _______, _______  \
),


/* LOWER
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BKSP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |PG UP |PG DN |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | NEXT | VOL- | VOL+ | PLAY |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL, \
  KC_TILD,        KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL, \
  _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS,    _______, \
  _______,        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_PIPE,    _______, \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    ADJUST,      _______,    _______,    _______,    _______  \
),


/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * |      | RESET|      |      |      |      |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |AUD ON|AUDOFF|AGNORM|AGSWAP|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |VOICE-|VOICE+|MUS ON|MUSOFF|MIDION|MIDIOF|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |CLICKY|CLKDN |CLKUP |CLKRST|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,  _______, \
  _______,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    LCAG(KC_M),     LCAG(KC_1),     LCAG(KC_UP),    LCAG(KC_2),     LCAG(KC_N),    XXXXXXX,                  \
  _______,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        LCAG(KC_LEFT),  LCAG(KC_C),     LCAG(KC_RGHT),  LCAG(KC_P),    XXXXXXX,                 \
  _______,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        LCAG(KC_3),     LCAG(KC_DOWN),  LCAG(KC_4),     XXXXXXX,       XXXXXXX,                 \
  _______,  _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,  _______ \
),
/* FN         
 * ,-----------------------------------------------------------------------------------.
 * |      | RESET|      |      |      |      |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |AUD ON|AUDOFF|AGNORM|AGSWAP|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |VOICE-|VOICE+|MUS ON|MUSOFF|MIDION|MIDIOF|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |CLICKY|CLKDN |CLKUP |CLKRST|
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,  _______, \
  RGB_TOG,        RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                  \
  _______,        RGB_RMOD,   RGB_HUD,    RGB_SAD,    RGB_VAD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,                 \
  BL_TOGG,        BL_STEP,    BL_BRTG,    BL_ON,      BL_INC,     _______,    _______,    _______,    _______,    _______,    _______,    _______,                 \
  _______,        _______,    _______,    BL_OFF,     BL_DEC,     _______,    _______,    _______,    _______,    _______,    _______, _______ \
),
/* MEDIA
 * ,-----------------------------------------------------------------------------------.
 * |      | RESET|      |      |      |      |      |      |      |      |      |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |AUD ON|AUDOFF|AGNORM|AGSWAP|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |VOICE-|VOICE+|MUS ON|MUSOFF|MIDION|MIDIOF|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |CLICKY|CLKDN |CLKUP |CLKRST|
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_preonic_grid(
  _______,  _______,    _______,    _______,    _______,    _______,    _______,        _______,        _______,        _______,        _______,  _______, \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLU,    _______,    _______,    _______,                  \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_MPRV,    KC_VOLD,    KC_MNXT,    _______,    _______,                 \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY,     KC_MUTE,    KC_MSTP,    _______,    _______,                 \
  _RST,        _______,    TG(_CMDH),    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______ \
),

[_RST] = LAYOUT_preonic_grid(
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  RESET, \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,                  \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,                 \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,                 \
  _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______ \
), 


}; // END KEYMAPS

// IF BACKLIGHTING IS ENABLED, CONFIGURE IT ON BOOT
// #IFDEF BACKLIGHT_ENABLE
// VOID MATRIX_INIT_USER(VOID) {
  // SET TO MAX
  // BACKLIGHT_LEVEL(BACKLIGHT_LEVELS);
  // FLICKER_RESTORE_LEVEL = GET_BACKLIGHT_LEVEL();

  // IF BREATHING HAPPENS TO BE COMPILED IN, TURN IT OFF
// #IFDEF BACKLIGHT_BREATHING
//   BREATHING_DISABLE();
// #ENDIF
// }
// #ENDIF

// VOID PERSISTANT_DEFAULT_LAYER_SET(UINT16_T DEFAULT_LAYER) {
//   EECONFIG_UPDATE_DEFAULT_LAYER(DEFAULT_LAYER);
//   DEFAULT_LAYER_SET(DEFAULT_LAYER);
// }

// BOOL PROCESS_RECORD_USER(UINT16_T KEYCODE, KEYRECORD_T *RECORD) {

  // HANDLE THE _ADJUST LAYER AND CUSTOM KEYCODES:
//   SWITCH (KEYCODE) {
//     CASE LOWER:
//       IF (RECORD->EVENT.PRESSED) {
//         LAYER_ON(_LOWER);
//         UPDATE_TRI_LAYER(_LOWER, _RAISE, _ADJUST);
//       } ELSE {
//         LAYER_OFF(_LOWER);
//         UPDATE_TRI_LAYER(_LOWER, _RAISE, _ADJUST);
//       }
//       RETURN FALSE;
//       BREAK;
//     CASE RAISE:
//       IF (RECORD->EVENT.PRESSED) {
//         LAYER_ON(_RAISE);
//         UPDATE_TRI_LAYER(_LOWER, _RAISE, _ADJUST);
//       } ELSE {
//         LAYER_OFF(_RAISE);
//         UPDATE_TRI_LAYER(_LOWER, _RAISE, _ADJUST);
//       }
//       RETURN FALSE;
//       BREAK;
// #IFDEF BACKLIGHT_ENABLE
//     CASE BL_FLICKER:
//       IF (RECORD->EVENT.PRESSED) {
//         FLICKER_TOGGLE();
//       }
//       RETURN FALSE;
//       BREAK;
// #ENDIF
//   } // END SWITCH CASE OVER CUSTOM KEYCODES

// #IFDEF BACKLIGHT_ENABLE
//   IF (FLICKER_ENABLE) {
//     IF (RECORD->EVENT.PRESSED) {
//       FLICKER_KEYDOWN();
//     } ELSE {
//       FLICKER_KEYUP();
//     }
//   }
// #ENDIF

//   RETURN TRUE;
// }

// VOID ENCODER_UPDATE(BOOL CLOCKWISE) {
//   IF (CLOCKWISE) {
//     REGISTER_CODE(KC_VOLU);
//     UNREGISTER_CODE(KC_VOLU);
//   } ELSE {
//     REGISTER_CODE(KC_VOLD);
//     UNREGISTER_CODE(KC_VOLD);
//   }
// }

// // FLICKER IMPLEMENTATION:
// #IFDEF BACKLIGHT_ENABLE
// VOID FLICKER_TOGGLE(VOID) {
//   FLICKER_ENABLE = !FLICKER_ENABLE;
// }

// VOID FLICKER_KEYDOWN(VOID) {
//   // GUARD CONDITION: ONLY SET THE LEVEL TO RESTORE IF THE FLICKER IS NOT ALREADY DOWN
//   IF (!FLICKER_ISDOWN) {
//     FLICKER_RESTORE_LEVEL = GET_BACKLIGHT_LEVEL();
//     FLICKER_ISDOWN = TRUE;
//   }

//   // CALCULATE A RANDOM FLICKER LEVEL BETWEEN MIN AND MAX
//   UINT8_T FLICKER_LEVEL = (RAND() % (FLICKER_MAX_LEVELS - FLICKER_MIN_LEVELS)) + FLICKER_MIN_LEVELS;
//   UINT8_T LEVEL_TO_SET = FLICKER_LEVEL <= FLICKER_RESTORE_LEVEL ? FLICKER_RESTORE_LEVEL - FLICKER_LEVEL : 0;
//   BACKLIGHT_LEVEL(LEVEL_TO_SET);
// }

// VOID FLICKER_KEYUP(VOID) {
//   BACKLIGHT_LEVEL(FLICKER_RESTORE_LEVEL);
//   FLICKER_ISDOWN = FALSE;
// }
// #ENDIF
