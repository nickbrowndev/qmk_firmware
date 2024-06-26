/* Copyright 2021 Don Kjer 
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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

const is31fl3733_led_t PROGMEM g_is31fl3733_leds[IS31FL3733_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */

   {0, C_1,   B_1,   A_1},  // Esc
   {0, C_2,   B_2,   A_2},  // F1
   {0, C_3,   B_3,   A_3},  // F2
   {0, C_4,   B_4,   A_4},  // F3
   {0, C_5,   B_5,   A_5},  // F4
   {0, C_6,   B_6,   A_6},  // F5
   {0, C_7,   B_7,   A_7},  // F6
   {0, C_8,   B_8,   A_8},  // F7
   {0, C_9,   B_9,   A_9},  // F8
   {0, C_10,  B_10,  A_10}, // F9
   {0, C_11,  B_11,  A_11}, // F10
   {0, C_12,  B_12,  A_12}, // F11
   {0, C_13,  B_13,  A_13}, // F12
   {0, C_14,  B_14,  A_14}, // PrtSc
   {0, C_15,  B_15,  A_15}, // Pause
   {0, C_16,  B_16,  A_16}, // Del

   {0, F_1,   E_1,   D_1},  // `
   {0, F_2,   E_2,   D_2},  // 1
   {0, F_3,   E_3,   D_3},  // 2
   {0, F_4,   E_4,   D_4},  // 3
   {0, F_5,   E_5,   D_5},  // 4
   {0, F_6,   E_6,   D_6},  // 5
   {0, F_7,   E_7,   D_7},  // 6
   {0, F_8,   E_8,   D_8},  // 7
   {0, F_9,   E_9,   D_9},  // 8
   {0, F_10,  E_10,  D_10}, // 9
   {0, F_11,  E_11,  D_11}, // 0
   {0, F_12,  E_12,  D_12}, // -
   {0, F_13,  E_13,  D_13}, // =
   {0, F_14,  E_14,  D_14}, // Bksp
   {0, F_15,  E_15,  D_15}, // Home

   {0, I_1,   H_1,   G_1},  // Tab
   {0, I_2,   H_2,   G_2},  // Q
   {0, I_3,   H_3,   G_3},  // W
   {0, I_4,   H_4,   G_4},  // E
   {0, I_5,   H_5,   G_5},  // R
   {0, I_6,   H_6,   G_6},  // T
   {0, I_7,   H_7,   G_7},  // Y
   {0, I_8,   H_8,   G_8},  // U
   {0, I_9,   H_9,   G_9},  // I
   {0, I_10,  H_10,  G_10}, // O
   {0, I_11,  H_11,  G_11}, // P
   {0, I_12,  H_12,  G_12}, // [
   {0, I_13,  H_13,  G_13}, // ]
   {0, I_14,  H_14,  G_14}, // Pipe
   {0, I_15,  H_15,  G_15}, // End

   {0, L_1,   K_1,   J_1},  // Caps
   {0, L_2,   K_2,   J_2},  // A
   {0, L_3,   K_3,   J_3},  // S
   {0, L_4,   K_4,   J_4},  // D
   {0, L_5,   K_5,   J_5},  // F
   {0, L_6,   K_6,   J_6},  // G
   {0, L_7,   K_7,   J_7},  // H
   {0, L_8,   K_8,   J_8},  // J
   {0, L_9,   K_9,   J_9},  // K
   {0, L_10,  K_10,  J_10}, // L
   {0, L_11,  K_11,  J_11}, // :
   {0, L_12,  K_12,  J_12}, // '
   {0, L_14,  K_14,  J_14}, // Enter
   {0, L_15,  K_15,  J_15}, // PgUp

   {1, C_1,   B_1,   A_1},  // LShift
   {1, C_3,   B_3,   A_3},  // Z
   {1, C_4,   B_4,   A_4},  // X
   {1, C_5,   B_5,   A_5},  // C
   {1, C_6,   B_6,   A_6},  // V
   {1, C_7,   B_7,   A_7},  // B
   {1, C_8,   B_8,   A_8},  // N
   {1, C_9,   B_9,   A_9},  // M
   {1, C_10,  B_10,  A_10}, // <
   {1, C_11,  B_11,  A_11}, // >
   {1, C_12,  B_12,  A_12}, // ?
   {1, C_13,  B_13,  A_13}, // RShift
   {1, C_14,  B_14,  A_14}, // Up
   {1, C_15,  B_15,  A_15}, // PgDn

   {1, F_1,   E_1,   D_1},  // LCtrl
   {1, F_2,   E_2,   D_2},  // LAlt
   {1, F_3,   E_3,   D_3},  // LGUI
   {1, F_7,   E_7,   D_7},  // Space
   {1, F_10,  E_10,  D_10}, // RAlt
   {1, F_11,  E_11,  D_11}, // Fn1
   {1, F_12,  E_12,  D_12}, // Fn2
   {1, F_13,  E_13,  D_13}, // Left
   {1, F_14,  E_14,  D_14}, // Down
   {1, F_15,  E_15,  D_15}  // Right
};

