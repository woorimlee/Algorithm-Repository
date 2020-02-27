#include <iostream>
#include <string>

#define alphabet 26

using namespace std;

int main() {
	char ans[alphabet] = { 0 };
	fill_n(ans, alphabet, -1);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if(ans[str[i]-'a'] == -1)
			ans[str[i] - 'a'] = i;
	}
	for (int i = 0; i < alphabet; i++) {
		cout << (int)ans[i] << " ";
	}

	return 0;
}