#include <iostream>
#include <map>
#include <string>

using namespace std;

const string text = "Protocol data unit";
const int n = 5;
const string replaceKey = "PpCeEzGoHxIvJFKLNOjAQ RTfUVWwBZaMbcdghiklmYnDqrSstuXy";

string shiftEncrypt(string input, int key);
string genASCIISequence();
string replaceEncrypt(string input, string key);

int main() {
	cout << "Input: " << text << endl;
	cout << "Ouput (shift encryption): " << shiftEncrypt(text, n) << endl;
	cout << "Ouput (replace encryption): " << replaceEncrypt(text, replaceKey) << endl;
	return 0;
}

string shiftEncrypt(string input, int key) {
	string output;
	string asciiseq = genASCIISequence();
	map<string, string> listMap;
	for (int i = 0; i < asciiseq.size(); i++) {
		int keyNum = i + key;
		while (keyNum >= asciiseq.size()) {
			keyNum -= asciiseq.size();
		}
		listMap[asciiseq.substr(i, 1)] = asciiseq.substr(keyNum, 1);
	}
	
	for (int i = 0; i < input.size(); i++) {
		output += listMap.at(input.substr(i, 1));
	}
	
	return output;
}

string replaceEncrypt(string input, string key) {
	string output;
	string asciiseq = genASCIISequence();
	map<string, string> listMap;
	for (int i = 0; i < asciiseq.size(); i++) {
		listMap[asciiseq.substr(i, 1)] = key.substr(i, 1);
	}
	
	for (int i = 0; i < input.size(); i++) {
		output += listMap.at(input.substr(i, 1));
	}
	
	return output;
}

string genASCIISequence() {
	const int A_CODE = 65;
	const int Z_CODE = 90;
	const int a_CODE = 97;
	const int z_CODE = 122;
	const int space_CODE = 32;
	string list;
	for (int i = A_CODE; i <= Z_CODE; i++) {
		char letter = i;
		list += letter;
	}
	for (int i = a_CODE; i <= z_CODE; i++) {
		char letter = i;
		list += letter;
	}
	
	char letter = space_CODE;
	list += letter;
	
	return list;
}
