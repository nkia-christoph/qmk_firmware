#prama once


#ifndef NQADNW_COMMON_FUNCTIONS_H
#define NQADNW_COMMON_FUNCTIONS_H


/**
  * This file holds some common NQADNW functions.
  */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

/* // if 2 layers active then activate another layer instead // TODO doesn't work with my configuration atm

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        }
    return true;
*/

    // process dynamic macro recording feature thingy
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    // send  strings, send even more strings when tap dance is disabled
    if (record->event.pressed) {
        switch(keycode) {
            case KS_00:
                send_string(ST_DNUL);
                return false;

/* //disabled because not directly mapped to any keymap
            case KS_SGDH:
                send_string(ST_SGDH);
                return false;
            case KS_DSOM:
                send_string(ST_DSOM);
                return false;
            case KS_LKUK:
                send_string(ST_LKUK);
                return false;
            case KS_DRCS:
                send_string(ST_DRCS);
                return false;
            case KS_MFGN:
                send_string(ST_MFGN);
                return false;
            case KS_HAVL:
                send_string(ST_HAVL);
                return false;
            case KS_BTRS:
                send_string(ST_BTRS);
                return false;
*/

            #ifndef TAP_DANCE_ENABLE // If TD is not enabled, TD_x = KS_x
                case KS_SUDO:
                    send_string(ST_SUDO);
                    return false;
    /*
                case KS_DFN:
                    send_string(ST_DFN);
                    return false;
                case KS_INCL:
                    send_string(ST_INCL);
                    return false;
    */
                case KS_APIS:
                    send_string(ST_APIS);
                    return false;
    /*
                case KS_APUD:
                    send_string(ST_APUD);
                    return false;
                case KS_APUG:
                    send_string(ST_APUG);
                    return false;
    */
                case KS_PMNS:
                    send_string(ST_PMNS);
                    return false;
    /*
                case KS_PSYU:
                    send_string(ST_PSYU);
                    return false;
                case KS_PSYY:
                    send_string(ST_PSYY);
                    return false;
    */
            #endif
        }
    }
    return true;
};


// Tap dance events
// ' "
void TD_VOID_QUOT_DQOT (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_QUOT);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        tap_code(DE_DQOT);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// € $
void TD_VOID_EURO_DLLR (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(CUR_EUR);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        tap_code(DE_DLR);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// ~ ™
void TD_VOID_TILD_UC_TM (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_TILD);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        #ifdef UNICODE_ENABLE
            send_unicode_hex_string(UST_TMK);
        #endif
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// @ ©
void TD_VOID_ATAT_UC_CPR (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_AT);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        #ifdef UNICODE_ENABLE
            send_unicode_hex_string(UST_CPR);
        #endif
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// § ®
void TD_VOID_PARA_UC_RTM (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_PARA);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        #ifdef UNICODE_ENABLE
            send_unicode_hex_string(UST_RTM);
        #endif
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}


// ()
void TD_VOID_LPRN_RPRN (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_LPRN);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        tap_code(DE_RPRN);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        tap_code(DE_LPRN);
        tap_code(DE_RPRN);
        tap_code(KC_LEFT);
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// []
void TD_VOID_LBRC_RBRC (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_LBRC);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        tap_code(DE_RBRC);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        tap_code(DE_LBRC);
        tap_code(DE_RBRC);
        tap_code(KC_LEFT);
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// {}
void TD_VOID_LCBR_RCBR (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_LCBR);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        tap_code(DE_RCBR);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        tap_code(DE_LCBR);
        tap_code(DE_RCBR);
        tap_code(KC_LEFT);
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// <>
void TD_VOID_LESS_MORE (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(DE_LESS);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        tap_code(DE_MORE);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 3) {
        tap_code(DE_LESS);
        tap_code(DE_MORE);
        tap_code(KC_LEFT);
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// sudo
// #define
// #include
void TD_VOID_SUDO_DFNE_INCL (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_string(ST_SUDO);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_DFNE);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_INCL);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 4) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// apt-get install
// apt-get update
// apt-get upgrade
void TD_VOID_APT_GET (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_string(ST_APIS);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_APUD);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_APUG);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 4) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// pacman -S
// pacman -Syu
// pacman -Syyuu
void TD_VOID_PACMAN (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_string(ST_PMNS);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_PSYU);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_PSYY);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 4) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

