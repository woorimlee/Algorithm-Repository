#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int N, NN, ans_y, ans_x; //Natural Number
	cin >> N >> NN;

	//������ ���� �迭 ����
	int** arr;
	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		//������ �迭 0���� �ʱ�ȭ
		fill_n(arr[i], N, 0);
	}

	int cnt = N * N;
	//dir[i][0] = y ����, dir[i][1] = x����
	int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
	int y = 0, x = 0, index = 0, ny, nx;

	while (cnt) {
		if (cnt == NN) {
			ans_y = y;
			ans_x = x;
		}
		arr[y][x] = cnt--;

		//������ �ٲ�����ϴ� ������ �˻���
		ny = y + dir[index][0];
		nx = x + dir[index][1];
		if (0 > ny || ny >= N || 0 > nx || nx >= N || arr[ny][nx] != 0) {
			//index == 0 -> �Ʒ�, 1 -> ������, 2 -> ��, 3 -> ���� ������ �ǹ���
			index = (index + 1) % 4;
		}
		y = y + dir[index][0];
		x = x + dir[index][1];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << ans_y + 1 << " " << ans_x + 1;
	return 0;
}