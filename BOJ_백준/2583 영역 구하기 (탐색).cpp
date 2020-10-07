/*
입력받은 M * N 배열에 넣을 값을 다음과 같이 설정함.
(문제의 모눈종이는 일반적인 2차원 배열과 수평 대칭인 상황)
-1 == 직사각형 내부
0 == 비어있는 영역
1 == 첫 번째 분리된 영역
2 == 두 번째 분리된 영역 
...

전체 2차원 배열을 dfs를 이용해 위와 같은 값으로 배열을 채워나감.
*/

#include <iostream>
#include <queue>

using namespace std;

int M, N; //M == 세로, N == 가로
int K;
int cur_area = 1; //분리된 영영으로 쓸 변수
int area_size = 0; //각 분리된 영역의 크기를 저장할 변수
int map[101][101] = { 0 }; 
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
priority_queue <int, vector<int>, greater<int> > ans; //영역의 크기 저장할 배열. 오름차순 기준이라 우선순위큐 씀

void dfs(int y, int x, int area);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;
	int x1, y1, x2, y2; //K개의 직사각형 꼭짓점 입력받을 변수
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		//x1 == 0, y1 == 2, x2 == 4, y2 == 4
		//직사각형 내부 -1로 바꾸기
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				map[j][k] = -1;
			}
		}
	}

	//입력받은 직사각형이 반영 된 맵 출력
	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = M-1; j >= 0; j--) {
			if (map[j][i] == 0) {
				dfs(j, i, cur_area);
				ans.push(area_size);
				cur_area++;
				area_size = 0;
			}
		}
	}


	cout << cur_area - 1 << "\n";
	int ans_size = ans.size();
	for (int i = 0; i < ans_size; i++) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}

void dfs(int y, int x, int area) {
	area_size++;
	map[y][x] = area;
	int nx, ny;
	//현재 좌표 기준 상하좌우 네 방향 검사
	for (int i = 0; i < 4; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (0 <= ny && ny < M && 0 <= nx && nx < N && map[ny][nx] == 0) {
			dfs(ny, nx, area);
		}
	}
}