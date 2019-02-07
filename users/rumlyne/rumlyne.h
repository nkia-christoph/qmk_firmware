#pragma once


#include "keymap_german.h"
//#include <sendstring_german.h>
#include "quantum.h"
#include "action.h"


#ifdef TAP_DANCE_ENABLE
    enum /*tap_key*/ {
        QOT = 0,
        CUR,
        TLD,
        AT,
        PAR,
        SDO,
        APT,
        PCM,
        GUI,

        UCS,
        AF4,
        GTN,
        GTW,
        EML,
        BYE,

        BR1, //bracket 1,2,3,4
        BR2,
        BR3,
        BR4,
        ARH, //arrow H,J,K,L
        ARJ,
        ARK,
        ARL
    };

#endif // TAP_DANCE_ENABLE


enum userspace_layers {
  _BASE = 0,	// Programmer BUX // default
  _JPNS,      // 2 // Japanese Kana layout based on esrilles new stickney layout // TODO FUTURE
  _CODE,      // 3	// Code friendly layer
  _STD,    // 4  // QWERTZ, QWERTY, AZERTY, etc.

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

// Error prevention
#define ______   KC_TRNS
#define ________ KC_TRNS
#define XXXXXX   KC_NO
#define XXXXXXXX KC_NO

// NQADNW specific layer MODs
#define RS_L      LT(_RAISE_L, KC_SPC) // access _RAISE via left MOD
#define RS_L_C    LT(_RAISE_L_C, KC_SPC) // access _RAISE_C via left MOD on _CODE layer
#define RS_R      LT(_RAISE_R, KC_DOT) // access _RAISE via right MOD
#define RS_R_C    LT(_RAISE_R_C, KC_DOT) // access _RAISE_C via right MOD on _CODE layer
#define LW_L      LT(_LOWER_L, KC_COMM) // access _LOWER via left MOD
#define LW_L_C    LT(_LOWER_L_C, KC_COMM) // access _LOWER_C via left MOD on _CODE layer
#define LW_R      LT(_LOWER_R, KC_ENT) // access _LOWER via right MOD
#define LW_R_C    LT(_LOWER_L_C, KC_ENT) // access _LOWER_C via right MOD on _CODE layer
#define LEFT      TT(_LEFT)
#define RIGHT     LT(_RIGHT, /*TG(_RIGHT)*/KC_NO) // TODO FUTURE
//#define CODE      TT(_CODE)

// Important modded keys
#define C_A_DEL		RALT(KC_DEL)
#define ALT_F4		LALT(KC_F4)

#define GUI_LCK		LGUI(KC_L)
#define GUI_TAB		LGUI(KC_TAB)
#define ALT_TAB 	LALT(KC_TAB)
#define SH_TAB		S(KC_TAB)
#define SH_ENT		S(KC_ENT)
#define SH_BSPC		S(KC_BSPC)
#define ALT_ENT   LALT(KC_ENT)
#define ALT_MCR   RALT(KC_M)

#define CTL_X     LCTL(KC_X)
#define CTL_C     LCTL(KC_C)
#define CTL_V     LCTL(KC_V)

#define SH_HOME		S(KC_HOME)
#define SH_END		S(KC_END)
#define SH_PGUP		S(KC_PGUP)
#define SH_PGDN		S(KC_PGDN)

#define C_HOME    LCTL(KC_HOME)
#define C_END     LCTL(KC_END)
#define C_PGUP    LCTL(KC_PGUP)
#define C_PGDN    LCTL(KC_PGDN)

// Shifted characters for shift layer
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


//Future raised numbers
#define RA_0 KC_0
#define RA_1 KC_1
#define RA_2 KC_2
#define RA_3 KC_3
#define RA_4 KC_4
#define RA_5 KC_5
#define RA_6 KC_6
#define RA_7 KC_7
#define RA_8 KC_8
#define RA_9 KC_9


//Saving space for human readability
#define SYSREQ KC_SYSREQ
#define RETURN KC_RETURN
#define CANCEL KC_CANCEL
#define KC_CLA KC_CLEAR_AGAIN
#define DM_RC1 KC_NO//DYN_REC_START1
#define DM_RC2 KC_NO//DYN_REC_START2
#define DM_PB1 KC_NO//DYN_MACRO_PLAY1
#define DM_PB2 KC_NO//DYN_MACRO_PLAY2
#define DM_STP KC_NO//DYN_REC_STOP


// Define non-capitalized UTF shortcuts here
#ifdef UNICODE_ENABLE
  // #define PHY_HBR UC(UST_HBR)
  // #define PHY_DEG UC(UST_DEG)
  // #define CUR_LIR UC(UST_LIR)
  #define CUR_BIT UC(UST_BIT) // ₿ Bitcoin
  #define CUR_EUR RALT(KC_E) // UC(0x20ac) // €
  #define CUR_BPN UC(UST_BPN) // £
  #define CUR_YEN UC(UST_YEN) // ¥
  #define UC_TMK  UC(UST_TMK) // ™
  #define UC_RTM  UC(UST_RTM) // ®
  #define UC_CPR  UC(UST_CPR) // ©
#else
  // #define PHY_HBR KC_NO
  // #define PHY_DEG KC_NO
  // #define CUR_LIR KC_NO
  #define CUR_BIT KC_NO
  #define CUR_EUR RALT(KC_E)
  #define CUR_BPN KC_NO
  #define CUR_YEN KC_NO
  #define UC_TMK  KC_NO
  #define UC_RTM  KC_NO
  #define UC_CPR  KC_NO
#endif


// Tap dance declarations
#ifdef TAP_DANCE_ENABLE

