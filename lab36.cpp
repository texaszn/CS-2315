// Zach Nadeau
// CS 2315
// Lab 36


#include <iostream>
#include <iomanip>
#include <d_matrix.h>
#include <cmath>
#include <lab36.h>

using namespace std;

ostream& operator<<(ostream& out, const Spiral& spiral)
{
	int size = spiral.data.rows();
	
	for (int m = 0; m < size; ++m)
		for (int n = 0; n < size; ++n)
			out << setw(log10(size*size)+1) << right << spiral.data[m][n] << (n < size - 1 ? ' ' : '\n');

	return out;
}

void Spiral::initialize(int n)
{
	this->data.resize(n,n);
}

void Spiral::build()
{
	int r = -1, c = -1, n = this->data.rows(), k = 1;
	
	while (k <= n*n) {
		// Go East
		++r; ++c;
		while (c < n && this->data[r][c] == 0) {
			data[r][c] = k;
			++k;
			++c;
		}
		
		// Go South
		++r; --c;
		while (r < n && this->data[r][c] == 0) {
			data[r][c] = k;
			++k;
			++r;
		}
		
		// Go Weast
		--r; --c;
		while (c >= 0 && this->data[r][c] == 0) {
			data[r][c] = k;
			++k;
			--c;
		}
		
		// Go North
		--r; ++c;
		while (r >= 0 && this->data[r][c] == 0) {
			data[r][c] = k;
			++k;
			--r;
		}
	}
}
