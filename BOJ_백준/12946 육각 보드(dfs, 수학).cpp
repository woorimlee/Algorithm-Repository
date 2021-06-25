#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
육각 보드에서 한 꼭짓점에 최대 세 개의 육각형이 맞닿아있음.
따라서 색칠에 필요한 색은 최대 세 개 (A, B, C라고 가정).
dfs의 경우는 다음과 같음
1. 색이 안칠해져 있음 -> 자신의 색이 0이면 1을, 1이면 0을 칠함
2. 색이 칠해져 있음 -> 특수한 경우에만 세 번째 색이 필요함. 
	1) 자기랑 다른 색이 칠해져있음 : 노상관
	2) 자기랑 같은 색이 칠해져있음 : 특수한 경우임. 세번째 색 사용
*/

int N, ans;
vector <string> board;

int dir[6][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };

void dfs(int y, int x, char color) {
	board[y][x] = color;
	ans = max(ans, 1);
	int ny = 0, nx = 0;
	for (int i = 0; i < 6; i++) {
		ny = y + dir[i][0];
		nx = x + dir[i][1];
		if (0 <= nx && nx < N && 0 <= ny && ny < N) {
			if (board[ny][nx] == 'X') { // 자기랑 다른 색 칠함
				char next_color = (color == 'A') ? 'B' : 'A';
				dfs(ny, nx, next_color);
				ans = max(ans, 2);
			}

			if (board[ny][nx] == color)  
				// 2.2 특수한 경우. 실제로 board를 C로 칠하진 않음
				ans = max(ans, 3);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	board.resize(N);
	for (auto& row : board) {
		cin >> row;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == 'X')
				dfs(i, j, 'A');
	
	cout << ans;
	return 0;
}