  #define TD_QUOT TD(QOT)
  #define TD_CUR  TD(CUR)
  #define TD_TILD TD(TLD)
  #define TD_AT   TD(AT)
  #define TD_PARA TD(PAR)
  #define TD_SUDO TD(SDO)
  #define TD_APTG TD(APT)
  #define TD_PCMN TD(PCM)
  #define TD_GUI  TD(GUI)

  #define TD_F2   TD(GTW)
  #define TD_F3   TD(GTN)
  #define TD_F4   TD(AF4)

  #define TD_F9   TD(UCS)
  #define TD_F10  TD(BYE)
  #define TD_F11  TD(EML)

  #define TD_BR1  TD(BR1)
  #define TD_BR2  TD(BR2)
  #define TD_BR3  TD(BR3)
  #define TD_BR4  TD(BR4)
  #define BR_ARRH KC_LEFT
  #define BR_ARRJ KC_DOWN
  #define BR_ARRK KC_UP
  #define BR_ARRL KC_RGHT
  enum custom_keycodes {
      NEW_SAFE_RANGE = SAFE_RANGE
  };
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

  #define TD_F2   KC_F2
  #define TD_F3   KC_F3
  #define TD_F4   KC_F4

  #define TD_F9   KC_F9
  #define TD_F10  KC_F10
  #define TD_F11  KC_F11

  #define TD_BR1  DE_LPRN
  #define TD_BR2  DE_LBRC
  #define TD_BR3  DE_LCBR
  #define TD_BR4  DE_LESS
  #define BR_ARRH DE_RPRN
  #define BR_ARRJ DE_RBRC
  #define BR_ARRK DE_RCBR
  #define BR_ARRL DE_MORE
  enum custom_keycodes {
      NEW_SAFE_RANGE = SAFE_RANGE
  };
#endif // TAP_DANCE_ENABLE


// String keycodes & dynaminc macro dependancy
enum more_custom_keycodes {
  KS_00 = NEW_SAFE_RANGE, // necessary for dynamic macros according to QMK guide

  #ifndef TAP_DANCE_ENABLE
    KS_SGDH,
    KS_DSOM,
    KS_LKUK,
    KS_DRCS,
    KS_MFGN,
    KS_HAVL,
    KS_BTRS,

    KS_SUDO, // sudo
    // KS_DFN, // #define
    // KS_INCL, // #include
    KS_APIS, // apt-get install
    // KS_APUD, // apt-get update
    // KS_APUG, // apt-get upgrade
    KS_PMNS, // pacman -S
    // KS_PSYU, // pacman -Syu
    // KS_PSYY // pacman -Syyuu
  #endif

