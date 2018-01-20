// Zach Nadeau
// CS 2315
// Lab 29


#include <algorithm>

template<typename T>
bool nextPermutation(vector<T>& v)
{
	bool isPerm = false;
	typename vector<T>::iterator i, j,
		begin = v.begin(),
		end = v.end();
	
	for (i = end-2; i >= begin; i--)
		if (*i < *(i+1)) {
			isPerm = true;
			break;
		}
	
	if (!isPerm) {
		reverse(i+1,end);
		return false;
	}
	
	for (j = end-1; j >= begin; j--)
		if (*j > *i) { break; }
	
	swap(*i,*j);
	
	reverse(i+1,end);
	
	return true;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	typename vector<T>::const_iterator i;
	
	for (i = v.begin(); i <  v.end(); i++)
	{
		os << *i;
	}
	
	return os;
}