// Zach Nadeau
// CS 2315
// Lab 14


#include<bits.h>

void printBinary(int num, ostream& os)
{
	uint unum = static_cast<unsigned int>(num);
	
	if (num != 0)
	{
		printBinary(unum >> 1, os);
		os << getBit(unum, 0);
	}
}
