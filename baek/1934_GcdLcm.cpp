#include <iostream>

using namespace std;

int T;

//���� ���� ū ���� %
//�������� 0�̸� �ִ� �����
//�ּ� ����� = �� ���� �� / �ִ� �����
int LCM(int a, int b) {
	int A = a;
	int B = b;

	int temp;
	while (!(b % a == 0)) {
		temp = a;
		a = b % a;
		b = temp;
	}

	return A * B / a;
}

int main(void) {

	cin >> T;

	int A, B, answer;
	while (T--) {
		cin >> A >> B;
		if (A > B) {
			int temp = A;
			A = B;
			B = temp;
		}
		answer = LCM(A, B);
		cout << answer << endl;
	}


	return 0;
}