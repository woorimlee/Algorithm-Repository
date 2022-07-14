#include <iostream>
#include <vector>

using namespace std;

int V;
int diameter_node;
int max_dist = -1;
bool visited[100001];
vector <vector <pair <int, int> > > tree;

//트리 지름의 특징 (그래프 구조 + dfs이용시)
//1. 임의의 정점에서 시작해 가장 멀리 떨어져있는 노드를 찾는다.
//2. 그 노드는 원 위에 위치해있을 것임
//3. 1번에서 찾은 노드에서 다시 한 번 가장 멀리 떨어져 있는 노드를 찾는다.
//4. 3번에서 찾은 노드는 1번에서 찾은 노드의 정 반대에 위치하기 때문에 이 두 노드는 지름이 된다.
//5. 양방향 이동이 가능한 그래프 구조를 이용 (입력으로 양방향 이동이 주어짐)

void dfs(int n1, int dist) {
	visited[n1] = true;
	if (dist > max_dist) {
		diameter_node = n1;
		max_dist = dist;
	}
	for (pair <int, int> n2 : tree[n1]) 
		if (!visited[n2.first])
			dfs(n2.first, dist + n2.second);
}


void find_maximum_diameter() { 
	dfs(1, 0); // 아무 노드에서나 시작 가능
	fill(visited, visited + V + 1, false);
	max_dist = 0;
	dfs(diameter_node, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V;
	tree.resize(V + 1);
	int n1, n2, dist;
	for (int i = 0; i < V; i++) {
		cin >> n1;
		while (true) {
			cin >> n2;
			if (n2 == -1) 
				break;
			cin >> dist;
			tree[n1].push_back({ n2, dist });
		}
	}
	find_maximum_diameter();
	cout << max_dist;
	return 0;
}