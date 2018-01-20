// Zach Nadeau
// CS 2315
// Lab 04


#include <lab04.h>

IntegerSet::IntegerSet()                           // initializes the set to the empty set
{
	// allocate storage for bitVector by calling private member function
	this->allocateStorage();
	
	// iterate through the elements of the universe and delete each element
	for (uint e = 0; e < N; e++)
	{
		this->deleteElement(e);
	}
}

IntegerSet::IntegerSet(const IntegerSet& otherSet) // copy constructor
{
	this->allocateStorage();
	
	for (uint e = 0; e < N; e++)
	{
		this->deleteElement(e);
	}
	
	for (uint e = 0; e < N; ++e)
	{
		if (otherSet.isMember(e))
			this->insertElement(e);
		else
			this->deleteElement(e);
	}
}

IntegerSet::~IntegerSet()                          // destructor
{
	delete [] this->bitVector;
}

bool IntegerSet::isMember(uint e) const            // returns true if e is a member of the set and false otherwise
{
	return this->isValid(e) && getBit(this->bitVector[this->word(e)], this->bit(e));
}

uint IntegerSet::cardinality() const               // cardinality of a set
{
	uint card = 0;
	
	/*// for each value within the bitVector that is a member, add 1 to cardinality
	for (uint e = 0; e < N; e++)
		card += getBit(this->bitVector[this->word(e)], this->bit(e)); //*/
	
	/// the same loop can be expressed with a reference to the already-defined "isMember" function
	for (uint e = 0; e < N; ++e)
	{
		if (this->isMember(e))
			++card;
	} //*/
	
	return card;
}

void IntegerSet::insertElement(uint e)             // if e is valid and not a member of the set, insert e into set
{
	if (this->isValid(e) && !this->isMember(e))
		this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 1);
}

void IntegerSet::deleteElement(uint e)             // if e is valid and a member of the set, delete e from set
{
	if (this->isValid(e) && this->isMember(e))
		this->bitVector[this->word(e)] = setBit(this->bitVector[this->word(e)], this->bit(e), 0);
}

IntegerSet IntegerSet::complement() const          // complement of a Set
{
	IntegerSet comp;
	
	for (uint e = 0; e < N; e++)
	{
		if (this->isMember(e))
			comp.deleteElement(e);
		else 
			comp.insertElement(e);
	}
	
	return comp;
}

ostream& IntegerSet::print(ostream& os) const      // prints an IntegerSet object in set notation
{
	if (this->cardinality() == 0)
	{
		os << static_cast<char>(216) << endl;
	}
	else
	{
		uint end = N;
		
		while (end > 0 && !isMember(end))
		{
			end = end-1;
		}
		
		os << '{';
		
		for (uint e = 0; e < end; e++)
		{
			if (this->isMember(e))
				os << this->word(e) * 32 + this->bit(e) << ',';
		}
		
		os << this->word(end) * 32 + this->bit(end) << '}' << endl;
	}
	
	return os;
}

bool IntegerSet::isValid(uint e) const             // 0 <= e < N
{
	if (e >= 0 && e < N)
		return true;
	else
		return false;
}
