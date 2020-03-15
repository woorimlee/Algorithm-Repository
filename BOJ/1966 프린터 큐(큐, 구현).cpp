#include <iostream>
#include <queue>

using namespace std;

int T, N, M, cnt;
int imp; //imp == important. 중요도 입력 받을 예정

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cnt = 0;
		cin >> N >> M;
		//우선순위 큐는 큐에 넣은 값들을 오름차순으로(바꿀 수 있음)
		priority_queue<pair <int, int > > pq;
		for (int j = 0; j < N; ++j) {
			cin >> imp;
			pq.push({ imp, j });
		}

		while(!pq.empty()) {
			cout << pq.top().first << " " << pq.top().second << "\n";
			cnt++;
			if (pq.top().second == M) {
				cout << "?? : " << cnt << "\n";
				break;
			}
			pq.pop();
		}
		
		cnt = 0;
	}
	return 0;
}
