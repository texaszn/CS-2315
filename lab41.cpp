// Zach Nadeau
// CS 2315
// Lab 41


#include <iostream>
#include <cctype>
#include <stack>
#include <string>

using namespace std;

bool isoperator(char);
uint Presedence(char);

void infix2Postfix(string infix, ostream& out) {
	stack<char> postfix;
	uint n = infix.size();
	
	for(uint i = 0; i < n; i++) {
		if (isspace(infix[i]))
			continue;
		else if (infix[i] == '(')
			postfix.push(infix[i]);
		else if (isupper(infix[i]))
			out << infix[i] << ' ';
		else if (isoperator(infix[i])) {
			while (!postfix.empty()
			&& postfix.top() != '(' 
			&& (Presedence(postfix.top()) >= Presedence(infix[i]))) {
				out << postfix.top() << ' ';
				postfix.pop();
			}
			postfix.push(infix[i]);
		}
		else {
			while (postfix.top() != '(') {
				out << postfix.top() << ' ';
				postfix.pop();
				if (postfix.empty()) { out << "error\n"; }
			}
			if (!postfix.empty())
				postfix.pop();
		}
	}
	
	while (!postfix.empty()) {
		out << postfix.top() << ' ';
		postfix.pop();
	}
}

bool isoperator(char c) {
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	return false;
}

uint Presedence(char c) {
	uint p = 0;
	
	!isoperator(c) ? p = 0
	: ((c == '+') || (c == '-')) ? p = 1
	: p = 2;
	
	return p;
}