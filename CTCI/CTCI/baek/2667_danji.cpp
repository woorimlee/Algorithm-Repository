#include <iostream>
#include <algorithm>

using namespace std;

//N * N 의 0, 1을 입력받고
//단지 수(danji_num)와 각 단지내 집의 수(danji_max[최대 단지 수])를 dfs하며 갱신.
//더 이상 탐색할 곳이 없으면 출력

int N;
int house[26][26] = { -1, };
int direct[4][2] = { {0, -1}, {1,0}, {0, 1},  {-1, 0} };
int danji_num = 0;
int danji_max[314] = { 0, };
//팁 2. 에 따르면 최대 단지 수는 313. 313번째 단지를 [313]에 저장하기 위해 
//초기에 [314] 만큼 선언

void dfs(int y, int x, int danji_num) {
	//dfs 들어오는것 자체가 현재 위치에 집이 있다는 뜻이니
	//다시 탐색하지 못하게 만들고
	house[y][x] = -1;
	//danji_num번째 단지의 집 수를 늘려.
	danji_max[danji_num]++;

	//1. 이동 가능한 방향이고 (범위 내)
	//2. 이동하려는 곳이 집이 있는 곳이라면
	//깊이 탐색 고고
	int dx;	
	int dy;
	int cur_house;
	for (int i = 0; i < 4; i++) {
		dx = x + direct[i][0];
		dy = y + direct[i][1];
		cur_house = house[dy][dx];
		if (0 <= dx && dx < N && 0 <= dy && dy < N && cur_house == 1) {
			dfs(dy, dx, danji_num);
		}
	}
	return;
}

void search() {
	//N * N의 집 정보를 처음부터 끝까지 다 검사하며 1을 만나면 dfs 진행
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == 1) {
				dfs(i, j, ++danji_num);
			}
		}
	}
	return;
}

int main(void) {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%1d", &house[i][j]);
		}
	}

	search();
	
	//출력 전에 단지 내 집의 수를 오름차순으로 정리
	sort(danji_max + 1, danji_max + danji_num + 1);
	cout << danji_num << "\n";
	if (danji_num != 0) {
		for (int i = 1; i <= danji_num; i++) {
			cout << danji_max[i] << "\n";
		}
	}

	return 0;

}