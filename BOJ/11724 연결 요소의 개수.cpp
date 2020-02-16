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
		vec[nodeA].push_back(nodeB);
		vec[nodeB].push_back(nodeA);
	}

	for (int i = 1; i <= N; i++) {
		//�湮�� ��尡 �ƴ϶��
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;
}

void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {
		//�湮�� ��尡 �ƴ϶��
		if (!visited[vec[node][i]])
			dfs(vec[node][i]);
	}
}