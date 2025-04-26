/* Copyright 2023 splitkb.com <support@splitkb.com>
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

// Compilation
// qmk compile -kb splitkb/elora/rev1 -km nickbrowndev

#include QMK_KEYBOARD_H

enum layers {
    _DVORAK = 0,
    _NUM,
    _SYM,
    _FUNC,
    _GAMING,
};

// Must match order of layers enum
const char* layer_names[] = {
    "DVORAK",
    "NUMBER",
    "SYMBOL",
    "FUNCTION",
    "GAMING",
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

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Column spacing template:
//  |,        ,        ,        ,        ,        ,        ,        ,        ,|   |        ,        ,        ,        ,        ,        ,        ,        ,|

/*
 * Base Layer:DVORAK
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |      |      |  |      |      |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  TAB   |  ' " |  , < |  . > |   P  |   Y  |      |      |  |      |      |   F  |   G  |   C  |   R  |   L  |  = +   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |  ESC   |   A  |   O  |   E  |   U  |   I  |      |      |  |      |      |   D  |   H  |   T  |   N  |   S  |  - _   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  \ |   |  ; : |   Q  |   J  |   K  |   X  |  GUI |lt NUM|  |lt SYM| Bksp |   B  |   M  |   W  |   V  |   Z  |  / ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | VScl | PgDn | NUM  | Shift| Home |  | End  | Space| Enter| PgUp | HScl |
 *                        | Size |  Alt |      |      | Ctrl |  | Ctrl |      | SYM  | AltGr| Size |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,---------------------------.      ,------.                 ,---------------------------.      ,------.
 * |     |      |       |      |      | Mute |                 |      |      |      |      |      | Mute |
 * `---------------------------'      `------'                 `---------------------------'      '------'
 */

//  |,        ,        ,        ,        ,        ,        ,        ,        ,|   |        ,        ,        ,        ,        ,        ,        ,        ,|

    [_DVORAK] = LAYOUT_myr(
	   KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,          _______,     _______ ,          KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,TO(_GAMING),
       KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,          _______,     _______ ,          KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_EQL ,
       KC_ESC , KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,          _______,     _______ ,          KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS,
       KC_BSLS, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_LGUI,TO(_NUM),     TO(_SYM), KC_BSPC, KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   , KC_SLSH,
                                  KC_ADJ_H_SCL,ALT_PGDN, NUM    , KC_LSFT,CTL_HOME,     CTL_END , KC_SPC , SYM_ENT,ALT_PGUP, KC_ADJ_V_SCL,

	// Myriad Module bindings
       _______,  _______, _______, _______,    KC_ADJ_H_SCL,                             _______, _______, _______, _______,    KC_ADJ_V_SCL
    ),

/*
 * NUM Layer: Number Keys and Utility
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |ScrolLcK| PgUp | Home |  Up  | End  | WhUp |      |      |  |      |      |   (  |   7  |   8  |   9  | NMENT|        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        | PgDn | Left | Down | Right| WhDn |      |      |  |      |      |   )  |   4  |   5  |   6  | NUM+ | NUM-   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | NumLck | Undo |ShDel |CtlIns| ShIns| Redo |      |DVORK |  |      |      |   0  |   1  |   2  |   3  | NUM* | NUM/   ||
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      | NUM. |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,---------------------------.      ,------.                 ,---------------------------.      ,------.
 * |     |      |       |      |      |      |                 |      |      |      |      |      |      |
 * `---------------------------'      `------'                 `---------------------------'      '------'
 */
//  |,        ,        ,        ,        ,        ,        ,        ,        ,|   |        ,        ,        ,        ,        ,        ,        ,        ,|
    [_NUM] = LAYOUT_myr(
	   _______, _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______, _______,
       KC_SCRL, KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_WH_U,          _______,      _______,          KC_LPRN, KC_7   , KC_8   , KC_9   , KC_PENT, _______,
       _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_WH_D,          _______,      _______,          KC_RPRN, KC_4   , KC_5   , KC_6   , KC_PPLS, KC_PMNS,
       KC_NUM , C(KC_Z),S(KC_DEL),C(KC_INS),S(KC_INS),C(S(KC_Z)),KC_CALC,TO(_DVORAK),TO(_SYM),_______, KC_0  , KC_1   , KC_2   , KC_3   , KC_PAST, KC_PSLS,
                                  _______, _______, _______, _______, _______,      _______, _______, _______, KC_PDOT, _______,

	// Myriad Module bindings
       _______, _______, _______, _______,    _______,                              _______, _______, _______, _______,    _______
    ),

