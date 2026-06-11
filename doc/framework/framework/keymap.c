// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"

enum layers {
    _BASE,
    _NAV,
    _FN
};

enum custom_keycodes {
    RGB_BRI_STEP = KC_CPLT + 1,
};

enum tap_dance_codes {
    TD_ESC_CAPS,
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Esc, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

static uint8_t global_brightness = 64;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer (Modified QWERTY)
     *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
     * 14 keys │TD/Es│Mut│vDn│vUp│Prv│Ply│Nxt│bDn│bUp│Scn│Air│Prt│App│Del │
     *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
     * 14 keys │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp│
     *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * 14 keys │Nav/T│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \  │
     *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
     * 13 keys │Sft/T │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter │
     *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
     * 12 keys │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  Shift  │
     *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
     *         │    │   │   │   │                   │   │   │    │↑  │    │
     * 11 keys │Ctrl│FN │GUI│Alt│                   │Alt│Ctl│ ←  ├───┤  → │
     *         │    │   │   │   │                   │   │   │    │  ↓│    │
     *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
     */
    [_BASE] = LAYOUT(
        TD(TD_ESC_CAPS), KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL, KC_DEL,
        KC_GRV,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,          KC_Q,    KC_W,    LT(_NAV, KC_E), KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LSFT_T(KC_TAB),  MT(MOD_LCTL, KC_A), MT(MOD_LGUI, KC_S), MT(MOD_LALT, KC_D), KC_F, KC_G, KC_H, KC_J, MT(MOD_LALT, KC_K), MT(MOD_LGUI, KC_L), MT(MOD_LCTL, KC_SCLN), MT(MOD_RSFT, KC_QUOT), KC_ENT,
        KC_ESC,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,         MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT
    ),

    /*
     * Navigation Layer
     *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
     * 14 keys │     │   │   │   │   │   │   │   │   │   │   │   │   │    │
     *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
     * 14 keys │   │   │   │   │   │   │   │   │   │   │   │   │   │      │
     *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * 14 keys │     │   │   │   │   │   │   │Hom│PgU│PgD│End│   │   │    │
     *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
     * 13 keys │      │   │   │   │   │   │   │Lft│Dwn│Up │Rgt│   │       │
     *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
     * 12 keys │        │   │   │   │   │   │   │C-L│   │   │C-R│         │
     *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
     *         │    │   │   │   │                   │   │   │    │   │    │
     * 11 keys │    │   │   │   │                   │   │   │    │   │    │
     *         │    │   │   │   │                   │   │   │    │   │    │
     *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
     */
    [_NAV] = LAYOUT(
        _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,       _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, _______,
        _______, _______, _______,       _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,          _______,
        _______, _______, _______,       _______, _______, _______, _______, LCTL(KC_LEFT), _______, _______, LCTL(KC_RGHT), _______,
        _______, _______, _______,       _______,          _______,                   _______, _______, _______, _______, _______, _______
    ),

    /*
     * Function Layer
     *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
     * 14 keys │FN lk│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│BOOT│
     *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
     * 14 keys │   │   │   │   │   │   │   │   │   │   │   │   │   │      │
     *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * 14 keys │     │   │RGB│Nxt│Hue│Sat│Spd│Brt│   │   │Pau│   │   │    │
     *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
     * 13 keys │      │   │   │Prv│Hue│Sat│Spd│Brt│ScL│   │   │   │       │
     *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
     * 12 keys │        │   │   │   │   │   │Brk│   │   │   │   │         │
     *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
     *         │    │   │   │   │    Brightness     │   │   │    │PgU│    │
     * 11 keys │    │   │   │   │    Cycle          │   │   │Home├───┤End │
     *         │    │   │   │   │                   │   │   │    │PgD│    │
     *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
     */
    [_FN] = LAYOUT(
        TG(_FN), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, _______, _______, KC_PAUS, _______, _______, _______,
        _______, _______, _______, KC_MPRV, RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, KC_MNXT, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______,                   _______,
        _______, _______, _______, _______,          RGB_BRI_STEP,              _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),
};


// Set default RGB values on init
void keyboard_post_init_user(void) {
    // Mode Solid Color
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // Saturation 50% (128), Value/Brightness 50% (128)
    rgb_matrix_sethsv_noeeprom(0, 128, global_brightness);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case _FN:
             // Green
            rgb_matrix_sethsv_noeeprom(85, 255, global_brightness);
            break;
        case _NAV:
             // Blue
            rgb_matrix_sethsv_noeeprom(170, 255, global_brightness);
            break;
        default:
            // Saturation 50% (128), Value/Brightness 50% (128)
            // Orange-ish / Warm White (Hue 0-20 approx)
            rgb_matrix_sethsv_noeeprom(0, 128, global_brightness);
            break;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_BRI_STEP:
            if (record->event.pressed) {
                // Cycle brightness: 0 -> 25% -> 50% -> 75% -> 100% -> 0
                // QMK Val is 0-255. 
                // Steps: 0, 64, 128, 191, 255.
                
                if (global_brightness < 60) global_brightness = 64;       // 0 -> 25%
                else if (global_brightness < 120) global_brightness = 128; // 25 -> 50%
                else if (global_brightness < 180) global_brightness = 191; // 50 -> 75%
                else if (global_brightness < 250) global_brightness = 255; // 75 -> 100%
                else global_brightness = 0;                         // 100 -> 0%
                
                rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), rgb_matrix_get_sat(), global_brightness);
            }
            return false;
    }
    return true;
}