led_config_t g_led_config = {{
    { 0,  1,      2,  3,      4,      5,      6,  7,      8,      9,  10, 11, 12,     13, 14, 15     },
    { 16, 17,     18, 19,     20,     21,     22, 23,     24,     25, 26, 27, 28,     29, 30, NO_LED },
    { 31, 32,     33, 34,     35,     36,     37, 38,     39,     40, 41, 42, 43,     44, 45, NO_LED },
    { 46, 47,     48, 49,     50,     51,     52, 53,     54,     55, 56, 57, NO_LED, 58, 59, NO_LED },
    { 60, NO_LED, 61, 62,     63,     64,     65, 66,     67,     68, 69, 70, 71,     72, 73, NO_LED },
    { 74, 75,     76, NO_LED, NO_LED, NO_LED, 77, NO_LED, NO_LED, 78, 79, 80, 81,     82, 83, NO_LED }
}, {
    {  0,  0 }, { 16,  0 }, { 32,  0 }, { 48,  0 }, { 64,  0 }, { 80,  0 }, { 96,   0 }, { 112,  0 }, { 128,  0 }, { 144,  0 }, { 160,  0 }, { 176,  0 }, { 192,  0 }, { 208,  0 }, { 224,  0 }, { 240,  0 },
    {  0, 13 }, { 16, 13 }, { 32, 13 }, { 48, 13 }, { 64, 13 }, { 80, 13 }, { 96,  13 }, { 112, 13 }, { 128, 13 }, { 144, 13 }, { 160, 13 }, { 176, 13 }, { 192, 13 },              { 216, 13 }, { 240, 13 },
    {  4, 26 }, { 24, 26 }, { 40, 26 }, { 56, 26 }, { 72, 26 }, { 88, 26 }, { 104, 26 }, { 120, 26 }, { 136, 26 }, { 152, 26 }, { 168, 26 }, { 184, 26 }, { 200, 26 },              { 220, 26 }, { 240, 26 },
    {  6, 38 }, { 28, 38 }, { 44, 38 }, { 60, 38 }, { 76, 38 }, { 92, 38 }, { 108, 38 }, { 124, 38 }, { 140, 38 }, { 156, 38 }, { 172, 38 }, { 188, 38 },                           { 214, 38 }, { 240, 38 },
    { 10, 51 },             { 36, 51 }, { 52, 51 }, { 68, 51 }, { 84, 51 }, { 100, 51 }, { 116, 51 }, { 132, 51 }, { 148, 51 }, { 164, 51 }, { 180, 51 },              { 202, 51 }, { 224, 51 }, { 240, 51 },
    {  2, 64 }, { 22, 64 }, { 42, 64 },                                     { 101, 64 },                                        { 160, 64 }, { 176, 64 }, { 192, 64 }, { 208, 64 }, { 224, 64 }, { 240, 64 }
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,       1, 4,
    1,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    1, 4, 4,
    1, 1, 1,          4,          1, 1, 1, 4, 4, 4
}};
#endif /* RGB_MATRIX_ENABLE */
