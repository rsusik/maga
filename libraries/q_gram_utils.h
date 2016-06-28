#ifndef Q_GRAM_UTILS_H
#define Q_GRAM_UTILS_H

#ifndef Q_GRAM_UTIL_NEW_L
#define Q_GRAM_UTIL_NEW_L 2
#endif

namespace q_gram_utilities_dna_opt_l2 {

	struct get_1_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( (*(uint64_t*)x) & 0xFF) >> 1 ) & 0x03 );
		}
		static int const q_size = 1;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_2_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFF) >> 1 ) & 0x0303 ) * 0x401 ) >> 8 ) & 0xF;
		}
		static int const q_size = 2;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_3_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFFFF ) >> 1 ) & 0x030303) * 0x100401) >> 16 ) & 0x3F;
		}
		static int const q_size = 3;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_4_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFFFFFF ) >> 1 ) & 0x03030303) * 0x40100401) >> 24 ) & 0xFF;
		}
		static int const q_size = 4;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_5_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFFFFFFFF ) >> 1 ) & 0x0303030303) * 0x4010040100401) >> 32 ) & 0x3FF;
		}
		static int const q_size = 5;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_6_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_3_gram::get_q_gram(x+3) | get_3_gram::get_q_gram(x)<<6;
		}
		static int const q_size = 6;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_7_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_4_gram::get_q_gram(x+3) | get_3_gram::get_q_gram(x)<<8;
		}
		static int const q_size = 7;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_8_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_4_gram::get_q_gram(x+4) | get_4_gram::get_q_gram(x)<<8;
		}
		static int const q_size = 8;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_9_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_5_gram::get_q_gram(x+4) | get_4_gram::get_q_gram(x)<<10;
		}
		static int const q_size = 9;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

	struct get_10_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_5_gram::get_q_gram(x+5) | get_5_gram::get_q_gram(x)<<10;
		}
		static int const q_size = 10;
		static size_t const super_sigma = (uint64_t)1<<(2*q_size);
	};

};

namespace q_gram_utilities_dna_opt_l3 {

	struct get_1_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( (*(uint64_t*)x) & 0xFF) >> 1 ) & 0x07 );
		}
		static int const q_size = 1;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_2_gram {
		static uint64_t get_q_gram(const uchar *x) {
			//return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFF) >> 1 ) & 0x0707 ) * 0x421 ) >> 10 ) & 0x3F;
			return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFF) >> 1 ) & 0x0707 ) * 0x200400801 ) >> 8 ) & 0x3F;
		}
		static int const q_size = 2;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_3_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ( ( ( ( ( (*(uint64_t*)x) & 0xFFFFFF ) >> 1 ) & 0x070707) * 0x200400801) >> 16 ) & 0x1FF;
		}
		static int const q_size = 3;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_4_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_2_gram::get_q_gram(x+2) | get_2_gram::get_q_gram(x)<<6;
			//uint64_t s1 = ( ( ( ( ( (*(uint64_t*)x) ) >> 1 ) & 0x0707 ) * 0x400801 ) >> 8 ) & 0x3F;
			//uint64_t s2 = ( ( ( ( ( (*(uint64_t*)(x+2))) >> 1 ) & 0x0707 ) * 0x400801 ) >> (8-6) ) & 0xFC0;
			//return s1 | s2;
		}
		static int const q_size = 4;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_5_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_3_gram::get_q_gram(x+2) | get_2_gram::get_q_gram(x)<<9;
		}
		static int const q_size = 5;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_6_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_3_gram::get_q_gram(x+3) | get_3_gram::get_q_gram(x)<<9;
		}
		static int const q_size = 6;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_7_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_4_gram::get_q_gram(x+3) | get_3_gram::get_q_gram(x)<<12;
		}
		static int const q_size = 7;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_8_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_4_gram::get_q_gram(x+4) | get_4_gram::get_q_gram(x)<<12;
		}
		static int const q_size = 8;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_9_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_5_gram::get_q_gram(x+4) | get_4_gram::get_q_gram(x)<<15;
		}
		static int const q_size = 9;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

	struct get_10_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return get_5_gram::get_q_gram(x+5) | get_5_gram::get_q_gram(x)<<15;
		}
		static int const q_size = 10;
		static size_t const super_sigma = (uint64_t)1<<(3*q_size);
	};

};

namespace q_gram_utilities_dna_l_bits {

	static uint64_t const l = Q_GRAM_UTIL_NEW_L;
	static uint64_t const b = ((uint64_t)1<<l)-(uint64_t)1;

