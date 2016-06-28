#ifndef COMMON_DEF_H
#define COMMON_DEF_H

#include <unordered_set>
// ================================
// Counters and indexes
long counter = 0;
std::unordered_set<unsigned long> indexes;

long long print_matches() {
	std::set<unsigned long> indexes_ordered( indexes.begin(), indexes.end() );
	for(std::set<unsigned long>::iterator itr = indexes_ordered.begin(); itr != indexes_ordered.end(); itr++) {
		printf("%ld\n", *itr); // vector 
	}
	indexes_ordered.clear();
	return indexes.size();
}
// ================================

#endif