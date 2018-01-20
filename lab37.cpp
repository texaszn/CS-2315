// Zach Nadeau
// CS 2315
// Lab 37

#include <iomanip>
#include <cmath>
#include <lab37.h>
#include <array>
#include <algorithm> 

using namespace std;

ostream& operator<<(ostream& out, const Sudoku& puzzle) {
	int i, j, n = puzzle.gameBoard.rows();

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			out << setw(1) << right << puzzle.gameBoard[i][j] << (j < n - 1 ? " " : " \n");

	return out;
}

istream& operator>>(istream& in, Sudoku& puzzle) {
	int i, j, temp, n = puzzle.gameBoard.rows();
	
	for (i = 0; i < n; i++) {
		in >> temp;
		for (j = n-1; j >= 0; --j) {
			puzzle.gameBoard[i][j] = temp%10;
			temp /= 10;
		}
	}
	
	return in;
}

Sudoku::Sudoku() {
	this->gameBoard.resize(4, 4);
}

bool Sudoku::isValid() const {
	int i, j, p, q, r, n = this->gameBoard.rows();
	const int array[] = {1,2,3,4};
	int tempR[4] = {}, tempC[4] = {};
	
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			tempR[j] = this->gameBoard[i][j]; 
			tempC[j] = this->gameBoard[j][i];
		}
		sort(tempR, tempR + 4);
		sort(tempC, tempC + 4);
		for(j = 0; j < n; ++j) {
			if((tempR[j] != array[j]) || (tempC[j] != array[j])) {
				//cout << "**1**";
				return false;
			}
		}
	}
	
	//tempR.fill(0);
	
	for (p = 0; p < n; p += 2) {
		for (q = 0; q < n; q += 2) {
			r = 0;
			for (i = 0; i < 2; i++) 
				for (j = 0; j < 2; j++, r++)
					tempR[r] = this->gameBoard[i+p][j+q];
			
			sort(tempR, tempR + 4);
			
			for(j = 0; j < n; ++j)
				if(tempR[j] != array[j]) {
					//cout << "**2**";
					return false;
				}
		}
	}
	
	return true;
}
