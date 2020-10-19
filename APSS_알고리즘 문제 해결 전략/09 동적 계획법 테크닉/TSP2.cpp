//개선점 : -1에서 시작하는걸 0으로 바꾸고,
//도시 번호를 0 ~ N-1 -> 1 ~ N으로 바꾸면 더 깔끔할듯
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;
vector <vector<double> > dist;
double cache[16][1 << 16];
double shortest_path(int here, int visited) {
	if (visited == (1 << N) - 1) {
		return 0;
	}

	double& ret = cache[here + 1][visited];
	if (ret != -1)
		return ret;
	ret = 123456789.0;
	for (int next = 0; next < N; next++) {
		if ((visited & (1 << next)) == 0) {
			double cand = shortest_path(next, visited + (1 << next));
			if (here != -1)
				cand += dist[here][next];
			ret = min(ret, cand);
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
		fill(&cache[0][0], &cache[15][1 << 16], -1);
		double d;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> d;
				dist[i].push_back(d);
			}
		}
		cout << fixed;
		cout.precision(10);
		cout << shortest_path(-1, 0) << "\n"; 
	}

	return 0;
}