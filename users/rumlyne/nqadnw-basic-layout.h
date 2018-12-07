#pragma once


#include "quantum.h"
#include "dynamic_macro.h"
#include "process_keycode/process_tap_dance.h"
#include "keymap_german.h"
#include <sendstring_german.h>
#include "nqadnw-common-definitions.h"
#include "nqadnw-common-functions.h"
#include QMK_KEYBOARD_H

#ifndef NQADNW_BASIC_LAYOUT_H
#define NQADNW_BASIC_LAYOUT_H

/**
  * This is not quite the the Aus Der Neo Welt (BuT) layout (http://www.adnw.de/) but an
  * ortho, thumb keys and programmer friendly adaptation by me called Progammer BUX
  *
  * It consists of a block of 5x3 or 5x4, for each hand. This allows us
  * to use these blocks for a variety of keyboards like the planck, preonic, XD75 and
  * even splits like the ergodox - and all the cloes of course.
  *
  * The naming convention for these blocks is
  *   L<LAYER>(_<ALTERNATE>)_<SIDE><ROW>(_<ALTERNATE>)
  *
  *   The LAYER is a number starting at
  *   00 for the base layer.
  *   3 & 4 are mostly shift,
  *   5 & 6 is for special chars etc.
  *
  *   SIDE is, well either the left or right side/half of a keyboard.
  *
  *   The ROW is starting from the top, numbering beginning at 1, or 0.
  */


/**
  * Since our quirky block definitions are basically a list of comma separated
  * arguments, we need a wrapper in order for these definitions to be
  * expanded before being used as arguments to the LAYOUT_xxx macro.
  */

#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif

#define KEYMAP_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_5x14_wrapper(...) LAYOUT_ortho_5x14(__VA_ARGS__)
#define LAYOUT_ortho_5x15_wrapper(...) LAYOUT_ortho_5x15(__VA_ARGS__)


enum userspace_layers {
  _BASE = 00,	// Programmer BUX // default
  _CODE,      // 01	// Code friendly layer
  _STNDRD,    // 02  // QWERTZ, QWERTY, AZERTY, etc.
  // _JPNS,      // 03 // Japanese Kana layout based on esrilles new stickney layout // TODO

  _RAISE_L,   // _RAISE when accessed via left MOD // BuT based symbol layer
  _RAISE_L_C, // _RAISE when accessed via left MOD on _CODE layer
  _RAISE_R,
  _RAISE_R_C,

  _LOWER_L,
  _LOWER_L_C,
  _LOWER_R,
  _LOWER_R_C,

  _LEFT,
  _LEFT_C,    // _LEFT when pressed on _CODE layer

  _RIGHT      // NUM+
  // _RIGHT_C
};


/*
 *  _BASE (NQADNW)
 *                    LEFT                  		       RIGHT
 *   ,----------------------------------.  ,----------------------------------.
 * 1 | b    | u    | g    | ß    | ü    |  | p    | c    | l    | m    | f    |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 2 | h    | i    | e    | a    | o    |  | d    | t    | r    | n    | s    |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 3 | k    | y    | ö    | ä    | q    |  | j    | g    | w    | v    | z    |
 *   `-------------+------+------+------|  |------+------+------+-------------'
 * 4               | LEFT |SPC RS| , LW |  | . RS |ENT LW| RIGHT|
 *                 `--------------------'  `--------------------'
 */
#define _BASE_L1     KC_B   , KC_U   , KC_X   , DE_SS  , DE_UE
#define _BASE_L2     KC_H   , KC_I   , KC_E   , KC_A   , KC_O
#define _BASE_L3     KC_K   , DE_Y   , DE_OE  , DE_AE  , KC_Q
#define _BASE_L4                       LEFT   , RS_L   , LW_L

#define _BASE_R1     KC_P   , KC_C   , KC_L   , KC_M   , KC_F
#define _BASE_R2     KC_D   , KC_T   , KC_R   , KC_N   , KC_S
#define _BASE_R3     KC_J   , KC_G   , KC_W   , KC_V   , DE_Z
#define _BASE_R4     RS_R   , LW_R   , RIGHT


