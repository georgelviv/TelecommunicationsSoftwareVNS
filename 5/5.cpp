#include <cstdio> 
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;

const string a = "6";
const string b = "A";

string hammingCodeByPosition (string information, int tFix);
int hammingCodeByGMatrix (string information);

int main() {
	cout << hammingCodeByPosition(a, 1) << endl;
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
int hammingCodeByGMatrix (string information) {
	return 0;
}
