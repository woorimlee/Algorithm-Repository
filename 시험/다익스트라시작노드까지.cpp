#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;

int V, E;
vector<vector<pair<int, int>>> adj;

vector <int> dijkstra(int start)
{
	vector<int> dist(V, INF);
	priority_queue<pair<int, int>> pq;
	//dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int thereCost = cost + adj[here][i].second;
			if (dist[there] > thereCost)
			{
				dist[there] = thereCost;
				pq.push({-dist[there], there});
			}
		}
	}

	return dist;
}


int main()
{
	int T;
	cin >> T;
	int u, v, w;

	while (T--)
	{
		cin >> V >> E;

		adj.clear();
		adj.resize(V+1);

		for (int i = 0; i < E; i++)
		{
			cin >> u >> v >> w;
			adj[u-1].push_back({ v-1, w });
		}

		for (int i = 0; i < V; i++) {
			vector <int> answer = dijkstra(i);
			cout << answer[i] << " ";
		}
	}
	return 0;
}