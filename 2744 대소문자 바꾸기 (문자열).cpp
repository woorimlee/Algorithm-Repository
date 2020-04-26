#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		('a' <= s[i] && s[i] <= 'z') ? cout << (char)(s[i] - 'a' + 'A') : cout << (char)(s[i] - 'A' + 'a');
	}

	return 0;
}