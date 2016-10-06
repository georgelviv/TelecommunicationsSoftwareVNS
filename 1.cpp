#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int m = 2, n = 2;

double genRandomMuller();
double genRandomKnuth(int m, int n);

int main() {
	cout << "Muller:" << genRandomMuller() << endl;
	cout << "Knuth:" << genRandomKnuth(m, n) << endl;
	return 0;
}


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

double genRandomKnuth(int m, int n) {
	double lambda, l, k = 0, p = 1, u;
	
	lambda = m / n;
	
	l = pow(M_E, -lambda);
	

	do {
		k += 1;
		u = rand();
		p = p * u;
	} while (p > l);
	
	return k - 1;
}
