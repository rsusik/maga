#ifndef LEV_H
#define LEV_H

uint64_t ver_lev = 0;

// Source: http://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C (2013-10)
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
template <class T> int levenshtein(T s1, T s2, unsigned int s1len, unsigned int s2len) {
	ver_lev++;
    unsigned int x, y, lastdiag, olddiag;
    unsigned int *column = new unsigned int[s1len+1];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++) {
        column[0] = x;
        for (y = 1, lastdiag = x-1; y <= s1len; y++) {
            olddiag = column[y];
            column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
            lastdiag = olddiag;
        }
    }
	int result = column[s1len];
	delete [] column;
    return(result);
}

#endif