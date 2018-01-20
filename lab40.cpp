// Zach Nadeau
// CS 2315
// Lab 40


#include <string>
#include <stack>

using namespace std;

bool isNestedCorrectly(string str) {
	stack<char> delimiters;
	uint n = str.size();
	
	for (uint i = 0; i < n; i++) {
		switch(str[i]) {
			case '(':
			case '[':
			case '{':
				delimiters.push(str[i]);
				break;
			case ')':
				if (delimiters.size() == 0)
					return false;
				else if (delimiters.top() == '(')
					delimiters.pop();
				break;
			case ']':
				if (delimiters.size() == 0)
					return false;
				else if (delimiters.top() == '[')
					delimiters.pop();
				break;
			case '}':
				if (delimiters.size() == 0)
					return false;
				else if (delimiters.top() == '{')
					delimiters.pop();
				break;
			default:
				break;
		}
	}
	
	return (delimiters.size() > 0 ? false : true);
}
