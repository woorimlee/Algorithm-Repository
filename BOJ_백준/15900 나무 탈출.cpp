#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, cnt;
bool visited[500001];
vector<int> tree[500001];

void dfs(int n, int depth)
{
	// leaf node
	if (n != 1 && tree[n].size() == 1)
	{
		if (depth % 2 == 1) cnt++;
		return;
	}

	for (int i = 0; i < tree[n].size(); i++)
	{
		if (visited[n] == false)
		{
			visited[n] = true;
			dfs(tree[n][i], depth + 1);
			visited[n] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0);
	if (cnt % 2 == 1) cout << "Yes";
	else cout << "No";
	return 0;
}