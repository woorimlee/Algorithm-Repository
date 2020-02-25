#include <iostream>
#include <vector>

using namespace std;

int N, delete_node, root, reaf=0;
//트리를 저장할 이차원 벡터
vector <vector <int> > graph;
bool visited[51] = { false };

void dfs(int node) {
	//dfs 들어온 노드는 검사했다고 처리함
	visited[node] = true;
	//base case
	if (node >= N) {
		return;
	}
	//자식 노드의 존재를 확인
	bool child = false;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] == false) {
			//자식 노드가 있는 상태 && 자식 노드 방문하지 않은 상태
			child = true;
			dfs(graph[node][i]);
		}
	}
	//자식 노드가 없다면
	if (!child) {
		//답 1 증가
		reaf++;
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
	//지울 노드는 dfs로 탐색하지 않을 예정
	visited[delete_node] = true;
	//루트 노드를 지울 노드로 선정하는 경우가 있다고 함.
	if(visited[root] == false) 
		dfs(root);
	cout << reaf;
	
	return 0;
}