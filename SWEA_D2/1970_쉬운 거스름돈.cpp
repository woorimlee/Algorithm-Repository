#include <iostream>
using namespace std;

int T, N;
int PaperMoney[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

void giveBack(int money) {
	int num;
	for (int i = 0; i < 8; i++) {
		num = money / PaperMoney[i];
		money %= PaperMoney[i];
		cout << num << " ";
	}
	cout << "\n";
}

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << "#" << i << "\n";
		giveBack(N);
	}

	return 0;
}