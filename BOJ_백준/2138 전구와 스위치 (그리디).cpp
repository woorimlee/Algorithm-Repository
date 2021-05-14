#include <iostream>
#include <string>
#include <algorithm>

#define ANS_MAX 1234567890

using namespace std;

int N;

int run(const string& base, const string& target) {
	int cnt = 0;
	string copy_base = base;
	for (int i = 1; i < N; i++) {
		if (copy_base[i - 1] != target[i - 1]) {
			for (int j = i - 1; j <= i + 1 && j < N; j++) {
				copy_base[j] = copy_base[j] == '0' ? '1' : '0';
			}
			cnt++;
		}
	}
	if (copy_base == target)
		return cnt;
	return ANS_MAX;
}

int main() {
	string original, c_original, target;
	cin >> N >> original >> target;

	c_original = original;
	c_original[0] = original[0] == '0' ? '1' : '0';
	c_original[1] = original[1] == '0' ? '1' : '0';

	int ans = min(run(original, target), run(c_original, target) + 1);
	if (ans == ANS_MAX)
		cout << -1;
	else
		cout << ans;

	return 0;
}