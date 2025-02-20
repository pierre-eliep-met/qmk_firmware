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
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, MT(MOD_RSFT, KC_CAPS),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              TT(1),LALT_T(KC_SPC),MT(MOD_LGUI,KC_ENT),LCTL(KC_BSPC),MT(MOD_RALT,KC_LSFT),TT(2)
                                      //`--------------------------'  `--------------------------'
  ),


    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, XXXXXXX,LCTL(KC_W),KC_VOLU, XXXXXXX, KC_BRIU,                      MS_WHLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  TO(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,LCTL(KC_A),LCTL(KC_S),KC_VOLD,  KC_F2, KC_BRID,		                   MS_WHLD, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, KC_CAPS, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 KC_LCTL,LCTL(KC_Z),LCTL(KC_X),KC_MUTE,LCTL(KC_V),LCTL(KC_Y),     	      MS_WHLL,LCTL(KC_LEFT),XXXXXXX,LCTL(KC_RIGHT),MS_WHLR,KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            TT(1),LALT_T(KC_SPC),MT(MOD_LGUI,KC_ENT),LCTL(KC_BSPC),MT(MOD_RALT,KC_LSFT),TT(2)
                                      //`--------------------------'  `--------------------------'
  ),



    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB, XXXXXXX,     KC_7,    KC_8,    KC_9, XXXXXXX,                      XXXXXXX, KC_AMPR, KC_PAST, XXXXXXX, XXXXXXX,   TO(0),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX,                      XXXXXXX, KC_PPLS, KC_PMNS, KC_PSLS, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX,    KC_4,    KC_5,	   KC_6, XXXXXXX,     	               KC_PDOT, XXXXXXX, XXXXXXX,  KC_DOT, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                            TT(1),LALT_T(KC_SPC),MT(MOD_LGUI,KC_ENT),LCTL(KC_BSPC),MT(MOD_RALT,KC_LSFT),TT(2)
                                      //`--------------------------'  `--------------------------'
  ),
};
