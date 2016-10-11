#include <ctime>
#include <vector>
#include "MLS.h"

using namespace std;

const int m = 2, n = 2;

int main() {
	const int mLength = 4;
	const int polynomialArr[2] = {4, 3};
	vector<int> polynomialV (polynomialArr, polynomialArr + sizeof(polynomialArr) / sizeof(polynomialArr[0]));
	
	srand((unsigned)time(NULL));

	MLS mSequence(mLength, polynomialV);
	mSequence.setMArray();
	mSequence.printMArray();

	return 0;
}


