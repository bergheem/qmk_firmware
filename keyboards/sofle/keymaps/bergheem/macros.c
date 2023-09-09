#include "version.c"

enum macro_keycodes {
	// keymap occupies these keycodes
    KC_OCCP0 = SAFE_RANGE,
    KC_OCCP1,
    KC_OCCP2,
    KC_OCCP3,
    KC_OCCP4,
    KC_OCCP5,
    KC_OCCP6,
	// macro keycodes
    MC_VERS,
    MC_LOGX,
    MC_SERF,
#ifdef UNICODE_ENABLE
	MC_TTBL,
    MC_UGRV,
#endif
};


bool send_macro(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case MC_VERS:
			if (record->event.pressed) {
				// when keycode MC_VERS is pressed
				SEND_STRING(VERSION);
			} else {
				// when keycode MC_VERS is released
			}
			return true;
			break;
		case MC_LOGX:
			if (record->event.pressed) {
				SEND_STRING("Debug.LogError(\"X\");");
			}
			return true;
			break;
		case MC_SERF:
			if (record->event.pressed) {
				SEND_STRING("[SerializeField]");
			}
			return true;
			break;
	#ifdef UNICODE_ENABLE
		case MC_TTBL:
			if (record->event.pressed) {
				send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
			}
			return true;
			break;
		case MC_UGRV:
			if (record->event.pressed) {
				send_unicode_string("ù");
			}
			return true;
			break;
    #endif
    }
	
    return true;
};