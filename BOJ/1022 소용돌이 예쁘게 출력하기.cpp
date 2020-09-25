/*1->오른쪽 하나 이동
2 * 4->오른쪽 하나 이동
4 * 4->오른쪽 하나 이동
6 * 4->오른쪽 하나 이동*/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int num = 1, fill_len = 0;
int x = 0, y = 0;
int dir_y[4] = { 0, -1, 0, 1 };
int dir_x[4] = { 1, 0, -1, 0 };
int board[50][5]; 

int main() {

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int cnt = 0;
	int last_cnt = (abs(r2 - r1) + 1) * (abs(c2 - c1) + 1);

	if (c1 <= x && x <= c2 && r1 <= y && y <= r2) {
		board[y - r1][x - c1] = num;
		cnt++;
	}

	int dir = 0, fill_len = 0, last_num = 0;
	while (cnt < last_cnt) {
		if (dir % 2 == 0) {
			fill_len++;
		}
		for (int i = 0; i < fill_len; i++) {
			num++;
			y += dir_y[dir];
			x += dir_x[dir];
			if (r1 <= y && y <= r2 && c1 <= x && x <= c2) {
				board[y - r1][x - c1] = num;
				last_num = num;
				cnt++;
			}
		}

		dir = (dir + 1) % 4;
	}

	cnt = 0;
	while (last_num > 0) {
		last_num /= 10;
		cnt++;
	}
	for (int i = 0; i <= (r2 - r1); i++) {
		for (int j = 0; j <= (c2 - c1); j++)
			printf("%*d ", cnt, board[i][j]);
		cout << "\n";
	}
}
