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

	//방법 1. solve_1()
	//배열 맨 뒤에서부터 값 줄여나가며,
	//100에 가장 가까운 수 찾아서 갱신
	//|기존 값 - 100| 보다 |현재 값 - 10| 
	//0| 더 작으면 갱신

	//방법 2. slove_2()
	//100에 가까운 수가 x라고 할 때,
	//x의 경우는 총 두개로,
	//x >=100 혹은 x < 100 중 답이 있음.

	//solve_1();
	solve_2();

	return 0;
}