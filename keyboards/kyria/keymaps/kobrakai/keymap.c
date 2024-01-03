/* Copyright 2020 Nick Brown <nickbrown.dev@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _DVORAK = 0,
    _NUM = 1,
    _SYM = 2,
    _FUNC = 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer:DVORAK
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  TAB   |  ' " |  , < |  . > |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  = +   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  ESC   |   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |  - _   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  \ |   |  ; : |   Q  |   J  |   K  |   X  |  GUI |lt NUM|  |lt SYM| Bksp |   B  |   M  |   W  |   V  |   Z  |  / ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | PgDn | NUM  | Shift| Home |  | End  | Space| Enter| PgUp |      |
 *                        |      |  Alt |      |      | Ctrl |  | Ctrl |      | SYM  | AltGr|      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,   KC_Y,                                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQL,
      KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U,   KC_I,                                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
      KC_BSLS, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,    KC_LGUI, TO(_NUM), TO(_SYM), KC_BSPC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
               _______, MT(MOD_LALT, KC_PGDN), MO(_NUM), KC_LSFT, MT(MOD_LCTL, KC_HOME), MT(MOD_RCTL, KC_END), KC_SPC, LT(_SYM, KC_ENT), MT(MOD_RALT, KC_PGUP),_______
    ),
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LShift|  |LShift|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
/*    [_QWERTY] = LAYOUT(
      LT(_RAISE, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
      MT(MOD_LCTL, KC_BSPC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,                 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,   KC_LSFT, KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC), LT(_LOWER, KC_ENT), LT(_RAISE,#define ENCODER_DIRECTION_FLIP KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
    ),*/
