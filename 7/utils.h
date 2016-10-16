#include <string>
#include <vector>
#include <cmath>
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
	
	std::string hexToBin(std::string& hex) {
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
	
	vector<string> convertToBinaryVector(const string list) {
		vector<string> x;
		for (int i = 0; i < list.size(); i++) {
			x.push_back(utils::hexToBin(list.substr(i, 1)));
		}
		return x;
	}	
	
	string convertToBinaryString(string list) {
		string intString;
		for (int i = 0; i < list.size(); i++) {
			int l = list[i];
			intString += to_string(l);
		}
		
		return intString;
	}
	
	vector<string> convertToVector(string list, int size) {
		vector<string> r;
		for (int i = 0; i < list.size(); i += size) {
			r.push_back(list.substr(i, size));
		}
		return r;
	}

}
