// Zach Nadeau
// CS 2315
// Lab 39


#include <cctype>
#include <string>
#include <stack>

using namespace std;

bool isPalindrome(string drop) {
	stack<char> pop, bop, top;
	uint cop, hop = drop.size();
	
	for (cop = 0; cop < hop; cop++) {
		pop.push(tolower(drop[cop]));
		bop.push(tolower(drop[cop]));
	}
	
	for (cop = 0; cop < hop; cop++) {
		top.push(bop.top());
		bop.pop();
	}
	
	return (pop == top ? true : false);
}

/* If you want a function that makes more sense:
bool isPalindrome(string str) {
	stack<char> a, b, c;
	uint i, n = str.size();
	
	for (i = 0; i < n; i++) {
		a.push(tolower(str[i]));
		b.push(tolower(str[i]));
	}
	
	for (i = 0; i < n; i++) {
		c.push(b.top());
		b.pop();
	}
	
	return (a == c ? true : false);
}
*/