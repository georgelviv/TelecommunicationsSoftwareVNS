#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include "utils.h"

using namespace std;

const string list = "0911E3F4";
const string hexTarget = "F";
const string target = "W";

vector<string> convertToBinaryVector(const string list);
string genASCIISequence();
bool someBySequential(vector<string> list, string key);
bool someByBinary(string list, string key);

int main() {
	bool res = someBySequential(utils::convertToBinaryVector(list), 
		utils::hexToBin(hexTarget));
	string asciiSeq = genASCIISequence();


	cout << "Input: " << list << endl;
	cout << "Find in list: " << hexTarget << endl;
	cout << "Results of search: ";
	if (res) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	
	cout << "\n \n " << endl;
	cout << "Input: " << asciiSeq << endl;
	cout << "Find in list: " << target << endl;
	cout << "Results of search: ";
	if (someByBinary(asciiSeq, target)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	return 0;
}

bool someBySequential(vector<string> list, string key) {
	for (int i = 0; i < list.size(); i++) {
		if (list[i] == key) {
			return true;
		}
	}
	return false;
}



string genASCIISequence() {
	const int A_CODE = 65;
	const int Z_CODE = 90;
	string list;
	for (int i = A_CODE; i <= Z_CODE; i++) {
		char letter = i;
		list += letter;
	}
	
	return list;
}

bool someByBinary(string list, string key) {
	string intString = utils::convertToBinaryString(list);
	vector<string> vList = utils::convertToVector(intString, 2);
	int keyI = key[0];
	int startP = 0;
	int endP = vList.size() - 1;

	do {
		int cur = floor((startP + endP) / 2);
		int curEl = stoi(vList[cur]);
		if (keyI == curEl) {
			return true;
		}
		if (keyI > curEl) {
			startP = cur + 1;
		} else {
			endP = cur - 1;
		}
	} while((endP - startP) > 0);

	
	return false;
}
