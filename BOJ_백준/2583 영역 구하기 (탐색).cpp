/*
�Է¹��� M * N �迭�� ���� ���� ������ ���� ������.
(������ �����̴� �Ϲ����� 2���� �迭�� ���� ��Ī�� ��Ȳ)
-1 == ���簢�� ����
0 == ����ִ� ����
1 == ù ��° �и��� ����
2 == �� ��° �и��� ���� 
...

��ü 2���� �迭�� dfs�� �̿��� ���� ���� ������ �迭�� ä������.
*/

#include <iostream>
#include <queue>

using namespace std;

int M, N; //M == ����, N == ����
int K;
int cur_area = 1; //�и��� �������� �� ����
int area_size = 0; //�� �и��� ������ ũ�⸦ ������ ����
int map[101][101] = { 0 }; 
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
priority_queue <int, vector<int>, greater<int> > ans; //������ ũ�� ������ �迭. �������� �����̶� �켱����ť ��

void dfs(int y, int x, int area);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;
	int x1, y1, x2, y2; //K���� ���簢�� ������ �Է¹��� ����
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		//x1 == 0, y1 == 2, x2 == 4, y2 == 4
		//���簢�� ���� -1�� �ٲٱ�
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				map[j][k] = -1;
			}
		}
	}

	//�Է¹��� ���簢���� �ݿ� �� �� ���
	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = M-1; j >= 0; j--) {
			if (map[j][i] == 0) {
				dfs(j, i, cur_area);
				ans.push(area_size);
				cur_area++;
				area_size = 0;
			}
		}
	}


	cout << cur_area - 1 << "\n";
	int ans_size = ans.size();
	for (int i = 0; i < ans_size; i++) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}

void dfs(int y, int x, int area) {
	area_size++;
	map[y][x] = area;
	int nx, ny;
	//���� ��ǥ ���� �����¿� �� ���� �˻�
	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (0 <= ny && ny < M && 0 <= nx && nx < N && map[ny][nx] == 0) {
			dfs(ny, nx, area);
		}
	}
}