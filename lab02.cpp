// Zach Nadeau
// CS 2315
// Lab 02


#include <lab02.h>
#include <cstdlib>

Rational::Rational() {                        // default constructor
	setNumerator(0);
	setDenominator(1);
}
Rational::Rational(int num, int denom) {      // additional constructor
	setNumerator(num);
	setDenominator(denom);
}

void Rational::setNumerator(int num) {        // set numerator to num
	r[0] = num;
}
void Rational::setDenominator(int denom) {    // set denominator to denom
	r[1] = denom == 0 ? 1 : denom;
}

int  Rational::getNumerator() const {         // return numerator
	// return (*this).r[0] //OR
	return this->r[0];
}
int  Rational::getDenominator() const {       // return denominator
	return r[1];
}

void Rational::reduce() {                     // Reduce to lowest terms and normalize
	int gcd = /*Rational::*/ this->gcd(getNumerator(), getDenominator());
	
	if (getDenominator() < 0)
		gcd = -gcd;
	
	setNumerator(getNumerator() / gcd);
	setDenominator(getDenominator() / gcd);
}

int  Rational::gcd(int m, int n) const {      // returns the gcd of m and n
	int gcd, rem;
	
	if (m == n)
		gcd = abs(n);
	else if (m==0)
		gcd = abs(n);
	else {
		m = abs(m);
		n = abs(n);
		rem = m % n;
		
		while (rem != 0) {
			m = n;
			n = rem;
			rem = m % n;
		}
		gcd = n;
	}
	return gcd;
}