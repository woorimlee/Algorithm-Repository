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
		//�� �׽�Ʈ ���̽����� �׷��� �ʱ�ȭ
		graph.clear();
		graph.resize(V + 1);
		//visited�� 0���� �ʱ�ȭ
		memset(visited, 0, sizeof(int) * (V + 1));
		for (int i = 0; i < E; i++) {
			cin >> nodeA >> nodeB;
			graph[nodeA].push_back(nodeB);
			graph[nodeB].push_back(nodeA);
		}
		//bfs ����� ���� YES Ȥ�� NO ���
		if (bfs()) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}

bool bfs() {
	//���� COLOR�� RED�� ����
	int node, next_color = RED;
	queue<int> que;
	//1�� ��忡���� �����ϴ� �� �ƴ�.
	//���� �׷����� �ƴ� �� �ֱ� ������, ��� ��带 �˻�
	for (int i = 1; i <= V; i++) {
		//visited[���� ���]�� RED �Ǵ� BLUE�� ��ĥ�� ���¶��
		//�� ��Ʈ���� BFS�˻縦 �� �ʿ䰡 ����
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
				//���� �������� �� �� �ִ� ��� ���� �˻�
				for (int i = 0; i < graph[node].size(); i++) {
					//������ ������ ���� ��ĥ���� �ʾҴٸ�,
					if (visited[graph[node][i]] == 0) {
						//�ڱ�� �ٸ� �� ĥ�ϰ� que�� ����
						visited[graph[node][i]] = next_color;
						que.push(graph[node][i]);
					}
					//������ ������ ��ĥ�� ��Ȳ�ε� �ڱ�� ���� ���̸�
					else if (visited[graph[node][i]] == visited[node])
						//NO�� ����ϱ� ���� & Ž�� ������ ���� false return
						return false;
				}
			}
		}
	}
	//�˻縦 ������ ����ϸ� �̺� �׷���
	return true;
}