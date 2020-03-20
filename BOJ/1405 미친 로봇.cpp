#include <iostream>

using namespace std;

int N;
bool map[31][31] = { false };
double point[4]; 
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

double DFS(int x, int y, int cnt) {
	//로봇의 이동이 끝났을 때 
	if (cnt == 0) {
		//지금까지 이동했던 경로의 확률을 곱해줘야 하니
		//1.0을 리턴해줌.
		return 1.0;
	}
	//단순한 경로를 만들기 위해 한 번 간 좌표는 true로 만들어둠
	map[x][y] = true;
	int nx, ny;
	double result = 0.0;
	double probability;

	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][1];
		nx = x + dir[i][0];

		//단순 경로를 위한 조건
		if (map[nx][ny]) {
			continue;
		}

		//리턴 받은 값(맨 처음엔 1.0이겠지요?)에 이동했던 경로의 확률 값을 곱함.
		probability = DFS(nx, ny, cnt - 1) * point[i];
		result += probability;
	}
	//경로 탐색이 다 끝났다면 방금 내가 갔던 좌표를 false로 만들어둬서 
	//다른 경로 탐색 중일때 이 위치를 다시 올 수 있게 뒷정리해줌.
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
