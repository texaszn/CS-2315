// Zach Nadeau
// CS 2315
// Lab 27


#include <algorithm>

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v)
{
	pair<T, int> myMode;
	vector<T> myCopy(v); // use the copy constructor to make a copy of va_arg
	typename vector<T>::size_type i;
	int countA = 1;
	
	// sort myCopy using the STL algorithm sort
	sort(myCopy.begin(), myCopy.end());
	
	myMode.first  = myCopy.at(0);
	myMode.second = 1;
	
	if (myCopy.size() != 1)
	{
		for (i=1; i < myCopy.size(); i++)
		{
			myCopy.at(i) == myCopy.at(i-1) ? countA++ : countA = 1;
			if (countA > myMode.second)
			{
				myMode.first  = myCopy.at(i);
				myMode.second = countA;
			}
		}
	}
	
	return myMode;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v)
{
	pair<T, int> myMode;
	vector<T> myCopy(v); // use the copy constructor to make a copy of va_arg
	typename vector<T>::iterator i,
		begin = myCopy.begin(),
		end = myCopy.end();
	int countA = 1;
	
	// sort myCopy using the STL algorithm sort
	sort(begin, end);
	
	myMode.first  = *(myCopy.begin());
	myMode.second = 1;
	
	if (end - begin != 1)
	{
		for (i = begin+1; i < end; i++)
		{
			*(i - 1) == *i ? countA++ : countA = 1;
			if (countA > myMode.second)
			{
				myMode.first  = *i;
				myMode.second = countA;
			}
		}
	}
	
	return myMode;
}

//NOTE: Test equals case for average (5 5 7 7 has mode 6)
