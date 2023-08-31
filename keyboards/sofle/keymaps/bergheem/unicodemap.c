
#ifdef UNICODEMAP_ENABLE

#define KI_AUNC     X(UM_AGRV)
#define KI_EUNC     XP(UM_EGRV, UM_EACT)
#define KI_IUNC     X(UM_IGRV)
#define KI_OUNC     X(UM_OGRV)
#define KI_UUNC     X(UM_UGRV)
#define KI_DEGR     X(UM_DEGR)
#define KI_EURO     X(UM_EURO)

enum unicode_names {
    UM_SNEK,
	UM_ROKT,
	UM_KISS,
	UM_SQUI,
	UM_PIGG,
	UM_WINK,
	UM_HART,
	UM_AGRV,
	UM_EGRV,
	UM_EACT,
	UM_IGRV,
	UM_OGRV,
    UM_UGRV,
    UM_DEGR,
    UM_EURO,
};

const uint32_t unicode_map[] PROGMEM = {
    [UM_SNEK]  = 0x1F40D, // 🐍
    [UM_ROKT]  = 0x1F680, // 🚀
    [UM_KISS]  = 0x1F618, // 😘
	[UM_SQUI]  = 0x1F991, // 🦑
	[UM_PIGG]  = 0x1F416, // 🐖
	[UM_WINK]  = 0x1F609, // 😉
	[UM_HART]  = 0x02764, // ❤
	[UM_AGRV]  = 0x00E0, // à
	[UM_EGRV]  = 0x00E8, // è
	[UM_EACT]  = 0x00E9, // é
	[UM_IGRV]  = 0x00EC, // ì
	[UM_OGRV]  = 0x00F2, // ò
    [UM_UGRV]  = 0x00F9, // ù
	[UM_DEGR]  = 0x00B0, // °
	[UM_EURO]  = 0x20AC, // €
};

#endif
