// Zach Nadeau
// CS 2315
// Lab 03

#include<lab03.h>

Rational Rational::add(const Rational& addend) const               // Addition
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

Rational Rational::additiveInverse() const                         // Returns the additive inverse
{   /*
	Rational additiveInverse(this->getNumerator() * -1, this->getDenominator());
	
	return additiveInverse;
	*/
	return Rational(this->getNumerator() * -1, this->getDenominator());
}

Rational Rational::subtract(const Rational& subtrahend) const      // Subtraction
{
	Rational additiveInverse = subtrahend.additiveInverse();
	/* Rational difference = this->add(additiveInverse);
	
	return difference;*/
	return Rational(this->add(additiveInverse));
}

Rational Rational::multiply(const Rational& multiplicand) const    // Multiplication
{
	Rational product;  // declare a local object
	
	// Populate the data fields of the local object
	product.setNumerator(this->getNumerator() * multiplicand.getNumerator());
	product.setDenominator(this->getDenominator() * multiplicand.getDenominator());
	product.reduce();
	
	// return the local object
	return product;
}

Rational Rational::multiplicativeInverse() const                   // Returns the multiplicative inverse
{
	return Rational(this->getDenominator(), this->getNumerator());
}

Rational Rational::divide(const Rational& divisor) const           // Division
{
	Rational multiplicativeInverse = divisor.multiplicativeInverse();
	
	return Rational(this->multiply(multiplicativeInverse));
}

ostream& Rational::print(ostream& os) const                        // Print Rational to output stream
{
	os << this->getNumerator() << '/' << this->getDenominator();
	
	return os;
}

istream& Rational::read(istream& is)                               // Read Rational from input stream
{
	int n, d;
	
	is >> n >> d;
	this->setNumerator(n);
	this->setDenominator(d);
	
	return is;
}

int Rational::lcm(int m, int n) const                              // returns the least common multiple of m and n
{
	if (m == 0 && n == 0)
		return 0;
	else
		return m * n / gcd(m, n);
}