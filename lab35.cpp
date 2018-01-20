// Zach Nadeau
// CS 2315
// Lab 35


#include <iostream>
#include <d_matrix.h>

using namespace std;

bool isIdentityMatrix(const matrix<int>& mat) {
	int m, n, size = mat.rows();
	
	if (mat.rows() != mat.cols())
		return false;
	
	for (m = 0; m < size; m++) {
		for (n = 0; n < size; n++) {
			if (m == n && mat[m][n] != 1)
				return false;
			else if (m != n && mat[m][n] != 0)
				return false;
		}
	}
	
	return true;
}
