#include <iostream>
#include <vector>

using namespace std;

//컴퓨터의 수 N
//연결된 쌍의 수 S
//무방향성 그래프 구현을 위해 이차원 vector를 사용함.

int N, S, answer = 0;
bool visited[101] = { false, };
vector <vector <int> > com_graph;

int map[101][101];

void dfs(int cur) {
	visited[cur] = true;

	for (int i = 0; i < com_graph[cur].size(); i++) {
		if (visited[com_graph[cur][i]] == false) {
			dfs(com_graph[cur][i]);
			answer++;
		}
	}

	return;
}

void ddfs(int node) {
	answer++;
	visited[node] = true;
	for (int i = 1; i <= N; i++) {
		if (map[node][i] && !visited[i])
			dfs(i);
	}
}

int main(void) {
	cin >> N >> S;

	com_graph.resize(N + 1);

	int a, b;
	while (S--) {
		cin >> a >> b;
		com_graph[a].push_back(b);
		com_graph[b].push_back(a);
		map[a][b] = map[b][a] = 1;
	}

	//dfs(1);
	ddfs(1);
	cout << answer;

	return 0;
}