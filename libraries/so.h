#ifndef SO_H
#define SO_H

#include "common.h"
#include "common_def.h"

#ifndef ASIZE
#define ASIZE 256
#endif

namespace shor {

	void SO_verif(const uchar *p, int m, const uchar *t, int n, int pos, void *args) {
		if (memcmp(p, t + pos, m) == 0) {
			indexes.insert(pos);
		}
	}

	template <void (*FUN_VERIF)(const uchar *, int, const uchar *, int, int, void *)> void 
	SO(uchar *p, int m, uchar *t, int n, void *args) {
		word D, mm, i, B[ASIZE], pos;

		if (m > MAX_WORD_SIZE) { m = MAX_WORD_SIZE; }

		// Preprocessing
		for (i = 0; i < ASIZE; ++i) B[i] = (word)~0;
		for (i = 0; i < m; ++i) B[(uchar)p[i]] &= ~((word)1<<i);
		D = (word)~0; mm = (word)1 << ( m - 1); i = 0;

		// Searching
		while (i < n) {
			D = ( D << 1 ) | B[(uchar)t[i]];
			if ( (D & mm) != mm ) {
				// Verifying
				FUN_VERIF(p, m, t, n, i-m+1, args);
			}
			++i;
		}
	}

}

#endif