#include <cstdio> 
#include <iostream>
#include <string>
#include <vector>
#include "utils.h"

using namespace std;

const string a = "6";
const string b = "A";

string hammingCodeByPosition (string information, int tFix);
string hammingCodeByGMatrix (string information, int tFix);

int main() {
	cout << "By position. Information code:" <<  utils::hexToBin(a) << endl;
	cout << hammingCodeByPosition(a, 1) << endl;
	cout << "By g matrix. Information code:"  <<  utils::hexToBin(b) << endl;
	cout << hammingCodeByGMatrix(b, 1) << endl;
	return 0;
}

string hammingCodeByPosition (string information, int tFix) {
	string bin = utils::hexToBin(information);
	int dMin = 2 * tFix + 1;
	int n = dMin + bin.size();
	string code;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 0 || utils::isPowerOfTwo(i)) {
			s = 0;
			for (int y = 0; y < bin.size(); y++) {
				s += stoi(bin.substr(y, 1), nullptr, 2);
			}
			code += to_string(s % 2) ;
		} else {
			code += bin[0];
			bin = bin.substr(1, bin.size() - 1);
		}
	}
	return code;
}
string hammingCodeByGMatrix (string information, int tFix) {
	string bin = utils::hexToBin(information);
	int dMin = 2 * tFix + 1;
	int rowSize = bin.size();
	int colSize = bin.size() + dMin;
	vector< vector<int> > gMatrix(rowSize, vector<int>(colSize));
	string code;
	
	for (int i = 0; i < rowSize; i++) {
		for (int y = 0; y < colSize; y++) {
			int curBit;
			if (y < bin.size()) {
				i == y ? curBit = 1 : curBit = 0;
			} else {
				(y - bin.size()) != i ? curBit = 1 : curBit = 0; 	
			}
			gMatrix[i][y] = curBit;
		}
	}
	
	for (int i = 0; i < colSize; i++) {
		int curBit = 0;
		for (int y = 0; y < rowSize; y++) {
			curBit ^= stoi(bin.substr(y, 1), nullptr, 2) * gMatrix[y][i];
		}
		code += to_string(curBit);
	}
	
	return code;
}
