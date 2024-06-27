#include "libmx.h"

void mx_print_unicode(wchar_t c) {
	char uniChar[4];

	if (c < 0x80 ) {
		uniChar[0] = (c >> 0 & 0x7F ) | 0x00;
		write(1, uniChar, 1);

		return;
	}

	if (c < 0x0800 ) {
		uniChar[0] = (c >> 6 & 0x1F ) | 0xC0;
		uniChar[1] = (c >> 0 & 0x3F ) | 0x80;
		write(1, uniChar, 2);

		return;
	}

	if (c < 0x010000 ) {
		uniChar[0] = (c >> 12 & 0x0F) | 0xE0;
		uniChar[1] = (c >> 6 & 0x3F ) | 0x80;
		uniChar[2] = (c >> 0 & 0x3F ) | 0x80;
		write(1, uniChar, 3);

		return;
	}

	if (c < 0x110000) {
		uniChar[0] = (c >> 18 & 0x07 ) | 0xF0;
		uniChar[1] = (c >> 12 & 0x3F) | 0x80;
		uniChar[2] = (c >> 6 & 0x3F ) | 0x80;
		uniChar[3] = (c >> 0 & 0x3F ) | 0x80;
		write(1, uniChar, 4);

		return;
	}
}
