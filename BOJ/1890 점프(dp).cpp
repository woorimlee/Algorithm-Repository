#include <iostream>

using namespace std;

int N;
int board[101][101];
long long cache[101][101];

//dp를 만들어나갈 함수 
//dp(y, x) = 도착지에 도착할 수 있는 경우의 수.
//도착지에 도착한 경우 한 가지 방법이 나타난 것임으로 1을 리턴하고
//1을 리턴 받은 위치(jump 함수를 실행한 곳)에서 자신의 위치에서 도달할 수 있는 경우에 1을 더해준다.
//도착지에서부터 dp를 누적해나간다고 생각하자.
long long jump(int y, int x) {
	if (y >= N || x >= N) {
		return 0;
	}
	if (y == N - 1 && x == N - 1) {
		return 1;
	}
	if (cache[y][x] != -1) {
		return cache[y][x];
	}

	//ret는 cache의 참조형 변수로 cache[y][x]의 값 자체를 바꿔줄 수 있음.
	long long& ret = cache[y][x];
	ret = 0;
	ret += jump(y + board[y][x], x);
	ret += jump(y, x + board[y][x]);
	return ret;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	//dp의 모든 값을 -1로 바꿔놓고, 도달할 수 없는 경우 0을, 도달할 수 있는 경우 1을 return 하는 형식.
	fill(&cache[0][0], &cache[100][100], -1);
	cout << jump(0, 0);
	return 0;
}