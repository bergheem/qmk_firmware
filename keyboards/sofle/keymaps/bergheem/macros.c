#define VERSION     "bergm0.8"

enum macro_keycodes {
    MC_VERS = SAFE_RANGE,
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