  /*DYNAMIC_MACRO_RANGE,*/
  NEW_NEW_SAFE_RANGE
};


static const char ST_EML_UNAME1[10] = "xxxxxxxxxx";
static const char ST_EML_UNAME2[17] = "xxxxxxxxxxxxxxxxx";
static const char ST_EML_UNAME3[7]  = "xxxxxxx";
/*
static const char ST_EML_UNAME[3] = {
    "xxxxxxxxxx",
    "xxxxxxxxxxxxxxxxx",
    "xxxxxxx"
};
*/

static const char ST_EML_DOMAIN1[9] = "xxxxxxxxx";
static const char ST_EML_DOMAIN2[6] = "xxxxxx";
static const char ST_EML_DOMAIN3[6] = "xxxxxx";
static const char ST_EML_DOMAIN4[6] = "xxxxxx";
/*
static const char ST_EML_DOMAIN[4] = {
    "xxxxxxxxx",
    "xxxxxx",
    "xxxxxx",
    "xxxxxx"
};
*/


static const char ST_DNUL[2]  = "00";

static const char ST_SUDO[5]  = "sudo ";
static const char ST_DFNE[8]  = "#define ";
static const char ST_INCL[9]  = "#include ";

static const char ST_APIS[16] = "apt-get install ";
static const char ST_APUD[15] = "apt-get update ";
static const char ST_APUG[16] = "apt-get upgrade ";
static const char ST_PMNS[10] = "pacman -S ";
static const char ST_PSYU[12] = "pacman -Syu ";
static const char ST_PSYY[14] = "pacman -Syyuu ";

static const char ST_SGDH[31] = "Sehr geehrte Damen und Herren, ";
static const char ST_LKUK[32] = "Liebe Kolleginnen und Kollegen, ";
static const char ST_MFG1[20] = "Mit freundlichen Gr["; // see quantum/keymap_extras/sendstring_german
static const char ST_MFG2[3] = "en ";
static const char ST_HAVL[17] = "Hochachtungsvoll ";

static const char ST_DSOM[19] = "Dear sir or madam, ";
static const char ST_DRCS[16] = "Dear collegues, ";
static const char ST_BTRS[14] = "Best regards, ";

/*
static const char * const ST_DEGR[] = {
    "Sehr geehrte Damen und Herren, ",
    "Liebe Kolleginnen und Kollegen, ",
    "Mit freundlichen Grüßen "
};

static const char macros[] = {
    [ST_DNUL] = "00",

    [ST_SUDO] = "sudo ",
    [ST_DFNE] = "#define ",
    [ST_INCL] = "#include ",

    [ST_APIS] = "apt-get install",
    [ST_APUD] = "apt-get update",
    [ST_APUG] = "apt-get upgrade",
    [ST_PMNS] = "pacman -S ",
    [ST_PSYU] = "pacman -Syu ",
    [ST_PSYY] = "pacman -Syyuu ",

    [ST_SGDH] = "Sehr geehrte Damen und Herren, ",
    [ST_LKUK] = "Liebe Kolleginnen und Kollegen, ",
    [ST_MFG1] = "Mit freundlichen Gr[", // see quantum/keymap_extras/sendstring_german
    [ST_MFG2] = "en ",
    [ST_HAVL] = "Hochachtungsvoll ",

    [ST_DSOM] = "Dear sir or madam, ",
    [ST_DRCS] = "Dear collegues, ",
    [ST_BTRS] = "Best regards, "
};
*/


#ifdef UNICODE_ENABLE

  enum unicode_name {
    //UST_HBR, //
    //UST_DEG, //
    //UST_LIR, //
    UST_BIT, // ₿ Bitcoin
    //UST_EUR, // €
    UST_BPN, // £
    UST_YEN, // ¥
    UST_TMK, // ™
    UST_RTM, // ®
    UST_CPR  // ©
  };

  static const uint16_t PROGMEM unicode_map[] = { //16 enough? Probably yes
    //[UST_HBR] = 0x0127,
    //[UST_DEG] = 0x00B0,
    //[UST_LIR] = 0x20BA,
    [UST_BIT] = 0x20BF, // ₿ Bitcoin
    //[UST_EUR] = 0x20AC, // €
    [UST_BPN] = 0x00A3, // £
    [UST_YEN] = 0x00A5, // ¥
    [UST_TMK] = 0x2122, // ™
    [UST_RTM] = 0x00B0, // ®
    [UST_CPR] = 0x00AE  // ©
  };


#endif // UNICODE_ENABLE
