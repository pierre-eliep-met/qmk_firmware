// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t word_delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LCTL(KC_BSPC), LCTL(KC_DEL));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override,
  &word_delete_key_override,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,LALT_T(KC_SPC),TT(1),   KC_ENT,LCTL(KC_BSPC),KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),


    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, XXXXXXX, XXXXXXX, MS_BTN2,   MS_UP, MS_BTN1,                      MS_WHLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  TO(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,LCTL(KC_A),LCTL(KC_S),MS_LEFT,MS_DOWN,MS_RGHT,		                 MS_WHLD, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, KC_CAPS, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 KC_LCTL,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_W),LCTL(KC_V),TT(2),     	               XXXXXXX, MS_WHLL, KC_BSPC, MS_WHLR, XXXXXXX, CW_TOGG,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,LALT_T(KC_SPC),TO(0),  KC_ENT,LCTL(KC_BSPC), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  


    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      ALT_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_AMPR, KC_PAST, KC_PSLS, XXXXXXX, TO(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,			                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX, XXXXXXX,     	               KC_PDOT, KC_PPLS, KC_PMNS, KC_PCMM, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,LALT_T(KC_SPC),TO(1),  KC_ENT,LCTL(KC_BSPC), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
};
