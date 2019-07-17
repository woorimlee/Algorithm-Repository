#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;

int T, N, W, H, answer;
int direct[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int map[5][16][13];

//bead번 째 구슬 위치시키기
void locateBead(int bead);
//현재 맵에 이전 배열을 복사해둠.(bead번 째 구슬이 벽돌 깬 뒤에 다시 이전 맵으로 복원. 백트랙킹)
void copyMap(int bead); 
//map[bead][y][x]에서 블록 크기 만큼 break 시작.
void breakBlock(int x, int y, int bead);
//벽돌 깨고 난 뒤 빈 공간이 있을수 있으니 정렬.
void sortMap(int bead);

int main() {
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N >> W >> H;
		answer = 987654321;

		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> map[0][j][k];
			}
		}

		locateBead(1);
		if (answer == 987654321)
			answer = 0;
		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}

void locateBead(int bead) {
	if (bead > N) {
		//점수 검사
		int temp = 0;
		for (int i = 0; i < H; i++) 
			for (int j = 0; j < W; j++) 
				if (map[bead-1][i][j] >= 1)
					temp++;
			
		answer = min(answer, temp);
		return;
	}

	// bead번 째 구슬을 0~ W-1 위치에서 떨어트리기
	for (int i = 0; i < W; i++) {
		copyMap(bead); //맨 처음 map을 bead 번째 map에 복사(이전 걸 지금 거에 복사)
		int j = 0;
		for (j; j < H; j++) {
			if (map[bead][j][i]) {
				breakBlock(i, j, bead);
				break;
			}
		}
		if (j == H) continue;
		sortMap(bead);
		locateBead(bead + 1);
	}
}

void copyMap(int bead) {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			map[bead][i][j] = map[bead - 1][i][j];
}

void breakBlock(int x, int y, int bead) {
	int block = map[bead][y][x];
	map[bead][y][x] = 0;

	for (int i = 0; i < block; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + i * direct[j][0];
			int ny = y + i * direct[j][1];
			if (nx < 0 || ny < 0 || nx >= W || ny >= H || map[bead][ny][nx] == 0) continue;
			breakBlock(nx, ny, bead);
		}
	}
}

void sortMap(int bead) {
	//FIFO que에 넣어두고 맨 밑에서부터 재할당
	queue <int> que;

	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (map[bead][j][i]) {
				que.push(map[bead][j][i]);
				map[bead][j][i] = 0;
			}
		}
		int j = H - 1;
		while (!que.empty()) {
			map[bead][j][i] = que.front();
			j--;
			que.pop();
		}
	}
}