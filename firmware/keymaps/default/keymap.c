// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define the mod-tap keys for the home row
#define HOME_A LGUI_T(KC_A)  // A acts as GUI (Cmd/Win) when held
#define HOME_S LALT_T(KC_S)  // S acts as Alt when held
#define HOME_D LSFT_T(KC_D)  // D acts as Shift when held
#define HOME_F LCTL_T(KC_F)  // F acts as Ctrl when held

#define HOME_J RCTL_T(KC_J)  // J acts as Ctrl when held
#define HOME_K RSFT_T(KC_K)  // K acts as Shift when held
#define HOME_L RALT_T(KC_L)  // L acts as Alt when held
#define HOME_SCLN RGUI_T(KC_SCLN)  // ; acts as GUI (Cmd/Win) when held

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 50;
        case HOME_SCLN:
            return TAPPING_TERM + 50;  
        default:
            return TAPPING_TERM;
    }
}

enum layers {
    BASE,
    NUM,
    NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ _ │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │; :│' "│
      * │   │GUI│ALT│Sft│Ctl│   │       │   │Ctl│Sft│ALT│GUI│   │ 
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘   
      *               ┌───┐                   ┌───┐
      *               │Tab├───┐           ┌───┤Bsp│
      *               └───┤Spc├───┐   ┌───┤Ent├───┘
      *                   └───┤Num│   │Nav├───┘
      *                       └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x6_3( 
        KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       XXXXXXX,
        KC_UNDS,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                                   KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,  KC_QUOT,
        XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    XXXXXXX,
                                             KC_TAB,  KC_SPC, MO(NUM),               MO(NAV), KC_ENT,  KC_BSPC
    ),
         /* 
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ @ │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ ` │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ $ │ # │ ! │ ( │ ) │ - │       │ + │ [ │ ] │ & │ | │ ~ │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ^ │ % │ < │ > │ ? │       │ = │ { │ } │ \ │ * │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘               
      *               ┌───┐                   ┌───┐
      *               │Tab├───┐           ┌───┤Bsp│
      *               └───┤Spc├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [NUM] = LAYOUT_split_3x6_3(
        KC_AT,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_DLR,  KC_HASH, KC_EXLM, KC_LPRN, KC_RPRN, KC_MINS,                               KC_PLUS, KC_LBRC, KC_RBRC, KC_AMPR, KC_PIPE, KC_TILD,
        XXXXXXX, KC_CIRC, KC_PERC, KC_LABK, KC_RABK, KC_QUES,                               KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS, KC_ASTR, XXXXXXX,
                                            KC_TAB,  KC_SPC, XXXXXXX,              XXXXXXX, KC_ENT,  KC_BSPC
    ),
    
     /*
      * ┌────┬────┬────┬────┬────┬────┐       ┌────┬────┬────┬────┬────┬────┐
      * │    │ F1 │ F2 │ F3 │ F4 │ F5 │       │ F6 │ F7 │ F8 │ F9 │ F10│    │
      * ├────┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼────┼────┤
      * │    │ F11│ F12│    │    │    │       │ ←  │ ↓  │ ↑  │ →  │Home│ End│
      * ├────┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼────┼────┤
      * │    │    │    │PSCR│Mute│ V- │       │ V+ │PgDn│PgUp│ Del│    │    │
      * └────┴────┴────┴────┴────┴────┘       └────┴────┴────┴────┴────┴────┘   
      *               ┌───┐                   ┌───┐
      *               │Tab├───┐           ┌───┤Bsp│
      *               └───┤Spc├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [NAV] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  XXXXXXX,
        XXXXXXX, KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                              KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_HOME, KC_END,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_MUTE, KC_VOLD,                          KC_VOLU, KC_PGDN, KC_PGUP, KC_DEL,   XXXXXXX, XXXXXXX,
                                            KC_TAB,  KC_SPC, XXXXXXX,           XXXXXXX, KC_ENT,  KC_BSPC  
    )
};

     






