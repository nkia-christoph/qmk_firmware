#include "quantum.h"
//#include "dynamic_macro.h"`
#include "action.h"
//#include "rumlyne.h"
#include "nqadnw_basic_layout.h"


__attribute__ ((weak))
void matrix_init_keymap(void) {}


void matrix_init_user(void) {
  matrix_init_keymap();
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
    // process dynamic macro recording feature thingy
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
*/

    // send  strings, send even more strings when tap dance is disabled
    switch(keycode) {
        case KS_00:
            if (record->event.pressed) {
                send_string_with_delay(ST_DNUL);
                return false;

/* disabled because not directly mapped to any keymap
            case KS_SGDH:
                send_string_with_delay(ST_SGDH);
                return false;
            case KS_DSOM:
                send_string_with_delay(ST_DSOM);
                return false;
            case KS_LKUK:
                send_string_with_delay(ST_LKUK);
                return false;
            case KS_DRCS:
                send_string_with_delay(ST_DRCS);
                return false;
            case KS_MFGN:
                send_string_with_delay(ST_MFG1);
                return false;
            case KS_HAVL:
                send_string_with_delay(ST_HAVL);
                return false;
            case KS_BTRS:
                send_string_with_delay(ST_BTRS);
                return false;
*/

            #ifndef TAP_DANCE_ENABLE // If TD is not enabled, TD_x = KS_x
                case KS_SUDO:
                    send_string_with_delay(ST_SUDO);
                    return false;
    /*
                case KS_DFN:
                    send_string_with_delay(ST_DFN);
                    return false;
                case KS_INCL:
                    send_string_with_delay(ST_INCL);
                    return false;
    */
                case KS_APIS:
                    send_string_with_delay(ST_APIS);
                    return false;
    /*
                case KS_APUD:
                    send_string_with_delay(ST_APUD);
                    return false;
                case KS_APUG:
                    send_string_with_delay(ST_APUG);
                    return false;
    */
                case KS_PMNS:
                    send_string_with_delay(ST_PMNS);
                    return false;
    /*
                case KS_PSYU:
                    send_string_with_delay(ST_PSYU);
                    return false;
                case KS_PSYY:
                    send_string_with_delay(ST_PSYY);
                    return false;
    */
            #endif // TAP_DANCE_ENABLE

        }
    }
    return true;
};


#ifdef TAP_DANCE_ENABLE

// Tap dance events
// ' "
void td_quot_dqot (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(DE_QUOT);

        register_code(KC_LSFT);
        tap_code(KC_BSLS/*DE_HASH*/);
        unregister_code(KC_LSFT);
    } else if (state->count == 2) {
        clear_mods();
        //tap_code(DE_DQOT);

        register_code(KC_LSFT);
        tap_code(KC_2);
        unregister_code(KC_LSFT);
    } else if (state->count == 3) {
        clear_mods();
        //tap_code(DE_DQOT);
        //tap_code(DE_DQOT);

        register_code(KC_LSFT);
        tap_code(KC_2);
        tap_code(KC_2);
        unregister_code(KC_LSFT);
        tap_code(KC_LEFT);
    } else if (state->count == 4) {
        clear_mods();
        //tap_code(DE_QUOT);
        //tap_code(DE_QUOT);

        register_code(KC_LSFT);
        tap_code(KC_BSLS/*DE_HASH*/);
        tap_code(KC_BSLS/*DE_HASH*/);
        unregister_code(KC_LSFT);
        tap_code(KC_LEFT);
    } else if (state->count >= 5) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// € $
void td_euro_dllr (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(CUR_EUR);

        register_code(KC_RALT);
        tap_code(KC_E);
        unregister_code(KC_RALT);
    } else if (state->count == 2) {
        clear_mods();
        //tap_code(DE_DLR);

        register_code(KC_LSFT);
        tap_code(KC_4);
        unregister_code(KC_LSFT);
    } else if (state->count >= 3) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// ~ ™
