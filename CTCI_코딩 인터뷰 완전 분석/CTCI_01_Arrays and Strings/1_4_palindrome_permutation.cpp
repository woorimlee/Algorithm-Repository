#include <iostream>
#include <string>

using namespace std;

//BCR : O(s). s is a input string's length.

bool check_palindrome(string & inStr);
int ctoInt(char & temp);
void toggle(int & temp, int & bitInt);

void main() {
	string inStr;
	getline(cin, inStr, '\n');

	if (check_palindrome(inStr))
		cout << "True";
	else cout << "False";

	return;
}

bool check_palindrome(string & inStr) {
	int bitInt = 0;

	for (int i = 0; i < inStr.length(); i++) {
		//inStr[i] to 0 ~ 25 int value.
		int temp = ctoInt(inStr[i]);
		//toggle [temp] index;
		if (0 <= temp && temp < 26)
			toggle(temp, bitInt);
	}

	//if you type like this "(bitInt & (bitInt - 1) == 0)", then the expression becomes "(bitInt & ((bitInt - 1) == 0))". Because of the Operator Precedence.
	//cout << "test 1 : " << (bitInt & (bitInt - 1) == 0) << "\ntest 2 : " << ((bitInt & (bitInt - 1)) == 0) << endl;
	return (bitInt == 0) || ((bitInt & (bitInt - 1)) == 0);
}

int ctoInt(char & temp) {
	if ('a' <= temp && temp <= 'z')
		return temp - 'a';
	else if ('A' <= temp && temp <= 'Z')
		return temp - 'A';
	else return -1;
}

void toggle(int & temp, int & bitInt) {
	int bitmask = (1 << temp);
	
	if ((bitInt & bitmask) == 0) {
		bitInt |= bitmask;
	}
	else
		bitInt &= ~bitmask;

	return;
}