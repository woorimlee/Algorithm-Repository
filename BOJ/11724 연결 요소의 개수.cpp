#include <iostream>
#include <vector>

using namespace std;

int N, M, ans = 0;
bool visited[1001] = { false };
vector <vector <int> > vec;

void dfs(int node);

int main() {
	cin >> N >> M;
	vec.resize(N + 1);
	int nodeA, nodeB;
	for (int i = 0; i < M; i++) {
		cin >> nodeA >> nodeB;
		//무방향 그래프를 만들어줌
		vec[nodeA].push_back(nodeB);
		vec[nodeB].push_back(nodeA);
	}

	for (int i = 1; i <= N; i++) {
		//모든 노드를 기준으로 이미 방문한 노드가 아니라면 
		//dfs 탐색 시작
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;
}

void dfs(int node) {
	//연결된 모든 노드를 dfs로 탐색할 것임
	visited[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {
		//방문한 노드가 아니라면
		if (!visited[vec[node][i]])
			dfs(vec[node][i]);
	}
}