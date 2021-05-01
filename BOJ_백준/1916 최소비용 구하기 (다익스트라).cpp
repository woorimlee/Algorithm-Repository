#include <iostream>
#include <vector>
#include <queue>

#define MAX_INT 1234567890
using namespace std;

int N, M;
int start, dest, weight;
vector <pair <int, int> > city[1001];

vector <int> dijkstra(int source) {
	vector <int> dist(N + 1, MAX_INT);
	dist[source] = 0;
	priority_queue <pair <int, int> > pq;	// 정렬해야하니까 
											// cost, vertex
	pq.push({ dist[source], source });

	int cost, vertex, nb, nb_dist;
	while (!pq.empty()) {
		// 현재에서 갈 수 있는 최단거리
		cost = -pq.top().first;
		vertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < city[vertex].size(); i++) {
			nb = city[vertex][i].first;
			nb_dist = cost + city[vertex][i].second;

			//최소 경로 발견
			if (dist[nb] > nb_dist) {
				dist[nb] = nb_dist;
				pq.push({ -nb_dist, nb });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> start >> dest >> weight;
		city[start].push_back({ dest, weight });
	}
	cin >> start >> dest;

	vector <int> result = dijkstra(start);
	cout << result[dest];
	return 0;
}