/*
 *  _CODE
 *                    LEFT
 *   ,----------------------------------.
 * 1 | b    | u    | g    | $    | #    |
 *   |------+------+------+------+------|
 * 2 |______|______|______|______|______|
 *   |------+------+------+------+------|
 * 3 | k    | y    | |    | ~    | q    |
 *   `-------------+------+------+------|  ,--------------------.
 * 4               | LEFT |SPC RS| , LW |  | . LW |ENT RS| RIGHT|
 *                 `--------------------'  `--------------------'
 */
#define _CODE_L1         KC_B   , KC_U   , KC_X   , DE_DLR , DE_HASH
// #define  _CODE_L2        _BASE_L2
#define _CODE_L3         KC_K   , DE_Y   , DE_PIPE, DE_TILD, KC_Q
#define _CODE_L4                           LEFT   , RS_L_C , LW_L_C

// #define  _CODE_L1 _BASE_R1
// #define  _CODE_L2 _BASE_R2
// #define  _CODE_L3 _BASE_R3
#define     _CODE_R4     RS_R_C , LW_R_C , RIGHT


/*
 *  _STNDRD
 *                    LEFT                  		       RIGHT                    EXTRA
 *   ,----------------------------------.  ,-----------------------------------------.
 * 1 | q    | w    | e    | r    | t    |  | z    | u    | i    | o    | p    | ü    |
 *   |------+------+------+------+------|  |------+------+------+------+------+------|
 * 2 | a    | s    | d    | f    | g    |  | h    | j    | k    | l    | ö    | ä    |
 *   |------+------+------+------+------|  |------+------+------+------+------+------|
 * 3 | y    | x    | c    | v    | b    |  | n    | m    | ,    | .    | -    |SH/ENT|
 *   `-------------+------+------+------|  |------+------+------+--------------------'
 * 4               | SPACE| SPACE| SPACE|  | ENT  | SHIFT| ALTGR|
 *                 `--------------------'  `--------------------'
 */
#define _STNDRD_L1        KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _STNDRD_L2        KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _STNDRD_L3        KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define _STNDRD_L4                          KC_SPC , KC_SPC , KC_SPC

#define _STNDRD_R1        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,DE_UE
#define _STNDRD_R2        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN,DE_AE
#define _STNDRD_R3        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,RSFT_T(KC_ENT)
#define _STNDRD_R4        KC_ENT , DE_LESS, ALTGR


################################################################################
################################################################################


/*
 *  _RAISE
 *                    LEFT                  		       RIGHT
 *   ,----------------------------------.  ,----------------------------------.
 * 1 | B    | U    | X    | ?    | Ü    |  | P    | C    | L    | M    | F    |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 2 | H    | I    | E    | A    | O    |  | D    | T    | R    | N    | S    |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 3 | K    | Y    | Ö    | Ä    | Q    |  | J    | G    | W    | V    | Z    |
 *   `-------------+------+------+------|  |------+------+------+-------------'
 * 4               |      |      |      |  |      |      |      |
 *                 `--------------------'  `--------------------'
 */
#define _RAISE_L1         SH_B   , SH_U   , SH_X   , DE_QST , SH_UE
#define _RAISE_L2         SH_H   , SH_I   , SH_E   , SH_A   , SH_O
#define _RAISE_L3         SH_K   , SH_Y   , SH_OE  , SH_AE  , SH_Q
#define _RAISE_L4_L                         LEFT   , _______, DE_SCLN
#define _RAISE_L4_R                         LEFT   , DE_UNDS, DE_SCLN

