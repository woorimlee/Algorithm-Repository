#include <iostream>
using namespace std;
int main() {
	int N, K;
	bool sosoo[1001] = { false };
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (sosoo[j] == false) {
				sosoo[j] = true;
				K--;
			}
			if (K == 0) {
				cout << j;
				return 0;
			}
		}
	}
	return 0;
}