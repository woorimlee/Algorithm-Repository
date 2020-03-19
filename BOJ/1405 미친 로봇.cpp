#include <iostream>

using namespace std;

int N;
bool map[31][31] = { false };
double point[4]; 
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

double DFS(int x, int y, int cnt) {
	if (cnt == 0) {
		return 1.0;
	}

	map[x][y] = true;
	int nx, ny;
	double result = 0.0;
	double probability;

	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][1];
		nx = x + dir[i][0];

		if (map[nx][ny]) {
			continue;
		}

		probability = DFS(nx, ny, cnt - 1) * point[i];
		result += probability;
	}
	map[x][y] = false;

	return result;
}

int main() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> point[i];
		//확률로 변환
		point[i] /= 100.0;
	}
	//(x, y) == (15, 15) 부터 시작
	//중심 좌표부터 N 최대 뻗어나가는 길이 수용 가능한 상황
	printf("%.9lf\n", DFS(15, 15, N));
	return 0;
}