/**
 * Copyright 2023 Duke Institute for Health Innovation (DIHI), 
 * Duke University School of Medicine, Durham NC. 
 * All Rights Reserved 
 * 
 *  This product includes software developed or owned by Duke Institute for Health Innovation.  
 * Redistribution and use in source and binary forms, with or without modification, are not 
 * permitted without written permission from DIHI.  
 * 
 * https://dihi.org
 */


#ifdef RGB_MATRIX_ENABLE
// LED index
// 9    10    2    3
//         1
//         0
//   8 7   6   5 4

led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
         {9,     9,    9,   9,    9,            3, 3, 3,    3,     3 },
         {10,    10,   10,  10,   10,           2, 2, 2,    2,     2 },
         {8,     8,    8,   8,    8,            4, 4, 4,    4,     4 },
         {NO_LED, NO_LED, 7, NO_LED,      6,    6, 6, 5, NO_LED, NO_LED, }
    },
    // LED Index to Physical Positon
    {
        { 128, 40 },
        { 128, 30 },
        { 166, 0 },
        { 255, 0 },
        { 255, 48 },
        { 178, 64 },
        { 128, 64 },
        { 77, 64 },
        { 0, 48 },
        { 0, 0 },
        { 115, 0 }
    },
    //  LED Index to Flag
    //  https://docs.qmk.fm/#/feature_rgb_matrix?id=flags
    // { 8, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
    { 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 8 }
};

// Layer and Mods indicator
#define LED_CENTER_TOP 9
#define LED_CENTER_BOTTOM 10

#define LAYER_R layer_colors[layer][0] * RGB_MATRIX_DEFAULT_VAL / (RGB_MATRIX_MAXIMUM_BRIGHTNESS*0.75)
#define LAYER_G layer_colors[layer][1] * RGB_MATRIX_DEFAULT_VAL / (RGB_MATRIX_MAXIMUM_BRIGHTNESS*0.75)
#define LAYER_B layer_colors[layer][2] * RGB_MATRIX_DEFAULT_VAL / (RGB_MATRIX_MAXIMUM_BRIGHTNESS*0.75)

// #define MODS_ACTIVE(mods)i
//     ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_MATRIX_DEFAULT_VAL:0)
// #define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_MATRIX_DEFAULT_VAL/4:0)
// #define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
// #define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
// #define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE

const uint8_t PROGMEM layer_colors[][3] = {
    {RGB_OFF},
    {RGB_RED},
    {RGB_GREEN},
    {RGB_BLUE},
    {RGB_YELLOW},
    {RGB_PURPLE},
    {RGB_PINK},
    {RGB_TEAL}
};

void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
    #if defined(RGB_MATRIX_LAYER_INDICATOR)
    int layer = get_highest_layer(layer_state|default_layer_state);
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, layer_colors[layer][0], layer_colors[layer][1], layer_colors[layer][2]);
    /* uprintf("layer RGB: (%u, %u, %u)\n", LAYER_R, LAYER_G, LAYER_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, 0, 0, 0);
    #endif

    // #if defined(RGB_MATRIX_MODS_INDICATOR)
    // RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    // /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
    // #else
    // RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, RGB_OFF);
    // #endif
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     set_rgb_matrix_indicators(led_min, led_max);
//     return false;
// }

HSV hsv_color_helper(int8_t hue, uint8_t sat, uint8_t val){
   HSV hsv = {hue, sat, val}; 
   return hsv;
}

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     HSV hsv = {0, 255, 255};

//     switch(get_highest_layer(layer_state|default_layer_state)) {
//         case _FN:
//           hsv = hsv_color_helper(HSV_RED);
//           break;
//         case _SYM:
//           hsv = hsv_color_helper(HSV_GREEN);
//           break;
//         case _NUM:
//           hsv = hsv_color_helper(HSV_AZURE);
//           break;
//         case _MEDIA:
//           hsv = hsv_color_helper(HSV_AZURE);
//           break;
//         case _NAV:
//           hsv = hsv_color_helper(HSV_AZURE);
//           break;
//         default:
//           hsv = hsv_color_helper(HSV_OFF);
//           break;
//     }

//     // if (layer_state_is(layer_state, 1)) {
//     //     hsv = {130, 255, 255};
//     // } else {
//     //     hsv = {30, 255, 255};
//     // }

//     if (hsv.v > rgb_matrix_get_val()) {
//         hsv.v = rgb_matrix_get_val();
//     }
//     RGB rgb = hsv_to_rgb(hsv);

//     for (uint8_t i = led_min; i < led_max; i++) {
//         if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x01 == LED_FLAG_MODIFIER
//             rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
//         }
//     }
//     return false;
// }

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     if (get_highest_layer(layer_state) > 0) {
//         uint8_t layer = get_highest_layer(layer_state);

//         for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
//             for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
//                 uint8_t index = g_led_config.matrix_co[row][col];

//                 if (index >= led_min && index < led_max && index != NO_LED &&
//                 keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
//                     rgb_matrix_set_color(index, RGB_GREEN);
//                 }
//             }
//         }
//     }
//     return false;
// }

#endif