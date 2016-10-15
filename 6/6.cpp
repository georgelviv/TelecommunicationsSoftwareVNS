#include <cstdio>
#include <iostream>
#include <string>
#include "utils.h"

const string info = "A0B";
const int polynomialArr[3] = {4, 1, 0};

string getCRC (string information, vector<int> polynomialArr);

int main() {
	vector<int> a;
	
	string bitesInfo = utils::hexToBin(info);
	cout << bitesInfo << endl;
	cout << "\n";
	cout << getCRC(bitesInfo, utils::convertToVector(polynomialArr, 3)) << endl;
	return 0;
}

string getCRC (string information, vector<int> polynomialArr) {
	vector<int> p;
	vector<int> pX;
	vector<int> r;
	
	p = utils::convertToPolynomial(information);
	
	for (int i = 0; i < p.size(); i++) {
		pX.push_back(p[i] + polynomialArr[0]);
	}
	
	r = utils::modPolynomial(pX, polynomialArr);
	
	
	for (int i = 0; i < r.size(); i++) {
		pX.push_back(r[i]);
	}

	return utils::polynomialToBinary(pX);
}