void td_tild_uc_tm (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(DE_TILD);

        register_code(KC_RALT);
        tap_code(KC_RBRC/*DE_PLUS*/);
        unregister_code(KC_RALT);
    } else if (state->count == 2) {
        #ifdef UNICODE_ENABLE
            unicode_input_start();
            register_hex(UST_TMK);
            unicode_input_finish();
        #else
            clear_mods();
            register_code(KC_RALT);
            tap_code(KC_RBRC/*DE_PLUS*/);
            unregister_code(KC_RALT);
        #endif // UNICODE_ENABLE
    } else if (state->count >= 3) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// @ ©
void td_at_uc_cpr (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        //tap_code(DE_AT);

        register_code(KC_RALT);
        tap_code(KC_Q);
        unregister_code(KC_RALT);
    } else if (state->count == 2) {
        #ifdef UNICODE_ENABLE
            unicode_input_start();
            register_hex(UST_CPR);
            unicode_input_finish();
        #else
            clear_mods();
            register_code(KC_RALT);
            tap_code(KC_Q);
            unregister_code(KC_RALT);
        #endif // UNICODE_ENABLE
    } else if (state->count >= 3) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// § ®
void td_para_uc_rtm (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(DE_PARA);

        register_code(KC_LSFT);
        tap_code(KC_3);
        unregister_code(KC_LSFT);
    } else if (state->count == 2) {
        #ifdef UNICODE_ENABLE
            unicode_input_start();
            register_hex(UST_RTM);
            unicode_input_finish();
        #else
            clear_mods();
            register_code(KC_LSFT);
            tap_code(KC_3);
            unregister_code(KC_LSFT);
        #endif
    } else if (state->count >= 3) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// ()
void td_lprn_rprn (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(DE_LPRN);

        register_code(KC_LSFT);
        tap_code(KC_8);
        unregister_code(KC_LSFT);
    } else if (state->count == 2) {
        clear_mods();
        //tap_code(DE_RPRN);

        register_code(KC_LSFT);
        tap_code(KC_9);
        unregister_code(KC_LSFT);
    } else if (state->count == 3) {
        clear_mods();
        //tap_code(DE_LPRN);
        //tap_code(DE_RPRN);

        register_code(KC_LSFT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_LSFT);
    } else if (state->count == 4) {
        clear_mods();
        //tap_code(DE_LPRN);
        //tap_code(DE_RPRN);

        register_code(KC_LSFT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_LSFT);

        tap_code(KC_LEFT);
    } else if (state->count >= 5) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// []
void td_lbrc_rbrc (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(DE_LBRC);

        register_code(KC_RALT);
        tap_code(KC_8);
        unregister_code(KC_RALT);
    } else if (state->count == 2) {
        clear_mods();
        //tap_code(DE_RBRC);

        register_code(KC_RALT);
        tap_code(KC_9);
        unregister_code(KC_RALT);
    } else if (state->count == 3) {
        clear_mods();
        //tap_code(DE_LBRC);
        //tap_code(DE_RBRC);

        register_code(KC_RALT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_RALT);
    } else if (state->count == 4) {
        clear_mods();
        //tap_code(DE_LBRC);
        //tap_code(DE_RBRC);

        register_code(KC_RALT);
        tap_code(KC_8);
        tap_code(KC_9);
        unregister_code(KC_RALT);

        tap_code(KC_LEFT);
    } else if (state->count >= 5) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// {}
void td_lcbr_rcbr (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        //tap_code(DE_LCBR);

        register_code(KC_RALT);
        tap_code(KC_7);
        unregister_code(KC_RALT);
    } else if (state->count == 2) {
        clear_mods();
        //tap_code(DE_RCBR);

        register_code(KC_RALT);
        tap_code(KC_0);
        unregister_code(KC_RALT);
    } else if (state->count == 3) {
        clear_mods();
        //tap_code(DE_LCBR);
        //tap_code(DE_RCBR);

        register_code(KC_RALT);
        tap_code(KC_7);
        tap_code(KC_0);
        unregister_code(KC_RALT);
    } else if (state->count == 4) {
        clear_mods();
        //tap_code(DE_LCBR);
        //tap_code(DE_RCBR);

        register_code(KC_RALT);
        tap_code(KC_7);
        tap_code(KC_0);
        unregister_code(KC_RALT);

        tap_code(KC_LEFT);
    } else if (state->count >= 5) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// <>
