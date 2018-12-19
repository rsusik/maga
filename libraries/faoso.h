// ------------------------------------------------------------------------------------
// This code was orginally written by Kimmo Fredriksson (University of Eastern Finland)
// Later modified by Robert Susik (Lodz University of Technology), changes:
// + "converted" to c++
// + added templates (metaprogramming)
// + some small conditions added (constraints)
// + search function added (faoso wrapper)
// ------------------------------------------------------------------------------------

#ifndef FAOSO_H
#define FAOSO_H

#include "common.h"
#include "common_def.h"

namespace faoso {

	static int* build_verify_table( int m, int k, int r, int l ) {
		int	mk, h, mpk = m / k, c, f, * t;
		t = (int*)malloc( MAX_WORD_SIZE * sizeof( int ));

		for( f = 0; f < r; f++ ) {
			c = ( 1 - f - mpk ) * k;
			mk = ( mpk * l - 1 + f * l );

			for( h = 0; h < k; h++, c-- ) {
				t[ mk ] = c; 
				mk += mpk * l + r - 1;
			}
		}
		return t;
	}

	// offset will be added to index number (use if not searching from the begining)
	void faoso_verify_opt( uchar * t, uchar * p, int m, word d, word mm, int pos, int * vt, int myn, void *arg ) {
		//++v_count;
		int	s, c;
		d = ( d & mm ) ^ mm;
		while( d ) {
			s = ilog2( d );
			c = vt[ s ] + pos;
			// Verification
			if(memcmp(t+c, p, m)==0) {
				indexes.insert(c);
			}
			d &= ~(( word )1 << s );
		}
	}

	/// Returns maximum available m.
	/// In case of error prints message and terminates program
	int inline get_max_m(int m, int u, int k) {
		//	int max_m = k * (MAX_WORD_SIZE - u);	// konf.
		int max_m = (MAX_WORD_SIZE) - k * (u - 1);
		if( m > max_m ) {
			m = max_m;
		}
		// Assume that we search at least 2 chars, so m should be >= 2*k
		if( m < 2*k ) { printf("Error: m < 2*k (%d < %d)", m, 2*k); exit(EXIT_FAILURE); }
		return m;
	}

	template <unsigned int U_i_PARAM, unsigned int U_PARAM, unsigned int K_PARAM>
	struct faoso_ { 
		static void get_d(word &d, uchar *tt, word *b) {
			d = ( d << 1 ) | b[ tt[ (U_PARAM - U_i_PARAM) * K_PARAM]];
			faoso_<U_i_PARAM-1, U_PARAM, K_PARAM>::get_d(d, tt, b);
		}
	};

	template <unsigned int U_PARAM, unsigned int K_PARAM>
	struct faoso_<0, U_PARAM, K_PARAM> {
		static void get_d(word &d, uchar *tt, word *b) {
			return;
		}
	};

	// as FUN_VERIFY use faoso_verify_opt with 0 as the offset paramter
	// offset is additional parameter and may be used to add functionality to validation
	template<unsigned int U_PARAM, unsigned int K_PARAM, void (*FUN_VERIFY)(uchar *, uchar *, int, word, word, int, int *, int, void*)> void 
	faoso( uchar * p, int m, uchar * text, unsigned long n, void *args ) {
		word		b[ 256 ];
		word		d;
		word		mm;
		int		i, j, h, r, *vt, foo = U_PARAM * K_PARAM, m_orginal = m;
		uchar		* tt;
		
		m = get_max_m(m, U_PARAM, K_PARAM);	// cutting m

		for( i = 0; i < 256; i++ ) b[ i ] = ~( word )0; 

		for( j = h = 0, mm = ( word )0; j < K_PARAM; j++ ) {
			for( i = 0; i < m/K_PARAM; i++ ) 
				b[ p[ i * K_PARAM + j ]] &= ~(( word )1 << ( h++ ));
			for( r = 0; r < U_PARAM; r++, h++ )
				mm = mm | (( word )1 << ( h - 1 )); 
			--h;
		}

		if( h > MAX_WORD_SIZE ) { printf("Error: h=%d >= %d (WSIZE), {\"Cannot shift more than WSIZE-1\", m = %d, k = %d, U = %d }\n", h, ( int )MAX_WORD_SIZE, m, K_PARAM, U_PARAM ); exit(EXIT_FAILURE); }
		for( i = 0; i < 256; i++ ) b[ i ] &= ~( mm & ( mm << 1 ));
		vt = build_verify_table( m, K_PARAM, U_PARAM, 1 );
		d = ~mm; i = n; tt = text;

		do {
			faoso_<U_PARAM, U_PARAM, K_PARAM>::get_d(d, tt, b);
			if(( d & mm ) != mm ) FUN_VERIFY( text, p, m_orginal, d, mm, tt - text - K_PARAM + foo, vt, n, args );
			d &= ~mm;
			tt += foo;

		} while(( i -= foo ) > 0 );
		free(vt);
	}

	template <void (*FUN_VERIFY)(uchar *, uchar *, int, word, word, int, int *, int, void*)> void 
	search(byte U, byte k, uchar * p, int m, uchar * text, unsigned long n, void *arg) {
		if (0) {
		} else if( U==1 && k==1 ) {
			faoso<1, 1, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==1 && k==2 ) {
			faoso<1, 2, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==1 && k==4 ) {
			faoso<1, 4, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==1 && k==6 ) {
			faoso<1, 6, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==1 && k==8 ) {
			faoso<1, 8, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==1 && k==12 ) {
			faoso<1, 12, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==1 && k==16 ) {
			faoso<1, 16, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==1 ) {
			faoso<2, 1, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==2 ) {
			faoso<2, 2, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==4 ) {
			faoso<2, 4, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==6 ) {
			faoso<2, 6, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==8 ) {
			faoso<2, 8, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==12 ) {
			faoso<2, 12, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==2 && k==16 ) {
			faoso<2, 16, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==1 ) {
			faoso<4, 1, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==2 ) {
			faoso<4, 2, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==4 ) {
			faoso<4, 4, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==6 ) {
			faoso<4, 6, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==8 ) {
			faoso<4, 8, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==12 ) {
			faoso<4, 12, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==4 && k==16 ) {
			faoso<4, 16, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==1 ) {
			faoso<8, 1, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==2 ) {
			faoso<8, 2, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==4 ) {
			faoso<8, 4, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==6 ) {
			faoso<8, 6, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==8 ) {
			faoso<8, 8, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==12 ) {
			faoso<8, 12, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==8 && k==16 ) {
			faoso<8, 16, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==1 ) {
			faoso<16, 1, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==2 ) {
			faoso<16, 2, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==4 ) {
			faoso<16, 4, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==6 ) {
			faoso<16, 6, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==8 ) {
			faoso<16, 8, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==12 ) {
			faoso<16, 12, FUN_VERIFY>(p, m, text, n, arg);
		} else if( U==16 && k==16 ) {
			faoso<16, 16, FUN_VERIFY>(p, m, text, n, arg);
		} else {
			printf("Error: faoso::search do not support given parameters (U=%d, k=%d)", U, k); exit(1);
		}
	}
}

#endif