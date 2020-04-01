#include <iostream>

bool prime[1000000001] = { false, };

using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 2; i * i <= 1000000001; i++) {
		if (prime[i] == false)
			for (int j = i * i; j <= 1000000001; j += i) {
				prime[j] = true;
			}
	}
	if (prime[N]) {
		cout << N - 1;
	}
	else {
		for (int i = N / 2; i >= 1; i--) {
			if (N % i == 0) {
				cout << N - i;
			}
		}

	}
	return 0;
}