void td_less_more (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        tap_code(KC_NUBS/*DE_LESS*/);
    } else if (state->count == 2) {
        clear_mods();
        //tap_code(DE_MORE);

        register_code(KC_LSFT);
        tap_code(KC_NUBS/*DE_LESS*/);
        unregister_code(KC_LSFT);
    } else if (state->count == 3) {
        clear_mods();
        tap_code(KC_NUBS/*DE_LESS*/);

        //tap_code(DE_MORE);
        register_code(KC_LSFT);
        tap_code(KC_NUBS/*DE_LESS*/);
        unregister_code(KC_LSFT);
    } else if (state->count == 4) {
        clear_mods();
        tap_code(KC_NUBS/*DE_LESS*/);

        //tap_code(DE_MORE);
        register_code(KC_LSFT);
        tap_code(KC_NUBS/*DE_LESS*/);
        unregister_code(KC_LSFT);

        tap_code(KC_LEFT);
    } else if (state->count >= 5) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// sudo
// #define
// #include
void td_sudo_dfne_incl (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_string_with_delay(ST_SUDO);
    } else if (state->count == 2) {
        send_string_with_delay(ST_DFNE);
    } else if (state->count == 3) {
        send_string_with_delay(ST_INCL);
    } else if (state->count >= 4) {
        reset_tap_dance (state);
    }
    reset_tap_dance(state);
}

// apt-get install
// apt-get update
// apt-get upgrade
void td_apt_get (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_string_with_delay(ST_APIS);
    } else if (state->count == 2) {
        send_string_with_delay(ST_APUD);
    } else if (state->count == 3) {
        send_string_with_delay(ST_APUG);
    } else if (state->count >= 4) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// pacman -S
// pacman -Syu
// pacman -Syyuu
void td_pacman (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        send_string_with_delay(ST_PMNS);
    } else if (state->count == 2) {
        send_string_with_delay(ST_PSYU);
    } else if (state->count == 3) {
        send_string_with_delay(ST_PSYY);
    } else if (state->count >= 4) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

void td_greet_nice (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        tap_code(KC_F3);
    } else if (state->count == 2) {
        clear_mods();
        send_string_with_delay(ST_SGDH);
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count == 3) {
        clear_mods();
        send_string_with_delay(ST_DSOM);
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count >= 4) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

void td_greet_work (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        tap_code(KC_F2);
    } else if (state->count == 2) {
        clear_mods();
        send_string_with_delay(ST_LKUK);
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count == 3) {
        clear_mods();
        send_string_with_delay(ST_DRCS);
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count >= 4) {
        reset_tap_dance (state);
    }
    reset_tap_dance(state);
}

void td_email (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        tap_code(KC_F11);
    } else if (state->count == 2) {
        clear_mods();

        send_string_with_delay(ST_EML_UNAME1);

        register_code(KC_RALT);
        tap_code(KC_Q);
        unregister_code(KC_RALT);

        send_string_with_delay(ST_EML_DOMAIN2);
    } else if (state->count == 3) {
        clear_mods();

        send_string_with_delay(ST_EML_UNAME2);

        register_code(KC_RALT);
        tap_code(KC_Q);
        unregister_code(KC_RALT);

        send_string_with_delay(ST_EML_DOMAIN3);
    } else if (state->count == 4) {
        clear_mods();

        send_string_with_delay(ST_EML_UNAME3);

        register_code(KC_RALT);
        tap_code(KC_Q);
        unregister_code(KC_RALT);

        send_string_with_delay(ST_EML_DOMAIN2);
    } else if (state->count == 5) {
        clear_mods();

        send_string_with_delay(ST_EML_UNAME2);

        register_code(KC_RALT);
        tap_code(KC_Q);
        unregister_code(KC_RALT);

        send_string_with_delay(ST_EML_DOMAIN1);
    } else if (state->count == 6) {
        clear_mods();

        send_string_with_delay(ST_EML_UNAME2);

        register_code(KC_RALT);
        tap_code(KC_Q);
        unregister_code(KC_RALT);

        send_string_with_delay(ST_EML_DOMAIN4);
    } else if (state->count >= 7) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

