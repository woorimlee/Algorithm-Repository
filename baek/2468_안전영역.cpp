#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, cnt, answer = 1;
int direct[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
bool visited[101][101];
int town[101][101];

void dfs(int y, int x, int h);

int main() {
	cin >> N;
	int min_h = 102, max_h = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> town[i][j];
			min_h = min(town[i][j], min_h);
			max_h = max(town[i][j], max_h);
		}
	}

	for (int i = min_h; i <= max_h; i++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] && town[j][k] > i) {
					dfs(j, k, i);
					cnt++;
				}
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer;
	return 0;
}

void dfs(int y, int x, int h) {
	visited[y][x] = true;
	int nx, ny;
	for (int dir = 0; dir < 4; dir++) {
		nx = x + direct[dir][0];
		ny = y + direct[dir][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (!visited[ny][nx] && town[ny][nx] > h)
			dfs(ny, nx, h);
	}
}