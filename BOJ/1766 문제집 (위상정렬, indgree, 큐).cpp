/*
1 ~ N 문제. N이 가장 어려움
가능하면 쉬운문제,
위상 정렬 개념으로 1 -> 4 ...
indegree가 0이고 숫자가 낮은 것부터
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B;
int len;
int indegree[32001];
vector <vector<int> > vec;
priority_queue <int, vector<int>, greater<int> > que;

int main() {
	cin >> N >> M;
	vec.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		vec[A].push_back(B);
		indegree[B]++;
	}
	//진입 차수 0인 노드 전부 큐에 추가
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	int cur_node;
	//정렬이 완전히 수행되려면 정확히 n개의 노드를 방문.
	while (N--) {
		if (que.empty()) {
			printf("사이클 발생\n");
			return 0;
		}
		cur_node = que.top();
		que.pop();
		cout << cur_node << " ";
		len = vec[cur_node].size();
		for (int i = 0; i < len; i++) {
			if (--indegree[vec[cur_node][i]] == 0) {
				que.push(vec[cur_node][i]);
			}
		}
	}

	return 0;
}
