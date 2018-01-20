// Zach Nadeau
// CS 2315
// Lab 13


#include<bits.h>

int countOneBits(int i)
{
	//int count = 0;
	uint ui = static_cast<unsigned int>(i);
	
	if (ui == 0)
	{
		return 0;
	}
	else
	{
		//count = countOneBits(i >> 1) + getBit(i, 0);
		return countOneBits(ui >> 1) + getBit(ui, 0);
	}

	//return count;
}
