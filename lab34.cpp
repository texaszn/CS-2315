// Zach Nadeau
// CS 2315
// Lab 34

template<typename T>
void miniVector<T>::insert(int i, const T& item)
// insert item at index i in the vector.
// Precondition vector is not empty and 0 <= i <= vSize.
// Postcondition the vector size increases by 1.
{
	if (this->empty() && i != 0)
		throw underflowError("miniVector insert(): vector empty");
	else if (i < 0 || i > this->size())
		throw indexRangeError("miniVector insert(): index range error", i, this->size());
	else 
	{
		this->push_back(item);
		for (int count = (this->size())-1; count > i; count--) {
			*(vArr + count) = *(vArr + count - 1);
		}
		*(vArr + i) = item;
	}
}

template<typename T> 
void miniVector<T>::erase(int i)
// erase the item at index i in the vector.
// Precondition vector is not empty and 0 <= i < vSize.
// Postcondition the vector size decreases by 1.
{
	if (this->empty())
		throw underflowError("miniVector erase(): vector empty");
	else if (i < 0 || i >= this->size())
		throw indexRangeError("miniVector erase(): index range error", i, this->size());
	else
	{
		for (int count = i; count < (this->size())-1; count++)
			*(vArr + count) = *(vArr + count + 1);
		this->pop_back();
	}
	
}
