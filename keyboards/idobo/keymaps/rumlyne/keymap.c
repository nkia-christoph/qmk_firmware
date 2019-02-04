#include "idobo.h"
#include QMK_KEYBOARD_H
//#include "quantum.h"

#include "rumlyne.h"
#include "nqadnw_basic_layout.h"
#include "keymap_german.h"

//extern userspace_config_t userspace_config; // do I need that?
extern keymap_config_t keymap_config;

//#define LAYOUT_ortho_5x15_wrapper(...) LAYOUT_ortho_5x15(__VA_ARGS__) // defined in userspace


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  _BASE (NQADNW)
 *
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | ESC  | F1   | F2   | F3   | F4   | F5   | F6   | LOCK | F7   | F8   | F9   | F10  | F11  | F12  | DEL  |
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | 7    | 8    | 9    |                                  | BSPC |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 | CTRL |              BASE                | 4    | 5    | 6    |                BASE              | ENTER|
 *   |------|                                  |------+------+------|                                  |------|
 * 3 | SHIFT|                                  | 1    | 2    | 3    |                                  | SHIFT|
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | PRINT|                    | .    | 0    | ,    |                    | PAUS | RGUI | RCTRL|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F1  , TD_F2  , TD_F3  , TD_F4  , KC_F5  , KC_F6  , TD_GUI , KC_F7  , KC_F8  , TD_F9  , TD_F10 , TD_F11 , KC_F12 , KC_DEL  , \
    KC_TAB ,                       _BASE_L1             , KC_7   , KC_8   , KC_9   ,           _BASE_R1                         , KC_BSPC , \
    KC_LCTL,                       _BASE_L2             , KC_4   , KC_5   , KC_6   ,           _BASE_R2                         , KC_ENT  , \
    KC_LSFT,                       _BASE_L3             , KC_1   , KC_2   , KC_3   ,           _BASE_R3                         , KC_RSFT , \
    KC_LCTL, KC_LALT, KC_PSCR,     _BASE_L4             , KC_DOT , KC_0   , KC_COMM,           _BASE_R4       , KC_PAUS, KC_ALGR, KC_RCTL   \
),


/**  _JPNS
  *   ,--------------------------------------------------------------------------------------------------------.
  * 0 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
  *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
  * 1 |      |                                  |      |      |      |                                  |      |
  *   |------|                                  |------+------+------|                                  |------|
  * 2 |      |                                  |      |      |      |                                  |      |
  *   |------|                                  |------+------+------|                                  |------|
  * 3 |      |                                  |      |      |      |                                  |      |
  *   |------+------.------.                    |------+------+------|                    .------.------+------|
  * 4 |      |      |      |                    |      |      |      |                    |      |      |______|
  *   `--------------------------------------------------------------------------------------------------------'
  */
[_JPNS] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F1  , TD_F2  , TD_F3  , TD_F4  , KC_F5  , KC_F6  , TD_GUI , KC_F7  , KC_F8  , TD_F9  , TD_F10 , TD_F11 , KC_F12 , KC_DEL  , \
    KC_TAB ,                       _JPNS_L1             , KC_7   , KC_8   , KC_9   ,           _JPNS_R1                         , KC_BSPC , \
    KC_LCTL,                       _JPNS_L2             , KC_4   , KC_5   , KC_6   ,           _JPNS_R2                         , KC_ENT  , \
    KC_LSFT,                       _JPNS_L3             , KC_1   , KC_2   , KC_3   ,           _JPNS_R3                         , KC_RSFT , \
    KC_LCTL, XXXXXXX, XXXXXXX,     _JPNS_L4             , KC_DOT , KC_0   , KC_COMM,           _JPNS_R4       , XXXXXXX, XXXXXXX, KC_RCTL   \
),


