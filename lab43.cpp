// Zach Nadeau
// CS 2315
// Lab 43


#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

// Use only with lab43main.C
// ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits) {
	vector<queue<uint> > buckets;
	uint n = v.size();
	const uint BASE = 10;
	
	buckets.resize(BASE);
	
	for (uint d = 0; d < numDigits; d++) {
		
		// Distribution Pass
		for (uint i = 0; i < n; i++) {
			buckets[(v.at(i) / static_cast<uint>(pow(BASE,d))) % BASE].push(v.at(i));
		}
		
		v.clear();
		
		// Gathering Pass
		for (uint i = 0; i < BASE; i++) {
			while (!buckets[i].empty()) {
				v.push_back(buckets[i].front());
				buckets[i].pop();
			}
		}
		
		// Use only with lab43main.C
		// cout << v << endl;
	}
}
