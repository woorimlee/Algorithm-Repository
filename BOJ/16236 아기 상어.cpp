#include <iostream>
#include <queue>
/*
규칙 : 
아기 상어는 자신의 크기보다 작거나 같은 곳으로 이동 가능
아기 상어는 자신보다 작은애만 먹음
자기 크기만큼 물고기를 먹어야 크기가 1증가
자기와 제일 가까운 애를 먹음
가까운 애가 여러명이면 1) 맨 위, 2) 맨 왼쪽
더이상 먹을게 없으면 프로그램 끝

자료구조 : 
가장 가까운 먹방 가능한 물고기를 찾기 위해 우선순위 큐를 사용할 것이다.
우선순위 큐는 기본적으로 max heap.
맨 오른쪽 끝 값이 pop 되는 기준이니까 우선순위 큐의 맨 끝에는 아래의 조건에 해당하는 물고기가 들어있다.
	1) 가장 거리가 가까운 물고기
	2) 거리가 가까운 물고기가 여럿이라면 y가 작은 애
	3) y값도 같으면 x가 작은 애
위 조건을 만족하는 애가 오른쪽 끝으로 가게 한다. (ex. a.x < b.x)

알고리즘 
1. 현 시점 기준 가장 가까운 물고기 bfs로 찾으며 우선순위큐에 넣음
2. 우선순위큐 pop하고 그 물고기 위치로 이동하며 초 증가 및 아기 상어가 먹은 물고기 갯수 1 증가
3. 만약 먹은 물고기 갯수가 자신의 몸무게와 같으면 몸무게 1 증가 및 먹은 물고기 갯수 초기화
4. 우선순위큐 초기화하면서 1 ~ 3 반복
5. 더이상 먹을게 없으면 정답 출력

*/

using namespace std;

struct Fish{
	int x, y, dist;
	Fish(int x, int y, int dist) : x{ x }, y{ y }, dist{ dist }{};
	bool operator < (const Fish other) const {
		if (dist == other.dist) {
			if (y == other.y)
				return x > other.x;
			else
				return y > other.y;
		}
		return dist > other.dist;
	}
};
typedef struct Fish Fish; //C언어와의 호환성을 위해

int N, ans;
int s_eat, s_size, s_x, s_y; //shark가 먹은 갯수, shark 사이즈
int map[21][21];
bool visited[21][21];
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

void bfs(); // 우선 순위큐로 돌면서 물고기 찾고 먹고...

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s_x = j;
				s_y = i;
				map[i][j] = 0;
			}
		}
	}

	s_size = 2;
	bfs();
	cout << ans;

	return 0;
}

void bfs() {

}