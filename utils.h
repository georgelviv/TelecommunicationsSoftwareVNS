#include <cstdlib>
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
}