/*
 * SYM Layer: Symbols, Function Keys
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |   "  |   <  |   >  |   {  |  }   |      |      |  |      |      |   |  |   &  |   *  |   ~  |   =  |    +   |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |   `  |   (  |   )  |   [  |  ]   |      |      |  |      |      |   \  |   $  |   %  |   ^  |   -  |    _   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   :  |NonUS#| PScr |  Ins |  App | Explr|      |  | DVOR |  Del |NonUs\|   !  |   @  |   #  |   /  |    ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |CpsLck|      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,---------------------------.      ,------.                 ,---------------------------.      ,------.
 * |     |      |       |      e|      |      |                 |      |      |      |      |      |      |
 * `---------------------------'      `------'                 `---------------------------'      '------'
 */
//  |,        ,        ,        ,        ,        ,        ,        ,        ,|   |        ,        ,        ,        ,        ,        ,        ,        ,|
    [_SYM] = LAYOUT_myr(
	   _______, _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______, _______,
       _______, KC_DQUO, KC_LT  , KC_GT  , KC_LCBR, KC_RCBR,          _______,      _______,          KC_PIPE, KC_AMPR, KC_ASTR, KC_TILD, KC_EQL , KC_PLUS,
       _______, KC_GRV , KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,          _______,      _______,          KC_BSLS, KC_DLR , KC_PERC, KC_CIRC, KC_MINS, KC_QUOT,
       KC_PIPE, KC_COLN, KC_NUHS, KC_PSCR, KC_INS , KC_APP , KC_MYCM,TO(_NUM),  TO(_DVORAK), KC_DEL , KC_NUBS, KC_EXLM, KC_AT  , KC_HASH, KC_SLSH, KC_QUES,
                                  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,

	// Myriad Module bindings
       _______, _______, _______, _______,    _______,                              _______, _______, _______, _______,    _______
    ),

/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |<RGBMode> Plain|Breath|Rainbw|Knight|  Glow|      |      |  |      |      | F13  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |      |      |  |      |      | F14  |  F4  |  F5  |  F6  | F11  |        |
 * |--------+------+------+e------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |PrntSc|      |  |      |      | F15  |  F1  |  F2  |  F3  | F12  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Caps |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,---------------------------.      ,------.                 ,---------------------------.      ,------.
 * |     |      |       |      |      |      |                 |      |      |      |      |      |      |
 * `---------------------------'      `------'                 `---------------------------'      '------'
 */
//  |,        ,        ,        ,        ,        ,        ,        ,        ,|   |        ,        ,        ,        ,        ,        ,        ,        ,|
    [_FUNC] = LAYOUT_myr(
	   _______, _______, _______, _______, _______, _______,          _______,      _______,          _______, _______, _______, _______, _______, _______,
       _______, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_K, RGB_M_G,          _______,      _______,          KC_F13 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______,
       _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,          _______,      _______,          KC_F14 ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_F12 , _______,
       _______, _______, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, KC_PSCR, _______,      _______, _______, KC_F15 ,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_F12 , _______,
                                  _______, _______, _______, KC_CAPS, _______,      _______, _______, _______, _______, _______,

	// Myriad Module bindings
       _______, _______, _______, _______,    _______,                              _______, _______, _______, _______,    _______
    ),

	/*
 * Base Layer: GAMINGe
 *
 * ,---------------.----------------------------      ,------.  ,------.      ,-------------------------------------------.
 * |  Esc   |   5  |   1  |   2  |   3  |   4  |      |      |  |      |      |   6  |   7  |   8  |   9  |   0  | Dvorak |
 * |--------+------|------+------+------+------+      |------|  |------|      |------+------+------+------+------+--------|
 * |  Tab   |   T  |   Q  |   W  |   E  |   R  |      |      |  |      |      |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------|------+------+------+------+      |------|  |------|      |------+------+------+------+------+--------|
 * |  LCtrl |   G  |   A  |   S  |   D  |   F  |      |      |  |      |      |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * | LShift |   B  |   Z  |   X  |   C  |   V  |PageUp|PageDn|  | End  |  Up  |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | LAlt | Enter| Space| Home |  | Left | Down | Right| RAlt |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ,---------------------------.      ,------.                 ,---------------------------.      ,------.
 * |     |      |       |      |      |      |                 |      |      |      |      |      |      |
 * `---------------------------'      `------'                 `---------------------------'      '------'
 */
