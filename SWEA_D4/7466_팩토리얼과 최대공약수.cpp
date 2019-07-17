#include <iostream>
using namespace std;
unsigned long long T, N, K;
unsigned long gcd(unsigned long long a, unsigned long long b) {
	if (a % b == 0) return b;
	gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		unsigned long long answer = 1;
		unsigned long long temp;
		for (unsigned long long j = N; j >= 2; j--) {
			if (K == 1)
				break;
			else if (K >= j) {
				temp = gcd(K, j);
				if (temp != 1) {
					answer *= temp;
					K /= temp;
				}
			}
			else {
				temp = gcd(j, K);
				if (temp != 1) {
					answer *= temp;
					K /= temp;
				}
			}
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}