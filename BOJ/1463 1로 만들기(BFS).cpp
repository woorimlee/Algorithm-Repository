#include <iostream>
#include <queue>

using namespace std;

int N;
bool visited[1000001] = { false };

void bfs() {
	/*
	N에서 시작 --> 1로 만들거임. 
	나누기를 하기 싫어서 곱하기로 바꿀예정임.
	어차피 3이나 2로 나누어 떨어진다는 것은 3과 2의 배수임.
	1을 --> N으로 만들 예정
	
	할 수 있는 연산
	1. 현재 값 * 3
	2. 현재 값 * 2
	3. 현재 값 + 1
	*/
	
	//q.first == 현재 값, second == 연산 횟수
	queue <pair <int, int> > q;
	//1부터 시작
	q.push({ 1, 0 });
	visited[1] = true;
	pair<int, int> now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		//연산된 현재 값이 N이면 연산 횟수 출력 및 리턴
		if (now.first == N) {
			cout << now.second;
			return;
		}
		//if문 세 개 쓰기 싫어서 배열에 계산해야 할 값 넣어둠
		int cal[3] = { now.first * 3, now.first * 2, now.first + 1 };
		for (int i = 0; i < 3; i++) {
			//인덱스 초과했는지 검사 안하면 런타임 에러
			if (cal[i] <= 1000000) {
				//새 연산 값이 방문 안 한 곳이면
				if (visited[cal[i]] == false) {
					//방문하고 push
					visited[cal[i]] = true;
					q.push({ cal[i], now.second + 1 });
				}
			}
		}
	}

}

int main() {
	cin >> N;
	bfs();
}