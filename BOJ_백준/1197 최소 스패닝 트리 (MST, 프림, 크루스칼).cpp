#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;
long long ans;

// 크루스칼
int parent[10001];
int rank_[10001];
struct edge {
	int u, v, w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};
vector<edge> graph;

int find(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (rank_[u] > rank_[v])
		swap(u, v);
	parent[u] = v;
	if (rank_[u] == rank_[v])
		rank_[v]++;
}

int comp(const edge& a, const edge& b) {
	return a.w < b.w;
}


// 프림
int visited[10001];
vector <pair <int, int> > edge2[10001];

long long prim() {
	long long res = 0;
	priority_queue <pair <int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({ 0, 1 }); // 가중치 제일 작은 상태로 1번 정점부터 시작

	while (!pq.empty()) {
		pair <int, int> cur = pq.top();
		pq.pop();

		if (!visited[cur.second]) {
			visited[cur.second] = 1;
			res += cur.first;
			for (int i = 0; i < edge2[cur.second].size(); i++)
				if (!visited[edge2[cur.second][i].second])
					pq.push(edge2[cur.second][i]);
		}
	}
	return res;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/* 크루스칼
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
		rank_[i] = 1;
	}
	int A, B, C;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		graph.push_back(edge(A, B, C));
	}
	sort(graph.begin(), graph.end(), comp);
	for (auto& e : graph) {
		if (find(e.v) != find(e.u)) {
			merge(e.u, e.v);
			ans += e.w;
		}
	}*/

	/* 프림
	cin >> V >> E;
	int A, B, C;
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		edge2[A].push_back({ C, B });
		edge2[B].push_back({ C, A });
	}
	ans = prim();
	*/

	cout << ans;
	return 0;
}