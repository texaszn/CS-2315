// Zach Nadeau
// CS 2315
// Lab 18


#include<bits.h>

void printBase32(int num, ostream& os)
{
	uint unum = static_cast<unsigned int>(num);
	
	if (num != 0)
	{
		printBase32(unum >> 5, os);
		uint base32 = getBits(unum, 0, 5);
		if (base32 < 9)
			os << base32;
		else
			os << static_cast<char>(base32 - 10 + 'A');
	}
}
