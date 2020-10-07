#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string str1, str2;

bool unnecessary_Work() {
	if (str1.length() != str2.length())
		return true;
	return false;
}

bool Brute_Force() {
	sort(str1.begin(), str1.end());
	do {
		if (str1.compare(str2) == 0)
			return true;
	} while (std::next_permutation(str1.begin(), str1.end()));

	return false;
}

bool use_Map() {
	map <char, int> s_m; //str_mapping;
	for (int i = 0; i < str1.length(); i++) {
		s_m[str1[i]]++;
	}
	for (int i = 0; i < str2.length(); i++) {
		s_m[str2[i]]--;
	}
	for (int i = 0; i < s_m.size(); i++) {
		if (s_m[(char)('a' + i)] != 0)
			return false;
	}

	return true;
}

void main(void) {
	cin >> str1 >> str2;

	if (unnecessary_Work()) {
		cout << "This isn't permutation\n";
		return;
	}

	if (Brute_Force())
		cout << "BF : Permutation" << endl;
	if (use_Map())
		cout << "MAP : Permutation" << endl;
	else 
		cout << "This isn't permutation\n";
	return;
}