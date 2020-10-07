#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//�׻� ��ȸ�� �� �ִ� ��츸 �־���.
//��� ���� ������ �������� ��ȸ�ϱ�.
//ex). arr[0] = 0, [1] = 1, ..., [3] = 3 �� �� :
//     0123 �� 0 -> 1 -> 2 -> 3 -> 0���� ��ȸ�Ѵٰ� ����.
//     ���� 0 -> 1 ���� 0�̸�, ���� ������ �ٷ� �Ѿ.
//     ��� ���� ������ Ž���ϸ� �ּ� �� ã��.

int main(void) {
	int N;
	cin >> N;
	int W[10][10];

	//����� ū ��
	int answer = 2147483647;
	int arr[10];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
		arr[i] = i;
	}

	do {
		//0 -> 1�� �� ���� 0�̶�� ���� ���� �������� �ѱ�� ���� flag.
		bool flag = true;
		//�� ��ȸ���� ����� ���� ������ temp.
		int temp = 0;
		for (int i = 0; i < N - 1; i++) {
			if (W[arr[i]][arr[i + 1]] == 0) flag = false;
			else temp += W[arr[i]][arr[i + 1]];
		}

		if (!flag || W[arr[N - 1]][arr[0]] == 0) continue;
		temp += W[arr[N - 1]][arr[0]];
		//�ּ� ������ answer�� ����.
		answer = min(answer, temp);

		//�� ������ 0 -> 1 -> 2 -> 3�� ���, �������� 3 -> 0���� ���ƿ��� ������ �� ���� ����
		//(��� ���� ���տ��� �� ���� ����) �����صΰ� ��� ������ ã�Ƶ� ��.
	} while (next_permutation(arr + 1, arr + N));

	cout << answer << endl;
	return 0;
}
