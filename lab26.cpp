// Zach Nadeau
// CS 2315
// Lab 26


#include <vector>
#include <cmath>

using namespace std;

int meanUsingIndexing(const vector<int>& v)
{
	vector<int>::size_type i;
	double sum = 0;
	
	for (i=0; i < v.size(); ++i)
		sum += v.at(i); // v[i] is ok
	
	return static_cast<int>(round(sum/v.size()));
}

int meanUsingIterators(const vector<int>& v)
{
	vector<int>::const_iterator i;
	double sum = 0;
	
	for (i=v.cbegin(); i < v.cend(); ++i)
		sum += *i; // v[i] is ok
	
	return static_cast<int>(round(sum/v.size()));
}
