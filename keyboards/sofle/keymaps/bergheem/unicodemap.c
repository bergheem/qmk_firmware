

#ifdef UNICODEMAP_ENABLE

#define KI_UUNC     X(UM_UGRV)
#define KI_EUNC     XP(UM_EGRV, UM_EACT)

enum unicode_names {
    UM_SNEK,
    UM_UGRV,
	UM_EGRV,
	UM_EACT,
};

const uint32_t unicode_map[] PROGMEM = {
    [UM_SNEK]  = 0x1F40D, // 🐍
    [UM_UGRV]  = 0x00F9, // ù
	[UM_EGRV]  = 0x00E8, // è
	[UM_EACT]  = 0x00E9, // é
};

#endif
