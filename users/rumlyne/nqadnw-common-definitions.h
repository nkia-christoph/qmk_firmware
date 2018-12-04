#pragma once


#ifndef NQADNW_COMMON_DEFINITIONS_H
#define NQADNW_COMMON_DEFINITIONS_H


/*
 * This file holds some common NQADNW definitions.
 */


// Error prevention
#define ______   KC_TRNS
#define _______  KC_TRNS
#define ________ KC_TRNS
#define XXXXXX   KC_NO
#define XXXXXXX  KC_NO
#define XXXXXXXX KC_NO


// NQADNW specific layer MODs
#define RS_L      LT(RAISE, KC_SPC) // access _RAISE via left MOD
#define RS_L_C    LT(RAISE_C, KC_SPC) // access _RAISE_C via left MOD on _CODE layer
#define RS_R      LT(RAISE, KC_DOT) // access _RAISE via right MOD
#define RS_R_C    LT(RAISE_C, KC_DOT) // access _RAISE_C via right MOD on _CODE layer
#define LW_L      LT(LOWER, KC_COMM) // access _LOWER via left MOD
#define LW_L_C    LT(LOWER_C, KC_COMM) // access _LOWER_C via left MOD on _CODE layer
#define LW_R      LT(LOWER, KC_ENT) // access _LOWER via right MOD
#define LW_R_C    LT(LOWER_C, KC_ENT) // access _LOWER_C via right MOD on _CODE layer
#define LEFT      TT(_LEFT)
#define RIGHT     LT(_RIGHT, TG(_RIGHT))
#define CODE      TT(_CODE) // TODO TOGGLE _CODE/_BASE/_STNDRD


// Important modded keys
#define C_A_DEL		ALTG(KC_DEL)
#define ALT_F4		LALT(KC_F4)

#define GUI_LCK		LGUI(KC_L)
#define GUI_TAB		LGUI(KC_TAB)
#define ALT_TAB 	LALT(KC_TAB)
#define SH_TAB		LS‎FT(KC_TAB)
#define SH_ENT		LS‎FT(KC_ENT)
#define SH_BSPC		LS‎FT(KC_BSPC)
#define SP_TAB    F(M_SPC_TAB) // TODO Macro
#define ALT_ENT   LALT(KC_ENT)

#define CTL_X     LCTL(KC_X)
#define CTL_C     LCTL(KC_C)
#define CTL_V     LCTL(KC_V)

#define SH_HOME		LS‎FT(KC_HOME)
#define SH_END		LS‎FT(KC_END)
#define SH_PGUP		LS‎FT(KC_PGUP)
#define SH_PGDN		LS‎FT(KC_PGDN)

#define C_HOME    LCTL(KC_HOME)
#define C_END     LCTL(KC_END)
#define C_PGUP    LCTL(KC_PGUP)
#define C_PGDN    LCTL(KC_PGDN)


// Shifted characters
#define SH_A LSFT(KC_A)
#define SH_B LSFT(KC_B)
#define SH_C LSFT(KC_C)
#define SH_D LSFT(KC_D)
#define SH_E LSFT(KC_E)
#define SH_F LSFT(KC_F)
#define SH_G LSFT(KC_G)
#define SH_H LSFT(KC_H)
#define SH_I LSFT(KC_I)
#define SH_J LSFT(KC_J)
#define SH_K LSFT(KC_K)
#define SH_L LSFT(KC_L)
#define SH_M LSFT(KC_M)
#define SH_N LSFT(KC_N)
#define SH_O LSFT(KC_O)
#define SH_P LSFT(KC_P)
#define SH_Q LSFT(KC_Q)
#define SH_R LSFT(KC_R)
#define SH_S LSFT(KC_S)
#define SH_T LSFT(KC_T)
#define SH_U LSFT(KC_U)
#define SH_V LSFT(KC_V)
#define SH_W LSFT(KC_W)
#define SH_X LSFT(KC_X)
#define SH_Y LSFT(DE_Y)
#define SH_Z LSFT(DE_Z)

#define SH_AE LSFT(DE_AE)
#define SH_UE LSFT(DE_UE)
#define SH_OE LSFT(DE_OE)


//Saving space for human readability
#define SYSREQ KC_SYSREQ
#define RETURN KC_RETURN
#define CANCEL KC_CANCEL
#define KC_CLA KC_CLEAR_AGAIN
#define DM_RC1 DYN_REC_START1
#define DM_RC2 DYN_REC_START2
#define DM_PB1 DYN_MACRO_PLAY1
#define DM_PB2 DYN_MACRO_PLAY2
#define DM_STP DYN_REC_STOP


