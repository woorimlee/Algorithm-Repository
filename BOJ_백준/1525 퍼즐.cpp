#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

char ch;
int ans = 0;
//dir[i][0] == y 좌표 연산, dir[i][1] == x 좌표 연산
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

typedef struct _puzzel{
	//blank.first에 빈 칸의 y좌표, second에 x좌표 저장
	pair<int, int> blank;
	string board = "";
	//구조체 생성자
	_puzzel(int a, int b, string s) {
		blank.first = a;
		blank.second = b;
		board = s;
	}
}puzzel;

puzzel temp(0, 0, "");
unordered_map <string, bool> checked;

bool bfs() {
	int nx, ny, q_size;
	string ns;
	queue <puzzel> q;
	q.push(temp);
	checked[temp.board] = true;
	while (!q.empty()) {
		q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			temp = q.front();
			q.pop();
			if (temp.board == "123456780") {
				return true;
			}
			//1. 0을 기준으로 위 오른쪽 아래 왼쪽 이동 가능한지 검사
			//2. 이미 검사한 적 있는 문자열인지 검사
			//3. 두 조건을 통과하면 퍼즐 bfs 확장
			for (int i = 0; i < 4; i++) {
				ny = temp.blank.first + dir[i][0];
				nx = temp.blank.second + dir[i][1];
				ns = temp.board;
				if (0 <= ny && ny < 3 && 0 <= nx && nx < 3) {
					//빈 공간의 위치와 상하좌우 바꿀 위치 swap해서 문자열 바꿔줌
					swap(ns[ny * 3 + nx], ns[temp.blank.first * 3 + temp.blank.second]);
					//cout << ns << "\n";
					if (checked[ns] != true) {
						q.push(puzzel(ny, nx, ns));
						checked[ns] = true;
					}
				}
			}
		}
		ans++;
	}
	return false;
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ch;
			temp.board += ch;
			if (ch == '0') {
				temp.blank.first = i;
				temp.blank.second = j;
			}
		}
	}

	//cout << temp.board << " " << temp.blank.first << " " << temp.blank.second;
	if (bfs()) {
		cout << ans;
	}
	else {
		cout << -1;
	}
	
	return 0;
}