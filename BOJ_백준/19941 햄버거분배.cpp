#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, K, cnt = 0;
	cin >> N >> K;
	string s;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
				if (0 <= j && j < N && s[j] == 'H') {
					s[j] = 'X';
					cnt++;
					break;
				}
			}
		}
	};
	cout << cnt;
	return 0;
}