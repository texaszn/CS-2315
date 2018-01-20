// Zach Nadeau
// CS 2315
// Lab 16


#include<bits.h>

void printOctal(int num, ostream& os)
{
	uint unum = static_cast<unsigned int>(num);
	
	if (num != 0)
	{
		printOctal(unum >> 3, os);
		os << getBits(unum, 0, 3);
	}
}
