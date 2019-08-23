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
#include <string.h>
#include <ctype.h>

void	 hd(const u_char *, int);

void
hd(const u_char *data, int len)
{
	int	 i, len1;
	char	 abuf[17];

	len1 = ((len + 15) / 16) * 16;
	for (i = 0; i < len1; i++) {
		if ((i % 16) == 0) {
			fprintf(stderr, "%08x ", i);
			memset(abuf, 0, sizeof(abuf));
		}
		if (i < len) {
			fprintf(stderr, " %02x", data[i]);
			abuf[i % 16] = (isprint((int)data[i]))? data[i] : '.';
		} else
			fputs("   ", stderr);
		if ((i % 16) == 7)
			fprintf(stderr, " -");
		if ((i % 16) == 15)
			fprintf(stderr, " |%s|\n", abuf);
	}
}
