/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
    QWERTY = 0,
    NUMPAD,
    NUML,
    ADJUST
};

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE,
    KC_SHIFT_BACKSPACE_DELETE,
    KC_SHIFT_SPACE_BACKSPACE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | TAB    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  [ {   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LSFT   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCTL   |   Z  |   X  |   C  |   V  |   B  | PRTSC|  AUX |  | Esc  | - _  |   N  |   M  | ,  < | . >  | /  ? |  ] }   |
 * `----------------------+------+------+------+------+      |  |------+------+------+------+------+----------------------'
 *                        |plypse| win  | alt  | num  | numpd|  | entr | spc  |  bs  |  =+  | \ |  |
 *                        |   vl |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [QWERTY] = LAYOUT(
      KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
      KC_LSFT, KC_A,   KC_S, KC_D, KC_F,   KC_G, KC_H, KC_J, KC_K,  KC_L, KC_SCLN, KC_QUOT,
      KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_PSCR,  MT(MOD_LGUI | MOD_LSFT, KC_DEL),  KC_ESC, KC_MINS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC,
              KC_MPLY, KC_LGUI, KC_LALT,TT(NUML) , TT(NUMPAD), KC_ENTER, KC_SPC, KC_SHIFT_BACKSPACE_DELETE, KC_EQUAL, KC_BSLASH
    ),
/*
 * Lower Layer: Numpad
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |  nlck| prtsc| sclck|break |                              |      |  7   |  8  |  9  | -  | /   
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | clck | ins  | home |pgup                                 |      |  4   |  5  |  6  | +  | *      |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |  sbd |del   | end  |pgdn  |      |      |  |      |  up  |      |  1   |  2  |  3  | ent| =       |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |  left| down | right|  0   |  .   |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUMPAD] = LAYOUT(
      _______, _______, KC_NLCK                  , KC_PSCR, KC_SLCK, KC_BRK,                                     _______, KC_P7,    KC_P8,    KC_P9, KC_PMNS, KC_PSLS,
      _______, _______, KC_CAPS                  , KC_INS, KC_HOME, KC_PGUP,                                    _______, KC_P4,    KC_P5,    KC_P6, KC_PPLS, KC_PAST,
      _______, _______, KC_SHIFT_BACKSPACE_DELETE, KC_DEL, KC_END, KC_PGDN, _______, _______, _______, KC_UP, _______, KC_P1,   KC_P2,    KC_P3, KC_PENT, KC_PEQL,
                                 _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT
    ),
/*
 * Raise Layer: Numbers, symbols, and F-keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |  `~    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |  F12   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  | F5   |      |      |  |      |      |   F6 |  F7  | F8   |  F9  | F10  |  F11   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [NUML] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
      _______, KC_1   , KC_2 ,   KC_3   , KC_4  , KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
      _______, KC_F1  , KC_F2,   KC_F3  , KC_F4 , KC_F5, _______, _______, _______, _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Navigation Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home | Up   | End  |      | ScrlLk |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | PgDn | Left | Down | Right|      | CapsLk |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_SLCK,
      _______, _______, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_CAPS,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

static layer_state_t newstate;
layer_state_t layer_state_set_user(layer_state_t state) {
    newstate = update_tri_layer_state(state, NUMPAD, NUML, ADJUST);
    rgblight_set_layer_state(1, layer_state_cmp(newstate, NUMPAD));
    rgblight_set_layer_state(2, layer_state_cmp(newstate, NUML));
    rgblight_set_layer_state(3, layer_state_cmp(newstate, ADJUST));
    return newstate;
}


//gr: https://www.reddit.com/r/olkb/comments/iuw3f1/qmk_shiftspacebackspace_shiftbackspacedelete/
//which shift is held?//
static uint16_t held_shift = 0;
//is shift held?//
static bool shift_held = false;
static bool bsdel_mods = false;
static bool bsspace_mods = false;
uint8_t mod_state = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSFT:
            //set "shift is held" variable//

            shift_held = record->event.pressed;
            //uprintf("shift_held: %s", shift_held ? "True" : "False");
            //specify which shift is held//
            held_shift = keycode;
            return true;
        break;
        case KC_RSFT:
            shift_held = record->event.pressed;
            held_shift = keycode;
            return true;
        break;
        case KC_SHIFT_BACKSPACE_DELETE:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                    bsdel_mods = true;
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                if (bsdel_mods) {
                    unregister_code(KC_DEL);
                    bsdel_mods = false;
                } else {
                unregister_code(KC_BSPC);
                }
            }
            return false;
        break;
        case KC_SHIFT_SPACE_BACKSPACE:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_BSPC);
                    bsspace_mods = true;
                } else {
                    register_code(KC_SPACE);
                }
            } else {
            if (bsspace_mods) {
                unregister_code(KC_BSPC);
                bsspace_mods = false;
            } else {
                unregister_code(KC_SPACE);
        }
        }
        return false;
        break;
    }
    return true;
}


bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
/*
static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}
*/
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
    oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case NUMPAD:
            oled_write_P(PSTR("NUMPAD\n"), false);
            break;
        case NUML:
            oled_write_P(PSTR("NUMLINE\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)

    } else {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        //render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
uint8_t the_layer = 0;
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
                if (clockwise)  {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
    } else if (index == 1) {
                the_layer = get_highest_layer(layer_state);
                xprintf("hi");
                if (clockwise) {
                    switch (the_layer) {
                            case QWERTY:
                                layer_clear();
                                layer_on(NUMPAD);
                                break;
                            case NUMPAD:
                                layer_clear();
                                layer_on(NUML);
                                break;
                            case NUML:
                                layer_clear();
                                layer_on(NUML);
                                layer_on(NUMPAD);                                
                                break;
                            case ADJUST:
                                layer_clear();
                                //layer_on(QWERTY);
                                break;
                    };
                } else {
                    switch (the_layer) {
                            case QWERTY:
                                layer_clear();
                                layer_on(NUML);
                                layer_on(NUMPAD);      
                                break;
                            case NUMPAD:
                                layer_clear();
                                //layer_on(QWERTY);
                                break;
                            case NUML:
                                layer_clear();
                                layer_on(NUMPAD);
                                break;
                            case ADJUST:
                                layer_clear();
                                layer_on(NUML);
                                break;
                    };
                }
    }
}
#endif

// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight#lighting-layers
// Light qwerty layer
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_WHITE},       // Light 1 LEDs, starting with LED 0
    {10, 1, HSV_WHITE}       // 
);
// Light numpad layer
const rgblight_segment_t PROGMEM my_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED},       // 
    {10, 1, HSV_RED}       // 
);
// Light numline layer
const rgblight_segment_t PROGMEM my_numline_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE},       // 
    {10, 1, HSV_BLUE}       // 
);
// Light adjust layer 
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN},       // 
    {10, 1, HSV_GREEN}       // 
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_numpad_layer,     
    my_numline_layer,    
    my_adjust_layer     
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, QWERTY));
    return state;
}

