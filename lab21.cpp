// Zach Nadeau
// CS 2315
// Lab 21

/*
template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind)
{
	for(int i=0; i<n; i++)
	{
		if(*(array+i) == itemToFind)
			return (array+i);
	}
	
	return nullptr;
}
*/

template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind)
{
	if (n==0)
		return nullptr;
	else if (*(array) == itemToFind)
		return (array);
	else
		return linearSearch(array+1, n-1, itemToFind);
}