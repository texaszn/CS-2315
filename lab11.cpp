// Zach Nadeau
// CS 2315
// Lab 11


#include<lab11.h>

bool IntegerSet::operator==(const IntegerSet& rhs) const // Test for equality
{
	for (uint i = 0; i < N; i++)
	{
		if (getBit(this->bitVector[this->word(i)], this->bit(i)) != 
			getBit(rhs.bitVector[rhs.word(i)], rhs.bit(i)))
			return false;
	}
	
	return true;
}

bool IntegerSet::operator<=(const IntegerSet& rhs) const // Subset
{
	if ((*this * rhs) == *this)
		return true;
	else
		return false;
}

bool IntegerSet::operator< (const IntegerSet& rhs) const // Proper Subset
{
	if ((*this <= rhs) && !(*this == rhs))
		return true;
	else
		return false;
}
