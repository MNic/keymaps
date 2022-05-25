/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* Custom Additions */
#define PERMISSIVE_HOLD

/* USB Device descriptor parameter */
#define VENDOR_ID       0xE5CA
#define PRODUCT_ID      0x0401
#define DEVICE_VER      0x0001
#define MANUFACTURER esca
#define PRODUCT GetawayVan


/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_COL_PINS { B11, B10, B2, B1, B0, A7, A6, A4, A13, A10, C13, C14 }
#define MATRIX_ROW_PINS { A9, A8, A3, A5 }
#define DIODE_DIRECTION COL2ROW

//#define BACKLIGHT_PIN  
//#define BACKLIGHT_LEVELS 6

//#define GRAVE_ESC_CTRL_OVERRIDE

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B15
#define DRIVER_LED_TOTAL 51
#define RGBLED_NUM 51
#define WS2812_SPI SPID2
#define WS2812_SPI_MOSI_PAL_MODE 0
#define WS2812_SPI_SCK_PAL_MODE 0
#define WS2812_SPI_SCK_PIN B13
//#define WS2812_EXTERNAL_PULLUP

#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 12
#define RGBLIGHT_VAL_STEP 12
#define RGBLIGHT_LIMIT_VAL 128
#define TAPPING_TERM 140

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG`

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
