#include "boardwalk.h"

#ifndef KEYMAP_NQADNW
#define KEYMAP_NQADNW

#include "keymap.h"
#include "keymap_german.h"
#include "nqadnw-basic-layout.h"
#include "nqadnw-common.h"

#endif


// More layers - MAX 31!
/*
enum keyboardspace_layers {
  _STH = sizeof(userspace_layers),
  _MORE,
  _EVENMORE
};
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  _BASE (NQADNW)
 *
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | ESC  | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  | DEL  |
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | HOME | PG UP|                                  | BSPC |
 *   |------|                                  |------+------|                                  |------|
 * 2 | CTRL |              BASE                | ENTER| LALT |                BASE              | ENTER|
 *   |------|                                  |------+------|                                  |------|
 * 3 | SHIFT|                                  | END  | PG DN|                                  | SHIFT|
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | PRINT|                    | LOCK |KB LCK|                    | PAUS | RGUI | RCTRL|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_BASE] = /*LAYOUT_ortho_5x14( */{
{ KC_ESC , KC_F1  , TD_F2  , TD_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , TD_F10 , KC_F11 , KC_F12 , KC_DEL  },
{ KC_TAB ,                       _BASE_L1             , KC_HOME, KC_PGUP,           _BASE_R1                         , KC_BSPC },
{ KC_LCTL,                       _BASE_L2             , KC_ENT , KC_LALT,           _BASE_R1                         , KC_ENT  },
{ KC_LSFT,                       _BASE_L3             , KC_END , KC_PGDN,           _BASE_R1                         , KC_RSFT },
{ KC_LCTL, KC_LALT, KC_PSCR,     _BASE_L4             , TD_GUI , KC_LOCK,           _BASE_R1       , KC_PAUS, DE_ALGR, KC_RCTL },
},


/*
 *  _CODE
 *
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | ESC  | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  | F11  | F12  | DEL  |
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | HOME | PG UP|                                  | BSPC |
 *   |------|                                  |------+------|                                  |------|
 * 2 | CTRL |              CODE                | ENTER| LALT |                CODE              | ENTER|
 *   |------|                                  |------+------|                                  |------|
 * 3 | SHIFT|                                  | END  | PG DN|                                  | SHIFT|
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | PRINT|                    | LOCK |KB LCK|                    | PAUS | RGUI | RCTRL|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_CODE] = {
{ KC_ESC , KC_F1  , TD_F2  , TD_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , TD_F10 , KC_F11 , KC_F12 , KC_DEL  },
{ KC_TAB ,                       _CODE_L1             , KC_HOME, KC_PGUP,               _BASE_R1                     , KC_BSPC },
{ KC_LCTL,                       _BASE_L2             , KC_ENT , KC_LALT,               _BASE_R2                     , KC_ENT  },
{ KC_LSFT,                       _CODE_L3             , KC_END , KC_PGDN,               _BASE_R3                     , KC_RSFT },
{ KC_LCTL, KC_LALT, KC_PSCR,     _CODE_L4             , TD_GUI , KC_LOCK,               _CODE_R4   , KC_PAUS, DE_ALGR, KC_RCTL },
},


/*
 *  _STNDRD
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | ESC ^| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 0    | ß    | ´    | BSPC |
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------'------|
 * 1 | TAB  |                                  | HOME | PGUP |                                         |
 *   |------|                                  |------+------|                                         |
 * 2 | CTRL |                                  | ENTER| LALT |                                         |
 *   |------|                                  |------+------|                                         |
 * 3 | SHIFT|                                  | END  | PGDN |                                         |
 *   |------+------.------.                    |------+------|                    .------.------.------|
 * 4 | LCTRL| LALT | LGUI |                    | LOCK | SPACE|                    | RALT | RGUI | RCTRL|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_STNDRD] = {
{ KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , DE_SS  , DE_ACUT, KC_BSPC },
{ KC_TAB ,                         _STNDRD_L1         , KC_HOME, KC_PGUP,         _STNDRD_R1                                   },
{ KC_LCTL,                         _STNDRD_L2         , KC_ENT , KC_LALT,         _STNDRD_R2                                   },
{ KC_LSFT,                         _STNDRD_L3         , KC_END , KC_PGDN,         _STNDRD_R3                                   },
{ KC_LCTL, KC_LALT, KC_LGUI,       _STNDRD_L4         , TD_GUI , KC_SPC ,         _STNDRD_R4       , KC_RGUI, DE_ALGR, KC_RCTL },
},


################################################################################
################################################################################


/*
 *  _RAISE_L triggered via left hand side modifier
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | ESC  | F13  | F14  | F15  | F16  | F17  | F18  | F19  | F20  | F21  | F22  | F23  | F24  | DEL  |
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 |SH TAB|                                  | SH HM| SH PU|                                  | DEL  |
 *   |------|                                  |------+------|                                  |------|
 * 2 | CTRL |                                  |SN ENT| ALTGR|                                  |SH ENT|
 *   |------|                                  |------+------|                                  |------|
 * 3 | SHIFT|                                  |SH END| SH PD|                                  | SHIFT|
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 | LCTRL| ALGR | SREQ |                    |      |      |                    | BREAK| LGUI | RCTRL|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_RAISE_L] = {
{ _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______ },
{ SH_TAB ,                       _RAISE_L1            , SH_HOME, SH_PGUP,        _RAISE_R1                           , KC_DEL  },
{ _______,                       _RAISE_L2            , SH_ENT , DE_ALGR,        _RAISE_R2                           , SH_ENT  },
{ _______,                       _RAISE_L3            , SH_END , SH_PGDN,        _RAISE_R3                           , _______ },
{ _______, DE_ALGR, SYSREQ ,     _RAISE_L4_L          , KC_DOT , KC_COMM,        _RAISE_R4_L       , KC_BRK , KC_LGUI, _______ },
},


/*
 *  _RAISE_L_C triggered via left hand side modifier when on code layer
 */
