// Zach Nadeau
// CS 2315
// Lab 20


template<typename T>
void mySwap(T& first, T& second)
{
	T temp = first;
	first = second;
	second = temp;
}

template<typename T>
void bubbleSort(T *array, int n)
{
	bool isSwapped = false;
	
	for (int i=0; i<n-1; i++)
	{
		if (*(array+i) > *(array+i+1))
		{
			mySwap(*(array+i), *(array+i+1));
			isSwapped = true;
		}
	}	
	
	if (isSwapped)
		bubbleSort(array, n-1);
}
