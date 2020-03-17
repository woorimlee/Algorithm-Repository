#include<iostream>
#include<queue>
using namespace std;

//[i][0] == y, [i][1] == x
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int tomato[1001][1001];
queue< pair <int, int> > q;


int main() {
	int M, N, size;
	int day = 0;
	int total = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i, j });
			}
			else if (tomato[i][j] == -1) {
				total++;
			}
		}
	}

	while (!q.empty()) {
		size = q.size();
		total += size;
		//익은 갯수와 비어있는 칸 다 합쳐서 배열의 크기가 된다면
		//답 출력하고 프로그램 종료
		if (total == N * M) {
			cout << day;
			return 0;
		}
		//q.size 만큼 queue를 탐색하면 현재 익은 토마토만큼만 알고리즘을 적용시킬 수 있음
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			//상 하 좌 우 방향에 덜 익은 토마토가 있으면
			//익게 만들고 queue에 넣어놔서 다음 타임에 또 익은 상태를 확장시킴
			for (int j = 0; j < 4; j++) {
				int ny = y + dir[j][0];
				int nx = x + dir[j][1];
				if (0 <= nx && nx < N && 0 <= ny && ny < M) {
					if (tomato[nx][ny] == 0) {
						tomato[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}
		day++;
	}
	//안 익은 갯수가 하나라도 있다면 while문 빠져나와서 -1 출력하고 프로그램 종료.
	if (total != N * M) {
		cout << -1;
	}
	return 0;
}