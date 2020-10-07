#include <iostream>
#include <string>

using namespace std;

int alphabet[26] = { 0 };

int main() {
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		alphabet[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
	return 0;
}