[_RAISE_L_C] = {
{ _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______ },
{ SH_TAB ,                       _RAISE_C_L1          , SH_HOME, SH_PGUP,        _RAISE_R1                           , KC_DEL  },
{ _______,                       _RAISE_L2            , SH_ENT , DE_ALGR,        _RAISE_R2                           , SH_ENT  },
{ _______,                       _RAISE_C_L3          , SH_END , SH_PGDN,        _RAISE_R3                           , _______ },
{ _______, DE_ALGR, SYSREQ ,     _RAISE_L4_L          , KC_DOT , KC_COMM,        _RAISE_R4_L       , KC_BRK , KC_LGUI, _______ },
},


/*
 *  _RAISE_R
 */
[_RAISE_R] = {
{ _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______ },
{ SH_TAB ,                       _RAISE_C_L1          , SH_HOME, SH_PGUP,        _RAISE_R1                           , KC_DEL  },
{ _______,                       _RAISE_L2            , SH_ENT , DE_ALGR,        _RAISE_R2                           , SH_ENT  },
{ _______,                       _RAISE_C_L3          , SH_END , SH_PGDN,        _RAISE_R3                           , _______ },
{ _______, DE_ALGR, SYSREQ ,     _RAISE_L4_R          , KC_DOT , KC_COMM,        _RAISE_R4_R       , KC_BRK , KC_LGUI, _______ },
},


/*
 *  _RAISE_R_C
 */
[_RAISE_R_C] = {
{ _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , _______ },
{ SH_TAB ,                       _RAISE_C_L1          , SH_HOME, SH_PGUP,        _RAISE_R1                           , KC_DEL  },
{ _______,                       _RAISE_L2            , SH_ENT , DE_ALGR,        _RAISE_R2                           , SH_ENT  },
{ _______,                       _RAISE_C_L3          , SH_END , SH_PGDN,        _RAISE_R3                           , _______ },
{ _______, DE_ALGR, SYSREQ ,     _RAISE_L4_R          , KC_DOT , KC_COMM,        _RAISE_R4_R       , KC_BRK , KC_LGUI, _______ },
},


