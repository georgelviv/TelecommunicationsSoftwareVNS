#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

namespace utils {
	double genRandomMuller() {
		double u, v, s, x;
	
		do {
			u = ((double) rand() / (RAND_MAX));
			v = ((double) rand() / (RAND_MAX));
			s = pow(u, 2) + pow(v, 2);
		} while (s < 0 || s > 1);
	
		x = u * (sqrt((-2 * log(s)) / s));
	
		return x;
	}
	void fillRandom (double arr[], int size) {
		for (int i = 0; i < size; i++) {
			arr[i] = genRandomMuller();
		}
	}
	void printArray (double arr[], int size) {
		for (int i = 0; i < size; i++) {
			printf("%d: %f; \n", i + 1, arr[i]);
		}
	}
}
