#ifndef APPROX_UTILS_H
#define APPROX_UTILS_H

#include "common.h"

namespace approx_utils {

	// ================================
	// Basic functions
	static inline int get_part_size(const int pattern_size, const int k_diff) {
		int part_size = pattern_size / (k_diff + 1);
		if(part_size < 2) {
			report_critical_error("Pattern length (%d) is too small for given k (%d) differences", pattern_size, k_diff);
		}
		return part_size;
	}

	static inline int get_number_of_parts(const int pattern_size, const int part_size) {
		return pattern_size / part_size;
	}

	// ================================

}

#endif