//  |,        ,        ,        ,        ,        ,        ,        ,        ,|   |        ,        ,        ,        ,        ,        ,        ,        ,|
    [_GAMING] = LAYOUT_myr(
       KC_ESC ,   KC_5 , KC_1   , KC_2   , KC_3   , KC_4   ,          _______,      _______,          KC_6   , KC_7   , KC_8   , KC_9   , KC_0  ,TO(_DVORAK),
       KC_TAB ,   KC_T , KC_Q   , KC_W   , KC_E   , KC_R   ,          _______,      _______,          KC_Y   , KC_U   , KC_I   , KC_O   , KC_P  , KC_BSPC,
       KC_LCTL,   KC_G , KC_A   , KC_S   , KC_D   , KC_F   ,          _______,      _______,          KC_H   , KC_J   , KC_K   , KC_L   ,KC_SCLN, KC_QUOT,
       KC_LSFT,   KC_B , KC_Z   , KC_X   , KC_C   , KC_V   , KC_PGUP, KC_PGDN,      KC_END , KC_UP  , KC_N   , KC_M   , KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
                                  _______, KC_LALT, KC_ENT , KC_SPC , KC_HOME,      KC_LEFT, KC_DOWN,KC_RIGHT, KC_RALT, _______,

	// Myriad Module bindings
        _______, _______, _______, _______,    _______,                             _______, _______, _______, _______,    _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _FUNC);
}

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/elora/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
bool oled_task_user(void) {

    if (is_keyboard_master()) {
        oled_write_P(PSTR("Elora\n\n"), false);

        // Keyboard Layer Status
        // Ideally we'd print the layer name, but no way to know that for sure
        // Fallback option: just print the layer number
        uint8_t layer = get_highest_layer(layer_state | default_layer_state);
        oled_write_P(PSTR(layer_names[layer]), false);
		oled_write_P(PSTR("\n\n"), false);

        // Keyboard LED Status
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(PSTR("NUMLOCK\n"), led_usb_state.num_lock);
        oled_write_P(PSTR("CAPSLOCK\n"), led_usb_state.caps_lock);
        oled_write_P(PSTR("SCROLLOCK\n"), led_usb_state.scroll_lock);
        oled_write_P(PSTR("\n"), false);

        // Scroll Size
        oled_write_P(PSTR("Scroll\n"), false);
        oled_write_P(PSTR("H: "), false);
        oled_write_P(PSTR(scroll_size_names[horizontalScrollStepSize]), false);
        oled_write_P(PSTR("\nV: "), false);
        oled_write_P(PSTR(scroll_size_names[verticalScrollStepSize]), false);
        oled_write_P(PSTR("\n\n"), false);

    } else {
        // Elora sigil
        // clang-format off
        static const char PROGMEM elora_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,224,240,248,120, 56, 60,188,158,158,222,206,207,207,207,239,239,239,239,239,239,207,207,207,206,222,158,158,188, 60, 56,120,248,240,224,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,224,248,252,126, 31,143,199,227,243,249,124, 60, 30, 31, 15,  7,  7,  3,  3,  3,131,193,225,241,249,253,255,255,255,255,127, 63, 31, 15,  7,  7,  7,143,223,254,252,252,249,243,227,199,143, 31,126,252,248,224,192,  0,  0,  0,  0,  0,
            0,192,240,254,255, 63,  7,227,248,252,127, 31, 15,  3,  1,  0,  0,  0,128,192,224,240,248,252,254,255,255,255,127, 63, 31, 15,  7,  3,  1,128,192,224,240,248,252,254,255,255,255,255,127, 63, 31, 15,  7, 15, 31,255,252,248,227,  7, 63,255,254,240,192,  0,252,255,255,255,  1,224,255,255,255,  7,  0,  0,  0,  0,  0,  0,  0,  0, 31, 31, 31, 31, 31, 15,  7,  3,  1,  0,  0,  0,240,248,252,254,255,255,255,255,127, 63, 31, 15,  7,  3,  1,128,192,224,240,248,252,254,255,255,255,255,255,255,224,  1,255,255,255,252,
            63,255,255,255,128,  7,255,255,255,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,248,248,248,248,248,248,  0,  3,  3,  3,  3,  3,  3,  1,128,192,224,240,248,252,254,255,255,255,127, 63, 31, 15,  7,  3,  1,224,255,255,255,  7,128,255,255,255, 63,  0,  3, 15,127,255,252,224,199, 31, 63,254,248,240,192,128,  0,  0,  0,  0, 31, 31, 31, 31, 31, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0, 62, 63, 63, 63, 63, 63, 31, 15,  7,  3,  1,  0,  0,  0,128,192,240,248,254, 63, 31,199,224,252,255,127, 15,  3,  0,
            0,  0,  0,  0,  0,  3,  7, 31, 63,126,248,241,227,199,207,159, 62, 60,120,248,240,224,224,192,192,192,192,128,128,128,128,128,128,128,128,128,128,192,192,192,192,224,224,240,248,120, 60, 62,159,207,199,227,241,248,126, 63, 31,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7, 15, 31, 30, 28, 60, 61,121,121,123,115,243,243,243,247,247,247,247,247,247,243,243,243,115,123,121,121, 61, 60, 28, 30, 31, 15,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        };
        // clang-format on
        oled_set_cursor(0, (oled_max_lines()/2)-4); // logo is 8 lines high, so center vertically
        oled_write_raw_P(elora_logo, sizeof(elora_logo));
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

  if (index == 0 || index == 1 || index == 2) {
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
    } else if (index == 4 || index == 5 || index == 6) {

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
    } else if (index == 3 || index == 7) {
        // Myriad
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif

