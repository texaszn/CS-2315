// Zach Nadeau
// CS 2315
// Lab 10


#include <lab10.h>

IntegerSet IntegerSet::operator+(const IntegerSet& rhs) const
{
	IntegerSet myUnion;
	
	for(uint e = 0; e < N; e++)
	{
		if(this->isMember(e) || rhs.isMember(e))
			myUnion = myUnion + e;
	}
	
	return myUnion;
}

IntegerSet IntegerSet::operator*(const IntegerSet& rhs) const
{
	IntegerSet myIntersection;
	
	for(uint e = 0; e < N; e++)
	{
		if(this->isMember(e) && rhs.isMember(e))
			myIntersection = myIntersection + e;
	}
	
	return myIntersection;
}

IntegerSet IntegerSet::operator-(const IntegerSet& rhs) const
{
	IntegerSet myDiff;
	
	for(uint e = 0; e < N; e++)
	{
		if(this->isMember(e) && !rhs.isMember(e))
			myDiff = myDiff + e;
	}
	
	return myDiff;
}

IntegerSet IntegerSet::operator/(const IntegerSet& rhs) const
{
	//IntegerSet myUnion = (*this + rhs) - (*this * rhs);
	
	return IntegerSet ((*this + rhs) - (*this * rhs));
}