void TD_VOID_GREET_NICE (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F3);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_SGDH);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_DSOM);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 4) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

void TD_VOID_GREET_WORK (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F2);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_LKUK);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_DRCS);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 4) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

void TD_VOID_EML (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F11);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_EML0);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_EML1);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 4) {
        send_string(ST_EML2);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 5) {
        send_string(ST_EML3);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 6) {
        send_string(ST_EML4);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 7) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

void TD_VOID_BYE (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F10);
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        send_string(ST_MFGN);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        send_string(ST_BTRS);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 4) {
        send_string(ST_HAVL);
        SEND_STRING(SS_DOWN(X_LSHIFT)SS_TAP(X_ENTER)SS_UP(X_LSHIFT));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 5) {
        break; // reset_tap_dance (state); // TODO CHECK
    }
}

// GUI lock
// switch default layer
void TD_VOID_GLCK_CD_STNDRD (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code (LGUI(KC_L));
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 2) {
        if (default_layer == _BASE) {
            switch_default_layer(_CODE);
        } else if (default_layer == _CODE) {
            switch_default_layer(_BASE);
        }
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count == 3) {
        break; // reset_tap_dance (state); // TODO CHECK
    } else if (state->count >= 4) {
        if (default_layer != _STNDRD) {
            switch_default_layer(_STNDRD);
        } else {
            switch_default_layer(_BASE);
        }
        break; // reset_tap_dance (state); // TODO CHECK
    }
}


// Tap dance definitions HAS TO BE AT THE END according to the docs
#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
    [QOT] = ACTION_TAP_DANCE_FN(TD_VOID_QUOT_DQOT  ),
    [CUR] = ACTION_TAP_DANCE_FN(TD_VOID_EURO_DLLR  ),
    [TLD] = ACTION_TAP_DANCE_FN(TD_VOID_TILD_UC_TM ),
    [AT]  = ACTION_TAP_DANCE_FN(TD_VOID_ATAT_UC_CPR),
    [PAR] = ACTION_TAP_DANCE_FN(TD_VOID_PARA_UC_RTM),

    [BR1] = ACTION_TAP_DANCE_FN(TD_VOID_LPRN_RPRN),
    [BR2] = ACTION_TAP_DANCE_FN(TD_VOID_LBRC_RBRC),
    [BR3] = ACTION_TAP_DANCE_FN(TD_VOID_LCBR_RCBR),
    [BR4] = ACTION_TAP_DANCE_FN(TD_VOID_LESS_MORE),

    [GUI] = ACTION_TAP_DANCE_FN(TD_VOID_GLCK_CD_STNDRD),
    [SDO] = ACTION_TAP_DANCE_FN(TD_VOID_SUDO_DFNE_INCL),
    [APT] = ACTION_TAP_DANCE_FN(TD_VOID_APT_GET       ),
    [PCM] = ACTION_TAP_DANCE_FN(TD_VOID_PACMAN        ),
/*
    [QOT] = ACTION_TAP_DANCE_DOUBLE(DE_QUOT, DE_DQOT), // won't work acc. to drashna
    [CUR] = ACTION_TAP_DANCE_DOUBLE(CUR_EUR, DE_DLR ), // won't work acc. to drashna

    [BR1] = ACTION_TAP_DANCE_DOUBLE(DE_LPRN, DE_RPRN), // won't work acc. to drashna
    [BR2] = ACTION_TAP_DANCE_DOUBLE(DE_LBRC, DE_RBRC), // won't work acc. to drashna
    [BR3] = ACTION_TAP_DANCE_DOUBLE(DE_LCBR, DE_RCBR), // won't work acc. to drashna
    [BR4] = ACTION_TAP_DANCE_DOUBLE(DE_LESS, DE_MORE), // won't work acc. to drashna
*/
    [GTN] = ACTION_TAP_DANCE_FN(TD_VOID_GREET_NICE),
    [GTW] = ACTION_TAP_DANCE_FN(TD_VOID_GREET_WORK),
    [EML] = ACTION_TAP_DANCE_FN(TD_VOID_EML),
    [BYE] = ACTION_TAP_DANCE_FN(TD_VOID_BYE)
};
#endif // TAP_DANCE_ENABLE


#endif // nqadnw-common-functions.h
