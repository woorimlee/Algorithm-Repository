#include <iostream>
#include <cmath>
#define MS 10
using namespace std;

int score[MS];

void solve_1() {
	int ans = 0;
	for (int i = 0; i < MS; i++) {
		cin >> score[i];
		ans += score[i];
	}

	int now_score = ans;
	for (int i = MS - 1; i >= 0; i--) {
		if (abs(ans - 100) > abs(now_score - score[i] - 100)) {
			ans = now_score - score[i];
		}
		now_score -= score[i];
	}

	cout << ans;
	return;
}

void solve_2() {
	int ans = 0;
	for (int i = 0; i < MS; i++) {
		cin >> score[i];
	}
	int i = 0;
	while (i < 10 && ans < 100) {
		ans += score[i];
		i++;
	}
	if (ans - 100 > abs(ans - score[i - 1] - 100)) {
		cout << ans - score[i - 1];
	}
	else
		cout << ans;
	return;
}

int main() {

	//��� 1. solve_1()
	//�迭 �� �ڿ������� �� �ٿ�������,
	//100�� ���� ����� �� ã�Ƽ� ����
	//|���� �� - 100| ���� |���� �� - 10| 
	//0| �� ������ ����

	//��� 2. slove_2()
	//100�� ����� ���� x��� �� ��,
	//x�� ���� �� �ΰ���,
	//x >=100 Ȥ�� x < 100 �� ���� ����.

	//solve_1();
	solve_2();

	return 0;
}