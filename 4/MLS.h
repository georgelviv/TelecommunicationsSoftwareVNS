#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

class MLS {
	private:
		std::vector<int> registerV;
		std::vector<int> polynomial;
		std::vector<std::string> mArray;
		int c;
		int sizeP;
	public:
		MLS (int size, std::vector<int> & polynomialV);
		void printCurrent ();
		void printPolynomial ();
		void printC ();
		void setNextC ();
		void shiftRegister ();
		void setMArray ();
		void printMArray();
		int getMArrayByIndex(int i);
		
};

MLS::MLS (int size, std::vector<int> & polynomialV) {
	registerV.reserve(size);
	int sum = 0;
	sizeP = size;
	do {
		sum = 0;
		for (int i = 0; i < size; i++) {
			registerV.insert(registerV.end(), rand() % 2);
			sum += registerV[i];
		}
	} while (sum == 0);
	
	polynomial.reserve(polynomialV.size());
	for (int i = 0; i < polynomialV.size(); i++) {
		polynomial.insert(polynomial.end(), polynomialV[i]);
	}
	
	mArray.reserve(pow(2, size) - 1);
	
	this->setNextC();
}

void MLS::setMArray() {
	int mSize = pow(2, sizeP) - 1;
	std::string cur;
	char numstr[21];
	for (int i = 0; i < mSize; i++) {
		cur = "";
		for (int i = 0; i < registerV.size(); i++) {
			cur += itoa(registerV[i], numstr, 10);
		}
		mArray.insert(mArray.end(), cur);
		this->shiftRegister();
	}
}

int MLS::getMArrayByIndex(int i) {
	int mSize = pow(2, sizeP) - 1;
	while (i < 0) {
		i = mArray.size() - i;
	}
	return std::stoi(mArray[i % mSize], nullptr, 2);
}

void MLS::printMArray() {
	for (int i = 0; i < mArray.size(); i++) {
		std::cout << mArray[i] << std::endl;
	}
}

void MLS::printCurrent () {
	for (int i = 0; i < registerV.size(); i++) {
		printf("%d", registerV[i]);
	}
	printf(" c: %d \n", c);
}

void MLS::printPolynomial() {
	for (int i = 0; i < polynomial.size(); i++) {
		printf("%d", polynomial[i]);
	}
	printf("\n");
}

void MLS::setNextC() {
	c = registerV[polynomial[0] - 1];
	for (int i = 1; i < polynomial.size(); i++) {
		c =  c ^ registerV[polynomial[i] - 1];
	}
}

void MLS::printC() {
	printf("%d \n", c);
}

void MLS::shiftRegister() {
	std::rotate(registerV.begin(), registerV.end() - 1, registerV.end());
	registerV[0] = c;
	this->setNextC();
}
