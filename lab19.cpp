// Zach Nadeau
// CS 2315
// Lab 19


#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(string s)
{
	if (s.length() <= 1)
		return true;
	else if (tolower(s[0]) != tolower(s[s.length() - 1]))
		return false;
	else
		return isPalindrome(s.substr(1, s.length() - 2));
}
