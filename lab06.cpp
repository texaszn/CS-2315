// Zach Nadeau
// CS 2315
// Lab 06


#include <lab06.h>

IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const
{
	IntegerSet myUnion;
	
	for(uint e = 0; e < N; e++)
	{
		if(this->isMember(e) || otherSet.isMember(e))
			myUnion.insertElement(e);
	}
	
	return myUnion;
}

IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const
{
	IntegerSet myIntersection;
	
	for(uint e = 0; e < N; e++)
	{
		if(this->isMember(e) && otherSet.isMember(e))
			myIntersection.insertElement(e);
	}
	
	return myIntersection;
}

IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const
{
	IntegerSet myDiff;
	
	for(uint e = 0; e < N; e++)
	{
		if(this->isMember(e) && !otherSet.isMember(e))
			myDiff.insertElement(e);
	}
	
	return myDiff;
}

IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const
{
	IntegerSet myUnion = this->Union(otherSet);
	
	return myUnion.difference(this->intersection(otherSet));
}
