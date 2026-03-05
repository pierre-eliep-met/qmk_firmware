// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define UNICODE_SELECTED_MODES UC_WINC


// main layer
  #define A_GUI LGUI_T(KC_A)
  #define S_ALT LALT_T(KC_S)
  #define D_CTL LCTL_T(KC_D)
  #define F_SFT LSFT_T(KC_F)
  #define J_SFT RSFT_T(KC_J)
  #define K_CTL RCTL_T(KC_K)
  #define L_ALT LALT_T(KC_L)
  #define SCLN_GUI RGUI_T(KC_SCLN)

// Thumb keys
  #define ENT_LY2 LT(2,KC_ENT)
  #define SPC_LY1 LT(1,KC_SPC)
  #define CTL_BSP LCTL(KC_BSPC)
  #define BSP_LY3 LT(3,KC_BSPC)
  #define ENT_ALTGR MT(MOD_RALT,KC_ENT)
  // QK_REP

  // Unused thumb keys
  #define BSP_CTL MT(MOD_LCTL,KC_BSPC)
  #define TAB_LY2 LT(2,KC_TAB)
  #define SPC_ALT LALT_T(KC_SPC)
  #define DKC_LY1 LT(1,KC_DEL)
  #define ENT_GUI LGUI(KC_ENT)
  #define ENT_ALT LALT_T(KC_ENT)

// layer 1 nav + ctrl
  #define ALT_F4 LALT(KC_F4)
  #define ALT_ESC LALT(KC_ESC)
  #define CTL_C LCTL(KC_W)
  #define IMPRECRAN LGUI(LSFT(KC_S))
  #define BSP_SFT MT(MOD_LSFT,KC_BSPC)
  #define CTL_Y LCTL(KC_P)
  #define CTL_A LCTL(KC_A)
  #define CTL_S LCTL(KC_S)
  #define CTL_E LCTL(KC_D)
  #define CTL_N LCTL(KC_N)
  #define CTL_F LCTL(KC_G)
  #define CTL_Z LCTL(KC_Z)
  #define CTL_X LCTL(KC_X)
  #define CTL_V LCTL(KC_V)
  #define CTL_B LCTL(KC_B)
  #define CTL_LEFT LCTL(KC_LEFT)
  #define CTL_RIGHT LCTL(KC_RIGHT)

// layer 2 num
  #define EURO KC_EXLM
  #define K0_GUI LGUI_T(KC_0)
  #define K4_ALT LALT_T(KC_4)
  #define K5_CTL LCTL_T(KC_5)
  #define K6_SFT LSFT_T(KC_6)
  #define PLS_SFT RSFT_T(KC_PLUS)
  #define MNS_CTL RCTL_T(KC_MINUS)
  #define SLS_ALT LALT_T(KC_SLASH)


const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t word_delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LCTL(KC_BSPC), LCTL(KC_DEL));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override,
  &word_delete_key_override,
};


const uint16_t PROGMEM  underscore[] = {ENT_ALTGR, SPC_LY1, COMBO_END};
combo_t key_combos[] = {
    COMBO(underscore, KC_UNDS),
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
            return true;

        // KC_V continues Caps Word, with shift applied.
        // ALTGR(KC_V) continues Caps Word, without shifting.
        case KC_V:
        case SPC_LY1:
            // Apply shift if altgr is not activated.
            if (!(get_mods() & MOD_BIT(KC_RALT))) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            return true;

        // Keycodes that continue Caps Word, with shift applied.
        case KC_A:
        case KC_B:
        case KC_C:
        case KC_D:
        case KC_E:
        case KC_F:
        case KC_G:
        case KC_H:
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_M:
        case KC_O:
        case KC_P:
        case KC_Q:
        case KC_R:
        case KC_S:
        case KC_T:
        case KC_U:
        case KC_SCLN: // u
        case KC_COMM: // g
        case KC_SLSH: // k
        case KC_W:
        case KC_X:
        case KC_Y:
        case KC_Z:
            if (get_mods() & MOD_BIT(KC_RALT)) { // Stop on altgr symbols
                return false;
            }
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift
            return true;

        // Stop on other keycodes
        default:
            return false;
    }
}

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}


// todo : KC_HASH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
      //    outer,   pinky,    ring,  middle,   index,   inner,                        inner,   index,  middle,    ring,   pinky,   outer
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ESC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_TAB,   A_GUI,   S_ALT,   D_CTL,   F_SFT,    KC_G,                         KC_H,   J_SFT,   K_CTL,   L_ALT, KC_SCLN,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          BSP_CTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, CW_TOGG,
      //|--------+--------+--------+--------+--------+--------+--------|---+--------+--------+--------+--------|
                                              ENT_LY2, SPC_LY1,  QK_REP,    ALT_TAB,ENT_ALTGR,CTL_BSP
                                          //`--------------------------'  `--------------------------'
  ),                                      //    mouse,ctrl nav, repeat,     backspace, altgr, numpad


  [1] = LAYOUT_split_3x6_3(
      //   outer,   pinky,    ring,  middle,   index,   inner,                        inner,   index,  middle,    ring,   pinky,   outer
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC,  ALT_F4,   CTL_C,  KC_F2,IMPRECRAN,   CTL_Y,                      MS_WHLU, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_ESC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          ALT_TAB,   CTL_A,   CTL_S,   CTL_E, BSP_SFT,   CTL_F,		                   MS_WHLD, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN, KC_CAPS, 
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          BSP_CTL,   CTL_Z,   CTL_X,  KC_DEL,   CTL_V,   CTL_B,     	               MS_WHLL,CTL_LEFT, KC_BSPC,CTL_RIGHT,MS_WHLR, CW_TOGG,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              ENT_LY2, SPC_LY1,  QK_REP,    ALT_TAB,ENT_ALTGR,CTL_BSP
                                            //`------------------------'  `--------------------------'
  ),                                        // mouse, ctrl nav, repeat,     backspace, altgr, numpad


  [2] = LAYOUT_split_3x6_3(
      //   outer,   pinky,    ring,  middle,   index,   inner,                        inner,   index,  middle,    ring,   pinky,   outer
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC, KC_CIRC,    KC_7,    KC_8,    KC_9, KC_PERC,                        KC_AT, KC_AMPR, KC_PAST, XXXXXXX, XXXXXXX, QK_BOOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           KC_TAB,    KC_0,    KC_4,    KC_5,    KC_6,  KC_EQL,                      KC_BSLS, KC_PLUS, KC_PMNS, KC_PSLS, KC_QUOT,  KC_TAB,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          BSP_CTL, KC_TILD,    KC_1,    KC_2,    KC_3, KC_HASH,                      KC_PDOT,    EURO, XXXXXXX, XXXXXXX, XXXXXXX, CW_TOGG,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              ENT_LY2, SPC_LY1,  QK_REP,    ALT_TAB,ENT_ALTGR,CTL_BSP
                                          //`--------------------------'  `--------------------------'
  ),                                      //   mouse, ctrl nav, repeat,     backspace, altgr, numpad
};
