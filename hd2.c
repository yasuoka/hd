/*
 * Copyright (c) 2017 YASUOKA Masahiko <yasuoka@yasuoka.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#include <stdio.h>

void
hd(const u_char *data, int len)
{
	int	 i;
	char	 buf[10], hexstr[] = "0123456789abcdef";
#define hexstring(_c, _b)				\
	do {						\
		(_b)[0] = hexstr[((_c) >> 4) & 0xf];	\
		(_b)[1] = hexstr[ (_c)       & 0xf];	\
		(_b)[2] = '\0';				\
	} while (0)

	for (i = 0; i < len; i++) {
		if ((i % 16) == 0) {
			hexstring(i >> 24, buf    );
			hexstring(i >> 16, buf + 2);
			hexstring(i >> 8 , buf + 4);
			hexstring(i      , buf + 6);
			printf("%s ", buf);
		}
		if ((i % 16) == 8)
			printf(" -");
		hexstring(data[i], buf);
		printf(" %s", buf);
		if ((i % 16) == 15)
			printf("\n");
	}
	if (i > 0 && (i % 16) != 0)
		printf("\n");
}
