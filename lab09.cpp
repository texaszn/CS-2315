// Zach Nadeau
// CS 2315
// Lab 09


#include<lab09.h>

Rational& Rational::operator++()             // preincrement
{
	this->setNumerator(this->getNumerator() + this->getDenominator());
	
	this->reduce();
	
	return *this;
}

Rational Rational::operator++(int)           // postincrement
{
	Rational copy = *this;
	
	++(*this);
	
	return copy;
}

Rational& Rational::operator--()             // predecrement
{
	this->setNumerator(this->getNumerator() - this->getDenominator());
	
	this->reduce();
	
	return *this;	
}

Rational Rational::operator--(int)           // postdecrement
{
	Rational copy = *this;
	
	--(*this);
	
	return copy;
}
