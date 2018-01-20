// Zach Nadeau
// CS 2315
// Lab 15


#include<bits.h>

void printQuaternary(int num, ostream& os)
{
	uint unum = static_cast<unsigned int>(num);
	
	if (num != 0)
	{
		printQuaternary(unum >> 2, os);
		os << getBits(unum, 0, 2);
	}
}
