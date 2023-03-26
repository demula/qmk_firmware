// Copyright 2022 (@demula)
// Derived from default created by Diego Palacios and feature
// tap dance documentation of QMK.fm
// SPDX-License-Identifier: GPL-2.0
#include QMK_KEYBOARD_H

// --- Layers
#define _BL 0  // Base layer
#define _FSL 1 // Function keys and symbols layer
#define _NNL 2 // Numbers, media and navigation layer

// --- Keymap definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Esc│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤L2*│
      *               └───┤L1*├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Spc├───┘
      *                       └───┘   └───┘
      *                 Mod-Tap: Alt for Ent and Spc
      *                 L1*: OSL(_FSL)
      *                 L2*: OSL(_NNL)
      */
    [_BL] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                KC_LGUI, OSL(_FSL), MT(MOD_LALT, KC_ENT),  MT(MOD_RALT, KC_SPC), KC_BSPC, OSL(_NNL)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ( │ ) │Esc│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│F1 │F2 │F3 │F4 │F5 │       │ - │ = │ ` │ [ │ ] │ | │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│F6 │F7 │F8 │F9 │F10│       │ _ │ + │ ~ │ { │ } │ ▼ │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │F11├───┐           ┌───┤ ▼ │
      *               └───┤N/A├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Spc├───┘
      *                       └───┘   └───┘
      *                 Mod-Tap: Alt for Ent and Spc
      */
    [_FSL] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_ESC,
        KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_RBRC, KC_PIPE,
        KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             KC_UNDS, KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, TO(_BL),
                                   KC_F11,  KC_NO,   MT(MOD_LALT,KC_ENT),   MT(MOD_RALT, KC_SPC), KC_BSPC, TO(_BL)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ / │ 7 │ 8 │ 9 │ - │       │Prv│Ply│Stp│Nxt│Vl+│Esc│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ * │ 4 │ 5 │ 6 │ + │       │ ← │ ↓ │ ↑ │ → │Vl-│Del│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ . │ 1 │ 2 │ 3 │ = │       │Hom│PDo│PUp│End│Mut│ ▼ │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ 0 ├───┐           ┌───┤N/A│
      *               └───┤ ▼ ├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Spc├───┘
      *                       └───┘   └───┘
      *                 Mod-Tap: Alt for Ent and Spc
      */
    [_NNL] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PMNS,                            KC_MRWD, KC_MPLY, KC_MSTP, KC_MFFD, KC_VOLU, KC_ESC,
        KC_LCTL, KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_DEL,
        KC_LSFT, KC_PDOT, KC_1,    KC_2,    KC_3,    KC_PEQL,                            KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MUTE, TO(_BL),
                                   KC_0,    TO(_BL),   MT(MOD_LALT,KC_ENT),   MT(MOD_RALT, KC_SPC), KC_BSPC, KC_NO
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  //debug_mouse=true;
}
