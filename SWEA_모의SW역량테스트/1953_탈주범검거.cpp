#include <iostream>
#include <memory.h>

using namespace std;

int T;
//지하 터널 지도의 세로 크기 N, 가로 크기 M, 맨홀 뚜껑이 위치한장소의 세로 위치 R, 가로 위치 C, 그리고 탈출 후 소요된 시간 L
int N, M, R, C, L;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
bool visited[51][51] = { false, };
//도둑이 있을 수 있는 위치
bool location[51][51];
int map[51][51];

void dfs(int X, int Y, int time);

int main(void) {
	cin >> T;
	int answer;

	for (int i = 1; i <= T; i++) {
		//테스트 케이스마다 초기화
		memset(location, false, sizeof(location));
		memset(map, 0, sizeof(map));
		answer = 0;
		cin >> N >> M >> R >> C >> L;
		
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> map[y][x];
			}
		}

		dfs(C, R, 0);
		//이동 가능한 위치 검사
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (location[y][x])
					answer++;
			}
		}

		cout << "#" << i  << " " << answer << "\n";
	}

	return 0;
}

void dfs(int X, int Y, int time) {
	//베이스 컨디션
	if (time == L)
		return;

	location[Y][X] = true;
	int cur = map[Y][X]; //cur = current
	int next;
	int nx, ny;

	//자기 좌표에서 상 우 하 좌 검사
	for (int i = 0; i < 4; i++) {
		nx = X + direct[i][0];
		ny = Y + direct[i][1];
		next = map[ny][nx];

		//갈 곳에 파이프가 없고, 이미 방문한 곳이고, 지도 범위 벗어나면
		if (map[ny][nx] == 0) continue;
		else if (visited[ny][nx]) continue;
		else if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

		//자기 파이프 형태가 위로 이동할 수 있는게 아니라면
		if (i == 0 && (cur == 3 || cur == 5 || cur == 6)) continue;
		//우
		else if (i == 1 && (cur == 2 || cur == 6 || cur == 7)) continue;
		//하
		else if (i == 2 && (cur == 3 || cur == 4 || cur == 7)) continue;
		//좌
		else if (i == 3 && (cur == 2 || cur == 4 || cur == 5)) continue;

		//다음 파이프 형태가 연결이 불가능한 형태라면
		if (i == 0 && (next == 3 || next == 4 || next == 7)) continue;
		else if (i == 1 && (next == 2 || next == 4 || next == 5)) continue;
		else if (i == 2 && (next == 3 || next == 5 || next == 6)) continue;
		else if (i == 3 && (next == 2 || next == 6 || next == 7)) continue;

		visited[Y][X] = true;
		dfs(nx, ny, time + 1);
		visited[Y][X] = false;
	}
}