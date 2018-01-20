// Zach Nadeau
// CS 2315
// Lab 32


template <typename T>
void exchangeSort(vector<T>& v) {
	// Using Pointers
	T *ptrA, *ptrB, *ptrBegin = v.data();
	int size = v.size();
	
	for (ptrA = ptrBegin; ptrA - ptrBegin < size; ptrA++)
		for (ptrB = ptrA+1; ptrB - ptrBegin < size; ptrB++)
			if (*ptrB < *ptrA) { swap(*ptrA, *ptrB); }
	
	/*// Using Iterators
	typename vector<T>::iterator itrA, itrB,
		begin = v.begin(),
		end = v.end();
	
	for (itrA = begin; itrA - begin < end - begin; itrA++)
		for (itrB = itrA+1; itrB - begin < end - begin; itrB++)
			if (*itrB < *itrA) { swap(*itrA, *itrB); }
	*/
}
