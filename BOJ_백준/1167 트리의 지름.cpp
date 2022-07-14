#include <iostream>
#include <vector>

using namespace std;

int V;
int diameter_node;
int max_dist = -1;
bool visited[100001];
vector <vector <pair <int, int> > > tree;

//Ʈ�� ������ Ư¡ (�׷��� ���� + dfs�̿��)
//1. ������ �������� ������ ���� �ָ� �������ִ� ��带 ã�´�.
//2. �� ���� �� ���� ��ġ������ ����
//3. 1������ ã�� ��忡�� �ٽ� �� �� ���� �ָ� ������ �ִ� ��带 ã�´�.
//4. 3������ ã�� ���� 1������ ã�� ����� �� �ݴ뿡 ��ġ�ϱ� ������ �� �� ���� ������ �ȴ�.
//5. ����� �̵��� ������ �׷��� ������ �̿� (�Է����� ����� �̵��� �־���)

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
	dfs(1, 0); // �ƹ� ��忡���� ���� ����
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