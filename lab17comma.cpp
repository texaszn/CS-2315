// Zach Nadeau
// CS 2315
// Lab 17


#include<bits.h>

void printHexadecimal(int num, ostream& os)
{
	uint unum = static_cast<unsigned int>(num);
	
	if (num != 0)
	{
		printHexadecimal(unum >> 4, os);
		if (uint hex = getBits(unum, 0, 4), hex < 9)
			os << hex;
		else
			os << static_cast<char>(hex - 10 + 'A');
	}
}
