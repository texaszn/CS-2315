// Zach Nadeau
// CS 2315
// Lab 30


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void sieveOfEratosthenes(vector<bool>& prime)
{
	typename vector<bool>::iterator i,j;
	typename vector<bool>::iterator begin = prime.begin(), end = prime.end();
	
	for (i = (begin + 2); begin + ((i - begin)*(i - begin)) < end; i++)
		if (*i)
			for (j = i + (i - begin); j < end; j = j + (i - begin))
				*j = false;
}

void printPrimes(const vector<bool>& prime, ostream& os)
{
	typename vector<bool>::const_iterator i;
	typename vector<bool>::const_iterator begin = prime.cbegin(), end = prime.cend();
	
	for (i = begin; i < end; i++)
		if (*i)
			os << i - begin << '\n';
}