	struct get_1_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[0] >> 1) & b);
		}
		static int const q_size = 1;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_2_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[1] >> 1) & b) + (((x[0] >> 1) & b) << l);
		}
		static int const q_size = 2;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_3_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[2] >> 1) & b) + (((x[1] >> 1) & b) << l) + (((x[0] >> 1) & b) << 2*l);
		}
		static int const q_size = 3;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_4_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[3] >> 1) & b) + (((x[2] >> 1) & b) << l) + (((x[1] >> 1) & b) << 2*l) + (((x[0] >> 1) & b) << 3*l);
		}
		static int const q_size = 4;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_5_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[4] >> 1) & b) + (((x[3] >> 1) & b) << l) + (((x[2] >> 1) & b) << 2*l) + (((x[1] >> 1) & b) << 3*l) + (((x[0] >> 1) & b) << 4*l);
		}
		static int const q_size = 5;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_6_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[5] >> 1) & b) + (((x[4] >> 1) & b) << l) + (((x[3] >> 1) & b) << 2*l) + (((x[2] >> 1) & b) << 3*l) + (((x[1] >> 1) & b) << 4*l) + (((x[0] >> 1) & b) << 5*l);
		}
		static int const q_size = 6;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_7_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[6] >> 1) & b) + (((x[5] >> 1) & b) << l) + (((x[4] >> 1) & b) << 2*l) + (((x[3] >> 1) & b) << 3*l) + (((x[2] >> 1) & b) << 4*l) + (((x[1] >> 1) & b) << 5*l) + (((x[0] >> 1) & b) << 6*l);
		}
		static int const q_size = 7;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_8_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[7] >> 1) & b) + (((x[6] >> 1) & b) << l) + (((x[5] >> 1) & b) << 2*l) + (((x[4] >> 1) & b) << 3*l) + (((x[3] >> 1) & b) << 4*l) + (((x[2] >> 1) & b) << 5*l) + (((x[1] >> 1) & b) << 6*l) + (((x[0] >> 1) & b) << 7*l);
		}
		static int const q_size = 8;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_9_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[8] >> 1) & b) + (((x[7] >> 1) & b) << l) + (((x[6] >> 1) & b) << 2*l) + (((x[5] >> 1) & b) << 3*l) + (((x[4] >> 1) & b) << 4*l) + (((x[3] >> 1) & b) << 5*l) + (((x[2] >> 1) & b) << 6*l) + (((x[1] >> 1) & b) << 7*l) + (((x[0] >> 1) & b) << 8*l);
		}
		static int const q_size = 9;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_10_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return ((x[9] >> 1) & b) + (((x[8] >> 1) & b) << l) + (((x[7] >> 1) & b) << 2*l) + (((x[6] >> 1) & b) << 3*l) + (((x[5] >> 1) & b) << 4*l) + (((x[4] >> 1) & b) << 5*l) + (((x[3] >> 1) & b) << 6*l) + (((x[2] >> 1) & b) << 7*l) + (((x[1] >> 1) & b) << 8*l) + (((x[0] >> 1) & b) << 9*l);
		}
		static int const q_size = 10;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

};

namespace q_gram_utilities_l_bits {

	static uint64_t const l = Q_GRAM_UTIL_NEW_L;
	static uint64_t const b = ((uint64_t)1<<l)-(uint64_t)1;

	struct get_1_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return x[0] & b;
		}
		static int const q_size = 1;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_2_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[1] & b) + ((x[0] & b) << l);
		}
		static int const q_size = 2;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_3_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[2] & b) + ((x[1] & b) << l) + ((x[0] & b) << 2*l);
		}
		static int const q_size = 3;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_4_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[3] & b) + ((x[2] & b) << l) + ((x[1] & b) << 2*l) + ((x[0] & b) << 3*l);
		}
		static int const q_size = 4;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_5_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[4] & b) + ((x[3] & b) << l) + ((x[2] & b) << 2*l) + ((x[1] & b) << 3*l) + ((x[0] & b) << 4*l);
		}
		static int const q_size = 5;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_6_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[5] & b) + ((x[4] & b) << l) + ((x[3] & b) << 2*l) + ((x[2] & b) << 3*l) + ((x[1] & b) << 4*l) + ((x[0] & b) << 5*l);
		}
		static int const q_size = 6;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_7_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[6] & b) + ((x[5] & b) << l) + ((x[4] & b) << 2*l) + ((x[3] & b) << 3*l) + ((x[2] & b) << 4*l) + ((x[1] & b) << 5*l) + ((x[0] & b) << 6*l);
		}
		static int const q_size = 7;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_8_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[7] & b) + ((x[6] & b) << l) + ((x[5] & b) << 2*l) + ((x[4] & b) << 3*l) + ((x[3] & b) << 4*l) + ((x[2] & b) << 5*l) + ((x[1] & b) << 6*l) + ((x[0] & b) << 7*l);
		}
		static int const q_size = 8;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_9_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[8] & b) + ((x[7] & b) << l) + ((x[6] & b) << 2*l) + ((x[5] & b) << 3*l) + ((x[4] & b) << 4*l) + ((x[3] & b) << 5*l) + ((x[2] & b) << 6*l) + ((x[1] & b) << 7*l) + ((x[0] & b) << 8*l);
		}
		static int const q_size = 9;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

	struct get_10_gram {
		static uint64_t get_q_gram(const uchar *x) {
			return (x[9] & b) + ((x[8] & b) << l) + ((x[7] & b) << 2*l) + ((x[6] & b) << 3*l) + ((x[5] & b) << 4*l) + ((x[4] & b) << 5*l) + ((x[3] & b) << 6*l) + ((x[2] & b) << 7*l) + ((x[1] & b) << 8*l) + ((x[0] & b) << 9*l);
		}
		static int const q_size = 10;
		static size_t const super_sigma = (uint64_t)1<<(l*q_size);
	};

};

#endif