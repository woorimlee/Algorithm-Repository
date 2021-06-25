#include <iostream>
#include <vector>

using namespace std;

/*
* �� ��忡 ���� ���� �׷����� ǥ����
* �̶� �� ��庰�� ������ ����, ������ ������ �����ؾ� ��.
* n1�� n2�� ������ �����̳� ������ ���� � ����̵� ����Ǿ�������
* ��� ���� �ľ� ����.
* 
* 1. ���� �׷��� �� �� �����ؼ� Ǯ�ų�
* 2. �÷��̵� ���� ����ϰų�
* 
* C++�δ� 1��
* Python���δ� 2�� ������� Ǯ�
*/

int N, M;
bool visited[101];

void dfs(int cur, vector <vector <int> >& graph) {
	visited[cur] = 1;
	for (int next : graph[cur]) {
		if(!visited[next])
			dfs(next, graph);
	}
}

int main() {
	cin >> N >> M;

	vector <vector <int> > scale, inverse_scale;
	scale.resize(N);
	inverse_scale.resize(N);

	int s1, s2;
	for (int i = 0; i < M; i++) {
		cin >> s1 >> s2;
		scale[s1 - 1].push_back(s2 - 1);
		inverse_scale[s2 - 1].push_back(s1 - 1);
	}


	for (int i = 0; i < N; i++) {
		fill(&visited[0], &visited[100], 0);

		dfs(i, scale);
		dfs(i, inverse_scale);
		int cnt = 0;
		for (int j = 0; j < N; j++) 
			if (!visited[j])
				cnt++;
		cout << cnt << "\n";
	}
	return 0;
}