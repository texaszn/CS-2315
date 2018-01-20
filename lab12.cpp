// Zach Nadeau
// CS 2315
// Lab 12


#include <iostream>
#include <iomanip>

using namespace std;

void insertComma(unsigned long num, ostream& os)
{
	char ch = os.fill();
	
	if (num < 1000)            //base case
	{
		os << num;
	}
	else
	{
		insertComma(num / 1000, os);
		os << ',' << setfill('0') << setw(3) << num % 1000;
	}
	
	os << setfill(ch);
}
