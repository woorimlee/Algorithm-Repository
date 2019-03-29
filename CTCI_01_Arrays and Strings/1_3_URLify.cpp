#include <iostream>
#include <string>

using namespace std;

// BCR : O(s). s is Input string's length.

string inStr;
int N; //second Input value.

void main(void) {
	getline(cin, inStr, '\n');
	cin >> N;

	string outStr = "";
	for (int i = 0; i < N; i++) {
		if (inStr[i] != ' ') {
			outStr += inStr[i];
		}
		else {
			outStr += "%20";
		}
	}

	cout << outStr << "\n";
}