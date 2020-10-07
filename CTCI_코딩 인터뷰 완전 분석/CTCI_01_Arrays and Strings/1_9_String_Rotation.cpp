#include <iostream>
#include <string>
using namespace std;

/*
s1 = "waterbot"
s2 = "botwater" 
Let's say y = "bot", x = "water".
So, s2 = y + x.

Approach 1:
if s2 is rotation of s1? then s1 = x + y.

Approach 2:
If we expand the String s1 "waterbot" --> it becomes "waterbotwaterbot"(s1 + s1).
So clearly if the s2 String is rotated from the s1 string, s2 will always be substring of "s1 + s1".
*/

string s1, s2;

bool rotated_str_a1() { //a1 = approach 1
	int j = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s2[j] == s1[i])
			j++;
		else
			j=0;
	}
	if (j == 0)
		j++;

	string y = s2.substr(0, j);
	string x = s2.substr(j);
	cout << "x : " << x << "\ny : " << y << endl;
	string xy = x + y;

	if (s1.compare(xy) == 0) {
		return true;
	}
	return false;
}

bool rotated_str_a2() { //a2 = approach 2
	string s1s1 = s1 + s1;
	if (s1s1.find(s2) != string::npos) { //npos == -1
		return true;
	}

	return false;
}

int main(void) {
	cin >> s1 >> s2;

	if (s1.length() == 0 || s1.length() != s2.length()) {
		cout << "s2 isn't rotation of s1\n";
		return -1;
	}

	cout << "\nApproach 1: \n";
	if (rotated_str_a1())
		cout << "s2 is rotation of s1\n";
	else
		cout << "s2 isn't rotation of s1\n";

	cout << "Approach 2 : \n";
	if(rotated_str_a2())
		cout << "s2 is rotation of s1\n";
	else
		cout << "s2 isn't rotation of s1\n";
		
	return 0;
}