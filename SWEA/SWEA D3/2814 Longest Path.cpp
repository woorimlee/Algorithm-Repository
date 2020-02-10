#include<iostream>
#include<vector>
#include <string.h>
using namespace std;
int T, N, M, ans;
bool visited[11];
vector <vector<int> > vec;

void dfs(int node, int length) {
	//to do : ans ����
	if (length > ans)
		ans = length;

	visited[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {
		if (visited[vec[node][i]] == false) {
			dfs(vec[node][i], length + 1);
			visited[vec[node][i]] = false;
		}
	}
	
}


int main()
{
	int a, b;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		//�׽�Ʈ ���̽� �� �ʱ�ȭ
		ans = 0;
		cin >> N >> M;
		vec.clear();
		vec.resize(N + 1);

		//���, ���� �Է¹޾Ƽ� �����⼺ �׷��� �����.
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		
		for (int i = 1; i <= N; i++) {
			memset(visited, false, sizeof(visited));
			dfs(i, 1);
		}

		cout << "#" << i << " " << ans << endl;
	}
	return 0;
}
