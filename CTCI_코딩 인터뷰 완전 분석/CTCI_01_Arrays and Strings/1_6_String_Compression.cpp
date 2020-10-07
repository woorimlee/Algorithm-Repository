#include <iostream>
#include <string>

using namespace std;

void compress(string &inStr, string &outStr) {
	int countConsecutive = 0;

	if (inStr.length() == 1) {
		outStr = inStr;
		return;
	}

	for (int i = 0; i < inStr.length() -1; i++) {
		countConsecutive++;
		if (inStr[i] != inStr[i + 1]) {
			outStr += inStr[i] + to_string(countConsecutive);
			countConsecutive = 0;
		}
	}

	countConsecutive++;
	outStr += inStr[inStr.length() - 1] + to_string(countConsecutive);
	
	if (outStr.length() >= inStr.length()) {
		outStr = inStr;
	}

	return;
}

void main() {
	string inStr;
	cin >> inStr;

	string outStr;
	compress(inStr, outStr);

	cout << outStr;
	return;
}