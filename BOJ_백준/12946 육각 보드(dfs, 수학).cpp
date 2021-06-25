#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
���� ���忡�� �� �������� �ִ� �� ���� �������� �´������.
���� ��ĥ�� �ʿ��� ���� �ִ� �� �� (A, B, C��� ����).
dfs�� ���� ������ ����
1. ���� ��ĥ���� ���� -> �ڽ��� ���� 0�̸� 1��, 1�̸� 0�� ĥ��
2. ���� ĥ���� ���� -> Ư���� ��쿡�� �� ��° ���� �ʿ���. 
	1) �ڱ�� �ٸ� ���� ĥ�������� : ����
	2) �ڱ�� ���� ���� ĥ�������� : Ư���� �����. ����° �� ���
*/

int N, ans;
vector <string> board;

int dir[6][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };

void dfs(int y, int x, char color) {
	board[y][x] = color;
	ans = max(ans, 1);
	int ny = 0, nx = 0;
	for (int i = 0; i < 6; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (board[ny][nx] == 'X') { // �ڱ�� �ٸ� �� ĥ��
				char next_color = (color == 'A') ? 'B' : 'A';
				dfs(ny, nx, next_color);
				ans = max(ans, 2);
			}

			if (board[ny][nx] == color)  
				// 2.2 Ư���� ���. ������ board�� C�� ĥ���� ����
				ans = max(ans, 3);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	board.resize(N);
	for (auto& row : board) {
		cin >> row;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == 'X')
				dfs(i, j, 'A');
	
	cout << ans;
	return 0;
}