#

/*#include <iostream>
#include <string.h>
#define MAX_SIZE 51

using namespace std;

int map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
bool ret[MAX_SIZE][MAX_SIZE];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void dfs(int m, int n, int x, int y, int l, int d) {
	if (d == l) return;

	ret[y][x] = 1;
	int cur = map[y][x];

	for (int i = 0; i < 4; i++) {
		if (i == 0 && (cur == 3 || cur == 5 || cur == 6)) continue;
		if (i == 1 && (cur == 2 || cur == 6 || cur == 7)) continue;
		if (i == 2 && (cur == 3 || cur == 4 || cur == 7))continue;
		if (i == 3 && (cur == 2 || cur == 4 || cur == 5))continue;

		int nx = x + dx[i];
		int ny = y + dy[i];

		int next = map[ny][nx];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
		else if (map[ny][nx] == 0 || visit[ny][nx]) continue;

		if (i == 0 && (next == 3 || next == 4 || next == 7)) continue;
		if (i == 1 && (next == 2 || next == 4 || next == 5)) continue;
		if (i == 2 && (next == 3 || next == 5 || next == 6)) continue;
		if (i == 3 && (next == 2 || next == 6 || next == 7)) continue;

		visit[y][x] = 1;
		dfs(m, n, nx, ny, l, d + 1);
		visit[y][x] = 0;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, m, r, c, l;
		cin >> n >> m >> r >> c >> l;

		memset(map, 0, sizeof(map));
		memset(ret, false, sizeof(ret));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[j][k];
			}
		}

		dfs(m, n, c, r, l, 0);

		int res = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (ret[j][k]) res++;
			}
		}

		cout << '#' << i << ' ' << res << '\n';
	}
	return 0;
}
*/