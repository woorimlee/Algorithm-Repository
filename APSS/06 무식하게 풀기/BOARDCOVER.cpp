#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DIR 4

int H, W;
int ans;
int dot_cnt;
int L[DIR][2][2] = {
	{ {1, 0}, {0, 1} }, //y, x
	{ {0, 1}, {1, 1} },
	{ {1, 0}, {1, 1}},
	{{1, 0}, {1, -1}}
};
vector <string> board;

bool check(int y, int x, int d) {
	//현재 위치에서 파생된 부분 모두 '.' 위치에 있어야함.
	int ny, nx;
	for (int i = 0; i < 2; i++) {
		ny = y + L[d][i][0];
		nx = x + L[d][i][1];
		//cout <<"??" << ny << nx<<"\n";
		if (0 <= ny && ny < H && 0 <= nx && nx < W) {
			//cout << board[ny][nx] << "\n";
			if (board[ny][nx] != '.')
				return false;
		}
		else {
			return false;
		}
	}
	return true;
}

void set_board(int y, int x, int d, char c) {
	board[y][x] = c;
	for (int i = 0; i < 2; i++) 
		board[y + L[d][i][0]][x + L[d][i][1]] = c;
}

void cover_board(int cnt) {
	//base case
	if (cnt == 0) {
		ans++;
		return;
	}
	/*
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j];
		}cout << "\n";
	}*/

	//첫 점 찾기
	int x = -1, y = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			//cout << i << j << board[i][j] << " ";
			if (board[i][j] == '.') {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) {
			break;
		}
	}//cout << "\n";

	if (y == -1)
		return;
	for (int i = 0; i < DIR; i++) {
		//cout << "!!" << y << x << "\n";
		if (check(y, x, i)) {
			set_board(y, x, i, 'H');
			cover_board(cnt - 1);
			set_board(y, x, i, '.');
		}
	}
}

int main() {

	int C;
	cin >> C;
	while (C--) {
		int x, y;
		ans = 0;
		dot_cnt = 0;
		board.clear();
		cin >> H >> W;
		string s;
		for (int i = 0; i < H; i++) {
			cin >> s;
			board.push_back(s);
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '.') {
					dot_cnt++;
				}
			}
		}
		if (dot_cnt % 3 == 0) {
			cover_board(dot_cnt/3);
		}
		cout << ans << "\n";
	}
}