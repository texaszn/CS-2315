// Zach Nadeau
// CS 2315
// Lab 46


#include <lab46.h>
#include <cmath>

BigInt  BigInt::operator+ ( const BigInt& rhs ) const // Addition
{
	if (this->sign == ZERO)
		return rhs;
	else if (rhs.sign == ZERO)
		return *this;
	
	BigInt nlhs(*this), nrhs(rhs);
	auto lItr = nlhs.digits.begin(), rItr = nrhs.digits.begin();
	
	
	if (nlhs.digits.size() > nrhs.digits.size()) {
		// while (nrhs.digits.size() != nlhs.digits.size())
			// nrhs.digits.push_front('0');
		nrhs.digits.resize(nlhs.digits.size(), '0');
		rItr = nrhs.digits.begin();
	}
	else if (nlhs.digits.size() < nrhs.digits.size()) {
		// while (nlhs.digits.size() != nrhs.digits.size())
			// nlhs.digits.push_front('0');
		nlhs.digits.resize(nrhs.digits.size(), '0');
		lItr = nlhs.digits.begin();
	}
	
	// Addition Case
	if (nlhs.sign == nrhs.sign) {
		BigInt sum;
		int carry = 0;
		
		sum.digits.clear();
		sum.sign = nlhs.sign;
		
		while (lItr != nlhs.digits.end()) {
			int temp = ((*lItr) - '0') + ((*rItr) - '0') + carry;
			sum.digits.push_back( ( temp % 10 ) + '0');
			carry = temp / 10;
			++lItr; ++rItr;
		}
		
		if (carry != '0')
			sum.digits.push_back( carry + '0' );
		
		while (sum.digits.back() == '0' && sum.digits.size() > 1) {
			sum.digits.pop_back();
		}
		
		return sum;
	}
	
	// Subtraction Case
	else {
		Sign sum_sign;
		
		if (nlhs.sign > nrhs.sign) {
			nrhs.sign = POSITIVE;
			sum_sign = POSITIVE;
			if (nlhs < nrhs) {
				nlhs.digits.swap(nrhs.digits);
				sum_sign = NEGATIVE;
			}
			else if (nlhs == nrhs) {
				return BigInt(0);
			}
		}
		else {
			nlhs.sign = POSITIVE;
			sum_sign = NEGATIVE;
			if (nlhs < nrhs) {
				nlhs.digits.swap(nrhs.digits);
				sum_sign = POSITIVE;
			}
			else if (nlhs == nrhs) {
				return BigInt(0);
			}
		}
		
		lItr = nlhs.digits.begin();
		rItr = nrhs.digits.begin();
		
		// 9's Compliment
		while (rItr != nrhs.digits.end()) {
			*rItr = ('9' - *rItr) + '0';
			++rItr;
		}
		
		rItr = nrhs.digits.begin();
		bool carry = false;
		
		// 10's Compliment
		do {
			if (!carry) {
				if (*rItr != '9') {
					*rItr += 1;
					break;
				}
				else {
					carry = true;
					*rItr = '0';
				}
			}
			else {
				if (*rItr != '9') {
					*rItr += 1;
					break;
				}
				else {
					*rItr = '0';
				}
			}
			++rItr;
		} while (rItr != nrhs.digits.end());
		
		BigInt sum(nlhs + nrhs);
		sum.digits.pop_back();
		sum.sign = sum_sign;
		
		while (sum.digits.back() == '0' && sum.digits.size() > 1) {
			sum.digits.pop_back();
		}
		
		return sum;
	}
}

BigInt  BigInt::operator- ( const BigInt& rhs ) const // Subtraction
{
	BigInt subtrahend(rhs); // use the copy contructor
	
	if (rhs.sign == NEGATIVE)
		subtrahend.sign = POSITIVE;
	else if (rhs.sign == POSITIVE)
		subtrahend.sign = NEGATIVE;
	else
		subtrahend.sign = ZERO;
	
	return (*this + subtrahend);
}
