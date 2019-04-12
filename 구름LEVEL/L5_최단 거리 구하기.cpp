#include <iostream>
#include <queue>
using namespace std;

int N;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int map[11][11];

void bfs(int startX, int startY) {
	int x = startX;
	int y = startY;
	int nx, ny;
	queue <pair<int, int> > que;

	que.push(make_pair(x, y));
	while (!que.empty()) {
		x = que.front().first;
		y = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + direct[i][0];
			ny = y + direct[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && map[ny][nx] == 1) {
				que.push(make_pair(nx, ny));
				map[ny][nx] += map[y][x];
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	bfs(0, 0);
	cout << map[N - 1][N - 1];
	return 0;
}