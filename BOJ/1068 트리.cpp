#include <iostream>
#include <vector>

using namespace std;

int N, delete_node, root, reaf=0;
vector <vector <int> > graph;
bool visited[51] = { false };

bool dfs(int node) {
	if 

	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] == false) {
			if()
		}
	}
}
int main() {
	cin >> N;
	graph.resize(N + 1);
	int parent;
	for (int i = 0; i < N; i++) {
		//양방향 연결 
		//입력받은 수와 i번째 노드를 양방향으로 연결함
		cin >> parent;
		if (parent != -1) {
			graph[i].push_back(parent);
			graph[parent].push_back(i);
		}
		else {
			root = i;
		}
	}
	cin >> delete_node;
	visited[delete_node] = true;
	dfs(root);
	cout << reaf;
	
	return 0;
}