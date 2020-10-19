#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;
vector <vector<double> > dist;
bool visited[8];

double shortest_path(vector<int> & path, double cur_len) {
	if (path.size() == N)
		return cur_len; //맨 마지막 <-> 처음 위치로 돌아가는 길의 경로 값은 더하질 않네
		//return cur_len + dist[path[0]][path.back()];

	double ret = 123456789.0;
	double length = 0.0;
	for (int next = 0; next < N; next++) {
		if (!visited[next]) {
			visited[next] = true;
			if (path.size() != 0) {
				int here = path.back();
				length = dist[here][next];
			}
			path.push_back(next);
			double cand = shortest_path(path, cur_len + length);
			ret = min(ret, cand);
			path.pop_back();
			visited[next] = false;
		}
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N;
		dist.clear();
		dist.resize(N + 1);
		fill(&visited[0], &visited[8], false);
		double d;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> d;
				dist[i].push_back(d);
			}
		}
		cout << fixed;
		cout.precision(10);
		vector<int> path;
		cout << shortest_path(path, 0) << "\n";
	}

	return 0;
}