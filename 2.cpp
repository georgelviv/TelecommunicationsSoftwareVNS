#include <iostream>
#include "utils.h"

using namespace std;

double genRandomArray (int arrLength);

int main() {
	cout << genRandomArray(200) << endl;
	return 0;
}

double* genRandomArray (int arrLength) {
	double arr[arrLength] = {};
	
	for (int i = 0; i < arrLength; i++) {
		arr[i] = utils::genRandomMuller();
	}
	
	cout << arr << endl;
	
	return new int[arrLength];
}
