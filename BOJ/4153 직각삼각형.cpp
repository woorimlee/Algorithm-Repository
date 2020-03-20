#include <iostream>
using namespace std;
int main() {
	long long a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) {
			return 0;
		}

		if (a * a + b * b == c * c) {
			cout << "right\n";
		}
		else if (a * a == b * b + c * c) {
			cout << "right\n";
		}
		else if (a * a + c * c == b * b  ) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
	return 0;
}