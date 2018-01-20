// Zach Nadeau
// CS 2315
// Lab 23


template<typename T>
int numDistinct(const T *array, int n)
{
/*	T *temp = new T[n];
	T element = *array;
	int counter = 1;
	
	if (n<=1)
		return n;
	else
	{
		for (int i=1; i<n; i++)
		{
			if (*(array+i) != element)
				*(temp+i) = *(array+i);
			else
			{
				for (
				counter++;
			}
		}
		return numDistinct(temp, n-counter);
	}
*/

	if (n<=1)
		return n;
	for (int i=1; i<n; i++)
	{
		if (*array == *(array + i))
			return numDistinct(array+1, n-1);
	}
	return 1 + numDistinct(array+1, n-1);
}
