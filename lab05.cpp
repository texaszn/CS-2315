// Zach Nadeau
// CS 2315
// Lab 05


#include <lab05.h>

bool Rational::isEqualTo(const Rational& other) const               // *this == other
{
	// lhs: left-hand side     rhs: right-hand side
	Rational lhs(this->getNumerator(), this->getDenominator());
	Rational rhs(other.getNumerator(), other.getDenominator());
	
	lhs.reduce();
	rhs.reduce();
	
	return lhs.getNumerator() == rhs.getNumerator() &&
		lhs.getDenominator() == rhs.getDenominator();
}

bool Rational::isNotEqualTo(const Rational& other) const            // *this != other
{
	return !this->isEqualTo(other);
}

bool Rational::isLessThan(const Rational& other) const              // *this < other
{
	// lhs: left-hand side     rhs: right-hand side
	Rational lhs(this->getNumerator(), this->getDenominator());
	Rational rhs(other.getNumerator(), other.getDenominator());
	
	lhs.reduce();
	rhs.reduce();
	
	int lcm = this->lcm(lhs.getDenominator(), rhs.getDenominator());
	
	return ((lcm / lhs.getDenominator()) * lhs.getNumerator()) <
		((lcm / rhs.getDenominator()) * rhs.getNumerator());
}

bool Rational::isLessThanOrEqualTo(const Rational& other) const     // *this <= other
{
	return this->isLessThan(other) || this->isEqualTo(other);
}

bool Rational::isGreaterThan(const Rational& other) const           // *this > other
{
	return !this->isLessThan(other) && !this->isEqualTo(other);
}

bool Rational::isGreaterThanOrEqualTo(const Rational& other) const  // *this >= other
{
	return !this->isLessThan(other);
}
