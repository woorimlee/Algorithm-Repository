#include <iostream>

using namespace std;

int main(void) {
	int T, X1, X2, Y1, Y2, Z1, Z2;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> X1 >> X2 >> Y1 >> Y2; // X1 = 3,   X2 = 17,   Y1 = 1,   Y2 = 39

		Z2 = X2 + Y2;
		Z1 = X1 + Y1;
		if (Z2 >= 60) {
			Z2 -= 60;
			Z1 += 1;
		}
		if (Z1 >= 13) {
			Z1 -= 12;
		}
		cout << "#" << i << " " << Z1 << " " << Z2 << "\n";
	}


	return 0;
}