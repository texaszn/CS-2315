// Zach Nadeau
// CS 2315
// Lab 31


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Global Variables
typedef unsigned int uint;
const string ID = "Zach Nadeau - CS 2315 - Lab 31\n\n";

// Functions
void printLine(ostream &out, int n){
	char ch = out.fill();
	out << setfill('-') << setw(n) << "-" << setfill(ch) << endl;
	return;
}

int main(){
	string inputLine;
	vector<string> fileNames;
	const int W = 60;
	uint biggestSize = 0;
	
	// output ID line
	cout << ID;
	printLine(cout, W);
	
	// read an unknown # of strings line-by-line, each representing a filename
	while (getline(cin, inputLine)){
		fileNames.emplace_back(inputLine);
		
		if(inputLine.size() > biggestSize)
			biggestSize = inputLine.size();
	}
	
	vector<string>::iterator begin = fileNames.begin();
	vector<string>::iterator end = fileNames.end();
	
	sort(begin, end);
	
	uint alloc_cols = (W-biggestSize)/(biggestSize+2)+1;
	uint rows = static_cast<uint>( ceil( static_cast<double>(fileNames.size()) / static_cast<double>(alloc_cols) ) ); // check col1
	uint cols = static_cast<uint>( ceil( static_cast<double>(fileNames.size()) / static_cast<double>(rows) ) );
	
	for (uint rowItr = 0; rowItr < rows; rowItr++) {
		for (auto colItr = begin + rowItr; colItr < end; colItr = colItr + rows) {
			cout << left << setw(biggestSize) << setfill(' ') << *colItr;
			if( static_cast<uint>( ceil((static_cast<double>(colItr - begin) + 1.0) / static_cast<double>(rows)) ) < cols )
				cout << left << setw(2) << setfill(' ') << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
	