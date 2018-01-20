// Zach Nadeau
// CS 2315
// Lab 49


#include <queue>

template <typename T>
void pqSort(vector<T>& v) {
	priority_queue< T, vector<T>, greater<T> > pq;
	
	while (!v.empty()) {
		pq.push(v.back());
		v.pop_back();
	}
	
	while (!pq.empty()) {
		v.push_back(pq.top());
		pq.pop();
	}
}