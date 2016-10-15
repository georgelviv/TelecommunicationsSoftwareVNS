#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace utils {
	const char* hexCharToBin(char c) {
    	switch(toupper(c)){
        	case '0': return "0000";
        	case '1': return "0001";
        	case '2': return "0010";
        	case '3': return "0011";
        	case '4': return "0100";
        	case '5': return "0101";
        	case '6': return "0110";
        	case '7': return "0111";
        	case '8': return "1000";
        	case '9': return "1001";
        	case 'A': return "1010";
        	case 'B': return "1011";
        	case 'C': return "1100";
        	case 'D': return "1101";
        	case 'E': return "1110";
        	case 'F': return "1111";
    		}
	}

	std::string hexToBin(const std::string& hex) {
		std::string bin;
    	for(int  i = 0; i != hex.length(); ++i) {
    		bin += hexCharToBin(hex[i]);
		}
    	return bin;
	}
	
	std::vector<int> convertToVector(const int array[], int size) {
		std::vector<int> v;
		for (int i = 0; i < size; i++) {
			v.push_back(array[i]);
		}
		return v;
	}
	
	std::vector<int> convertToPolynomial(std::string bites) {
		vector<int> p;
		for (int i = 0; i < bites.size(); i++) {
			int x = stoi(bites.substr(i, 1), nullptr, 2);
			if (x) p.push_back(bites.size() - i - 1);
		}
		
		return p;
	}
	
	std::string polynomialToBinary(std::vector<int> polynomial) {
		string code;
		for (int i = 0; i <= polynomial[0]; i++) {
			code += "0";
		}

		for (int i = 0; i < polynomial.size(); i++) {
			code.replace(code.size() - polynomial[i] -1, 1, "1");
		}
		
		return code;
	}
	
	std::string toBinaryString(int x) {
    	char buffer[64];
    	char* p = buffer + 64;
    	do {
        	*--p = '0' + (x & 1);
    	} while (x >>= 1);
    	return std::string(p, buffer + 64);
	}
		
	std::string modBinary(std::string a, std::string b) {
		int x = std::stoi(a, nullptr, 2);
		int y = std::stoi(b, nullptr, 2);
		return toBinaryString(x % y);
	}
	
	std::vector<int> modPolynomial(std::vector<int> a, std::vector<int> b) {
		vector<int> c;
		string x = polynomialToBinary(a);
		string y = polynomialToBinary(b);
		c = convertToPolynomial(modBinary(x, y));
		return c;
	}
	

}