#define _RAISE_R1         SH_P   , SH_C   , SH_L   , SH_M   , SH_F
#define _RAISE_R2         SH_D   , SH_T   , SH_R   , SH_N   , SH_S
#define _RAISE_R3         SH_J   , SH_G   , SH_W   , SH_V   , SH_Z
#define _RAISE_R4_L       DE_COLN, SH_ENT, RIGHT
#define _RAISE_R4_R       _______, SH_ENT, RIGHT


#define _RAISE_C_L1       /*_RAISE_L1*/ SH_B   , SH_U   , SH_X   , DE_EXLM, TD_SUDO
// #define _RAISE_C_L2       _RAISE_L2
#define _RAISE_C_L3       /*_RAISE_L3*/ SH_K   , SH_Y   , TD_APTG, TD_PCMN, SH_Q
// #define _RAISE_C_L4_L     _RAISE_R4_L
// #define _RAISE_C_L4_R     _RAISE_R4_R

// #define _RAISE_C_R1       _RAISE_R1
// #define _RAISE_C_R2       _RAISE_R2
// #define _RAISE_C_R3       _RAISE_R2
// #define _RAISE_C_R4_L     _RAISE_R4_L
// #define _RAISE_C_R4_R     _RAISE_R4_R


################################################################################
################################################################################


/*
 *  _LOWER
 *                    LEFT                  		       RIGHT
 *   ,----------------------------------.  ,----------------------------------.
 * 1 | ´    | _    | '  " | !    | #    |  | µ    | &    | -    | =    | `    |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 2 | <  > | {  } | [  ] | (  ) | /    |  | \    | <- H | v  J | ^  K | -> L |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 3 | ^    | €  $ | |    | ~  ™ | *    |  | @  © | %    | +    | §  ® | °    |
 *   `-------------+------+------+------|  |------+------+------+-------------'
 * 4               |LEFT  | BSPC | ;    |  | :    | A ENT| RIGHT|
 *                 `--------------------'  `--------------------'
 */
#define _LOWER_L1         DE_ACUT, DE_UNDS, TD_QUOT, DE_EXLM, DE_HASH
#define _LOWER_L2         TD_BR1 , TD_BR2 , TD_BR3 , TD_BR4 , DE_SLSH
#define _LOWER_L3         DE_RING, TD_CUR , DE_PIPE, TD_TILD, DE_ASTR
#define _LOWER_L4_L                         LEFT   , KC_BSPC, _______
#define _LOWER_L4_R                         LEFT   , KC_BSPC, DE_SCLN

#define _LOWER_R1         DE_MCRO, DE_AMPR, DE_MINS, DE_EQL , DE_GRV
#define _LOWER_R2         DE_BSLS, BR_ARRH, BR_ARRJ, BR_ARRK, BR_ARRL
#define _LOWER_R3         TD_AT  , DE_PERC, DE_PLUS, TD_PARA, DE_RING
#define _LOWER_R4_L       DE_COLN, ALT_ENT, RIGHT
#define _LOWER_R4_R       DE_COLN, _______, RIGHT

/*
 *  LAYER 18  _LOWER_L_C
 */
#define _LOWER_C_L1       _LOWER_L1 //DE_ACUT, DE_PROC, DE_QUOT, _______, _______
// #define _LOWER_C_L2       _LOWER_L2
#define _LOWER_C_L3       _LOWER_L3 //DE_RING, DE_AMPR, _______, _______, DE_PLUS
// #define _LOWER_C_L4_L     _LOWER_L4_L
// #define _LOWER_C_L4_R     _LOWER_L4_R

// #define _LOWER_C_R1       _LOWER_R1
// #define _LOWER_C_R2       _LOWER_R2
// #define _LOWER_C_R3       _LOWER_R3
// #define _LOWER_C_R4_L     _LOWER_R4_L
// #define _LOWER_C_R4_R     _LOWER_R4_R


################################################################################
################################################################################


