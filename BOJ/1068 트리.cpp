#include <iostream>
#include <vector>

using namespace std;

int N, delete_node, root, reaf=0;
//Ʈ���� ������ ������ ����
vector <vector <int> > graph;
bool visited[51] = { false };

void dfs(int node) {
	//dfs ���� ���� �˻��ߴٰ� ó����
	visited[node] = true;
	//base case
	if (node >= N) {
		return;
	}
	//�ڽ� ����� ���縦 Ȯ��
	bool child = false;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]] == false) {
			//�ڽ� ��尡 �ִ� ���� && �ڽ� ��� �湮���� ���� ����
			child = true;
			dfs(graph[node][i]);
		}
	}
	//�ڽ� ��尡 ���ٸ�
	if (!child) {
		//�� 1 ����
		reaf++;
	}
}
int main() {
	cin >> N;
	graph.resize(N + 1);
	int parent;
	for (int i = 0; i < N; i++) {
		//����� ���� 
		//�Է¹��� ���� i��° ��带 ��������� ������
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
	//���� ���� dfs�� Ž������ ���� ����
	visited[delete_node] = true;
	//��Ʈ ��带 ���� ���� �����ϴ� ��찡 �ִٰ� ��.
	if(visited[root] == false) 
		dfs(root);
	cout << reaf;
	
	return 0;
}