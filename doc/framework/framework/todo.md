# TODO

## How to

```bash
   qmk compile -kb framework/ansi -km cmiu  # (Adjust keyboard/keymap name as needed)
   qmk flash -kb framework/ansi -km cmiu
```

```
## Layere

### layer default with tap dance as follows

```
    [_TEST] = LAYOUT(
        KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL, KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        LT(_NAV, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        LSFT_T(KC_TAB), MT(MOD_LCTL, KC_A), MT(MOD_LGUI, KC_S), MT(MOD_LALT, KC_D), KC_F, KC_G, KC_H, KC_J, MT(MOD_LALT, KC_K), MT(MOD_LGUI, KC_L), MT(MOD_LCTL, KC_SCLN), MT(MOD_RSFT, KC_QUOT), KC_ENT,
        KC_ESC,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT
    ),
```

### layer _NAV temporar, activat pe TAB press

```
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, LCTL(KC_RGHT), _______, _______, _______, _______, KC_PGDN, KC_UP,   KC_PGUP, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_END,           _______,
        _______,          _______, _______, _______, _______, LCTL(KC_LEFT), _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, _______,          _______,                   _______, _______, _______, _______, _______, _______
    ),
```

### layer _FN

```
    [_FM] = LAYOUT(
        FN_LOCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL,  KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, _______, _______, KC_PAUS, _______, _______, _______,
        _______, _______, _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, KC_SCRL, _______, _______, _______,          _______,
        _______,          _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______,          BL_STEP,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),
```

### layer qwerty fara modificari

## Functionalitati de adaugat

### culori

- combinatia _FN + space shimba luminozitatea rgb a tastelor 0 25 50 75 100%
- in configuratia actuala in cazul in care sunt pe layerul test si apas _FN + space luminozitatea este modificata doar pe layerul_FN, nu si pe restul layerelor sau layerul activ, mai mult nu este salvata in cazul in care schimb layerul inapoi pe _TEST.
- modifica saturatia culorilor default la 50% si luminozitatea la 75%

### functii noi pentru taste

- ESC devine CAPSLOCK tap dance tap and hold
- switch pentru layerele functionale tap dance pe randul qwerty tap and hold
- in layerul _FN butonul del devine butonul care pune tastatura in modul de flash firmware

### comentarii

- pentru fiecare layer adauga comentariu cu functionalitatea lui foloseste ca exemplu:

```
/*
     * Function layer
     *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
     * 14 keys │FN lk│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Ins │
     *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
     * 14 keys │   │   │   │   │   │   │   │   │   │   │   │   │   │      │
     *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
     * 14 keys │     │   │RGB│Nxt│Hue│Sat│Spd│Brt│   │   │Pau│   │   │    │
     *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
     * 13 keys │      │   │   │Prv│Hue│Sat│Spd│Brt│ScL│   │   │   │       │
     *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
     * 12 keys │        │   │   │   │   │   │Brk│   │   │   │   │         │
     *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
     *         │    │   │   │   │                   │   │   │    │PgU│    │
     * 11 keys │    │   │   │   │ Toggle Backlight  │   │   │Home├───┤End │
     *         │    │   │   │   │                   │   │   │    │PgD│    │
     *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
     * 78 total
     */
```

### Optimizari

verifica daca mai este nevoie de toate functiile din fisierul keymap.c si elimina ce nu este necesar
