// Zach Nadeau
// CS 2315
// Lab 42


#include <cctype>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
	stack<char> stk;
	queue<char> que;
	uint i, n = str.size();
	
	transform(str.begin(), str.end(), str.begin(), static_cast<int (*)(int)>(toupper));
	
	for(i = 0; i < n; i++) {
		stk.push(str.at(i));
		que.push(str.at(i));
	}
	
	for(i = 0; i < n; i++) {
		if (que.front() != stk.top())
			return false;
		que.pop(); stk.pop();
	}
	
	return true;
}
