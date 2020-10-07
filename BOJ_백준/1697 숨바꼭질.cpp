#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001] = { false };
//수빈이의 위치 값, 걸린 시간이 들어있음
queue <pair<int, int> > sb;

int main(void) {
	
	cin >> N >> K;

	sb.push({ N, 0 });
	visited[N] = true;
	pair <int, int> cp; //current position
	while (!sb.empty()) {
		cp = sb.front();
		sb.pop(); 
		
		//수빈이의 위치와 동생의 위치가 같다면
		if (cp.first == K) {
			cout << cp.second;
			return 0;
		}

		//bfs로 탐색할 종류 
		//1) 현재위치 -1
		//2) 현재위치 +1
		//3) 현재위치 *2
		int calc[3] = { cp.first - 1, cp.first + 1, cp.first * 2 };
		for (int i = 0; i < 3; i++) {
			if (0 <= calc[i] && calc[i] < 100001) {
				if (!visited[calc[i]]) {
					sb.push({ calc[i], cp.second + 1 });
					visited[calc[i]] = true;
				}
			}
		}
	}
	return 0;
}

/* 아래의 코드를 for구문과 배열을 써서 위와 같이 바꿈
#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001] = { false };
//수빈이의 위치 값, 걸린 시간이 들어있음
queue <pair<int, int> > sb;

int main(void) {

	cin >> N >> K;

	sb.push({ N, 0 });
	visited[N] = true;
	pair <int, int> cp; //current position
	while (!sb.empty()) {
		cp = sb.front();
		sb.pop();

		//수빈이의 위치와 동생의 위치가 같다면
		if (cp.first == K) {
			cout << cp.second;
			return 0;
		}

		//bfs로 탐색할 종류
		//1) 현재위치 -1
		//2) 현재위치 +1
		//3) 현재위치 *2

		//1)
		//현재 위치 - 1이 0보다는 커야함
		if (cp.first - 1 >= 0) {
			if ((!visited[cp.first - 1])) {
				sb.push({ cp.first - 1, cp.second + 1 });
				visited[cp.first - 1] = true;
			}
		}

		//2)
		if (cp.first + 1 < 100001) {
			if (!visited[cp.first + 1]) {
				sb.push({ cp.first + 1, cp.second + 1 });
				visited[cp.first + 1] = true;
			}
		}

		//3)
		//위치가 100000 이상인 건 아예 처리하지 않아도 되는 문제인듯 함
		if (cp.first * 2 < 100001) {
			if (!visited[cp.first * 2]) {
				sb.push({ cp.first * 2, cp.second + 1 });
				visited[cp.first * 2] = true;
			}
		}
	}
	return 0;
}
*/