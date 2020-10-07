#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

#define RED 1
#define BLUE 2
int K, V, E;
int visited[20001] = { 0, };
vector <vector <int> > graph;

bool bfs();

int main() {
	cin >> K;
	int nodeA, nodeB;
	while (K--) {
		cin >> V >> E;
		//매 테스트 케이스마다 그래프 초기화
		graph.clear();
		graph.resize(V + 1);
		//visited도 0으로 초기화
		memset(visited, 0, sizeof(int) * (V + 1));
		for (int i = 0; i < E; i++) {
			cin >> nodeA >> nodeB;
			graph[nodeA].push_back(nodeB);
			graph[nodeB].push_back(nodeA);
		}
		//bfs 결과에 따라 YES 혹은 NO 출력
		if (bfs()) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}

bool bfs() {
	//시작 COLOR는 RED로 정함
	int node, next_color = RED;
	queue<int> que;
	//1번 노드에서만 시작하는 게 아님.
	//연결 그래프가 아닐 수 있기 때문에, 모든 노드를 검사
	for (int i = 1; i <= V; i++) {
		//visited[현재 노드]가 RED 또는 BLUE로 색칠된 상태라면
		//이 노트부터 BFS검사를 할 필요가 없음
		if(visited[i] == 0) {
			que.push(i);
			visited[i] = RED;
			while (!que.empty()) {
				node = que.front();
				que.pop();
				if (visited[node] == RED)
					next_color = BLUE;
				else if (visited[node] == BLUE)
					next_color = RED;
				//현재 정점에서 갈 수 있는 모든 정점 검사
				for (int i = 0; i < graph[node].size(); i++) {
					//인접한 정점이 아직 색칠되지 않았다면,
					if (visited[graph[node][i]] == 0) {
						//자기랑 다른 색 칠하고 que에 넣음
						visited[graph[node][i]] = next_color;
						que.push(graph[node][i]);
					}
					//인접한 정점이 색칠된 상황인데 자기랑 같은 색이면
					else if (visited[graph[node][i]] == visited[node])
						//NO를 출력하기 위해 & 탐색 끝내기 위해 false return
						return false;
				}
			}
		}
	}
	//검사를 무사히 통과하면 이분 그래프
	return true;
}