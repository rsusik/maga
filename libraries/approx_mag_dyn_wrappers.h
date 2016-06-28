#ifndef APPROX_MAG_DYN_WRAPPERS_H
#define APPROX_MAG_DYN_WRAPPERS_H

#include "q_gram_utils.h"
#include "common.h"

namespace mag_dyn {

	/* Definitions */
	using namespace Q_GRAM_UTIL_V; // defines which q-gram creation should be used

	size_t get_super_sigma(const unsigned int q_size) {
		if( q_size == 1 ) {
			return get_1_gram::super_sigma;
		} else if( q_size == 2 ) {
			return get_2_gram::super_sigma;
		} else if( q_size == 3 ) {
			return get_3_gram::super_sigma;
		} else if( q_size == 4 ) {
			return get_4_gram::super_sigma;
		} else if( q_size == 5 ) {
			return get_5_gram::super_sigma;
		} else if( q_size == 6 ) {
			return get_6_gram::super_sigma;
		} else if( q_size == 7 ) {
			return get_7_gram::super_sigma;
		} else if( q_size == 8 ) {
			return get_8_gram::super_sigma;
		} else if( q_size == 9 ) {
			return get_9_gram::super_sigma;
		} else if( q_size == 10 ) {
			return get_10_gram::super_sigma;
		} else {
			printf("Error: Not supported parameters\n"); exit(1); 
		}
	}
	
	long build_indexed_patterns_wrapper(uchar *patterns_txt, int pattern_txt_size, int nparts, int part_size, int pattern_size, int q_size) {
			if( q_size == 1 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_1_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 2 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_2_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 3 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_3_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 4 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_4_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 5 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_5_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 6 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_6_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 7 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_7_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 8 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_8_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 9 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_9_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else if( q_size == 10 ) {
				return approx_mag_dyn::approx_mag_dyn_build_indexed_patterns<get_10_gram>(patterns_txt, pattern_txt_size, nparts, part_size, pattern_size);
			} else {
				printf("Error: Not supported parameters\n"); exit(1); 
			}
	}
	
	void search_wrapper(const unsigned int U, const unsigned int k, const unsigned int q_size, const uchar *text, long text_size, int part_size, int p_number, void *args) {
		// Generated code
		if( k == 1 && U == 4 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 4 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 4 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 4 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 8 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 8, 1, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 8 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 8, 2, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 8 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 8, 4, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		}
		// U = 2
		else if( k == 1 && U == 2 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 1 ) {
			mag_dyn::mag_dyn<get_1_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_1_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 2 ) {
			mag_dyn::mag_dyn<get_2_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_2_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 3 ) {
			mag_dyn::mag_dyn<get_3_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_3_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 4 ) {
			mag_dyn::mag_dyn<get_4_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_4_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 5 ) {
			mag_dyn::mag_dyn<get_5_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_5_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 6 ) {
			mag_dyn::mag_dyn<get_6_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_6_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 7 ) {
			mag_dyn::mag_dyn<get_7_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_7_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 8 ) {
			mag_dyn::mag_dyn<get_8_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_8_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 9 ) {
			mag_dyn::mag_dyn<get_9_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_9_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 1 && U == 2 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 4, 1, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 2 && U == 2 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 4, 2, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else if( k == 4 && U == 2 && q_size == 10 ) {
			mag_dyn::mag_dyn<get_10_gram, 4, 4, approx_mag_dyn::approx_mag_dyn_verification<get_10_gram>>((const uchar*)text, text_size, part_size, p_number, (void*)(args) );
		} else {
			printf("Error: Not supported parameters\n"); exit(1); 
		}
	}
}


#endif