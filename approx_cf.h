#ifndef APPROX_CF_H
#define APPROX_CF_H

#ifndef K_DIFF
#define K_DIFF 2
#endif

#include "libraries/cf.h"

namespace approx_cf {

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

}

#endif