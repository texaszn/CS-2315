// Zach Nadeau
// CS 2315
// Lab 29


#include <algorithm>

template<typename T>
bool nextPermutation(vector<T>& v)
{
	typename vector<T>::iterator i = v.end() - 2;
	typename vector<T>::iterator j = v.end() - 1;
	
	while (i >= v.begin()) //Stops if both iterators = 1
	{
		while (*(i+1) > *i) //Compares 2nd to last with last number to find i
			--i;
	}
	while (j > v.begin())
	{
		while (*j < *i) //Compares to find j
			--j;
	}
	
	if (i == v.begin() && j == v.begin()) //If both iterators make it all the way through no more permutations
	{
		return false;
	}
	else //Swaps and Reverses otherwise
	{
		T temp = *i;
		*i = *j;
		*j = temp;
		
		reverse(i+1,v.end());
		// reverse(i+1,v.end());
		
		return true;
	}
	
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	typename vector<T>::const_iterator counter;
	
	for (counter = v.begin(); counter <  v.end(); ++counter)
	{
		os << *counter;
	}
	
	return os;
}