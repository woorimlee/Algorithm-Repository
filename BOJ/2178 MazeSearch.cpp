#include <iostream>
#include <queue>

using namespace std;

//(0, 0)���� ����Ͽ� (N-1, M-1)�� ����. �ּ� ĭ ���� ���µ� ��߰� ������ ����.
//BFS�� Ǯ ����.
//�̷θ� 0 �Ǵ� 1�� �����鼭, ���� ��ġ���� ���� �湮 ������ ������ �̵��ϸ�, 
//�̵� ���� �ִ� ���� �ش� ��ġ���� �̵��ϴµ� �ʿ��� �ּ� ĭ ���� �ٲ�.
//�̷��� �ϸ� �湮�ߴ� ���� �ٽ� �湮�� ���� ����.

int N, M;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int maze[101][101];
queue <pair<int, int> > que;

void bfs() {

	que.push(make_pair(0, 0));
	pair <int, int> current;
	int nx, ny;
	while (!que.empty()) {
		//���� ��ǥ�� current�� ���.
		current = que.front();
		que.pop();
		//���� ��ġ���� �����¿� �˻�.
		for (int i = 0; i < 4; i++) {
			nx = current.second + direct[i][0];
			ny = current.first + direct[i][1];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1)
			{
				//���� �̵������� ��ġ�� bfs�� queue�� �ְ�(�־�θ� ���� ���ʿ� �˻縦 ��) �� ��ġ ���� ����
				que.push(make_pair(ny, nx));
				maze[ny][nx] = maze[current.first][current.second] + 1;
			}
		}
	}

	return;
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &maze[i][j]);
		}
	}

	bfs();
	cout << maze[N - 1][M - 1];
	return 0;
}