/*
 *  _CODE
 *
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | ESC  | F1   | F2   | F3   | F4   | F5   | F6   | LOCK | F7   | F8   | F9   | F10  | F11  | F12  | DEL  |
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | 7    | 8    | 9    |                                  | BSPC |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 | CTRL |              CODE                | 4    | 5    | 6    |                CODE              | ENTER|
 *   |------|                                  |------+------+------|                                  |------|
 * 3 | SHIFT|                                  | 1    | 2    | 3    |                                  | SHIFT|
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | PRINT|                    | .    | 0    | ,    |                    | PAUS | RGUI | RCTRL|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_CODE] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F1  , TD_F2  , TD_F3  , TD_F4  , KC_F5  , KC_F6  , TD_GUI , KC_F7  , KC_F8  , TD_F9  , TD_F10 , TD_F11 , KC_F12 , KC_DEL  , \
    KC_TAB ,                       _CODE_L1             , KC_7   , KC_8   , KC_9   ,               _BASE_R1                     , KC_BSPC , \
    KC_LCTL,                       _BASE_L2             , KC_4   , KC_5   , KC_6   ,               _BASE_R2                     , KC_ENT  , \
    KC_LSFT,                       _CODE_L3             , KC_1   , KC_2   , KC_3   ,               _BASE_R3                     , KC_RSFT , \
    KC_LCTL, KC_LALT, KC_PSCR,     _CODE_L4             , KC_DOT , KC_0   , KC_COMM,               _CODE_R4   , KC_PAUS, KC_ALGR, KC_RCTL   \
),


/*
 *  _STD
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | ESC ^| 1    | 2    | 3    | 4    | 5    | 6    | LOCK | 7    | 8    | 9    | 0    | ß    | ´    | BSPC |
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------'------|
 * 1 | TAB  |                                  | 7    | 8    | 9    |                                         |
 *   |------|                                  |------+------+------|                                         |
 * 2 | CTRL |                                  | 4    | 5    | 6    |                                         |
 *   |------|                                  |------+------+------|                                         |
 * 3 | SHIFT|                                  | 1    | 2    | 3    |                                         |
 *   |------+------.------.                    |------+------+------|                    .------.------.------|
 * 4 | LCTRL| LALT | LGUI |                    | .    | 0    | ,    |                    | RALT | RGUI | RCTRL|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_STD] = LAYOUT_ortho_5x15_wrapper (
    KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , TD_GUI , KC_7   , KC_8   , KC_9   , KC_0   , DE_SS  , DE_ACUT, KC_BSPC , \
    KC_TAB ,                         _STD_L1            , KC_7   , KC_8   , KC_9   ,         _STD_R1                                      , \
    KC_LCTL,                         _STD_L2            , KC_4   , KC_5   , KC_6   ,         _STD_R2                                      , \
    KC_LSFT,                         _STD_L3            , KC_1   , KC_2   , KC_3   ,         _STD_R3                                      , \
    KC_LCTL, KC_LALT, KC_LGUI,       _STD_L4            , KC_DOT , KC_0   , KC_COMM,         _STD_R4          , KC_RGUI, KC_ALGR, KC_RCTL   \
),


/*
 *  _RAISE_L triggered via left hand side modifier
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | ESC  | F13  | F14  | F15  | F16  | F17  | F18  | LOCK | F19  | F20  | F21  | F22  | F23  | F24  | DEL  |
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 |SH TAB|                                  | 7    | 8    | 9    |                                  | DEL  |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 | CTRL |                                  | 4    | 5    | 6    |                                  |SH ENT|
 *   |------|                                  |------+------+------|                                  |------|
 * 3 | SHIFT|                                  | 1    | 2    | 3    |                                  | SHIFT|
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 | LCTRL| ALGR | SREQ |                    | .    | 0    | ,    |                    | BREAK| LGUI | RCTRL|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_RAISE_L] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , TD_GUI , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , KC_DEL  , \
    SH_TAB ,                       _RAISE_L1            , RA_7   , RA_8   , RA_9   ,        _RAISE_R1                           , KC_DEL  , \
    KC_LCTL,                       _RAISE_L2            , RA_4   , RA_5   , RA_6   ,        _RAISE_R2                           , SH_ENT  , \
    KC_LSFT,                       _RAISE_L3            , RA_1   , RA_2   , RA_3   ,        _RAISE_R3                           , KC_RSFT , \
    KC_LCTL, KC_ALGR, SYSREQ ,     _RAISE_L4_L          , KC_DOT , RA_0   , KC_COMM,        _RAISE_R4_L       , KC_BRK , KC_LGUI, KC_RCTL   \
),


/*
 *  _RAISE_L_C triggered via left hand side modifier when on code layer
 */
