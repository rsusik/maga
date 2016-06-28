#ifndef CF_H
#define CF_H

#include "common.h"
#include "common_def.h"
#include "lev.h"
#include "q_gram_utils.h"

#ifndef ASIZE
#define ASIZE 256
#endif

namespace cf {

	void cf1_verif_exact(const uchar *p, int m, const uchar *t, int n, int pos, int k, void *args) {
		if(memcmp(t + pos, p, m)==0) {
			indexes.insert(pos);
		}
	}

	void cf1_verif_lev(const uchar *p, int m, const uchar *t, int n, int pos, int k, void *args) {
		if(levenshtein<const uchar*>(p, t+pos, m, m) <= k) {
			indexes.insert(pos);
		}
	}

	template <void (*FUN_VERIF)(const uchar *, int, const uchar *, int, int, int, void *)> void
	cf1 (const uchar *p, const int m, const uchar *t, const int n, const int k, void *args) {
		long  count = 0, j = 0;
		char *A = (char*)calloc(ASIZE, CH_SIZE);
		if (A==NULL) { report_critical_error("Error: cf1: Can't allocate memory for variable A."); }
		for ( int i = 0; i < m; ++i) A[ p[i] ]++;
		count = -( m - k );
		for ( j = 0; j < m; j++ )
			if ( A[ t[j] ]-- > 0 ) count++;

		while (j <= n) {
			if ( count >= 0 ) {
				FUN_VERIF(p, m, t, n, j-m, k, args);
			}
			if ( ++A[ t[j - m] ] > 0 ) count--;
			if ( A[ t[j++] ]-- > 0 ) count++;
		}
		free(A);
	}

}

#endif
