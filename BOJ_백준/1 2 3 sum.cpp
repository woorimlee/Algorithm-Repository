#include <iostream>

using namespace std;

int answer = 0;

int find_combination(int sum, int goal) {
	//num�� ���� ����
	//sum�� ������ ��
	//goal�� ��ǥ ����

	//��ǥ ���� == �ٷ� ������ ������ ��
	if (goal == sum) {
		answer++;
		return 1; // ���� ���� �ϳ� �÷�
	}

	//���� ���� �÷ȴ��� sum�� �� Ŀ����. �׷� �� ���ŷ� ���� ����
	else if (goal < sum) {
		return 0;
	}

	//���� �� �ִ� ���ڴ� 1, 2, 3
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