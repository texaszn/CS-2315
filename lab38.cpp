// Zach Nadeau
// CS 2315
// Lab 38


#include<cmath>
#include<d_matrix.h>

// ostream& operator<<(ostream& os, const vector<uint>& v);

using namespace std;

void bucketSort(vector<uint>& v, uint numDigits) {
	matrix<uint> buckets;
	uint b, d, i, j, n = v.size();
	const uint BASE = 10;
	
	buckets.resize(BASE, 0);
	
	for (d = 0; d < numDigits; d++) {
		
		// Distribution Pass
		for (i = 0; i < n; i++) {
			buckets[(v.at(i) / static_cast<uint>(pow(BASE,d))) % BASE].push_back(v.at(i));
		}
		
		v.clear();
		
		// Gathering Pass
		for (i = 0; i < BASE; i++) {
			b = buckets[i].size();
			for (j = 0; j < b; j++) {
				v.push_back(buckets[i][j]);
			}
			buckets[i].clear();
		}
		
		// cout << v << endl;
	}
}
