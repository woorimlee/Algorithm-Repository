#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
bool compare(const string a, const string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() == b.length()) {
		return a < b;
	}
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string s;

	//compare 함수 만들어서 set의 정렬 조건 수정함.
	bool (*fn_pt)(string, string) = compare;
	set <string, bool(*)(string, string)> arr(compare);
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.insert(s);
	}

	for (auto& p : arr) {
		cout << p << "\n";
	}

	return 0;
}