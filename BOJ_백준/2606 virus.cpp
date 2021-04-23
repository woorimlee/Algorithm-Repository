#include <iostream>
#include <vector>

using namespace std;

//컴퓨터의 수 N
//연결된 쌍의 수 S
//무방향성 그래프 구현을 위해 이차원 vector를 사용함.

int N, S, answer = 0;
bool visited[101] = { false, };
vector <vector <int> > com_graph;

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

int main(void) {
	//cin >> N >> S;
	scanf_s("%d %d", &N, &S);

	com_graph.resize(N+1);

	int a, b;
	while (S--) {
		//cin >> a >> b;
		scanf_s("%d %d", &a, &b);
		com_graph[a].push_back(b);
		com_graph[b].push_back(a);
	}

	dfs(1);
	//cout << answer;
	printf("%d", answer);

	return 0;
}