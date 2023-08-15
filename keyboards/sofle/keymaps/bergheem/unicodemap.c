
#ifdef UNICODEMAP_ENABLE

#define KI_AUNC     X(UM_AGRV)
#define KI_EUNC     XP(UM_EGRV, UM_EACT)
#define KI_IUNC     X(UM_IGRV)
#define KI_OUNC     X(UM_OGRV)
#define KI_UUNC     X(UM_UGRV)

enum unicode_names {
    UM_SNEK,
	UM_AGRV,
	UM_EGRV,
	UM_EACT,
	UM_IGRV,
	UM_OGRV,
    UM_UGRV,
};

const uint32_t unicode_map[] PROGMEM = {
    [UM_SNEK]  = 0x1F40D, // 🐍
	[UM_AGRV]  = 0x00E0, // à
	[UM_EGRV]  = 0x00E8, // è
	[UM_EACT]  = 0x00E9, // é
	[UM_IGRV]  = 0x00EC, // ì
	[UM_OGRV]  = 0x00F2, // ò
    [UM_UGRV]  = 0x00F9, // ù
};

#endif
