#include <iostream>

using namespace std;

int answer = 0;

int find_combination(int sum, int goal) {
	//num은 더할 숫자
	//sum은 더해진 값
	//goal은 목표 정수

	//목표 정수 == 바로 전까지 더해진 값
	if (goal == sum) {
		answer++;
		return 1; // 더할 숫자 하나 늘려
	}

	//더할 숫자 늘렸더니 sum이 더 커졌네. 그럼 그 전거로 리턴 돌려
	else if (goal < sum) {
		return 0;
	}

	//더할 수 있는 숫자는 1, 2, 3
	find_combination(sum+1, goal);
	find_combination(sum+2, goal);
	find_combination(sum+3, goal);

	return 0;
}

int main(void) {
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	int n;
	while (T--) {
		cin >> n;
		answer = 0;
		find_combination(0, n);
		cout << answer << endl;
	}
}