#include <iostream>
#include <algorithm>

using namespace std;

//N * N �� 0, 1�� �Է¹ް�
//���� ��(danji_num)�� �� ������ ���� ��(danji_max[�ִ� ���� ��])�� dfs�ϸ� ����.
//�� �̻� Ž���� ���� ������ ���

int N;
int house[26][26] = { -1, };
int direct[4][2] = { {0, -1}, {1,0}, {0, 1},  {-1, 0} };
int danji_num = 0;
int danji_max[314] = { 0, };
//�� 2. �� ������ �ִ� ���� ���� 313. 313��° ������ [313]�� �����ϱ� ���� 
//�ʱ⿡ [314] ��ŭ ����

void dfs(int y, int x, int danji_num) {
	//dfs �����°� ��ü�� ���� ��ġ�� ���� �ִٴ� ���̴�
	//�ٽ� Ž������ ���ϰ� �����
	house[y][x] = -1;
	//danji_num��° ������ �� ���� �÷�.
	danji_max[danji_num]++;

	//1. �̵� ������ �����̰� (���� ��)
	//2. �̵��Ϸ��� ���� ���� �ִ� ���̶��
	//���� Ž�� ���
	int dx;	
	int dy;
	int cur_house;
	for (int i = 0; i < 4; i++) {
		dx = x + direct[i][0];
		dy = y + direct[i][1];
		cur_house = house[dy][dx];
		if (0 <= dx && dx < N && 0 <= dy && dy < N && cur_house == 1) {
			dfs(dy, dx, danji_num);
		}
	}
	return;
}

void search() {
	//N * N�� �� ������ ó������ ������ �� �˻��ϸ� 1�� ������ dfs ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 1) {
				dfs(i, j, ++danji_num);
			}
		}
	}
	return;
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &house[i][j]);
		}
	}

	search();
	
	//��� ���� ���� �� ���� ���� ������������ ����
	sort(danji_max + 1, danji_max + danji_num + 1);
	cout << danji_num << "\n";
	if (danji_num != 0) {
		for (int i = 1; i <= danji_num; i++) {
			cout << danji_max[i] << "\n";
		}
	}

	return 0;

}