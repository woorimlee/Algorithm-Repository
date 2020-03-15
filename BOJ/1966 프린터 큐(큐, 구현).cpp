#include <iostream>
#include <queue>

using namespace std;

int T, N, M, cnt;
int imp; //imp == important. �߿䵵 �Է� ���� ����

int main() {
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cnt = 0;
		cin >> N >> M;
		//�켱���� ť�� ť�� ���� ������ ������������(�ٲ� �� ����)
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