// Define non-capitalized UTF shortcuts here
#ifdef UNICODE_ENABLE
// #define PHY_HBR UC(0x0127)
// #define PHY_DEG UC(0x00b0)
// #define CUR_LIR UC(0x20ba)
#define CUR_BIT UC(0x20bf) // ₿ Bitcoin
#define CUR_EUR KC_RALT(KC_E) // UC(0x20ac) // €
#define CUR_BPN UC(0x00a3) // £
#define CUR_YEN UC(0x00a5) // ¥
#define UC_TM   UC(0x2122) // ™
#define UC_RTM  UC(0x00b0) // ®
#define UC_CPR  UC(0x00ae) // ©
#else
// #define PHY_HBR KC_NO
// #define PHY_DEG KC_NO
// #define CUR_LIR KC_NO
#define CUR_BIT KC_NO
#define CUR_EUR KC_RALT(KC_E)
#define CUR_BPN KC_NO
#define CUR_YEN KC_NO
#define UC_TM   KC_NO // TODO ab hier
#define UC_RTM  KC_NO
#define UC_CPR  KC_NO
#endif


################################################################################
################################################################################


// Tap dance declarations
#ifdef TAP_DANCE_ENABLE
    enum {
        QOT = 0,
        CUR,
        TLD,
        AT,
        PAR,
        SDO,
        APT,
        PCM,
        GUI,

        BR1, //bracket 1,2,3,4
        BR2,
        BR3,
        BR4,
        ARH, //arrow H,J,K,L
        ARJ,
        ARK,
        ARL
    };
    #define TD_QUOT TD(QOT)
    #define TD_CUR  TD(CUR)
    #define TD_TILD TD(TLD)
    #define TD_AT   TD(AT)
    #define TD_PARA TD(PAR)
    #define TD_SUDO TD(SDO)
    #define TD_APTG TD(APT)
    #define TD_PCMN TD(PCM)
    #define TD_GUI  TD(GUI)

    #define TD_BR1  TD(BR1)
    #define TD_BR2  TD(BR2)
    #define TD_BR3  TD(BR3)
    #define TD_BR4  TD(BR4)
    #define BR_ARRH KC_LEFT
    #define BR_ARRJ KC_DOWN
    #define BR_ARRK KC_UP
    #define BR_ARRL KC_RGHT
#else
    #define TD_QUOT DE_QUOT
    #define TD_CUR  CUR_EUR
    #define TD_TILD DE_TILD
    #define TD_AT   DE_AT
    #define TD_PARA DE_PARA
    #define TD_SUDO KS_SUDO
    #define TD_APTG KS_APIS
    #define TD_PCMN KS_PMNS
    #define TD_GUI  GUI_LCK

    #define TD_BR1  DE_LPRN
    #define TD_BR2  DE_LBRC
    #define TD_BR3  DE_LCBR
    #define TD_BR4  DE_LESS
    #define BR_ARRH DE_RPRN
    #define BR_ARRJ DE_RBRC
    #define BR_ARRK DE_RCBR
    #define BR_ARRL DE_MORE
#endif // TAP_DANCE_ENABLE


// String keycodes & dynaminc macro dependancy
enum custom_keycodes {
  KS_00 = SAFE_RANGE,
  KS_SUDO, // sudo
  // KS_DFN, // #define
  // KS_INCL, // #include
  KS_APIS, // apt-get install
  // KS_APUD, // apt-get update
  // KS_APUG, // apt-get upgrade
  KS_PMNS, // pacman -S
  // KS_PSYU, // pacman -Syu
  // KS_PSYY // pacman -Syyuu

  DYNAMIC_MACRO_RANGE // necessary for dynamic macros according to QMK guide
};


// Strings
char ST_DNUL[2]  = "00"

char ST_SUDO[5]  = "sudo "
char ST_DFNE[8]  = "#define "
char ST_INCL[9]  = "#include "

char ST_APIS[16] = "apt-get install "
char ST_APUD[15] = "apt-get update "
char ST_APUG[16] = "apt-get upgrade "
char ST_PMNS[10] = "pacman -S "
char ST_PSYU[12] = "pacman -Syu "
char ST_PSYY[14] = "pacman -Syyuu "

/* not yet assigned TODO
char ST_SGDH[31] = "Sehr geehrte Damen und Herren, ";
char ST_DSOM[19] = "Dear sir or madam, ";
char ST_LKUK[32] = "Liebe Kolleginnen und Kollegen, ";
char ST_DRCS[16] = "Dear collegues, ";
char ST_MFGN[24] = "Mit freundlichen Grüßen ";
char ST_HAVL[17] = "Hochachtungsvoll ";
char ST_BTRS[14] = "Best regards, ";
*/

################################################################################
################################################################################



#endif // nqadnw-common-definitions.h
