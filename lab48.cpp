// Zach Nadeau
// CS 2315
// Lab 48


#include <queue>

using namespace std;

template<typename T>
void distribution(const priority_queue<T>& pq, ostream& os) {
	if (pq.empty()) { return; }
	
	priority_queue<T> pqCopy(pq);
	uint count = 0;
	T value = pqCopy.top();
	
	while (!pqCopy.empty()) {
		if (pqCopy.top() == value)
			count++;
		else {
			os << value << '(' << count << ")\n";
			value = pqCopy.top();
			count = 1;
		}
		pqCopy.pop();
	}
	
	os << value << '(' << count << ")\n";
}
