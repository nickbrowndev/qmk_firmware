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

// Must match order of layers enum
const char* layer_names[] = {
    "DVORAK",
    "NUMBER",
    "SYMBOL",
    "FUNCTION"
};

enum scroll_size {
    ARROW = 0,
    TAB,
    MOUSE,
    PAGE,
    END
};

const char* scroll_size_names[] = {
    "ARROW",
    "TAB",
    "MOUSE",
    "PAGE",
    "**ERROR**"
};

enum custom_keycodes {
    KC_ADJ_H_SCL = SAFE_RANGE,
    KC_ADJ_V_SCL
};

static enum scroll_size horizontalScrollStepSize = TAB;
static enum scroll_size verticalScrollStepSize = PAGE;

// Aliases for readability
#define NUM      MO(_NUM)

#define SYM_ENT  LT(_SYM, KC_ENT)

#define ALT_PGDN MT(MOD_LALT, KC_PGDN)
#define CTL_HOME MT(MOD_LCTL, KC_HOME)
#define CTL_END  MT(MOD_RCTL, KC_END)
#define ALT_PGUP MT(MOD_RALT, KC_PGUP)

// clang-format off
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
 *                        | HScl | PgDn | NUM  | Shift| Home |  | End  | Space| Enter| PgUp | VScl |
 *                        | Size |  Alt |      |      | Ctrl |  | Ctrl |      | SYM  | AltGr| Size |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DVORAK] = LAYOUT(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT, KC_P,   KC_Y,                                          KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQL,
      KC_ESC,  KC_A,    KC_O,    KC_E,   KC_U,   KC_I,                                          KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
      KC_BSLS, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,    KC_LGUI, TO(_NUM), TO(_SYM), KC_BSPC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
               KC_ADJ_H_SCL, MT(MOD_LALT, KC_PGDN), MO(_NUM), KC_LSFT, MT(MOD_LCTL, KC_HOME), MT(MOD_RCTL, KC_END), KC_SPC, LT(_SYM, KC_ENT), MT(MOD_RALT, KC_PGUP), KC_ADJ_V_SCL
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
 * | NumLck | Undo |ShDel |CtlIns| ShIns| Redo |      |DVORK |  |      |      |   0  |   1  |   2  |   3  | NUM* | NUM/   ||
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      | NUM. |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUM] = LAYOUT(
      KC_SCRL, KC_PGUP, KC_HOME,  KC_UP,    KC_END,   KC_WH_U,                                         KC_LPRN, KC_7,    KC_8, KC_9, KC_PENT, _______,
      _______, KC_PGDN, KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_WH_D,                                         KC_RPRN, KC_4,    KC_5, KC_6, KC_PPLS, KC_PMNS,
      KC_NUM , C(KC_Z), S(KC_DEL),C(KC_INS),S(KC_INS),C(S(KC_Z)),KC_CALC,TO(_DVORAK),TO(_SYM),_______, KC_0,    KC_1,    KC_2, KC_3, KC_PAST, KC_PSLS, 
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
 * |        |      | SAD  | HUD  | VAD  | RMOD |PrntSc|      |  |      |      | F15  |  F1  |  F2  |  F3  | F12  |        | 
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Caps |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNC] = LAYOUT(
      _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                       KC_F13, KC_F7, KC_F8, KC_F9, KC_F10, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_F14, KC_F4, KC_F5, KC_F6, KC_F12, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,KC_PSCR, _______, _______, _______, KC_F15, KC_F1, KC_F2, KC_F3, KC_F12, _______,
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

#ifdef OLED_ENABLE

static void render_logo(void) {
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

void render_status(void) {

	// 21 Chars screen width
	oled_clear();
	oled_write_P(PSTR("Kyria         Rev 1.3\n"), false);  

	// Keyboard Layer Status
	// Ideally we'd print the layer name, but no way to know that for sure
	// Fallback option: just print the layer number
	uint8_t layer = get_highest_layer(layer_state | default_layer_state);
	oled_write_P(PSTR("Layer: "), false);
	oled_write(layer_names[layer], false);
	oled_write_P(PSTR("    \n\n"), false);

	// Keyboard LED Status
	led_t led_usb_state = host_keyboard_led_state();
	oled_write_P(PSTR(" NUML "), led_usb_state.num_lock);
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR(" CAPS "), led_usb_state.caps_lock);
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR(" SCRL "), led_usb_state.scroll_lock);
	oled_write_P(PSTR("\n\n"), false);

	// Scroll Size	
	oled_write_P(PSTR("Scr H: "), false);
	oled_write(scroll_size_names[horizontalScrollStepSize], false);
	oled_write_P(PSTR(" V: "), false);
	oled_write_ln(scroll_size_names[verticalScrollStepSize], false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
	return false;
}
#endif

void incrementHorizontalScrollStep(void) {
    switch (horizontalScrollStepSize) {
        case ARROW: horizontalScrollStepSize = TAB; break;
        case TAB:   horizontalScrollStepSize = MOUSE; break;
        case MOUSE: horizontalScrollStepSize = PAGE; break;
        case PAGE:  horizontalScrollStepSize = ARROW; break;
        default:    horizontalScrollStepSize = PAGE; break;
    }
}

void incrementVerticalScrollStep(void) {
    switch (verticalScrollStepSize) {
        case ARROW: verticalScrollStepSize = MOUSE; break;
        case MOUSE: verticalScrollStepSize = PAGE; break;
        case PAGE:  verticalScrollStepSize = ARROW; break;
        default:    verticalScrollStepSize = PAGE; break;
    }
}

/*
 * Handle custom key codes
 */
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_ADJ_H_SCL: {
            if (record->event.pressed) {
                incrementHorizontalScrollStep();
            }
            break;
            return false;
        }
        case KC_ADJ_V_SCL: {
            if (record->event.pressed) {
                incrementVerticalScrollStep();
            }
            break;
            return false;
        }
    }

    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

  if (index == 0) {
      // Left side

      switch (horizontalScrollStepSize) {
          case ARROW:
              // Left/Right
              if (clockwise) {
                  tap_code(KC_RIGHT);
              } else {
                  tap_code(KC_LEFT);
              }
              break;
          case MOUSE:
              // MouseWheel Left/Right
              if (clockwise) {
                  tap_code(QK_MOUSE_WHEEL_RIGHT);
              } else {
                  tap_code(QK_MOUSE_WHEEL_LEFT);
              }
              break;
            case PAGE:
              // Home/END
              if (clockwise) {
                  tap_code(KC_END);
              } else {
                  tap_code(KC_HOME);
              }
              break;
            default: // TAB
              // Tab/Shift-Tab
              if (clockwise) {
                  tap_code(KC_TAB);
              } else {
                  tap_code16(S(KC_TAB));
              }
              break;
        }
    } else if (index == 1) {

        switch (verticalScrollStepSize) {
            case ARROW:
                // Up/Down
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case MOUSE:
                // MouseWheel Up/Down
                if (clockwise) {
                  tap_code(KC_WH_D);
                } else {
                  tap_code(KC_WH_U);
                }
                break;
            default:
                // Page Up/Page Down
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
        }
	}
    return false;
}
#endif
