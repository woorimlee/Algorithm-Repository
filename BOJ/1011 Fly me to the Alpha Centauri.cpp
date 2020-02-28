#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		long long X, Y;
		cin >> X >> Y;
		long long length = Y - X;
		int answer = 0;
		long long i = 1;
		while (i * i <= length) {
			i++;
		}

		if ((i - 1) * (i - 1) == length)
			answer = 2 * (i - 1) - 1;
		else if ((i - 1) * (i - 1) + ((i * i - (i - 1) * (i - 1)) / 2) >= length)
			answer = 2 * i - 2;
		else
			answer = 2 * i - 1;

		cout << answer << "\n";
	}
	return 0;
}