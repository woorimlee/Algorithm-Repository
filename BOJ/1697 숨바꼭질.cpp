#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int N, K;
	int dist[200001] = { 0, };
	queue <int> q;
	cin >> N >> K;
	//N에 수빈이 위치 K에 동생 위치

	q.push(N);
	dist[N] = 1;

	while (!q.empty()) {
		int c_p = q.front(); q.pop(); // current_position
		if (c_p == K) {
			cout << dist[c_p] - 1;
			return 1;
		}

		if ((c_p - 1) >= 0) {
			if (dist[c_p - 1] == 0) {
				q.push(c_p - 1);
				dist[c_p - 1] = dist[c_p] + 1;
			}
		}

		if ((c_p + 1) < 200000) {
			if (dist[c_p + 1] == 0) {
				q.push(c_p + 1);
				dist[c_p + 1] = dist[c_p] + 1;
			}
		}
		
		if ((c_p * 2) < 200000) {
			if (dist[c_p * 2] == 0) {
				q.push(c_p * 2);
				dist[c_p * 2] = dist[c_p] + 1;
			}
		}
	}
	return 0;

}