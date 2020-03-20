#include <iostream>

using namespace std;

int N;
bool map[31][31] = { false };
double point[4]; 
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

double DFS(int x, int y, int cnt) {
	//�κ��� �̵��� ������ �� 
	if (cnt == 0) {
		//���ݱ��� �̵��ߴ� ����� Ȯ���� ������� �ϴ�
		//1.0�� ��������.
		return 1.0;
	}
	//�ܼ��� ��θ� ����� ���� �� �� �� ��ǥ�� true�� ������
	map[x][y] = true;
	int nx, ny;
	double result = 0.0;
	double probability;

	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][1];
		nx = x + dir[i][0];

		//�ܼ� ��θ� ���� ����
		if (map[nx][ny]) {
			continue;
		}

		//���� ���� ��(�� ó���� 1.0�̰�����?)�� �̵��ߴ� ����� Ȯ�� ���� ����.
		probability = DFS(nx, ny, cnt - 1) * point[i];
		result += probability;
	}
	//��� Ž���� �� �����ٸ� ��� ���� ���� ��ǥ�� false�� �����ּ� 
	//�ٸ� ��� Ž�� ���϶� �� ��ġ�� �ٽ� �� �� �ְ� ����������.
	map[x][y] = false;

	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> point[i];
		//Ȯ���� ��ȯ
		point[i] /= 100.0;
	}
	//(x, y) == (15, 15) ���� ����
	//�߽� ��ǥ���� N �ִ� ������� ���� ���� ������ ��Ȳ
	printf("%.9lf\n", DFS(15, 15, N));
	return 0;
}
