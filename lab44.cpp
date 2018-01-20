// Zach Nadeau
// CS 2315
// Lab 44


#include <cctype>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
	deque<char> que;
	uint i, n = str.size();
	
	transform(str.begin(), str.end(), str.begin(), static_cast<int (*)(int)>(toupper));
	
	for(i = 0; i < n; i++) {
		que.push_back(str.at(i));
	}
	
	while(que.size() > 1) {
		if (que.front() != que.back())
			return false;
		que.pop_front(); que.pop_back();
	}
	
	return true;
}