[_RAISE_L_C] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , TD_GUI , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , KC_DEL  , \
    KC_LCTL,                       _RAISE_L2            , RA_4   , RA_5   , RA_6   ,        _RAISE_R2                           , SH_ENT  , \
    KC_LSFT,                       _RAISE_C_L3          , RA_1   , RA_2   , RA_3   ,        _RAISE_R3                           , KC_RSFT , \
    SH_TAB ,                       _RAISE_C_L1          , RA_7   , RA_8   , RA_9   ,        _RAISE_R1                           , KC_DEL  , \
    KC_LCTL, KC_ALGR, SYSREQ ,     _RAISE_L4_L          , KC_DOT , RA_0   , KC_COMM,        _RAISE_R4_L       , KC_BRK , KC_LGUI, KC_RCTL   \
),


/*
 *  _RAISE_R
 */
[_RAISE_R] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , TD_GUI , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , KC_DEL  , \
    SH_TAB ,                       _RAISE_C_L1          , RA_7   , RA_8   , RA_9   ,        _RAISE_R1                           , KC_DEL  , \
    KC_LCTL,                       _RAISE_L2            , RA_4   , RA_5   , RA_6   ,        _RAISE_R2                           , SH_ENT  , \
    KC_LSFT,                       _RAISE_C_L3          , RA_1   , RA_2   , RA_3   ,        _RAISE_R3                           , KC_RSFT , \
    KC_LCTL, KC_ALGR, SYSREQ ,     _RAISE_L4_R          , KC_DOT , RA_0   , KC_COMM,        _RAISE_R4_R       , KC_BRK , KC_LGUI, KC_RCTL   \
),


/*
 *  _RAISE_R_C
 */
[_RAISE_R_C] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , TD_GUI , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , KC_DEL  , \
    KC_LCTL,                       _RAISE_L2            , RA_4   , RA_5   , RA_6   ,        _RAISE_R2                           , SH_ENT  , \
    SH_TAB ,                       _RAISE_C_L1          , RA_7   , RA_8   , RA_9   ,        _RAISE_R1                           , KC_DEL  , \
    KC_LSFT,                       _RAISE_C_L3          , RA_1   , RA_2   , RA_3   ,        _RAISE_R3                           , KC_RSFT , \
    KC_LCTL, KC_ALGR, SYSREQ ,     _RAISE_L4_R          , KC_DOT , RA_0   , KC_COMM,        _RAISE_R4_R       , KC_BRK , KC_LGUI, KC_RCTL   \
),


/*
 *  _LOWER_L
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | ESC  | UNDO | PRINT| SYSRQ| SCROL| REDO |      | LOCK |      | RET  | INS  | BREAK| PAUSE| CL AG| CLEAR|
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | 7    | 8    | 9    |                                  | DEL  |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 | CTRL |                                  | 4    | 5    | 6    |                                  | ENTER|
 *   |------|                                  |------+------+------|                                  |------|
 * 3 | SHIFT|                                  | 1    | 2    | 3    |                                  | SHIFT|
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | SCROL|                    | .    | 0    | ,    |                    | APP  | RGUI | RCTRL|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_LOWER_L] = LAYOUT_ortho_5x15_wrapper (
    CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_AGIN, XXXXXXX, TD_GUI , XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  , \
    KC_ESC ,                       _LOWER_L1            , RA_7   , RA_8   , RA_9   ,        _LOWER_R1                           , KC_DEL  , \
    KC_LCTL,                       _LOWER_L2            , RA_4   , RA_5   , RA_6   ,        _LOWER_R2                           , SH_ENT  , \
    KC_LSFT,                       _LOWER_L3            , RA_1   , RA_2   , RA_3   ,        _LOWER_R3                           , KC_RSFT , \
    KC_LCTL, KC_LALT, KC_SLCK,     _LOWER_L4_L          , KC_DOT , RA_0   , KC_COMM,        _LOWER_R4_L       , KC_APP , KC_RGUI, KC_RCTL   \
),


/*
 *  _LOWER_L_C
 */
[_LOWER_L_C] = LAYOUT_ortho_5x15_wrapper (
    CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_AGIN, XXXXXXX, TD_GUI , XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  , \
    KC_ESC ,                       _LOWER_C_L1          , RA_7   , RA_8   , RA_9   ,        _LOWER_R1                           , KC_DEL  , \
    KC_LCTL,                       _LOWER_L2            , RA_4   , RA_5   , RA_6   ,        _LOWER_R2                           , SH_ENT  , \
    KC_LSFT,                       _LOWER_C_L3          , RA_1   , RA_2   , RA_3   ,        _LOWER_R3                           , KC_RSFT , \
    KC_LCTL, KC_LALT, KC_SLCK,     _LOWER_L4_L          , KC_DOT , RA_0   , KC_COMM,        _LOWER_R4_L       , KC_APP , KC_RGUI, KC_RCTL   \
),


