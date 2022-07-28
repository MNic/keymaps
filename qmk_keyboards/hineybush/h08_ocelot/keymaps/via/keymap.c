#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_MPLY, KC_MNXT, KC_VOLU, KC_MUTE, 
        KC_MSTP, KC_MPRV, LT(2, KC_VOLD), MO(1) ),

    [1] =  LAYOUT(
        RGB_MOD,  RGB_HUI, RGB_SAI, RGB_SAD, 
        RGB_RMOD, RGB_HUD, MO(3), _______),

    [2] = LAYOUT(
        LGUI(KC_Z), LSFT(LGUI(KC_Z)), RGB_VAI, RGB_VAD, 
        LGUI(KC_C), LGUI(KC_V), _______, RGB_TOG),

    [3] = LAYOUT(
        RESET,  KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, _______, _______) };

