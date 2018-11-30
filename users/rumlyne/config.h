#pragma once

#ifndef CONFIG_H
#define CONFIG_H


//#define NO_ACTION_FUNCTION
//#define NO_ACTION_MACRO
#define NO_PRINT
#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 160  // how long before a tap becomes a hold // default = 200
#define TAPPING_TOGGLE 2
#define TAPPING_FORCE_HOLD  // makes it possible to use a dual role key as modifier shortly after having been tapped
#define QMK_KEYS_PER_SCAN 4  // default = 1

// RGB Settings
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP  // make sure backlight is off when PC is asleep
#include "rgblight_list.h"  // qmk-firmware/quantum/rgblight_list.h
#endif  // RGBLIGHT_ENABLE


// Mouse
#ifdef MOUSEKEY_ENABLE  // Mouse key config
// Frequency with which cursor movements are sent. Lower means more resolution / DPI.
// Default: 20
// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL       20
// MS after pressing the key before initial movement begins. Lower means quicker response.
// Default: 0
// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY          0
// MS it takes the cursor to accelerate to max speed
// Default: 60
// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX    60
// Maximum speed for the mouse keys
// Default: 7
// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED      7
// Delay before the mouse wheel
// Default: 0
// #undef MOUSEKEY_WHEEL_DELAY
// #define MOUSEKEY_WHEEL_DELAY    0
#endif // MOUSEKEY_ENABLE


#endif // nqadnw-config.h