/*
 *  _LOWER_R
 */
[_LOWER_R] = LAYOUT_ortho_5x15_wrapper (
    CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_AGIN, XXXXXXX, TD_GUI , XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  , \
    KC_ESC ,                       _LOWER_L1            , RA_7   , RA_8   , RA_9   ,        _LOWER_R1                           , KC_DEL  , \
    KC_LCTL,                       _LOWER_L2            , RA_4   , RA_5   , RA_6   ,        _LOWER_R2                           , SH_ENT  , \
    KC_LSFT,                       _LOWER_L3            , RA_1   , RA_2   , RA_3   ,        _LOWER_R3                           , KC_RSFT , \
    KC_LCTL, KC_LALT, KC_SLCK,     _LOWER_L4_R          , KC_DOT , RA_0   , KC_COMM,        _LOWER_R4_R       , KC_APP , KC_RGUI, KC_RCTL   \
),


/*
 *  _LOWER_R_C
 */
[_LOWER_R_C] = LAYOUT_ortho_5x15_wrapper(
    CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_AGIN, XXXXXXX, TD_GUI , XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  , \
    KC_ESC ,                       _LOWER_C_L1          , RA_7   , RA_8   , RA_9   ,        _LOWER_R1                           , KC_DEL  , \
    KC_LCTL,                       _LOWER_L2            , RA_4   , RA_5   , RA_6   ,        _LOWER_R2                           , SH_ENT  , \
    KC_LSFT,                       _LOWER_C_L3          , RA_1   , RA_2   , RA_3   ,        _LOWER_R3                           , KC_RSFT , \
    KC_LCTL, KC_LALT, KC_SLCK,     _LOWER_L4_R          , KC_DOT , RA_0   , KC_COMM,        _LOWER_R4_R       , KC_APP , KC_RGUI, KC_RCTL   \
),


/*
 *  _LEFT
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | C A D| prv  | prv  | pl/ps|next  | DBG  |      | LOCK |      | BL   | BL-  | BL+  | BLM  | BLM- | BLM+ |
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | 7    | 8    | 9    |                                  | BSPC |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 | CTRL |                                  | 4    | 5    | 6    |                                  | ENTER|
 *   |------|                                  |------+------+------|                                  |------|
 * 3 | SHIFT|                                  | 1    | 2    | 3    |                                  | SHIFT|
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 | LCTRL|      |      |                    | .    | 0    | ,    |                    |      |      | RCTRL|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_LEFT] = LAYOUT_ortho_5x15_wrapper (
    C_A_DEL, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, DEBUG  , XXXXXXX, TD_GUI , XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, BL_TOGG, BL_DEC , BL_INC  , \
    KC_TAB ,                       _LEFT_L1             , KC_7   , KC_8   , KC_9   ,           _LEFT_R1                         , KC_BSPC , \
    KC_LCTL,                       _LEFT_L2             , KC_4   , KC_5   , KC_6   ,           _LEFT_R2                         , KC_ENT  , \
    KC_LSFT,                       _LEFT_L3             , KC_1   , KC_2   , KC_3   ,           _LEFT_R3                         , KC_RSFT , \
    KC_LCTL, XXXXXXX, XXXXXXX,     _LEFT_L4             , KC_DOT , KC_0   , KC_COMM,           _LEFT_R4       , XXXXXXX, XXXXXXX, KC_RCTL   \
),


/*
 *  _LEFT_C
 */
[_LEFT_C] = LAYOUT_ortho_5x15_wrapper (
    C_A_DEL, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, DEBUG  , XXXXXXX, TD_GUI , XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, BL_TOGG, BL_DEC , BL_INC  , \
    KC_TAB ,                       _LEFT_L1             , KC_7   , KC_8   , KC_9   ,           _LEFT_R1                         , KC_BSPC , \
    KC_LCTL,                       _LEFT_L2             , KC_4   , KC_5   , KC_6   ,           _LEFT_C_R2                       , KC_ENT  , \
    KC_LSFT,                       _LEFT_C_L3           , KC_1   , KC_2   , KC_3   ,           _LEFT_R3                         , KC_RSFT , \
    KC_LCTL, XXXXXXX, XXXXXXX,     _LEFT_L4             , KC_DOT , KC_0   , KC_COMM,           _LEFT_R4       , XXXXXXX, XXXXXXX, KC_RCTL   \
),


