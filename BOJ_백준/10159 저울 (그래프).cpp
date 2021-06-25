#include <iostream>
#include <vector>

using namespace std;

/*
* 각 노드에 대해 방향 그래프를 표현함
* 이때 각 노드별로 들어오는 방향, 나가는 방향을 구분해야 함.
* n1과 n2가 들어오는 방향이나 나가는 방향 어떤 방식이든 연결되어있으면
* 대소 관계 파악 가능.
* 
* 1. 방향 그래프 두 개 구현해서 풀거나
* 2. 플로이드 워셜 사용하거나
* 
* C++로는 1번
* Python으로는 2번 방법으로 풀어봄
*/

int N, M;
bool visited[101];

void dfs(int cur, vector <vector <int> >& graph) {
	visited[cur] = 1;
	for (int next : graph[cur]) {
		if(!visited[next])
			dfs(next, graph);
	}
}

int main() {
	cin >> N >> M;

	vector <vector <int> > scale, inverse_scale;
	scale.resize(N);
	inverse_scale.resize(N);

	int s1, s2;
	for (int i = 0; i < M; i++) {
		cin >> s1 >> s2;
		scale[s1 - 1].push_back(s2 - 1);
		inverse_scale[s2 - 1].push_back(s1 - 1);
	}


	for (int i = 0; i < N; i++) {
		fill(&visited[0], &visited[100], 0);

		dfs(i, scale);
		dfs(i, inverse_scale);
		int cnt = 0;
		for (int j = 0; j < N; j++) 
			if (!visited[j])
				cnt++;
		cout << cnt << "\n";
	}
	return 0;
}