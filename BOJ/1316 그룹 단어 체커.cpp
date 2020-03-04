#include <iostream>
#include <string>

using namespace std;

int N, ans=0;
bool check[26] = { false };

bool group_word_check(string &str) {
	check[str[0] - 'a'] = true;
	for (int i = 1; i < str.length(); i++) {
		if (str[i] != str[i - 1] && check[str[i] - 'a']) {
			return false;
		}
		check[str[i] - 'a'] = true;
	}
	return true;
}

int main() {
	cin >> N;
	string str;
	while (N--) {
		cin >> str;
		fill_n(check, 26, false);
		if (group_word_check(str)) {
			ans++;
		}
	}
	cout << ans;
}