// Zach Nadeau
// CS 2315
// Lab 08


#include <lab08.h>

// overloaded output operator for printing IntegerSet set to output stream out
// NOTE: friend function is not a member func
ostream& operator<<(ostream& os, const IntegerSet& set)
{
	if (set.cardinality() == 0)
	{
		os << static_cast<char>(216) << endl;
	}
	else
	{
		uint end = N;
		
		while (end > 0 && !set.isMember(end))
		{
			end = end-1;
		}
		
		os << '{';
		
		for (uint e = 0; e < end; e++)
		{
			if (set.isMember(e))
				os << set.word(e) * 32 + set.bit(e) << ',';
		}
		
		os << set.word(end) * 32 + set.bit(end) << '}' << endl;
	}
	
	return os;
}

IntegerSet  IntegerSet::operator+(uint e) const           // if e is valid and not a member of the set, insert e into set
{
	IntegerSet mySet(*this);
	
	if (this->isValid(e) && !this->isMember(e))
		mySet.bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 1);
	
	return mySet;
}

IntegerSet  IntegerSet::operator-(uint e) const           // if e is valid and a member of the set, delete e from set
{
	IntegerSet mySet(*this);
	
	if (this->isValid(e) && this->isMember(e))
		mySet.bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 0);
	
	return mySet;
}

IntegerSet  IntegerSet::operator-() const                 // complement of a Set
{
	IntegerSet comp;
	
	for (uint e = 0; e < N; e++)
	{
		if (!this->isMember(e))
			comp = comp + e;
	}
	
	return comp;
}

IntegerSet& IntegerSet::operator=(const IntegerSet& rhs)  // *this = rhs
{
	if (this != &rhs)
	{
		for (uint e = 0; e < N; e++)
		{
			if (rhs.isMember(e))
				// *this = *this + e;
				this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 1);
			else
				// *this = *this - e;
				this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 0);
		}
	}
	
	return *this;
}