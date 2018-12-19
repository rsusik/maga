#ifndef APPROX_SHOR_H
#define APPROX_SHOR_H

#include "libraries/so.h"
#include "libraries/lev.h"
#include "libraries/approx_utils.h"
#include "approx_cf.h"

#ifndef K_DIFF
#define K_DIFF 2
#endif

namespace approx_shor {

	void print_result(double search_time, long ver_count, long matches, long text_file_size, long pattern_size, long k_diff
	) {
		double inmb = text_file_size / 1000.0 / 1000.0;
		printf("%ld\t", k_diff);							// k diff
		printf("%ld\t", text_file_size);					// data information
		printf("%ld\t%ld\t", ver_count, matches);			// search information
		printf("%lf\t", search_time);						// times
		printf("%f", inmb/search_time);						// speed
		printf("\n");
	}

	struct SO_verif_approx_args_s {
		int div;
		int pattern_size;
	};

	void cf1_verif_lev_with_offset(const uchar *p, int m, const uchar *t, int n, int pos, int k, void *args) {
		int levk = levenshtein<const uchar*>(p, t+pos, m, m);
		if(levk <= k ) {
			indexes.insert(pos + (* (int *)args) );
		}
	}

	void SO_verif_cf_lev(const uchar *p, int m, const uchar *t, int n, int pos, void *args) {
		int position = pos - ((SO_verif_approx_args_s*)args)->div - K_DIFF;

		cf::cf1<cf1_verif_lev_with_offset>(
			p - ((SO_verif_approx_args_s*)args)->div, 
			((SO_verif_approx_args_s*)args)->pattern_size, 
			t + position, 
			((SO_verif_approx_args_s*)args)->pattern_size + 2 * K_DIFF, 
			K_DIFF, 
			(void*)(&position)
		);
	}

	void SO_verif_exact(const uchar *p, int m, const uchar *t, int n, int pos, void *args) {
		int position = pos - ((SO_verif_approx_args_s*)args)->div;
		if (memcmp(p, t + position, ((SO_verif_approx_args_s*)args)->pattern_size) == 0) {
			indexes.insert(pos);
		};
	}

	void SO_verif_nothing(const uchar *p, int m, const uchar *t, int n, int pos, void *args) {
		int position = pos - ((SO_verif_approx_args_s*)args)->div;
		indexes.insert(position);
	}


}

#endif