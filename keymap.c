#include QMK_KEYBOARD_H

/** This enum is used in order to mantain a more descriptable name for the layers.
 */
enum layer_names {
    _Type,
    _Simbols,
    _Movement,
    _Media,
    _Numpad,
    _Function,
    _Config,
    _ModeShift,
};

enum {
    Shift_Caps,
};

tap_dance_action_t tap_dance_actions[] = {
    [Shift_Caps] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_Type] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_MINS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_TAB, LSFT_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LGUI_T(KC_F), KC_G,                         KC_H,    RGUI_T(KC_J),    RCTL_T(KC_K),    RALT_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(Shift_Caps), KC_Z, KC_X,   KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    MO(_ModeShift), KC_ESC,  KC_SPC,     KC_ENT,   KC_BSPC, MO(_ModeShift)
                                      //`--------------------------'  `--------------------------'
    ),

    [_Simbols] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        RALT(KC_GRV), KC_1, KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RALT(KC_TILD), KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC,              RALT(KC_CIRC), KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_SLSH, KC_MINS, KC_QUES, KC_BSLS, KC_RBRC, KC_LBRC,                      KC_LCBR, KC_RCBR, KC_PIPE, KC_EXLM, KC_UNDS, KC_QUES,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, TG(_Simbols), KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `---------------------------
    ),

    [_Numpad] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PPLS, KC_PMNS,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_P0,   KC_P4,   KC_P5,   KC_P6, KC_PAST, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_P7,   KC_P8,   KC_P9, KC_PDOT, KC_PEQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, TG(_Numpad), KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `---------------------------
    ),

    [_Function] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,  KC_DEL,  KC_INS, KC_PASTE, KC_COPY, KC_CUT,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, TG(_Function), KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `---------------------------
    ),

    [_Movement] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      MS_LEFT, MS_DOWN,  MS_UP, MS_RGHT,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO, MS_BTN1, MS_BTN2, MS_WHLU,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, MS_WHLD,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_TRNS, TG(_Movement),   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_Media] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO, KC_BRIU, KC_MNXT, KC_VOLU,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------|--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
        KC_NO,   KC_NO, KC_LEFT, KC_MPLY, KC_MUTE,KC_RIGHT,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------|--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
        KC_NO,   KC_NO, KC_BRID, KC_MPRV, KC_VOLD,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS, TG(_Media),  KC_NO,      KC_NO,   KC_NO, KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_Config] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT,  EE_CLR,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
        UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------|--------+--------|--------+--------|
        UG_NEXT, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_TRNS, TG(_Config), KC_KB_POWER,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
    ),

    [_ModeShift] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO, TO(_Config), TO(_Function), TO(_Media), KC_NO,          KC_NO, TO(_Simbols), TO(_Movement), TO(_Numpad), KC_NO, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO, KC_NO
                                      //`--------------------------'  `--------------------------'
    )

};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
  // Host Keyboard Layer Status
    if (is_keyboard_master()) {
        oled_set_cursor(0, 1);

        oled_write_P(PSTR("-----\n")),
        oled_write_P(get_highest_layer(layer_state) == _Simbols ? PSTR("> SIM\n") : PSTR("  SIM\n"), false);
        oled_write_P(get_highest_layer(layer_state) == _Movement ? PSTR("> MOV\n") : PSTR("  MOV\n"), false);
        oled_write_P(get_highest_layer(layer_state) == _Numpad ? PSTR("> NUM\n") : PSTR("  NUM\n"), false);
        oled_write_P(get_highest_layer(layer_state) == _Function ? PSTR("> FUN\n") : PSTR("  FUN\n"), false);
        oled_write_P(get_highest_layer(layer_state) == _Media ? PSTR("> MED\n") : PSTR("  MED\n"), false);
        oled_write_P(get_highest_layer(layer_state) == _Config ? PSTR("> CON\n") : PSTR("  CON\n"), false);

    } else {
        oled_write_P(PSTR("-----\n> 1 <\n> + <\n> M <\n> O <\n> R <\n> E <\n-----"), false);
    }

    return false;
}
#endif