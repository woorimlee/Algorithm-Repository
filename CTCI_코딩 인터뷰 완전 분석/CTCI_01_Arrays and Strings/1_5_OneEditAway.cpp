#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool editOne(string &strA, string &strB);
bool checkReplace(string & strA, string &strB);
bool checkAddDel(string &strA, string &strB);
bool checkCompact(string &strA, string &strB);

void main() {
	string a, b;
	cin >> a >> b;

	if (editOne(a, b))
		cout << "true\n";
	else cout << "false\n";

	return;
}

bool editOne(string &strA, string &strB) {
	int lengthA = strA.length();
	int lengthB = strB.length();

	if (lengthA == lengthB) {
		return checkReplace(strA, strB);
		//return checkCompact(strA, strB);
	}
	else if ((lengthA + 1) == lengthB) {
		return checkAddDel(strA, strB);
		//return checkCompact(strA, strB);
	}
	else if ((lengthA - 1) == lengthB) {
		return checkAddDel(strB, strA);
		//return checkCompact(strA, strB);
	}
	else return false;
}

bool checkReplace(string &strA, string &strB) {
	int check = 0;
	for (int i = 0; i < strA.length(); i++) {
		if (check >= 2)
			return false;
		else if (strA[i] != strB[i])
			check++;
	}
	return true;
}

// To Implement Insert func, Use two pointer algorithm.
// First one (j) points long string.
// The other one (i) points short string.
// While increasing i, j, if there are more than one difference between strA[i] and strB[j] --> return false;
// pale 
// ale	ple	pae	pal --> true
// lae				--> false
bool checkAddDel(string &strA, string &strB) {
	int check = 0;
	int j = 0;

	for (int i = 0; i < strA.length(); ) {
		if (check >= 2)
			return false;
		else if (strA[i] != strB[j]) {
			check++;
			j++;
		}
		else if (strA[i] == strB[j]) {
			i++;
			j++;
		}
	}
	return true;
}

// Compact (case of Replacement) + (case of Insert(or Delete))
bool checkCompact(string &strA, string &strB) {
	int check = 0;
	int j = 0;
	
									   //j++
	for (int i = 0; i < strA.length(); j++) {
	//j always increase.
		if (check >= 2)
			return false;
		else if (strA[i] != strB[j]) {
			check++;
			//Under the two lines were added to checkAddDel().
			if (strA.length() == strB.length())
				i++;
		}
		else if (strA[i] == strB[j]) {
			i++;
		}
	}
	return true;
}