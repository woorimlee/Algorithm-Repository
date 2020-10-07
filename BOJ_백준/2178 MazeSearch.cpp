#include <iostream>
#include <queue>

using namespace std;

//(0, 0)에서 출발하여 (N-1, M-1)에 도착. 최소 칸 수를 세는데 출발과 도착도 포함.
//BFS로 풀 예정.
//미로를 0 또는 1로 받으면서, 현재 위치에서 다음 방문 가능한 곳으로 이동하면, 
//이동 전에 있던 곳을 해당 위치까지 이동하는데 필요한 최소 칸 수로 바꿈.
//이렇게 하면 방문했던 곳을 다시 방문할 일이 없음.

int N, M;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int maze[101][101];
queue <pair<int, int> > que;

void bfs() {

	que.push(make_pair(0, 0));
	pair <int, int> current;
	int nx, ny;
	while (!que.empty()) {
		//현재 좌표가 current에 담김.
		current = que.front();
		que.pop();
		//현재 위치에서 상하좌우 검사.
		for (int i = 0; i < 4; i++) {
			nx = current.second + direct[i][0];
			ny = current.first + direct[i][1];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1)
			{
				//다음 이동가능한 위치를 bfs용 queue에 넣고(넣어두면 다음 차례에 검사를 함) 그 위치 값을 갱신
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