/*
 * NUM Layer: Number Keys and Utility
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |SCROLLLK| PgUp | Home |  Up  | End  | WhUp |                              |   (  |   7  |   8  |   9  | NMENT| NUMLCK |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | PgDn | Left | Down | Right| WhDn |                              |   )  |   4  |   5  |   6  | NUM+ | NUM-   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | Undo |ShDel |CtlIns| ShIns| Redo |      |DVORK |  |      |      |   0  |   1  |   2  |   3  | NUM* | NUM/   ||
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      | NUM. |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      KC_SLCK, KC_PGUP, KC_HOME,  KC_UP,    KC_END,   KC_WH_U,                                         KC_LPRN, KC_7,    KC_8, KC_9, KC_PENT, _______,
      _______, KC_PGDN, KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_WH_D,                                         KC_RPRN, KC_4,    KC_5, KC_6, KC_PPLS, KC_PMNS,
      KC_NO,   C(KC_Z), S(KC_DEL),C(KC_INS),S(KC_INS),C(S(KC_Z)),KC_CALC,TO(_DVORAK),TO(_SYM),_______, KC_0,    KC_1,    KC_2, KC_3, KC_PAST, KC_PSLS, 
                                  _______,  _______,  _______,   _______, _______,   _______, _______, _______, KC_PDOT, _______
    ),

/*
 * SYM Layer: Symbols, Function Keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   "  |   <  |   >  |   {  |  }   |                              |   |  |   &  |   *  |   ~  |   =  |    +   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   `  |   (  |   )  |   [  |  ]   |                              |   \  |   $  |   %  |   ^  |   -  |    _   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   :  |NonUS#| PScr |  Ins |  App | Explr|      |  | DVOR |  Del |NonUs\|   !  |   @  |   #  |   /  |    ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |CpsLck|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______, KC_DQUO, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR,                                     KC_PIPE, KC_AMPR, KC_ASTR, KC_TILD, KC_EQL,  KC_PLUS,
      _______, KC_GRV,  KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,                                     KC_BSLS, KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, KC_QUOT,
      KC_PIPE, KC_COLN, KC_NUHS, KC_PSCR, KC_INS,  KC_APP,  KC_MYCM,TO(_NUM),TO(_DVORAK), KC_DEL,KC_NUBS,KC_EXLM, KC_AT,   KC_HASH, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
/*[_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),*/
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F13  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              | F14  |  F4  |  F5  |  F6  | F11  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      | F15  |  F1  |  F2  |  F3  | F12  |        | 
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
      _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_F13, KC_F7, KC_F8, KC_F9, KC_F10, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_F14, KC_F4, KC_F5, KC_F6, KC_F12, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, KC_F15, KC_F1, KC_F2, KC_F3, KC_F12, _______,
                                 _______, _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _FUNC);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_stark_logo(void) {
    static const char PROGMEM f14_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x08, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 
0x1f, 0x3f, 0x7f, 0xff, 0xfe, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 
0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xff, 0xfb, 0xf8, 0xf0, 0xe0, 0xc0, 0xe0, 0xc0, 
0xe0, 0xe0, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0xc0, 0xe0, 0xf0, 0xff, 0xe0, 0xc0, 0x80, 
0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 
0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0xe5, 0xf9, 0x7b, 0xff, 0xff, 0xff, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x0f, 0x0f, 
0x0f, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 
0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1c, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 
0x47, 0x9f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0xbf, 0xff, 0xff, 0x17, 0xc8, 0x38, 0x08, 0x08, 
0xf8, 0x10, 0xe0, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0x3f, 
0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x0f, 0xff, 0xff, 0x0f, 0x7f, 0x3e, 0x51, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x06, 0x0f, 0x1f, 0x1f, 0x0f, 0x06, 0x01, 0xf8, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xfe, 0xfe, 0xfe, 
0xfd, 0xfc, 0xff, 0xff, 0xff, 0x23, 0x00, 0x00, 0x04, 0x38, 0x78, 0x7c, 0x7c, 0x3c, 0x03, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x7f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x03, 0x03, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    oled_write_raw_P(f14_logo, sizeof(f14_logo));

/*    static const char PROGMEM stark_logo[] = {
     // 'Stark', 128x64px
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, 64, 64, 64, 64,192,192,192,192,192,192,192,192,192,192,192,192,192,192,192,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,248,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,254,254,254,254,126, 62, 30, 14,  2,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,224,240,240,248,248,248,248,248,248,248,248,248,248,248,248,248,240,240,240,240,240,240,240,240,240,240, 48,  0,  0,128,224,240,240,240,240,240,240,240,240,  0,  0,  0,  0,  0,  0,224,240,240,240,240,240,240,248,248,240,240,240,240,224,193,  1,  1,225,241,241,241,241,113,  1,  1,129,193,225,241,241,241,113, 49, 25,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,193,225,249,253,255,255,255,255,127, 63, 31, 15,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6, 15, 63,127,255,255,252,248,240,192,  0,  0,  0,  0,  0,  0,224,252,255,255,255,127, 15,  1,  0,  0,192,224,240,248,254,255,255,255,247,243,255,255,255,255,255,255,  0,  0,  0,192,248,255,255,255,127, 15,249,248,248,248,254, 63, 31, 31, 15,  3,192,248,255,255,255,255, 31,251,252,254,255,255,239,135,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,240,248,254,255,255,127, 63, 31, 15,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30, 62, 62, 62, 62, 62, 62, 31, 31, 15, 15,  7,  1,  0,  0,  0,  0, 56, 31, 31, 31, 63, 31,  3,  0, 56, 28, 30, 31, 63, 31, 15,  3,  1,  1,  1,  1,  1,  1, 31, 63, 31, 31, 31, 63,  0, 56, 62, 63, 63, 63, 31,  3,  0,  0, 63, 63, 63, 63, 63, 62,  0,  0, 56, 31, 31, 31, 63, 31,  7,  0,  0,  0, 15, 63, 31, 31, 31, 31, 60,  0,  0,  0,  0,  0,192,224,248,252,255,127, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,224,252,255, 63,143,241,254,127, 31,255,255,248,248,254, 63,143,241,254,255,159,135,199,231,255,127, 62,224,252,255,191,135,128,224,252,255, 63,143,137,158,254,255,247,231,  7,  1,135,231,255,255, 63,  7,  7,199,251,254,127,255,247,247,255, 31,143,224,252,255, 63,199,248,254,255,191,183,183,183,135,135,140,190,255,255,247,103,  7,128,192,240,120, 62, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  3,  3,  3,  1,  0,  3,  3,  3,  0,  0,  1,  3,  3,  3,  1,  0,  3,  3,  3,  3,  3,  3,  1,  1,  0,  0,  0,  1,  3,  3,  3,  3,  3,  1,  1,  0,  1,  3,  3,  3,  3,  1,  1,  0,  0,  0,  3,  3,  3,  1,  0,  0,  2,  3,  3,  3,  0,  3,  3,  3,  3,  0,  3,  3,  3,  1,  2,  3,  3,  3,  3,  3,  3,  3,  1,  3,  3,  3,  3,195, 97, 49, 28, 14,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};

    oled_write_raw_P(stark_logo, sizeof(stark_logo)); */
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    //oled_write_P(PSTR("Kyria rev1.0\n\n"), false);
    oled_write_P(PSTR("\n"), false);
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("Dvorak\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _FUNC: 
            oled_write_P(PSTR("Func\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_stark_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code16(C(KC_RGHT));
        } else {
            tap_code16(C(KC_LEFT));
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (!clockwise) { // TODO correct orientation
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif
