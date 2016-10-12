#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "MLS.h"

using namespace std;

const int m = 2, n = 2;

void correlationFunction(int size, MLS mSequence);

int main() {
	const int mLength = 4;
	const int polynomialArr[2] = {4, 3};
	vector<int> polynomialV (polynomialArr, polynomialArr + sizeof(polynomialArr) / sizeof(polynomialArr[0]));
	
	srand((unsigned)time(NULL));

	MLS mSequence(mLength, polynomialV);
	mSequence.setMArray();
	correlationFunction(mLength, mSequence);

	return 0;
}

void correlationFunction(int size, MLS mSequence) {
	int N = (pow(size, 2) - 1);
	signed int tau = -(N - 1);
	int n, s;
	int r[N * 2 - 1];
	while (tau < N) {
		n = 0;
		s = 0;
		while (n < N) {
			s += mSequence.getMArrayByIndex(n) * mSequence.getMArrayByIndex(n + tau);
			n++;
		}
		r[tau + (N - 1)] = s;
		tau++;
	}
	
	for (int i = -(N - 1); i < N; i++) {
		printf("%3d |", i);
		for (int y = 0; y < ceil(r[i + (N - 1)] / 100); y++) {
			printf("-");
		}
		printf("\n");
	}
}