/*
 *  _LEFT
 *                    LEFT                  		       RIGHT
 *   ,----------------------------------.  ,----------------------------------.
 * 1 | MA0  | LC   | MC   | RC   | MA1  |  | RCTL | SC le| SC dn| SC up| SC ri|
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 2 | HOME | PG UP| PG DN| END  | RCTL |  | LCTL | left | down | up   | right|
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 3 | MA2  | CUT  | COPY | PASTE| RSFT |  | MC   | MS le| MS dn| MS up| MS dn|
 *   `-------------+------+------+------|  |------+------+------+-------------'
 * 4               |______| xxxx | xxxx |  | EXEC | LC   | RC   |
 *                 `--------------------'  `--------------------'
 */
#define _LEFT_L1          KC_ACL0, KC_BTN1, KC_BTN2, KC_BTN3, KC_ACL1
#define _LEFT_L2          KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_RCTL
#define _LEFT_L3          KC_ACL2, CTL_X  , CTL_C  , CTL_V  , KC_RSFT
#define _LEFT_L4                            KC_APP , XXXXXXX, XXXXXXX

#define _LEFT_R1          KC_RCTL, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R
#define _LEFT_R2          KC_LCTL, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
#define _LEFT_R3          KC_B   , KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R
#define _LEFT_R4          KC_EXEC, KC_BTN1, KC_BTN3

/*
 *  _LEFT_C
 */
// #define  _LEFT_C_L1       _LEFT_L1
// #define  _LEFT_C_L2       _LEFT_L2
#define _LEFT_C_L3        KC_ACL2, KC_CUT , KC_COPY, KC_PSTE, KC_RSFT
// #define  _LEFT_C_L4       _LEFT_L4

// #define  _LEFT_C_R1       _LEFT_R1
#define _LEFT_C_R2        KC_G   , KC_H   , KC_J   , KC_K   , KC_L
// #define  _LEFT_C_R3       _LEFT_R3
// #define  _LEFT_C_R4       _LEFT_R4


################################################################################
################################################################################


/*
 *  _RIGHT
 *                    LEFT                  		       RIGHT
 *   ,----------------------------------.  ,----------------------------------.
 * 1 | -    | 7    | 8    | 9    | +    |  | -    | $    | £    | €    | ¥    |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 2 | *    | 4    | 5    | 6    | /    |  | *    | F    | E    | F    | BTC  |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 3 | =    | 1    | 2    | 3    | ENTER|  | =    | A    | B    | C    | %    |
 *   `-------------+------+------+------|  |------+------+------+-------------'
 * 4               | 0    | ,    | ENTER|  | :    | ENTER|______|
 *                 `--------------------'  `--------------------'
 */
#define _RIGHT_L1     KC_PMNS, KC_7   , KC_8   , KC_9   , KC_PPLS
#define _RIGHT_L2     KC_PAST, KC_4   , KC_5   , KC_6   , KC_PSLS
#define _RIGHT_L3     KC_PEQL, KC_1   , KC_2   , KC_3   , KC_ENT
#define _RIGHT_L4                       KC_0   , KC_COMM, KC_ENT

#define _RIGHT_R1     KC_PMNS, DE_DLR , CUR_BPN, CUR_EUR, CUR_YEN
#define _RIGHT_R2     KC_PAST, KC_D   , KC_E   , KC_F   , CUR_BIT
#define _RIGHT_R3     KC_PEQL, KC_A   , KC_B   , KC_C   , DE_PERC
#define _RIGHT_R4     DE_COLN, KC_ENT , _______


#endif // nqadnw-basic-layout.h


/*
 *  _STH  _template
 *                    LEFT                  		       RIGHT
 *   ,----------------------------------.  ,----------------------------------.
 * 1 |      |      |      |      |      |  |      |      |      |      |      |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 2 |      |      |      |      |      |  |      |      |      |      |      |
 *   |------+------+------+------+------|  |------+------+------+------+------|
 * 3 |      |      |      |      |      |  |      |      |      |      |      |
 *   `-------------+------+------+------|  |------+------+------+-------------'
 * 4               |      |      |      |  |      |      |      |
 *                 `--------------------'  `--------------------'
 */
