#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

int N, M, V;
bool visited[1001] = { false, };
vector <vector <int> > vec;

void dfs();
void bfs();

int main() {
	cin >> N >> M >> V;
	vec.resize(N+1);

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i < vec.size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	dfs();
	cout << "\n";
	bfs();
	return 0;
}

void dfs() {

}

void bfs() {

}