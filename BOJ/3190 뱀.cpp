#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int N, K, L, time=0;
int dir = 0; //뱀이 오른쪽으로 먼저 갈 거임
//순서대로 우, 위, 왼, 아
int direct[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
//사과 = 2, 뱀 = 1, 땅 = 0
int map[101][101] = { 0, };

queue <pair<int, char> > turn;
//덱의 front에는 꼬리 위치가, back에는 머리 위치가 들어있음.
deque <pair <int, int> > snake;

void turn_Snake(char t);

int main() {
	cin >> N >> K;
	int y, x;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		map[y - 1][x - 1] = 2;
	}
	cin >> L;
	char t;
	for (int i = 0; i < L; i++) {
		cin >> x >> t;
		turn.push({ x, t });
	}

	map[0][0] = 1;
	//first == y좌표, second == x좌표
	snake.push_back({ 0,0 });
	int nx, ny;
	pair <int, int> head;
	while (true) {
		//뱀 이동 확인용
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		if (!turn.empty()) {
			if (turn.front().first == time) {
				turn_Snake(turn.front().second);
				turn.pop();
			}
		}
		//머리 부분 위치 가져오기
		head = snake.back();
		ny = head.first + direct[dir][0];
		nx = head.second + direct[dir][1];

		time++;

		//다음 위치가 벽이거나 뱀이라면 끝
		if (N <= ny || ny < 0 || N <= nx || nx < 0 || map[ny][nx] == 1)
			break;

		//다음 위치가 땅이면
		else if (map[ny][nx] == 0) {
			//꼬리 좌표 제거
			map[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}
		
		//머리 좌표 넣어
		snake.push_back({ ny, nx });
		map[ny][nx] = 1;
	}

	cout << time << "\n";
	return 0;
}

/*
	L은 왼쪽으로 회전,
	D는 오른쪽으로 회전.
	가고 있는 방향이
	1) 오른쪽이었어 : L이면 위, D면 아래
	2) 왼쪽이었어 : L이면 아래, D면 위
	3) 아래였어 : L이면 오른쪽, D면 왼쪽
	4) 위였어 : L이면 왼쪽, D면 오른쪽
	L : 우 -> 위 -> 왼 -> 아
	D : 우 <- 위 <- 왼 <- 아
	현재 방향 dir에서 L이면 + 1씩, R이면 -1씩
*/
void turn_Snake(char t) {
	if (t == 'L') {
		(dir != 3) ? dir += 1 : dir = 0;
	}
	else {
		(dir != 0) ? dir -= 1 : dir = 3;
	}
}