################################################################################
################################################################################

/*
 *  _LOWER_L
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | ESC  | UNDO | PRINT| SYSRQ| SCROL| REDO |      |      | RET  | INS  | BREAK| PAUSE| CL AG| CLEAR|
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | C HM | C PU |                                  | DEL  |
 *   |------|                                  |------+------|                                  |------|
 * 2 | CTRL |                                  | C ENT| C ALT|                                  | ENTER|
 *   |------|                                  |------+------|                                  |------|
 * 3 | SHIFT|                                  | C END| C PD |                                  | SHIFT|
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | SCROL|                    |      |      |                    | APP  | RGUI | RCTRL|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_LOWER_L] = {
{ CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_REDO, XXXXXXX, XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  },
{ KC_ESC ,                       _LOWER_L1            , C_HOME , C_PGUP ,        _LOWER_R1                           , KC_DEL  },
{ _______,                       _LOWER_L2            , C_ENT  , LCA_T(KC_LALT), _LOWER_R2                           , SH_ENT  },
{ _______,                       _LOWER_L3            , C_END  , C_PGDN ,        _LOWER_R3                           , _______ },
{ _______, KC_LALT, KC_SLCK,     _LOWER_L4_L          , _______, _______,        _LOWER_R4_L       , KC_APP , KC_RGUI, _______ },
},


/*
 *  _LOWER_L_C
 */
[_LOWER_L_C] = {
{ CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_REDO, XXXXXXX, XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  },
{ KC_ESC ,                       _LOWER_C_L1          , C_HOME , C_PGUP ,        _LOWER_R1                           , KC_DEL  },
{ _______,                       _LOWER_L2            , C_ENT  , LCA_T(KC_LALT), _LOWER_R2                           , SH_ENT  },
{ _______,                       _LOWER_C_L3          , C_END  , C_PGDN ,        _LOWER_R3                           , _______ },
{ _______, KC_LALT, KC_SLCK,     _LOWER_L4_L          , _______, _______,        _LOWER_R4_L       , KC_APP , KC_RGUI, _______ },
},


/*
 *  _LOWER_R
 */
[_LOWER_R] = {
{ CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_REDO, XXXXXXX, XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  },
{ KC_ESC ,                       _LOWER_L1            , C_HOME , C_PGUP ,        _LOWER_R1                           , KC_DEL  },
{ _______,                       _LOWER_L2            , C_ENT  , LCA_T(KC_LALT), _LOWER_R2                           , SH_ENT  },
{ _______,                       _LOWER_L3            , C_END  , C_PGDN ,        _LOWER_R3                           , _______ },
{ _______, KC_LALT, KC_SLCK,     _LOWER_L4_R          , _______, _______,        _LOWER_R4_R       , KC_APP , KC_RGUI, _______ },
},


/*
 *  _LOWER_R_C
 */
[_LOWER_R_C] = {
{ CANCEL , KC_UNDO, KC_PSCR, SYSREQ, KC_SLCK , KC_REDO, XXXXXXX, XXXXXXX, RETURN , KC_INS , KC_BRK , KC_PAUS, KC_CLA , KC_CLR  },
{ KC_ESC ,                       _LOWER_C_L1          , C_HOME , C_PGUP ,        _LOWER_R1                           , KC_DEL  },
{ _______,                       _LOWER_L2            , C_ENT  , LCA_T(KC_LALT), _LOWER_R2                           , SH_ENT  },
{ _______,                       _LOWER_C_L3          , C_END  , C_PGDN ,        _LOWER_R3                           , _______ },
{ _______, KC_LALT, KC_SLCK,     _LOWER_L4_R          , _______, _______,        _LOWER_R4_R       , KC_APP , KC_RGUI, _______ },
},


################################################################################
################################################################################


