#include <iostream>
#include <vector>

using namespace std;

//��ǻ���� �� N
//����� ���� �� S
//�����⼺ �׷��� ������ ���� ������ vector�� �����.

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