void td_bye (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        clear_mods();
        tap_code(KC_F10);
    } else if (state->count == 2) {
        clear_mods();

        send_string_with_delay(ST_MFG1);
        tap_code(KC_MINS/*DE_SS*/);
        send_string_with_delay(ST_MFG2);

        register_code(KC_LSFT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count == 3) {
        send_string_with_delay(ST_BTRS);
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count == 4) {
        send_string_with_delay(ST_HAVL);
        register_code(KC_LSFT);
        tap_code(KC_ENT);
        unregister_code(KC_LSFT);
    } else if (state->count >= 5) {
        reset_tap_dance(state);
    }
    reset_tap_dance(state);
}

// GUI lock
// switch default layer
void td_glck_layer_switch (qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
        case 1:
            clear_mods();
            //tap_code(LGUI(KC_L));

            register_code(KC_LGUI);
            tap_code(KC_L);
            unregister_code(KC_LGUI);
            break;
/* FUTURE
        case 2:
            if (default_layer == _BASE)
                switch_default_layer(_CODE);
            else
                switch_default_layer(_BASE);
            break;
        case 3:
            if (default_layer != _JPNS)
                switch_default_layer(_JPNS);
            else
                switch_default_layer(_BASE);
            break;
        case 4:
            if (default_layer != _STD)
                switch_default_layer(_STD);
            else
                switch_default_layer(_BASE);
            break;
*/
        default:
            break;
    }
    reset_tap_dance(state);
}


void td_uni_switch (qk_tap_dance_state_t *state, void *user_data) {
    switch(state->count){
        case 1:
            clear_mods();
            tap_code(KC_F9);
            break;
#ifdef UNICODE_ENABLE
        case 2:
            set_unicode_input_mode(UC_LNX);
            break;
        case 3:
            set_unicode_input_mode(UC_WIN);
            break;
        case 4:
            set_unicode_input_mode(UC_WINC);
            break;
#endif // UNICODE_ENABLE
        default:
            break;
    }
    reset_tap_dance(state);
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [QOT] = ACTION_TAP_DANCE_FN(td_quot_dqot),
    [CUR] = ACTION_TAP_DANCE_FN(td_euro_dllr),
    [TLD] = ACTION_TAP_DANCE_FN(td_tild_uc_tm),
    [AT]  = ACTION_TAP_DANCE_FN(td_at_uc_cpr),
    [PAR] = ACTION_TAP_DANCE_FN(td_para_uc_rtm),

    [BR1] = ACTION_TAP_DANCE_FN(td_lprn_rprn),
    [BR2] = ACTION_TAP_DANCE_FN(td_lbrc_rbrc),
    [BR3] = ACTION_TAP_DANCE_FN(td_lcbr_rcbr),
    [BR4] = ACTION_TAP_DANCE_FN(td_less_more),

    [UCS] = ACTION_TAP_DANCE_FN(td_uni_switch),
    [AF4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, LALT(KC_F4)), // thx u/grizzly_teddy
    [GUI] = ACTION_TAP_DANCE_FN(td_glck_layer_switch),
    [SDO] = ACTION_TAP_DANCE_FN(td_sudo_dfne_incl),
    [APT] = ACTION_TAP_DANCE_FN(td_apt_get),
    [PCM] = ACTION_TAP_DANCE_FN(td_pacman),

    [GTN] = ACTION_TAP_DANCE_FN(td_greet_nice),
    [GTW] = ACTION_TAP_DANCE_FN(td_greet_work),
    [EML] = ACTION_TAP_DANCE_FN(td_email),
    [BYE] = ACTION_TAP_DANCE_FN(td_bye)
};

#endif // TAP_DANCE_ENABLE
