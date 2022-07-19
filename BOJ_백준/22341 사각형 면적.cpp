#include <iostream>

using namespace std;

int main() {
	int N, C;
	cin >> N >> C;

	//A, X = ���� / B, Y = ����
	int A = N, B = N;
	int X, Y;
	while (C--) {
		cin >> X >> Y;
		if (X >= A || Y >= B)
			continue;
		if (X * B >= Y * A)
			A = X;
		else
			B = Y;
	}

	cout << A * B;
	return 0;
}