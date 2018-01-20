// Zach Nadeau
// CS 2315
// Lab 07


#include <lab07.h>

// overloaded input operator initializes Rational rat from input stream in
istream& operator>>(istream& in, Rational& rat)
{
	int n, d;
	
	in >> n >> d;
	rat.setNumerator(n);
	rat.setDenominator(d);
	
	return in;
}

// overloaded output operator prints Rational rat to output stream out
ostream& operator<<(ostream& out, const Rational& rat)
{
	out << rat.getNumerator() << '/' << rat.getDenominator();
	
	return out;
}

Rational& Rational::operator=(const Rational& rhs)                 // *this = rhs
{
	if (this != &rhs)
	{
		this->setNumerator(rhs.getNumerator());
		this->setDenominator(rhs.getDenominator());
	}
	
	return *this;
}

Rational  Rational::operator+(const Rational& addend) const        // returns *this + addend
{
	int lcm = Rational::lcm(this->getDenominator(), addend.getDenominator());
	Rational sum;  // declare a local object
	
	// Populate the data fields of the local object
	sum.setNumerator(lcm / this->getDenominator() * this->getNumerator() +
	                 lcm / addend.getDenominator() * addend.getNumerator());
	sum.setDenominator(lcm);
	sum.reduce();
	
	// return the local object
	return sum;
}

Rational  Rational::operator-() const                              // returns -(*this)
{
	return Rational(this->getNumerator() * -1, this->getDenominator());
}

Rational  Rational::operator-(const Rational& subtrahend) const    // returns *this - subtrahend
{
	// return this->operator+(subtrahend.operator-());
	return *this + -subtrahend;
}

Rational  Rational::operator*(const Rational& multiplicand) const  // returns *this * multiplicand
{
	Rational newRational;
	
	newRational.setNumerator(this->getNumerator() * multiplicand.getNumerator());
	newRational.setDenominator(this->getDenominator() * multiplicand.getDenominator());
	
	newRational.reduce();
	
	return newRational;
}

Rational  Rational::operator/(const Rational& divisor) const       // returns *this / divisor
{
	return (*this * divisor.multiplicativeInverse());
}

bool Rational::operator==(const Rational& other) const             // *this == rhs
{
	Rational lhs(this->getNumerator(), this->getDenominator());
	Rational rhs(other.getNumerator(), other.getDenominator());
	
	lhs.reduce();
	rhs.reduce();
	
	return lhs.getNumerator() == rhs.getNumerator() &&
		lhs.getDenominator() == rhs.getDenominator();
}

bool Rational::operator!=(const Rational& rhs) const               // *this != rhs
{
	return !(*this == rhs);
}

bool Rational::operator< (const Rational& rhs) const               // *this <  rhs
{
	int lcm = Rational::lcm(this->getDenominator(), rhs.getDenominator());
	
	return (lcm / this->getDenominator() * this->getNumerator() <
	        lcm / rhs.getDenominator() * rhs.getNumerator());
}

bool Rational::operator<=(const Rational& rhs) const               // *this <= rhs
{
	return (*this < rhs || *this == rhs);
}

bool Rational::operator> (const Rational& rhs) const               // *this >  rhs
{
	return !(*this <= rhs);
}

bool Rational::operator>=(const Rational& rhs) const               // *this >= rhs
{
	return !(*this < rhs);
}