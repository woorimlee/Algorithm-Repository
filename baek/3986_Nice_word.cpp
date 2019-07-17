#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int answer = 0;

	vector <char> vec;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		vec.push_back(str[0]);
		for (int j = 1; j < str.length(); j++) {
			if (!vec.empty() && str[j] == vec.back()) vec.pop_back();
			else vec.push_back(str[j]);
		}

		if (vec.size() == 0) answer++;
		vec.clear();
	}

	cout << answer << endl;


	return 0;
}