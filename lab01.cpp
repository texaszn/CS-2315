// Zach Nadeau
// CS 2315
// Lab 01


#include <iostream>
#include <string>

using namespace std;

const string ID = "Zach Nadeau - CS 2315 - Lab 01\n\n";

unsigned int productOfDigits(unsigned int num);

int main()
{
	unsigned int num, persistence = 0;
	
	//output ID line
	cout << ID;
	
	// read an unknown # of unsigned ints from stdin
	while (cin >> num) {
		cout << num << ' ';
		persistence = 0;
		while (num > 9){
			num = productOfDigits(num);
			cout << "-> " << num << ' ';
			persistence++;
		}
		cout << "persistence = " << persistence << endl;
	}
	
	return 0;
}

unsigned int productOfDigits(unsigned int num)
{
	unsigned int digit, product = 1;
	
	if (num == 0)
		return 0;
	
	while (num != 0)
	{
		// Step 1: extract the rightmost digit from num
		digit = num % 10;
		
		// Step 2: incorporate the digit into product
		product = product * digit;
		
		// Step 3: eliminate the rightmost digit from num
		num = num / 10;
	}
	
	return product;
}