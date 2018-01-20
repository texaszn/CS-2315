// Zach Nadeau
// CS 2315
// Lab 45


#include <cstdlib>
#include <cmath>
#include <cctype>
#include <lab45.h>

using namespace std;

const bool DEBUG = false;
void printDebug(const BigInt&);

BigInt::BigInt() {                                     // constructor digits = 0
	this->sign = ZERO;
	this->digits.push_back('0');
	printDebug(*this);
}

BigInt::BigInt( int num ) {                            // constructor digits = num
	if (num == 0) {
		this->sign = ZERO;
		this->digits.push_back('0');
		printDebug(*this);
		return;
	}
	else if (num < 0) {
		this->sign = NEGATIVE;
		num *= -1;
	}
	else {
		this->sign = POSITIVE;
	}
	
	while (num > 0) {
		this->digits.push_back((num % 10) + '0');
		num /= 10;
	}
	
	printDebug(*this);
}

BigInt::BigInt( const string str ) {                   // constructor digits = str
	uint n = str.size();
	
	if (fsaForInt(str) == 0) { // fsa = finite state automata
		this->sign = ZERO;
		this->digits.push_back('0');
		printDebug(*this);
		return;
	}
	else {
		this->sign = POSITIVE;
		
		for (uint i = 0; i < n; i++) {
			if (str.at(i) == '-')
				this->sign = NEGATIVE;
			else if (isdigit(str.at(i)))
				this->digits.push_front(str.at(i));
		}
		
		while (!this->digits.empty() && this->digits.back() == '0')
			this->digits.pop_back();
		
		if (this->digits.empty()) {
			this->sign = ZERO;
			this->digits.push_back('0')
		}
		
		printDebug(*this);
	}
}

BigInt::BigInt( const BigInt& other ) {                // copy constructor
	this->sign = other.sign;
	this->digits = other.digits;
	printDebug(*this);
}

bool BigInt::operator==( const BigInt& rhs ) const {   // Equality
	typename list<char>::const_iterator i = this->digits.begin(), j = rhs.digits.begin();
	
	if ((this->digits.size() != rhs.digits.size()) || (this->sign != rhs.sign))
		return false;
	
	while (i != this->digits.end()) {
		if (*i != *j)
			return false;
		++i; ++j;
	}
	
	return true;
}

bool BigInt::operator< ( const BigInt& rhs ) const {   // Less Than
	auto i = this->digits.rbegin(), j = rhs.digits.rbegin();
	
	if (this->sign > rhs.sign)
		return false;
	else if (this->sign < rhs.sign)
		return true;
	
	if (this->sign == ZERO)
		return false;
	else if (this->sign == POSITIVE) {
		if (this->digits.size() != rhs.digits.size())
			return this->digits.size() < rhs.digits.size();
		while (i != this->digits.rend()) {
			if (*i > *j)
				return false;
			if (*i < *j)
				return true;
			++i; ++j;
		}
	}
	else {
		if (this->digits.size() != rhs.digits.size())
			return this->digits.size() > rhs.digits.size();
		while (i != this->digits.rend()) {
			if (*i < *j)
				return false;
			if (*i > *j)
				return true;
			++i; ++j;
		}
	}
	
	return false;
}

void printDebug(const BigInt& a) {
	if (DEBUG)
		cout << /* a.sign << */ "  " << a << endl;
}

