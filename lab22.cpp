// Zach Nadeau
// CS 2315
// Lab 22


template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind)
{
	//if(*first == itemToFind) return first;
	//if(*last == itemToFind) return last;
	
	const T *middle = first + ((last-first)/2);
		
	/*if (first == last || first+1 == last)
		return nullptr;*/
	if (first > last)
		return nullptr;
	else if (*middle == itemToFind)
		return middle;
	else if (*middle < itemToFind)
		return binarySearch(middle+1, last, itemToFind);
	else
		return binarySearch(first, middle-1, itemToFind);
}