/*
 *  _LEFT
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | C A D| prv  | pl/ps| next | stop | DEBUG|      |      | BL   | BL-  | BL+  | BLM  | BLM- | BLM+ |
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  |      |      |                                  | BSPC |
 *   |------|                                  |------+------|                                  |------|
 * 2 | CTRL |                                  |      |      |                                  | ENTER|
 *   |------|                                  |------+------|                                  |------|
 * 3 | SHIFT|                                  |      |      |                                  | SHIFT|
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 | LCTRL| LALT | LGUI |                    |      |      |                    | RALT | RGUI | RCTRL|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_LEFT] = {
{ C_A_DEL, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, DEBUG  , XXXXXXX, XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, BL_TOGG, BL_DEC , BL_INC  },
{ KC_TAB ,                       _LEFT_L1             , _______, _______,           _LEFT_R1                         , KC_BSPC },
{ _______,                       _LEFT_L2             , _______, _______,           _LEFT_R1                         , KC_ENT  },
{ _______,                       _LEFT_L3             , _______, _______,           _LEFT_R1                         , _______ },
{ _______, XXXXXXX, XXXXXXX,     _LEFT_L4             , _______, _______,           _LEFT_R1       , XXXXXXX, XXXXXXX, _______ },
},


 /*
  *  _LEFT_C
  */
[_LEFT_C] = {
{ C_A_DEL, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, DEBUG  , XXXXXXX, XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, BL_TOGG, BL_DEC , BL_INC  },
{ KC_TAB ,                       _LEFT_L1             , _______, _______,           _LEFT_R1                         , KC_BSPC },
{ _______,                       _LEFT_L2             , _______, _______,           _LEFT_C_R1                       , KC_ENT  },
{ _______,                       _LEFT_C_L3           , _______, _______,           _LEFT_R1                         , _______ },
{ _______, XXXXXXX, XXXXXXX,     _LEFT_L4             , _______, _______,           _LEFT_R1       , XXXXXXX, XXXXXXX, _______ },
},


################################################################################
################################################################################


/*
 *  _RIGHT
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 | ESC  | MY PC| =    | /    | *    | -    |      |      | RST  | MUTE | VOL D| VOL U|      | AL F4|
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 | TAB  |                                  | -    | +    |                                  | BSPC |
 *   |------|                                  |------+------|                                  |------|
 * 2 | CTRL |                                  | =    | /    |                                  | ENTER|
 *   |------|                                  |------+------|                                  |------|
 * 3 | SHIFT|                                  | *    | ENTER|                                  | SHIFT|
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 |______| SSPC | .    |                    | .    | ;    |                    |      |      |______|
 *   `-------------------------------------------------------------------------------------------------'
 */
[_RIGHT] = {
{ KC_ESC , KC_MYCM, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX, XXXXXXX, RESET  , KC_MUTE, KC_VOLD, KC_VOLU, KC_PWR , ALT_F4  },
{ KC_TAB ,                       _RIGHT_L1            , KC_PMNS, KC_PPLS,           _RIGHT_R1                        , KC_BSPC },
{ _______,                       _RIGHT_L2            , KC_PAST, KC_PSLS,           _RIGHT_R2                        , KC_ENT  },
{ _______,                       _RIGHT_L3            , KC_PEQL, KC_ENT ,           _RIGHT_R3                        , _______ },
{ _______, KC_BSPC, KC_DOT ,     _RIGHT_L4            , KC_DOT , DE_SCLN,           _RIGHT_R4      , XXXXXXX, XXXXXXX, _______ },
},


  };


/*
 *  _LAYER
 *   ,-------------------------------------------------------------------------------------------------.
 * 0 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 *   |------+------'------'------'------'------+------+------+------'------'------'------'------+------|
 * 1 |      |                                  |      |      |                                  |      |
 *   |------|                                  |------+------|                                  |------|
 * 2 |      |                                  |      |      |                                  |      |
 *   |------|                                  |------+------|                                  |------|
 * 3 |      |                                  |      |      |                                  |      |
 *   |------+------.------.                    |------+------|                    .------.------+------|
 * 4 |      |      |      |                    |      |      |                    |      |      |______|
 *   `-------------------------------------------------------------------------------------------------'
 */
