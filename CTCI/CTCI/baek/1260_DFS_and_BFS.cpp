#include <iostream>
//BFS��
#include <queue>
//sort()�� 
#include <algorithm>
//Undirected Graph��
#include <vector>
using namespace std;

int N, M, V;
bool visited[1001] = { false, };
//undirected graph�� ����� ���� 2���� ���� vec.
vector < vector <int> > vec;

int dfs(int now_num) {
	
	visited[now_num] = true;
	cout << now_num << " ";
	for (int i = 0; i < vec[now_num].size(); i++) {
		if (!visited[vec[now_num][i]]) {
			dfs(vec[now_num][i]);
		}
	}
	return 0;
}

//dfs�� �� visited �� ���ڰ� true�� �ٲ� ��Ȳ. (true�� �ʱ�ȭ �Ǿ��ִٴ� ��)
int bfs() {
	queue <int> que;

	que.push(V);
	visited[V] = false;
	cout << V << " ";
	while (!que.empty()) {
		int now_num = que.front(); que.pop();
		for (int i = 0; i < vec[now_num].size(); i++) {
			//�̹� üũ�� ���ڰ� �ƴϸ�
			if (visited[vec[now_num][i]]) {
				que.push(vec[now_num][i]);
				visited[vec[now_num][i]] = false;
				cout << vec[now_num][i] << " ";
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> N >> M >> V;
	vec.resize(N+1);

	//undirected Graph �Է� �ޱ�. 
	//����� �����̴�(���⼺�� ������) 1 3�� �Է¹����� 
	//1 -> 3,   3 -> 1 �� �� ���� ��.
	int temp_a, temp_b;
	while (M--) {
		cin >> temp_a >> temp_b;
		vec[temp_a].push_back(temp_b);
		vec[temp_b].push_back(temp_a);
	}

	//N = 4,   M = 5
	//1 4
	//1 3
	//1 2
	//4 3
	//4 2
	//vec.size = 5
	//sort �Ŀ�
	//vec[1] = 2, 3, 4
	//vec[2] = 1, 4
	//vec[3] = 1, 4
	//vec[4] = 1, 2, 3
	
	/* sort �� ��Ȳ
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << endl;
	}*/ 

	//���� ���ں��� ��ȸ�� ���̴� sort.
	for (int i = 1; i < vec.size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	/* sort �� ��Ȳ
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << endl;
	}*/

	dfs(V);
	cout << "\n";
	bfs();

	return 0;
}