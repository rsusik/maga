#ifndef MAG_DYN_H
#define MAG_DYN_H

#include "common.h"
#include "faoso.h"
#include "q_gram_utils.h"
#include <unordered_map>

/* Typedefs */
#ifdef ENV64BIT
	typedef		long double ldouble;
#endif
#ifdef ENV32BIT
	typedef		double ldouble;
#endif

// word *log2v = NULL; word log2cache = 0;

namespace mag_dyn {
	// patterns in text form
	uchar patterns[40000][500];

	template <class T, unsigned int U_i, unsigned int U, unsigned int K>
	struct mag_ { 
		static void get_d(word &d, const uchar *tt, word *b) {
			d = ( d << 1 ) | b[ T::get_q_gram(tt + (U-U_i)  * K * T::q_size) ];
			mag_<T, U_i-1, U, K>::get_d(d, tt, b);
		}
	};

	template <class T, unsigned int U, unsigned int K>
	struct mag_<T, 0, U, K> {
		static void get_d(word &d, const uchar *tt, word *b) {
			return;
		}
	};

	int64_t min_b = UINT64_MAX;
	int64_t max_b = 0;

	// main searching function based on faoso
	template <class T, int U, int K, void (*FUN_VERIF)(const uchar *, word, word, int, int *, void *)> int 
	mag_dyn(const uchar *text, long text_size, int p_size, int p_number, void *args) {
		word  *b = (word*)calloc(T::super_sigma, sizeof(word));
		word  d;
		word  mm;
		int  i, j, h, r, foo = U * K * T::q_size, *vt;
		const uchar  * tt;
		int max_m = ( MAX_WORD_SIZE / K + 1 - U ) * K - 2;
		int mod = p_size % T::q_size;
		int div = p_size / T::q_size;
		p_size = div - ( mod < (T::q_size - 1) ? 1 : 0 );
		if(p_size <= K) { report_critical_error("(m/2 and max_m)>=k, m=%d, max_m=%d, k=%d\n", p_size, max_m, K); }
		if(max_m < (int)p_size) { 
			p_size = max_m;
		}

		if( p_size > (int)MAX_WORD_SIZE ) {  free(b); report_critical_error("Error: patt_size > MAX_WORD_SIZE (%d > %d)", p_size, MAX_WORD_SIZE); }

		

		for( i = 0; i < T::super_sigma; i++ ) b[ i ] = ~( word )0; 
		for( j = h = 0, mm = ( word )0; j < K; j++ ) {
			for( i = 0; i < p_size/K; i++ ) {
				for( int z = 0; z < p_number; ++z) {
					for (int offset = 0; offset < T::q_size; offset++) { // Can be replaced by switch
						b[ T::get_q_gram(&mag_dyn::patterns[z][ i * K * T::q_size + j * T::q_size + offset]) ] &= ~(( word )1 << ( h ));
					}
				}
				++h;
			}
			for( r = 0; r < U; r++, h++ )
				mm = mm | (( word )1 << ( h - 1 )); 
			--h;
		}

		for( i = 0; i < T::super_sigma; i++ ) {
			min_b = min_b>b[i]?b[i]:min_b;
			max_b = max_b<b[i]?b[i]:max_b;
		}
		
		if( h > (int)MAX_WORD_SIZE ) { free(b); report_critical_error("Error: h=%d > %d\n", h, ( int )MAX_WORD_SIZE ); }
		for( i = 0; i < T::super_sigma; i++ ) b[ i ] &= ~( mm & ( mm << 1 ));
		vt = faoso::build_verify_table( p_size, K, U, 1 );
		d = ~mm; i = text_size; tt = text;
		do {
			mag_<T, U, U, K>::get_d(d, tt, b);

			if(( d & mm ) != mm ) FUN_VERIF( text, d, mm, tt - text - K * T::q_size + foo, vt, args );
			d &= ~mm;
			tt += foo;
		} while ( ( i -= foo ) > 0 );

		free(b);
		free(vt);

		return EXIT_SUCCESS;
	}

}

#endif