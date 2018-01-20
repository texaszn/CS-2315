// Zach Nadeau
// CS 2315
// Lab 47


#include <lab47.h>
#include <cctype>
#include <cmath>

BigInt  BigInt::operator* ( char digit ) const {           // Multiplication by digit '0' <= digit <= '9'
	if ( !isdigit(digit) || digit == '0' ) {
		return BigInt(0);
	}
	
	BigInt product;
	int carry = 0, temp = 0;
	auto itr = this->digits.begin(), end = this->digits.end();
	
	product.digits.clear();
	product.sign = this->sign;
	
	while (itr != end) {
		temp = (*itr - '0') * (digit - '0') + carry;
		product.digits.push_back( ( temp % 10 ) + '0' );
		carry = temp / 10;
		++itr;
	}
	
	while (carry != 0) {
		product.digits.push_back( ( carry % 10 ) + '0' );
		carry /= 10;
	}
	
	while (product.digits.back() == '0' && product.digits.size() > 1) {
		product.digits.pop_back();
	}
	
	if (product.digits.back() == '0')
		return BigInt(0);
	
	return product;
}

BigInt  BigInt::operator* ( const BigInt& rhs ) const {    // Multiplication
	BigInt product;
	product.digits.clear();
	
	if ( this->sign == ZERO || rhs.sign == ZERO )
		return BigInt(0);
	
	auto itr = rhs.digits.cbegin(), end = rhs.digits.cend();
	product.sign = POSITIVE;
	
	for (int i = 0; itr != end; i++, itr++) {
		BigInt temp((*this) * (*itr));
		temp.sign = POSITIVE;
		for (int j = 0; j < i; j++)
			temp.digits.push_front('0');
		product.digits = (product + temp).digits;
	}
	
	while (product.digits.back() == '0' && product.digits.size() > 1) {
		product.digits.pop_back();
	}
	
	if ( this->sign != rhs.sign )
		product.sign = NEGATIVE;
	
	if (product.digits.back() == '0')
		return BigInt(0);
	
	return product;
}
