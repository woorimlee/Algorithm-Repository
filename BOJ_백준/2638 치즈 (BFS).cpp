#include <iostream>
#include <queue>
using namespace std;

int N, M, ans;
int map[100][100];
bool visited[100][100];
int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void bfs() {
	fill(&visited[0][0], &visited[99][99], false);
	queue<pair<int, int> > q;
	q.push({ 0, 0 });
	visited[0][0] = true;
	pair <int, int> cord;
	int nx, ny;
	while (!q.empty()) {
		cord = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = cord.first + dir[i][1];
			nx = cord.second + dir[i][0];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && visited[ny][nx] == false) {
				if (map[ny][nx] >= 1) {
					map[ny][nx] += 1;
				}
				else {
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

bool melt() {
	bool melted = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] >= 3) {
				map[i][j] = 0;
				melted = true;
			}
			else if (map[i][j] == 2) map[i][j] = 1;
		}
	}
	return melted;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		bfs();
		if (melt()) ans++;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}


//√‚√≥: https://rebas.kr/771