#include QMK_KEYBOARD_H
#include "version.c"
#include "macros.c"
#include "unicodemap.c"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _ARROW,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_ARROW,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Space /       \ Enter\  |RAISE | RCTR | RAlt | Menu |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
	KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,								KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
	KC_ESC,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,								KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSPC,
	KC_TAB,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,								KC_H,		KC_J,		KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_MPLY,	KC_MUTE,	KC_N,		KC_M,		KC_COMM,	KC_DOT,		KC_SLSH,	KC_RSFT,
					KC_LGUI,	KC_LALT,	KC_LCTL,	MO(_LOWER),		KC_SPC,				KC_ENT,			MO(_RAISE),	KC_RCTL,	KC_ALGR,	KC_APP
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |  Up  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  | Left | Down | Right|   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Space /       \ Enter\  |RAISE | RCTR | RAlt | Menu |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ARROW] = LAYOUT(
	KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,								KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_MINS,
	KC_ESC,		KC_Q,		KC_W,		KC_E,		KC_R,		KC_T,								KC_Y,		KC_U,		KC_I,		KC_O,		KC_P,		KC_BSPC,
	KC_TAB,		KC_A,		KC_S,		KC_D,		KC_F,		KC_G,								KC_H,		KC_J,		KC_UP,		KC_L,		KC_SCLN,	KC_QUOT,
	KC_LSFT,	KC_Z,		KC_X,		KC_C,		KC_V,		KC_B,		KC_MPLY,	KC_MUTE,	KC_N,		KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_SLSH,	KC_RSFT,
					KC_LGUI,	KC_LALT,	KC_LCTL,	MO(_LOWER),		KC_SPC,				KC_ENT,			MO(_RAISE),	KC_RCTL,	KC_ALGR,	KC_APP
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | mute |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | Vers |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | F11  | F12  |  è é |   (  |   )  |                    |      |   ù  |   ì  |   ò  |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   // |   à  |   /  |   *  |   [  |   ]  |-------.    ,-------|   °  |      |      |      |   |  |      |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   =  |   -  |   +  |   {  |   }  |-------|    |-------|      |      |   ;  |   :  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |LOWER | /       /       \      \  |RAISE |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
	LALT(KC_M),	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,								KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		MC_VERS,
	_______,	KC_F11,		KC_F12,		KI_EUNC,	KC_LPRN,	KC_RPRN,							XXXXXXX,	KI_UUNC,	KI_IUNC,	KI_OUNC,	XXXXXXX,	KC_DEL,
	LCA(KC_C),	KI_AUNC,	KC_PSLS,	KC_ASTR,	KC_LBRC,	KC_RBRC,							KI_DEGR,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_PIPE,	XXXXXXX,
	_______,	KC_EQL,		KC_MINS,	KC_PLUS,	KC_LCBR,	KC_RCBR,	_______,	_______,	XXXXXXX,	XXXXXXX,	KC_SCLN,	KC_COLN,	KC_BSLS,	_______,
					_______,	_______,	_______,	_______,		_______,			_______,		_______,	_______,	_______,	_______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | LogX |SerFld|      |      |      |                    | Scrl |      |      |      | Pause| Vers |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  🐖  |   €  |  🚀  |  ❤ |                    | Caps |      |      |      | DLine|  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  🦑  |      |      |  😘 |-------.    ,-------|  Num |      |  Up  |      | Home | PgUp |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift| Undo |  Cut | Copy | Paste|  😉  |-------|    |-------| Pscr | Left | Down | Right|  End |PgDown|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |LOWER | /       /       \      \  |RAISE |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
	XXXXXXX,	MC_LOGX,	MC_SERF,	XXXXXXX,	XXXXXXX,	XXXXXXX,							KC_SCRL,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_PAUSE,	MC_VERS,
	XXXXXXX,	XXXXXXX,	X(UM_PIGG),	KI_EURO,	X(UM_ROKT),	X(UM_HART),							KC_CAPS,	XXXXXXX,	XXXXXXX,	XXXXXXX,	KC_INS, 	KC_DEL,
	XXXXXXX,	XXXXXXX,	X(UM_SQUI),	XXXXXXX,	XXXXXXX,	X(UM_KISS),							KC_NUM,		XXXXXXX,	KC_UP,		XXXXXXX,	KC_HOME,	KC_PGUP,
	_______,	KC_UNDO,	KC_CUT,		KC_COPY,	KC_PASTE,	X(UM_WINK),	_______,	_______,	KC_PSCR,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_END,		KC_PGDN,
					_______,	_______,	_______,	_______,		_______,			_______,    	_______,	_______,	_______,	_______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |QK_BOOT|QWERTY|     |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | ARROW|      |      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |LOWER | /       /       \      \  |RAISE |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,							XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	QK_BOOT,	KC_QWERTY,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,							XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	KC_ARROW,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,							XXXXXXX,	KC_VOLD,	KC_MUTE,	KC_VOLU,	XXXXXXX,	XXXXXXX,
	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,	XXXXXXX,     XXXXXXX,	XXXXXXX,	KC_MPRV,	KC_MPLY,	KC_MNXT,	XXXXXXX,	XXXXXXX,
					_______,	_______,	_______,	_______,		_______,			_______,    	_______,	_______,	_______,	_______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
	// Print current mode
	if (keymap_config.swap_lctl_lgui) {
        oled_write_P(PSTR("MAC\n"), false);
    } else {
        oled_write_P(PSTR("WIN\n"), false);
    }
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrt\n"), false);
            break;
        case _ARROW:
            oled_write_P(PSTR("Arrow"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
	
    // Print current layer
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _ARROW:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Confg"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
	
    // Print current locks
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("SCRLK"), led_usb_state.scroll_lock);
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_P(PSTR("NUMLK"), led_usb_state.num_lock);
	
    // Print current version
    oled_write_P(PSTR("\n\n\n\n"), false);
    oled_write_P(PSTR(VERSION), true);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_ARROW:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ARROW);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
	
	if(!send_macro(keycode, record))
		return false;
	
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
		led_t led_usb_state = host_keyboard_led_state();
        if (clockwise) {
			if (!led_usb_state.num_lock) {
				tap_code(KC_RGHT);
			} else {
				tap_code(KC_DOWN);
			}
        } else {
			if (!led_usb_state.num_lock) {
				tap_code(KC_LEFT);
			} else {
				tap_code(KC_UP);
			}
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

#endif
