#include <iostream>
#include <queue>

using namespace std;
int T, M, N, K, X, Y;
//위 오른쪽 아래 왼쪽 순서
int dir[4][2] = { {-1, 0 }, {0, 1}, {1, 0}, {0, -1 } };

int main() {

	cin >> T;
	while (T--) {
		int temp_x;
		int temp_y;
		//field는 매 테스트 케이스마다 초기화되어야함.
		//이중 반복문 or memset 함수 or fill 함수를 쓰거나
		//변수 자체를 새로 만들자
		bool field[51][51] = { false };
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> temp_x >> temp_y;
			field[temp_x][temp_y] = true;
		}

		//2차원 배열 0, 0부터 N-1, M-1까지 지렁이 놓을 곳 탐색
		//true면 지렁이 놓고 해당 지렁이의 담당영역을 모두 bfs로 탐색
		int cnt = 0; //*cnt = 지렁이 수를 저장
		queue <pair<int, int > > q; //*first에 y좌표, second에 x좌표 저장할 예정
		pair <int, int> now; //*bfs 탐색할 때 q.front 받아줄 변수
		int ny, nx; //*now 좌표기준 상하좌우 탐색용 변수
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] == true) { //*배추가 있는 곳이니 bfs 탐색법으로 지렁이 영역 탐색
					q.push({ i, j });
					field[i][j] = false; //*지렁이 놓인 위치 false로 바꿈 
					//(다시 탐색 안하게. push랑 한 세트로 봐도됨)
					while (!q.empty()) {
						now = q.front();
						q.pop();
						for (int i = 0; i < 4; i++) {
							ny = now.first + dir[i][0];
							nx = now.second + dir[i][1];
							if (ny < 0 || nx < 0 || ny >= M || nx >= N || field[ny][nx] == false)
								continue;
							q.push({ ny, nx });
							field[ny][nx] = false;
						}
					}
					//bfs 탐색 끝나면 해당 영역에서 지렁이가 갈 수 있는곳은 다 간것.
					//답 1 증가
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}