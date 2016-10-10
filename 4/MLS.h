#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

class MLS {
	private:
		std::vector<int> registerV;
		std::vector<int> polynomial;
		int c;
	public:
		MLS (int size, std::vector<int> & polynomialV);
		void printCurrent ();
		void printPolynomial ();
		void printC ();
		void setNextC ();
		void shiftRegister ();
		
};

MLS::MLS (int size, std::vector<int> & polynomialV) {
	registerV.reserve(size);
	int sum = 0;
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
	
	this->setNextC();
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
	c = registerV[polynomial[0]];
	for (int i = 1; i < polynomial.size(); i++) {
		c ^= registerV[polynomial[i]];
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
