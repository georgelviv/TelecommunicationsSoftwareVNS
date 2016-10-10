#include <ctime>
#include <vector>
#include "MLS.h"

using namespace std;

const int m = 2, n = 2;

int main() {
	const int mLength = 15;
	const int polynomialArr[3] = {4, 3, 0};
	vector<int> polynomialV (polynomialArr, polynomialArr + sizeof(polynomialArr) / sizeof(polynomialArr[0]));
	
	srand((unsigned)time(NULL));

	MLS mSequence(mLength, polynomialV);
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();
	mSequence.shiftRegister();
	mSequence.printCurrent();


	return 0;
}