/*
 *  _RIGHT
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 | ESC  | MY PC| =    | /    | *    | -    |      | LOCK |      | RST  | MUTE | VOL D| VOL U|      | AL F4|
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | $    | £    | €    |                                  | BSPC |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 | CTRL |                                  | D    | E    | F    |                                  | ENTER|
 *   |------|                                  |------+------+------|                                  |------|
 * 3 | SHIFT|                                  | A    | B    | C    |                                  | SHIFT|
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 |______| SSPC | .    |                    | .    | 00   | ;    |                    |      |      |______|
 *   `--------------------------------------------------------------------------------------------------------'
 */
[_RIGHT] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC , KC_MYCM, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, TD_GUI , XXXXXXX, RESET  , KC_MUTE, KC_VOLD, KC_VOLU, KC_PWR , ALT_F4  , \
    KC_TAB ,                       _RIGHT_L1            , DE_DLR , CUR_BPN, CUR_EUR,           _RIGHT_R1                        , KC_BSPC , \
    KC_LCTL,                       _RIGHT_L2            , KC_D   , KC_E   , KC_F   ,           _RIGHT_R2                        , KC_ENT  , \
    KC_LSFT,                       _RIGHT_L3            , KC_A   , KC_B   , KC_C   ,           _RIGHT_R3                        , KC_RSFT , \
    KC_LCTL, KC_BSPC, KC_DOT ,     _RIGHT_L4            , KC_DOT , KS_00  , DE_SCLN,           _RIGHT_R4      , XXXXXXX, XXXXXXX, KC_RCTL   \
),


    }; // end layers


/*
 *  _LAYER
 *   ,--------------------------------------------------------------------------------------------------------.
 * 0 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 *   |------+------'------'------'------'------+------+------+------+------'------'------'------'------+------|
 * 1 |      |                                  |      |      |      |                                  |      |
 *   |------|                                  |------+------+------|                                  |------|
 * 2 |      |                                  |      |      |      |                                  |      |
 *   |------|                                  |------+------+------|                                  |------|
 * 3 |      |                                  |      |      |      |                                  |      |
 *   |------+------.------.                    |------+------+------|                    .------.------+------|
 * 4 |      |      |      |                    |      |      |      |                    |      |      |______|
 *   `--------------------------------------------------------------------------------------------------------'
 *
 * [_LAYER] = LAYOUT_ortho_5x15_wrapper (
 *   C_A_DEL, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, DEBUG  , XXXXXXX, TD_GUI , XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, BL_TOGG, BL_DEC , BL_INC  , \
 *   KC_TAB ,                       _LEFT_L1             , KC_7   , KC_8   , KC_9   ,           _LEFT_R1                         , KC_BSPC , \
 *   KC_LCTL,                       _LEFT_L2             , KC_4   , KC_5   , KC_6   ,           _LEFT_R1                         , KC_ENT  , \
 *   KC_LSFT,                       _LEFT_L3             , KC_1   , KC_2   , KC_3   ,           _LEFT_R1                         , KC_RSFT , \
 *   KC_LCTL, XXXXXXX, XXXXXXX,     _LEFT_L4             , KC_DOT , KC_0   , KC_COMM,           _LEFT_R1       , XXXXXXX, XXXXXXX, KC_RCTL   \
 * ),
 *
 */

<<<<<<< HEAD
void matrix_init_keymap(void) {
    set_unicode_input_mode(UC_WIN);
}

/*
void matrix_scan_keymap(void) {
    matrix_scan_user();
}
=======
__attribute__ ((weak))
void matrix_init_kb(void) {
    set_unicode_input_mode(UC_WIN);
    matrix_init_user();
}

/*
__attribute__ ((weak))
void matrix_scan_kb(void) {
    matrix_scan_user();
}

__attribute__ ((weak))
void matrix_init_user(void) {
}

__attribute__ ((weak))
void matrix_scan_user(void) {
}
>>>>>>> a33ca537b40d8d361465b9c3c0b05f30ada44c8e
*/
